#pragma once

#include <atomic>

#include "HAL/Accelerometer.h"
#include "NotifyDataBase.h"

#ifdef __cplusplus
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
  
 private:
  std::atomic<bool> m_active;
  std::atomic<HAL_AccelerometerRange> m_range;
  std::atomic<double> m_x;
  std::atomic<double> m_y;
  std::atomic<double> m_z;
}
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetAcceleromterActive(void);
void HALSIM_SetAccelerometerActive(HAL_AccelerometerRange range);

#ifdef __cplusplus
}
#endif