#include "AccelerometerDataInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<AccelerometerData>[]> hal::SimAccelerometerData = std::make_unique<std::shared_ptr<AccelerometerData>[]>(1);
void AccelerometerData::ResetData() {
  m_active = false;
  m_range = (HAL_AccelerometerRange)0;
  m_x = 0.0;
  m_y = 0.0;
  m_z = 0.0;
}

HAL_Bool AccelerometerData::GetActive() {
  return m_active;
}

void AccelerometerData::SetActive(HAL_Bool active) {
  HAL_Bool oldValue = m_active.exchange(active);
  if (oldValue != active) {
    OnPropertyChanged(&MakeBoolean(active));
  }
}

HAL_AccelerometerRange AccelerometerData::GetRange() {
  return m_range;
}

void AccelerometerData::SetRange(HAL_AccelerometerRange range) {
  HAL_AccelerometerRange oldValue = m_range.exchange(range);
  if (oldValue != range) {
    OnPropertyChanged(&MakeEnum(range));
  }
}

double AccelerometerData::GetX() {
  return m_x;
}

void AccelerometerData::SetX(double x) {
  double oldValue = m_x.exchange(x);
  if (oldValue != x) {
    OnPropertyChanged(&MakeDouble(x));
  }
}

double AccelerometerData::GetY() {
  return m_y;
}

void AccelerometerData::SetY(double y) {
  double oldValue = m_y.exchange(y);
  if (oldValue != y) {
    OnPropertyChanged(&MakeDouble(y));
  }
}

double AccelerometerData::GetZ() {
  return m_z;
}

void AccelerometerData::SetZ(double z) {
  double oldValue = m_z.exchange(z);
  if (oldValue != z) {
    OnPropertyChanged(&MakeDouble(z));
  }
}

extern "C" {
HAL_Bool HALSIM_GetAccelerometerActive(int32_t index) {
  return SimAccelerometerData[index]->GetActive();
}

HAL_AccelerometerRange HALSIM_GetAccelerometerRange(int32_t index) {
  return SimAccelerometerData[index]->GetRange();
}

double HALSIM_GetAccelerometerX(int32_t index) {
  return SimAccelerometerData[index]->GetX();
}

double HALSIM_GetAccelerometerY(int32_t index) {
  return SimAccelerometerData[index]->GetY();
}

double HALSIM_GetAccelerometerZ(int32_t index) {
  return SimAccelerometerData[index]->GetZ();
}

}
