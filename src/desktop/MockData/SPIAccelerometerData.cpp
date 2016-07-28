#include "SPIAccelerometerDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<SPIAccelerometerData>[]> hal::SimSPIAccelerometerData = std::make_unique<std::shared_ptr<SPIAccelerometerData>[]>(5);
void SPIAccelerometerData::ResetData() {
  m_active = false;
  m_range = 0;
  m_x = 0.0;
  m_y = 0.0;
  m_z = 0.0;
}

HAL_Bool SPIAccelerometerData::GetActive() {
  return m_active;
}

void SPIAccelerometerData::SetActive(HAL_Bool active) {
  HAL_Bool oldValue = m_active.exchange(active);
  if (oldValue != active) {
    OnPropertyChanged(&MakeBoolean(active));
  }
}

uint8_t SPIAccelerometerData::GetRange() {
  return m_range;
}

void SPIAccelerometerData::SetRange(uint8_t range) {
  uint8_t oldValue = m_range.exchange(range);
  if (oldValue != range) {
    OnPropertyChanged(&MakeEnum(range));
  }
}

double SPIAccelerometerData::GetX() {
  return m_x;
}

void SPIAccelerometerData::SetX(double x) {
  double oldValue = m_x.exchange(x);
  if (oldValue != x) {
    OnPropertyChanged(&MakeDouble(x));
  }
}

double SPIAccelerometerData::GetY() {
  return m_y;
}

void SPIAccelerometerData::SetY(double y) {
  double oldValue = m_y.exchange(y);
  if (oldValue != y) {
    OnPropertyChanged(&MakeDouble(y));
  }
}

double SPIAccelerometerData::GetZ() {
  return m_z;
}

void SPIAccelerometerData::SetZ(double z) {
  double oldValue = m_z.exchange(z);
  if (oldValue != z) {
    OnPropertyChanged(&MakeDouble(z));
  }
}

extern "C" {
HAL_Bool HALSIM_GetSPIAccelerometerActive(int32_t index) {
  return SimSPIAccelerometerData[index]->GetActive();
}

uint8_t HALSIM_GetSPIAccelerometerRange(int32_t index) {
  return SimSPIAccelerometerData[index]->GetRange();
}

double HALSIM_GetSPIAccelerometerX(int32_t index) {
  return SimSPIAccelerometerData[index]->GetX();
}

double HALSIM_GetSPIAccelerometerY(int32_t index) {
  return SimSPIAccelerometerData[index]->GetY();
}

double HALSIM_GetSPIAccelerometerZ(int32_t index) {
  return SimSPIAccelerometerData[index]->GetZ();
}

}
