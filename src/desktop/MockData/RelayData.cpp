#include "RelayDataInternal.h"

#include "NotifyCallbackHelpers.h"
#include "../PortsInternal.h"

using namespace hal;

RelayData hal::SimRelayData[kNumRelayHeaders];
void RelayData::ResetData() {
  m_initialized = false;
  m_initializedCallbacks = nullptr;
  m_forward = false;
  m_forwardCallbacks = nullptr;
  m_reverse = false;
  m_reverseCallbacks = nullptr;
}

int32_t RelayData::RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
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

void RelayData::CancelInitializedCallback(int32_t uid) {
  m_initializedCallbacks = CancelCallback(m_initializedCallbacks, uid);
}

void RelayData::InvokeInitializedCallback(HAL_Value value) {
  InvokeCallback(m_initializedCallbacks, "Initialized", &value);
}

HAL_Bool RelayData::GetInitialized() {
  return m_initialized;
}

void RelayData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    InvokeInitializedCallback(MakeBoolean(initialized));
  }
}

int32_t RelayData::RegisterForwardCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_forwardCallbacks = RegisterCallback(m_forwardCallbacks, "Forward", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeBoolean(GetForward());
    callback("Forward", param, &value);
  }
  return newUid;
}

void RelayData::CancelForwardCallback(int32_t uid) {
  m_forwardCallbacks = CancelCallback(m_forwardCallbacks, uid);
}

void RelayData::InvokeForwardCallback(HAL_Value value) {
  InvokeCallback(m_forwardCallbacks, "Forward", &value);
}

HAL_Bool RelayData::GetForward() {
  return m_forward;
}

void RelayData::SetForward(HAL_Bool forward) {
  HAL_Bool oldValue = m_forward.exchange(forward);
  if (oldValue != forward) {
    InvokeForwardCallback(MakeBoolean(forward));
  }
}

int32_t RelayData::RegisterReverseCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_reverseCallbacks = RegisterCallback(m_reverseCallbacks, "Reverse", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeBoolean(GetReverse());
    callback("Reverse", param, &value);
  }
  return newUid;
}

void RelayData::CancelReverseCallback(int32_t uid) {
  m_reverseCallbacks = CancelCallback(m_reverseCallbacks, uid);
}

void RelayData::InvokeReverseCallback(HAL_Value value) {
  InvokeCallback(m_reverseCallbacks, "Reverse", &value);
}

HAL_Bool RelayData::GetReverse() {
  return m_reverse;
}

void RelayData::SetReverse(HAL_Bool reverse) {
  HAL_Bool oldValue = m_reverse.exchange(reverse);
  if (oldValue != reverse) {
    InvokeReverseCallback(MakeBoolean(reverse));
  }
}

extern "C" {
void HALSIM_ResetRelayData(int32_t index) {
  SimRelayData[index].ResetData();
}

int32_t HALSIM_RegisterRelayInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimRelayData[index].RegisterInitializedCallback(callback, param, initialNotify);
}

void HALSIM_CancelRelayInitializedCallback(int32_t index, int32_t uid) {
  SimRelayData[index].CancelInitializedCallback(uid);
}

HAL_Bool HALSIM_GetRelayInitialized(int32_t index) {
  return SimRelayData[index].GetInitialized();
}

int32_t HALSIM_RegisterRelayForwardCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimRelayData[index].RegisterForwardCallback(callback, param, initialNotify);
}

void HALSIM_CancelRelayForwardCallback(int32_t index, int32_t uid) {
  SimRelayData[index].CancelForwardCallback(uid);
}

HAL_Bool HALSIM_GetRelayForward(int32_t index) {
  return SimRelayData[index].GetForward();
}

int32_t HALSIM_RegisterRelayReverseCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimRelayData[index].RegisterReverseCallback(callback, param, initialNotify);
}

void HALSIM_CancelRelayReverseCallback(int32_t index, int32_t uid) {
  SimRelayData[index].CancelReverseCallback(uid);
}

HAL_Bool HALSIM_GetRelayReverse(int32_t index) {
  return SimRelayData[index].GetReverse();
}

}
