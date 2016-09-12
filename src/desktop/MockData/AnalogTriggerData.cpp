#include "AnalogTriggerDataInternal.h"

#include "NotifyCallbackHelpers.h"
#include "../PortsInternal.h"

using namespace hal;

AnalogTriggerData hal::SimAnalogTriggerData[kNumAnalogTriggers];
void AnalogTriggerData::ResetData() {
  m_initialized = 0;
  m_initializedCallbacks = nullptr;
  m_triggerLowerBound = 0;
  m_triggerLowerBoundCallbacks = nullptr;
  m_triggerUpperBound = 0;
  m_triggerUpperBoundCallbacks = nullptr;
}

int32_t AnalogTriggerData::RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_initializedCallbacks = RegisterCallback(m_initializedCallbacks, "Initialized", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeBoolean(GetInitialized());
    callback("Initialized", param, &value);
  }
  return newUid;
}

void AnalogTriggerData::CancelInitializedCallback(int32_t uid) {
  m_initializedCallbacks = CancelCallback(m_initializedCallbacks, uid);
}

void AnalogTriggerData::InvokeInitializedCallback(HAL_Value value) {
  InvokeCallback(m_initializedCallbacks, "Initialized", &value);
}

HAL_Bool AnalogTriggerData::GetInitialized() {
  return m_initialized;
}

void AnalogTriggerData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    InvokeInitializedCallback(MakeBoolean(initialized));
  }
}

int32_t AnalogTriggerData::RegisterTriggerLowerBoundCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_triggerLowerBoundCallbacks = RegisterCallback(m_triggerLowerBoundCallbacks, "TriggerLowerBound", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeDouble(GetTriggerLowerBound());
    callback("TriggerLowerBound", param, &value);
  }
  return newUid;
}

void AnalogTriggerData::CancelTriggerLowerBoundCallback(int32_t uid) {
  m_triggerLowerBoundCallbacks = CancelCallback(m_triggerLowerBoundCallbacks, uid);
}

void AnalogTriggerData::InvokeTriggerLowerBoundCallback(HAL_Value value) {
  InvokeCallback(m_triggerLowerBoundCallbacks, "TriggerLowerBound", &value);
}

double AnalogTriggerData::GetTriggerLowerBound() {
  return m_triggerLowerBound;
}

void AnalogTriggerData::SetTriggerLowerBound(double triggerLowerBound) {
  double oldValue = m_triggerLowerBound.exchange(triggerLowerBound);
  if (oldValue != triggerLowerBound) {
    InvokeTriggerLowerBoundCallback(MakeDouble(triggerLowerBound));
  }
}

int32_t AnalogTriggerData::RegisterTriggerUpperBoundCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_triggerUpperBoundCallbacks = RegisterCallback(m_triggerUpperBoundCallbacks, "TriggerUpperBound", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeDouble(GetTriggerUpperBound());
    callback("TriggerUpperBound", param, &value);
  }
  return newUid;
}

void AnalogTriggerData::CancelTriggerUpperBoundCallback(int32_t uid) {
  m_triggerUpperBoundCallbacks = CancelCallback(m_triggerUpperBoundCallbacks, uid);
}

void AnalogTriggerData::InvokeTriggerUpperBoundCallback(HAL_Value value) {
  InvokeCallback(m_triggerUpperBoundCallbacks, "TriggerUpperBound", &value);
}

double AnalogTriggerData::GetTriggerUpperBound() {
  return m_triggerUpperBound;
}

void AnalogTriggerData::SetTriggerUpperBound(double triggerUpperBound) {
  double oldValue = m_triggerUpperBound.exchange(triggerUpperBound);
  if (oldValue != triggerUpperBound) {
    InvokeTriggerUpperBoundCallback(MakeDouble(triggerUpperBound));
  }
}

extern "C" {
void HALSIM_ResetAnalogTriggerData(int32_t index) {
  SimAnalogTriggerData[index].ResetData();
}

int32_t HALSIM_RegisterAnalogTriggerInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAnalogTriggerData[index].RegisterInitializedCallback(callback, param, initialNotify);
}

void HALSIM_CancelAnalogTriggerInitializedCallback(int32_t index, int32_t uid) {
  SimAnalogTriggerData[index].CancelInitializedCallback(uid);
}

HAL_Bool HALSIM_GetAnalogTriggerInitialized(int32_t index) {
  return SimAnalogTriggerData[index].GetInitialized();
}

int32_t HALSIM_RegisterAnalogTriggerTriggerLowerBoundCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAnalogTriggerData[index].RegisterTriggerLowerBoundCallback(callback, param, initialNotify);
}

void HALSIM_CancelAnalogTriggerTriggerLowerBoundCallback(int32_t index, int32_t uid) {
  SimAnalogTriggerData[index].CancelTriggerLowerBoundCallback(uid);
}

double HALSIM_GetAnalogTriggerTriggerLowerBound(int32_t index) {
  return SimAnalogTriggerData[index].GetTriggerLowerBound();
}

int32_t HALSIM_RegisterAnalogTriggerTriggerUpperBoundCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAnalogTriggerData[index].RegisterTriggerUpperBoundCallback(callback, param, initialNotify);
}

void HALSIM_CancelAnalogTriggerTriggerUpperBoundCallback(int32_t index, int32_t uid) {
  SimAnalogTriggerData[index].CancelTriggerUpperBoundCallback(uid);
}

double HALSIM_GetAnalogTriggerTriggerUpperBound(int32_t index) {
  return SimAnalogTriggerData[index].GetTriggerUpperBound();
}

}
