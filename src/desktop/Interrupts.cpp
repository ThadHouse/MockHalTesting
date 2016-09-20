#include "HAL/Interrupts.h"

#include "MockData/HAL_Value.h"
#include "MockData/DIODataInternal.h"
#include "MockData/AnalogInDataInternal.h"
#include "HAL/Errors.h"
#include "ErrorsInternal.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/LimitedHandleResource.h"
#include "HAL/handles/UnlimitedHandleResource.h"
#include "PortsInternal.h"
#include "DigitalInternal.h"
#include "AnalogInternal.h"
#include "HAL/AnalogTrigger.h"

#include <memory>
#include <condition_variable>

using namespace hal;

enum WaitResult
{
  Timeout = 0x0,
  RisingEdge = 0x1,
  FallingEdge = 0x100,
  Both = 0x101,
};

namespace {
struct Interrupt {
  bool isAnalog;
  HAL_Handle portHandle;
  uint8_t index;
  HAL_AnalogTriggerType trigType;
  bool watcher;
  double risingTimestamp;
  double fallingTimestamp;
  bool previousState;
  bool fireOnUp;
  bool fireOnDown;
  int32_t callbackId;

  void* callbackParam;
  HAL_InterruptHandlerFunction callbackFunction;
};

struct SynchronousWaitData {
  HAL_InterruptHandle interruptHandle;
  std::condition_variable waitCond;
  HAL_Bool waitPredicate;
};
}

static LimitedHandleResource<HAL_InterruptHandle, Interrupt, kNumInterrupts,
                             HAL_HandleEnum::Interrupt>
    interruptHandles;

typedef HAL_Handle SynchronousWaitDataHandle;
static UnlimitedHandleResource<SynchronousWaitDataHandle, SynchronousWaitData, 
                               HAL_HandleEnum::SimData>
    synchronousInterruptHandles;


