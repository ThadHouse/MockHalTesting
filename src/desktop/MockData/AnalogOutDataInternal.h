#pragma once

#include <atomic>
#include <memory>

#include "MockData/AnalogOutData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class AnalogOutData : NotifyDataBase {
 public:
  double GetVoltage();
  void SetVoltage(double voltage);

  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  virtual void ResetData() override;
 private:
  std::atomic<double> m_voltage = 0.0;
  std::atomic<HAL_Bool> m_initialized = 0.0;
};
extern std::unique_ptr<std::shared_ptr<AnalogOutData>[]> SimAnalogOutData;
}
