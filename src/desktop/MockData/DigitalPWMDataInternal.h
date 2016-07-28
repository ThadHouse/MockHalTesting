#pragma once

#include <atomic>
#include <memory>

#include "MockData/DigitalPWMData.h"
#include "MockData/DataBase.h"

namespace hal {
class DigitalPWMData : DataBase {
 public:
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  double GetDutyCycle();
  void SetDutyCycle(double dutyCycle);

  int32_t GetPin();
  void SetPin(int32_t pin);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_initialized = false;
  std::atomic<double> m_dutyCycle = false;
  std::atomic<int32_t> m_pin = 0;
};
extern std::unique_ptr<std::shared_ptr<DigitalPWMData>[]> SimDigitalPWMData;
}