extern "C" {
HAL_InterruptHandle HAL_InitializeInterrupts(HAL_Bool watcher, int32_t* status) {
  HAL_InterruptHandle handle = interruptHandles.Allocate();
  if (handle == HAL_kInvalidHandle) {
    *status = NO_AVAILABLE_RESOURCES;
    return HAL_kInvalidHandle;
  }
  auto anInterrupt = interruptHandles.Get(handle);
  if (anInterrupt == nullptr) {  // would only occur on thread issue.
    *status = HAL_HANDLE_ERROR;
    return HAL_kInvalidHandle;
  }

  anInterrupt->index = getHandleIndex(handle);
  anInterrupt->callbackId = -1;
}
void HAL_CleanInterrupts(HAL_InterruptHandle interruptHandle, int32_t* status) {
  HAL_DisableInterrupts(interruptHandle, status);
  auto interrupt = interruptHandles.Get(interruptHandle);
  interruptHandles.Free(interruptHandle);
  
}

static void ProcessInterruptDigitalSynchronous(const char* name, void* param, const struct HAL_Value *value) {
  // void* is a SynchronousWaitDataHandle.
  SynchronousWaitDataHandle handle = reinterpret_cast<SynchronousWaitDataHandle>(param);
  auto interruptData = synchronousInterruptHandles.Get(handle);
  if (interruptData == nullptr) return;
  auto interrupt = interruptHandles.Get(interruptData->interruptHandle);
  if (interrupt == nullptr) return;
  // Have a valid interrupt
  if (value->type != HAL_Type::HAL_BOOLEAN) return;
  bool retVal = value->data.v_boolean;
  // If no change in interrupt, return;
  if (retVal == interrupt->previousState) return;
  //If its a falling change, and we dont fire on falling return
  if (interrupt->previousState && !interrupt->fireOnDown) return;
  //If its a rising change, and we dont fire on rising return.
   if (!interrupt->previousState && !interrupt->fireOnUp) return;

   interruptData->waitPredicate = true;
   
   // Pulse interrupt
   interruptData->waitCond.notify_all();
}

static double GetAnalogTriggerValue(HAL_Handle triggerHandle, HAL_AnalogTriggerType type, int32_t* status) {
  return HAL_GetAnalogTriggerOutput(triggerHandle, type, status);
}


static void ProcessInterruptAnalogSynchronous(const char* name, void* param, const struct HAL_Value *value) {
  // void* is a SynchronousWaitDataHandle.
  SynchronousWaitDataHandle handle = reinterpret_cast<SynchronousWaitDataHandle>(param);
  auto interruptData = synchronousInterruptHandles.Get(handle);
  if (interruptData == nullptr) return;
  auto interrupt = interruptHandles.Get(interruptData->interruptHandle);
  if (interrupt == nullptr) return;
  // Have a valid interrupt
  if (value->type != HAL_Type::HAL_DOUBLE) return;
  double dVal = value->data.v_double;
  int32_t status = 0;
  bool retVal = GetAnalogTriggerValue(interrupt->portHandle, interrupt->trigType, &status);
  if (status != 0) {
    // Interrupt and Cancel
     interruptData->waitPredicate = true;
     // Pulse interrupt
     interruptData->waitCond.notify_all();
  }
  // If no change in interrupt, return;
  if (retVal == interrupt->previousState) return;
  //If its a falling change, and we dont fire on falling return
  if (interrupt->previousState && !interrupt->fireOnDown) return;
  //If its a rising change, and we dont fire on rising return.
   if (!interrupt->previousState && !interrupt->fireOnUp) return;

   interruptData->waitPredicate = true;
   
   // Pulse interrupt
   interruptData->waitCond.notify_all();
}

static int64_t WaitForInterruptDigital(HAL_InterruptHandle handle, Interrupt* interrupt, double timeout, bool ignorePrevious) {
  auto data = std::make_shared<SynchronousWaitData>();
  
  auto dataHandle = synchronousInterruptHandles.Allocate(data);
  if (dataHandle == HAL_kInvalidHandle) {
    // Error allocating data
    return WaitResult::Timeout;
  }

  //auto data = synchronousInterruptHandles.Get(dataHandle);
  data->waitPredicate = false;
  data->interruptHandle = handle;

  int32_t status = 0;

  int32_t digitalIndex = GetDigitalInputChannel(interrupt->portHandle, &status);

  if (status != 0) return WaitResult::Timeout;

  interrupt->previousState = SimDIOData[digitalIndex].GetValue();

  int32_t uid = SimDIOData[digitalIndex].RegisterValueCallback(&ProcessInterruptDigitalSynchronous, reinterpret_cast<void*>(dataHandle), false);

  bool timedOut = false;;

  std::mutex waitMutex;

#if defined(_MSC_VER) && _MSC_VER < 1900
  auto timeoutTime = std::chrono::steady_clock::now() + 
      std::chrono::duration<int64_t, std::nano>(static_cast<int64_t>
      (timeout * 1e9));
#else
  auto timeoutTime = std::chrono::steady_clock::now() + 
      std::chrono::duration<double>(timeout);
#endif
  
  {
    std::unique_lock<std::mutex> lock(waitMutex);
    while (!data->waitPredicate) {
      if (data->waitCond.wait_until(lock, timeoutTime) == std::cv_status::timeout) {
        timedOut = true;
        break;
      }
    }
  }
  
  // Cancel our callback
  SimDIOData[digitalIndex].CancelValueCallback(uid);
  synchronousInterruptHandles.Free(dataHandle);

  // Check for what to return
  if (timedOut) return WaitResult::Timeout;
  //True => false, Falling
  if (interrupt->previousState) {
    //Set our return value and our timestamps
    //interrupt.FallingTimestamp = SimHooks.GetFPGATimestamp();
    //interrupt.RisingTimestamp = 0;
    return WaitResult::FallingEdge;
  } else {
    //interrupt.RisingTimestamp = SimHooks.GetFPGATimestamp();
    //interrupt.FallingTimestamp = 0;
    return WaitResult::RisingEdge;
  }
}

static int64_t WaitForInterruptAnalog(HAL_InterruptHandle handle, Interrupt* interrupt, double timeout, bool ignorePrevious) {
  auto data = std::make_shared<SynchronousWaitData>();
  
  auto dataHandle = synchronousInterruptHandles.Allocate(data);
  if (dataHandle == HAL_kInvalidHandle) {
    // Error allocating data
    return WaitResult::Timeout;
  }

  data->waitPredicate = false;
  data->interruptHandle = handle;

  int32_t status = 0;
  interrupt->previousState = GetAnalogTriggerValue(interrupt->portHandle, interrupt->trigType, &status);

  if (status != 0) return WaitResult::Timeout;

  int32_t analogIndex = GetAnalogTriggerInputIndex(interrupt->portHandle, &status);

  if (status != 0) return WaitResult::Timeout;

  int32_t uid = SimAnalogInData[analogIndex].RegisterVoltageCallback(&ProcessInterruptAnalogSynchronous, reinterpret_cast<void*>(dataHandle), false);

  bool timedOut = false;;

  std::mutex waitMutex;

#if defined(_MSC_VER) && _MSC_VER < 1900
  auto timeoutTime = std::chrono::steady_clock::now() + 
      std::chrono::duration<int64_t, std::nano>(static_cast<int64_t>
      (timeout * 1e9));
#else
  auto timeoutTime = std::chrono::steady_clock::now() + 
      std::chrono::duration<double>(timeout);
#endif
  
  {
    std::unique_lock<std::mutex> lock(waitMutex);
    while (!data->waitPredicate) {
      if (data->waitCond.wait_until(lock, timeoutTime) == std::cv_status::timeout) {
        timedOut = true;
        break;
      }
    }
  }
  
  // Cancel our callback
  SimAnalogInData[analogIndex].CancelVoltageCallback(uid);
  synchronousInterruptHandles.Free(dataHandle);

  // Check for what to return
  if (timedOut) return WaitResult::Timeout;
  //True => false, Falling
  if (interrupt->previousState) {
    //Set our return value and our timestamps
    //interrupt.FallingTimestamp = SimHooks.GetFPGATimestamp();
    //interrupt.RisingTimestamp = 0;
    return WaitResult::FallingEdge;
  } else {
    //interrupt.RisingTimestamp = SimHooks.GetFPGATimestamp();
    //interrupt.FallingTimestamp = 0;
    return WaitResult::RisingEdge;
  }
}

int64_t HAL_WaitForInterrupt(HAL_InterruptHandle interruptHandle,
                             double timeout, HAL_Bool ignorePrevious,
                             int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return WaitResult::Timeout;
  }

  // Check to make sure we are actually an interrupt in synchronous mode
  if (!interrupt->watcher) {
    *status = NiFpga_Status_InvalidParameter;
    return WaitResult::Timeout;
  }

  if (interrupt->isAnalog) {
    // Do analog
  } else {
    return WaitForInterruptDigital(interruptHandle, interrupt.get(), timeout, ignorePrevious);
  }
}

