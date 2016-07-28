#pragma once

#include <atomic>
#include <memory>

#include "MockData/AnalogGyroData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class AnalogGyroData : NotifyDataBase {
 public:
  double GetAngle();
  void SetAngle(double angle);

  double GetRate();
  void SetRate(double rate);

  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  virtual void ResetData() override;
 private:
  std::atomic<double> m_angle = 0.0;
  std::atomic<double> m_rate = 0.0;
  std::atomic<HAL_Bool> m_initialized = false;
};
extern std::unique_ptr<std::shared_ptr<AnalogGyroData>[]> SimAnalogGyroData;
}
