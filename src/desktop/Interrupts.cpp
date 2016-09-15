#include "HAL/Interrupts.h"

#include "MockData/HAL_Value.h"
#include "MockData/DIODataInternal.h"
#include "HAL/Errors.h"
#include "ErrorsInternal.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/LimitedHandleResource.h"
#include "PortsInternal.h"

#include <memory>

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
  int pinIndex;
  uint8_t index;
  HAL_AnalogTriggerType trigType;
  bool watcher;
  double risingTimestamp;
  double fallintTimestamp;
  bool previousState;
  bool fireOnUp;
  bool fireOnDown;
  int32_t callbackId;

  void* callbackParam;
  HAL_InterruptHandlerFunction callbackFunction;
};
}

static LimitedHandleResource<HAL_InterruptHandle, Interrupt, kNumInterrupts,
                             HAL_HandleEnum::Interrupt>
    interruptHandles;


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
  auto interrupt = interruptHandles.Get(interruptHandle);
  interruptHandles.Free(interruptHandle);
}

static void ProcessInterruptSynchronous(const char* name, void* param, const struct HAL_Value *value) {
  // void* is a HAL handle
  HAL_InterruptHandle handle = reinterpret_cast<HAL_InterruptHandle>(param);
  auto interrupt = interruptHandles.Get(handle);
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
   
   // Pulse interrupt
}

static int64_t WaitForInterruptDigital(HAL_InterruptHandle handle, Interrupt* interrupt, double timeout, bool ignorePrevious) {
  interrupt->previousState = SimDIOData[interrupt->pinIndex].GetValue();

  SimDIOData[interrupt->pinIndex].RegisterValueCallback(&ProcessInterruptSynchronous, reinterpret_cast<void*>(handle), false);

  int64_t result = WaitResult::Timeout;

  // Lock and wait for stuff;

  return result;
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

static void ProcessInterruptAsynchronous(const char* name, void* param, const struct HAL_Value *value) {
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

  // run callback
}


static void EnableInterruptsDigital(HAL_InterruptHandle handle, Interrupt* interrupt) {
  interrupt->previousState = SimDIOData[interrupt->pinIndex].GetValue();

  int32_t uid = SimDIOData[interrupt->pinIndex].RegisterValueCallback(&ProcessInterruptAsynchronous, reinterpret_cast<void*>(handle), false);
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
    SimDIOData[interrupt->pinIndex].CancelValueCallback(interrupt->callbackId);
  }
  interrupt->callbackId = -1;
}
double HAL_ReadInterruptRisingTimestamp(HAL_InterruptHandle interruptHandle,
                                        int32_t* status);
double HAL_ReadInterruptFallingTimestamp(HAL_InterruptHandle interruptHandle,
                                         int32_t* status);
void HAL_RequestInterrupts(HAL_InterruptHandle interruptHandle,
                           HAL_Handle digitalSourceHandle,
                           HAL_AnalogTriggerType analogTriggerType,
                           int32_t* status);
void HAL_AttachInterruptHandler(HAL_InterruptHandle interruptHandle,
                                HAL_InterruptHandlerFunction handler,
                                void* param, int32_t* status);
void HAL_SetInterruptUpSourceEdge(HAL_InterruptHandle interruptHandle,
                                  HAL_Bool risingEdge, HAL_Bool fallingEdge,
                                  int32_t* status);
}