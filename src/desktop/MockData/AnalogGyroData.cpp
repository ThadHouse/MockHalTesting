#include "AnalogGyroDataInternal.h"
#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<AnalogGyroData>[]> hal::SimAnalogGyroData = std::make_unique<std::shared_ptr<AnalogGyroData>[]>(kNumAccumulators);
void AnalogGyroData::ResetData() {
  m_angle = 0.0;
  m_rate = 0.0;
  m_initialized = false;
  NotifyDataBase::ResetData();
}

double AnalogGyroData::GetAngle() {
  return m_angle;
}

void AnalogGyroData::SetAngle(double angle) {
  double oldValue = m_angle.exchange(angle);
  if (oldValue != angle) {
    OnPropertyChanged(&MakeDouble(angle));
  }
}

double AnalogGyroData::GetRate() {
  return m_rate;
}

void AnalogGyroData::SetRate(double rate) {
  double oldValue = m_rate.exchange(rate);
  if (oldValue != rate) {
    OnPropertyChanged(&MakeDouble(rate));
  }
}

HAL_Bool AnalogGyroData::GetInitialized() {
  return m_initialized;
}

void AnalogGyroData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

extern "C" {
double HALSIM_GetAnalogGyroAngle(int32_t index) {
  return SimAnalogGyroData[index]->GetAngle();
}

double HALSIM_GetAnalogGyroRate(int32_t index) {
  return SimAnalogGyroData[index]->GetRate();
}

HAL_Bool HALSIM_GetAnalogGyroInitialized(int32_t index) {
  return SimAnalogGyroData[index]->GetInitialized();
}

}