static void ProcessInterruptDigitalAsynchronous(const char* name, void* param, const struct HAL_Value *value) {
  // void* is a HAL handle
  HAL_InterruptHandle handle = reinterpret_cast<HAL_InterruptHandle>(param);
  auto interrupt = interruptHandles.Get(handle);
  if (interrupt == nullptr) return;
  // Have a valid interrupt
  if (value->type != HAL_Type::HAL_BOOLEAN) return;
  bool retVal = value->data.v_boolean;
  // If no change in interrupt, return;
  if (retVal == interrupt->previousState) return;
  if (interrupt->previousState) {
    interrupt->previousState = retVal;
    if (!interrupt->fireOnDown) return;
    // set timestamps
  } else {
    interrupt->previousState = retVal;
    if (!interrupt->fireOnUp) return;
  }

  int32_t status = 0;
  int32_t digitalIndex = GetDigitalInputChannel(interrupt->portHandle, &status);
  if (status != 0) return;

  // run callback
  auto callback = interrupt->callbackFunction;
  if (callback == nullptr) return;
  callback(digitalIndex, interrupt->callbackParam);
}


static void EnableInterruptsDigital(HAL_InterruptHandle handle, Interrupt* interrupt) {
  int32_t status = 0;
  int32_t digitalIndex = GetDigitalInputChannel(interrupt->portHandle, &status);
  if (status != 0) return;
  
  interrupt->previousState = SimDIOData[digitalIndex].GetValue();

  int32_t uid = SimDIOData[digitalIndex].RegisterValueCallback(&ProcessInterruptDigitalAsynchronous, reinterpret_cast<void*>(handle), false);
  interrupt->callbackId = uid;
}
void HAL_EnableInterrupts(HAL_InterruptHandle interruptHandle, int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  // If we have not had a callback set, error out 
  if (interrupt->callbackFunction == nullptr){
    *status = INCOMPATIBLE_STATE;
    return;
  }

  // EnableInterrupts has already been called
  if (interrupt->callbackId < 0) {
    // We can double enable safely.
    return;
  }

  if (interrupt->isAnalog) {
    // Do analog
  } else {
    return EnableInterruptsDigital(interruptHandle, interrupt.get());
  }
}
void HAL_DisableInterrupts(HAL_InterruptHandle interruptHandle,
                           int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  // No need to disable if we are already disabled
  if (interrupt->callbackId < 0) return;

  if (interrupt->isAnalog) {
    // Do analog
  } else {
    int32_t status = 0;
    int32_t digitalIndex = GetDigitalInputChannel(interrupt->portHandle, &status);
    if (status != 0) return;
    SimDIOData[digitalIndex].CancelValueCallback(interrupt->callbackId);
  }
  interrupt->callbackId = -1;
}
double HAL_ReadInterruptRisingTimestamp(HAL_InterruptHandle interruptHandle,
                                        int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return interrupt->risingTimestamp;
}
double HAL_ReadInterruptFallingTimestamp(HAL_InterruptHandle interruptHandle,
                                         int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return interrupt->fallingTimestamp;
}
void HAL_RequestInterrupts(HAL_InterruptHandle interruptHandle,
                           HAL_Handle digitalSourceHandle,
                           HAL_AnalogTriggerType analogTriggerType,
                           int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  bool routingAnalogTrigger = false;
  uint8_t routingChannel = 0;
  uint8_t routingModule = 0;
  bool success =
      remapDigitalSource(digitalSourceHandle, analogTriggerType, routingChannel,
                         routingModule, routingAnalogTrigger);
  if (!success) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  interrupt->isAnalog = routingAnalogTrigger;
  interrupt->trigType = analogTriggerType;
  interrupt->portHandle = digitalSourceHandle;
}
void HAL_AttachInterruptHandler(HAL_InterruptHandle interruptHandle,
                                HAL_InterruptHandlerFunction handler,
                                void* param, int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  interrupt->callbackFunction = handler;
  interrupt->callbackParam = param;
}
void HAL_SetInterruptUpSourceEdge(HAL_InterruptHandle interruptHandle,
                                  HAL_Bool risingEdge, HAL_Bool fallingEdge,
                                  int32_t* status) {
  auto interrupt = interruptHandles.Get(interruptHandle);
  if (interrupt == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  interrupt->fireOnDown = fallingEdge;
  interrupt->fireOnUp = risingEdge;
}
}