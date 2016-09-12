#pragma once

#include <atomic>
#include <memory>

#include "MockData/AnalogOutData.h"
#include "MockData/NotifyListenerVector.h"

namespace hal {
class AnalogOutData {
 public:
  int32_t RegisterVoltageCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelVoltageCallback(int32_t uid);
  void InvokeVoltageCallback(HAL_Value value);
  double GetVoltage();
  void SetVoltage(double voltage);

  int32_t RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelInitializedCallback(int32_t uid);
  void InvokeInitializedCallback(HAL_Value value);
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  virtual void ResetData();
 private:
  std::mutex m_registerMutex;
  std::atomic<double> m_voltage {0.0};
  std::shared_ptr<NotifyListenerVector> m_voltageCallbacks = nullptr;
  std::atomic<HAL_Bool> m_initialized {0};
  std::shared_ptr<NotifyListenerVector> m_initializedCallbacks = nullptr;
};
extern AnalogOutData SimAnalogOutData[];
}
