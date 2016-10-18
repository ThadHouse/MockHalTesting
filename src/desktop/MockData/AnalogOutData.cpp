#include "AnalogOutDataInternal.h"

#include "NotifyCallbackHelpers.h"
#include "../PortsInternal.h"

using namespace hal;

AnalogOutData hal::SimAnalogOutData[kNumAnalogOutputs];
void AnalogOutData::ResetData() {
  m_voltage = 0.0;
  m_voltageCallbacks = nullptr;
  m_initialized = 0;
  m_initializedCallbacks = nullptr;
}

int32_t AnalogOutData::RegisterVoltageCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Must return -1 on a null callback for error handling
  if (callback == nullptr) return -1;
  int32_t newUid = 0;
 {
    std::lock_guard<std::mutex> lock(m_registerMutex);
    m_voltageCallbacks = RegisterCallback(m_voltageCallbacks, "Voltage", callback, param, &newUid);
  }
  if (initialNotify) {
    // We know that the callback is not null because of earlier null check
    HAL_Value value = MakeDouble(GetVoltage());
    callback("Voltage", param, &value);
  }
  return newUid;
}

void AnalogOutData::CancelVoltageCallback(int32_t uid) {
  m_voltageCallbacks = CancelCallback(m_voltageCallbacks, uid);
}

void AnalogOutData::InvokeVoltageCallback(HAL_Value value) {
  InvokeCallback(m_voltageCallbacks, "Voltage", &value);
}

double AnalogOutData::GetVoltage() {
  return m_voltage;
}

void AnalogOutData::SetVoltage(double voltage) {
  double oldValue = m_voltage.exchange(voltage);
  if (oldValue != voltage) {
    InvokeVoltageCallback(MakeDouble(voltage));
  }
}

int32_t AnalogOutData::RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
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

void AnalogOutData::CancelInitializedCallback(int32_t uid) {
  m_initializedCallbacks = CancelCallback(m_initializedCallbacks, uid);
}

void AnalogOutData::InvokeInitializedCallback(HAL_Value value) {
  InvokeCallback(m_initializedCallbacks, "Initialized", &value);
}

HAL_Bool AnalogOutData::GetInitialized() {
  return m_initialized;
}

void AnalogOutData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    InvokeInitializedCallback(MakeBoolean(initialized));
  }
}

extern "C" {
void HALSIM_ResetAnalogOutData(int32_t index) {
  SimAnalogOutData[index].ResetData();
}

int32_t HALSIM_RegisterAnalogOutVoltageCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAnalogOutData[index].RegisterVoltageCallback(callback, param, initialNotify);
}

void HALSIM_CancelAnalogOutVoltageCallback(int32_t index, int32_t uid) {
  SimAnalogOutData[index].CancelVoltageCallback(uid);
}

double HALSIM_GetAnalogOutVoltage(int32_t index) {
  return SimAnalogOutData[index].GetVoltage();
}

void HALSIM_SetAnalogOutVoltage(int32_t index, double voltage) {
  SimAnalogOutData[index].SetVoltage(voltage);
}

int32_t HALSIM_RegisterAnalogOutInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAnalogOutData[index].RegisterInitializedCallback(callback, param, initialNotify);
}

void HALSIM_CancelAnalogOutInitializedCallback(int32_t index, int32_t uid) {
  SimAnalogOutData[index].CancelInitializedCallback(uid);
}

HAL_Bool HALSIM_GetAnalogOutInitialized(int32_t index) {
  return SimAnalogOutData[index].GetInitialized();
}

void HALSIM_SetAnalogOutInitialized(int32_t index, HAL_Bool initialized) {
  SimAnalogOutData[index].SetInitialized(initialized);
}

}
