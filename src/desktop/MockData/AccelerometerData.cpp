#include "AccelerometerDataInternal.h"

#include <memory>

using namespace hal;

static std::unique_ptr<AccelerometerData> accelData = std::make_unique<AccelerometerData>();

void AccelerometerData::ResetData() {
  m_active = false;
  m_range = (HAL_AccelerometerRange)0;
  m_x = 0;
  m_y = 0;
  m_z = 0;
}

bool AccelerometerData::GetActive() {
  return m_active;
}

void AccelerometerData::SetActive(bool active) {
  bool oldValue = m_active.exchange(active);
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