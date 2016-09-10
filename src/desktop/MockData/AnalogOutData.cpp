#include "AnalogOutDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<AnalogOutData>[]> hal::SimAnalogOutData = std::make_unique<std::shared_ptr<AnalogOutData>[]>(kNumAnalogOutputs);
void AnalogOutData::ResetData() {
  m_voltage = 0.0;
  m_initialized = 0.0;
  NotifyDataBase::ResetData();
}

double AnalogOutData::GetVoltage() {
  return m_voltage;
}

void AnalogOutData::SetVoltage(double voltage) {
  double oldValue = m_voltage.exchange(voltage);
  if (oldValue != voltage) {
    OnPropertyChanged(&MakeDouble(voltage));
  }
}

HAL_Bool AnalogOutData::GetInitialized() {
  return m_initialized;
}

void AnalogOutData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

extern "C" {
double HALSIM_GetAnalogOutVoltage(int32_t index) {
  return SimAnalogOutData[index]->GetVoltage();
}

HAL_Bool HALSIM_GetAnalogOutInitialized(int32_t index) {
  return SimAnalogOutData[index]->GetInitialized();
}

}
