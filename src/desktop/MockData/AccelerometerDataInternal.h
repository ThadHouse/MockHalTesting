#pragma once

#include <atomic>
#include <memory>

#include "MockData/AccelerometerData.h"
#include "MockData/DataBase.h"

namespace hal {
class AccelerometerData : DataBase {
 public:
  HAL_Bool GetActive();
  void SetActive(HAL_Bool active);

  HAL_AccelerometerRange GetRange();
  void SetRange(HAL_AccelerometerRange range);

  double GetX();
  void SetX(double x);

  double GetY();
  void SetY(double y);

  double GetZ();
  void SetZ(double z);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_active = false;
  std::atomic<HAL_AccelerometerRange> m_range = (HAL_AccelerometerRange)0;
  std::atomic<double> m_x = 0.0;
  std::atomic<double> m_y = 0.0;
  std::atomic<double> m_z = 0.0;
};
extern std::unique_ptr<std::shared_ptr<AccelerometerData>[]> SimAccelerometerData;
}