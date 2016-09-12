#pragma once

#include <atomic>
#include <memory>

#include "MockData/AnalogGyroData.h"
#include "MockData/NotifyListenerVector.h"

namespace hal {
class AnalogGyroData {
 public:
  int32_t RegisterAngleCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelAngleCallback(int32_t uid);
  void InvokeAngleCallback(HAL_Value value);
  double GetAngle();
  void SetAngle(double angle);

  int32_t RegisterRateCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelRateCallback(int32_t uid);
  void InvokeRateCallback(HAL_Value value);
  double GetRate();
  void SetRate(double rate);

  int32_t RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelInitializedCallback(int32_t uid);
  void InvokeInitializedCallback(HAL_Value value);
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  virtual void ResetData();
 private:
  std::mutex m_registerMutex;
  std::atomic<double> m_angle {0.0};
  std::shared_ptr<NotifyListenerVector> m_angleCallbacks = nullptr;
  std::atomic<double> m_rate {0.0};
  std::shared_ptr<NotifyListenerVector> m_rateCallbacks = nullptr;
  std::atomic<HAL_Bool> m_initialized {false};
  std::shared_ptr<NotifyListenerVector> m_initializedCallbacks = nullptr;
};
extern AnalogGyroData SimAnalogGyroData[];
}
