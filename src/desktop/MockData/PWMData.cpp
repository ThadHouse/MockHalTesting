#include "PWMDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<PWMData>[]> hal::SimPWMData = std::make_unique<std::shared_ptr<PWMData>[]>(kNumPWMPins);
void PWMData::ResetData() {
  m_initialized = false;
  m_rawValue = 0;
  m_speed = 0;
  m_position = 0;
  m_periodScale = 0;
  m_zeroLatch = false;
  NotifyDataBase::ResetData();
}

bool PWMData::GetInitialized() {
  return m_initialized;
}

void PWMData::SetInitialized(bool initialized) {
  bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeEnum(initialized));
  }
}

int PWMData::GetRawValue() {
  return m_rawValue;
}

void PWMData::SetRawValue(int rawValue) {
  int oldValue = m_rawValue.exchange(rawValue);
  if (oldValue != rawValue) {
    OnPropertyChanged(&MakeEnum(rawValue));
  }
}

double PWMData::GetSpeed() {
  return m_speed;
}

void PWMData::SetSpeed(double speed) {
  double oldValue = m_speed.exchange(speed);
  if (oldValue != speed) {
    OnPropertyChanged(&MakeDouble(speed));
  }
}

double PWMData::GetPosition() {
  return m_position;
}

void PWMData::SetPosition(double position) {
  double oldValue = m_position.exchange(position);
  if (oldValue != position) {
    OnPropertyChanged(&MakeDouble(position));
  }
}

int PWMData::GetPeriodScale() {
  return m_periodScale;
}

void PWMData::SetPeriodScale(int periodScale) {
  int oldValue = m_periodScale.exchange(periodScale);
  if (oldValue != periodScale) {
    OnPropertyChanged(&MakeEnum(periodScale));
  }
}

bool PWMData::GetZeroLatch() {
  return m_zeroLatch;
}

void PWMData::SetZeroLatch(bool zeroLatch) {
  bool oldValue = m_zeroLatch.exchange(zeroLatch);
  if (oldValue != zeroLatch) {
    OnPropertyChanged(&MakeEnum(zeroLatch));
  }
}

extern "C" {
bool HALSIM_GetPWMInitialized(int32_t index) {
  return SimPWMData[index]->GetInitialized();
}

int HALSIM_GetPWMRawValue(int32_t index) {
  return SimPWMData[index]->GetRawValue();
}

void HALSIM_SetPWMRawValue(int32_t index, int rawValue) {
  SimPWMData[index]->SetRawValue(rawValue);
}

double HALSIM_GetPWMSpeed(int32_t index) {
  return SimPWMData[index]->GetSpeed();
}

void HALSIM_SetPWMSpeed(int32_t index, double speed) {
  SimPWMData[index]->SetSpeed(speed);
}

double HALSIM_GetPWMPosition(int32_t index) {
  return SimPWMData[index]->GetPosition();
}

void HALSIM_SetPWMPosition(int32_t index, double position) {
  SimPWMData[index]->SetPosition(position);
}

int HALSIM_GetPWMPeriodScale(int32_t index) {
  return SimPWMData[index]->GetPeriodScale();
}

bool HALSIM_GetPWMZeroLatch(int32_t index) {
  return SimPWMData[index]->GetZeroLatch();
}

}
