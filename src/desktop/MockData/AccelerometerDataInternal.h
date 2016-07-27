#pragma once

#include "MockData/AccelerometerData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class AccelerometerData : DataBase {
 public:
  bool GetActive();
  void SetActive(bool active);
  
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
  std::atomic<bool> m_active;
  std::atomic<HAL_AccelerometerRange> m_range;
  std::atomic<double> m_x;
  std::atomic<double> m_y;
  std::atomic<double> m_z;
};
}