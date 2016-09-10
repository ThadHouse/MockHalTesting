#include "DIODataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<DIOData>[]> hal::SimDIOData = std::make_unique<std::shared_ptr<DIOData>[]>(kNumDigitalPins);
void DIOData::ResetData() {
  m_initialized = false;
  m_value = true;
  m_pulseLength = 0.0;
  m_isInput = true;
  m_filterIndex = -1;
  NotifyDataBase::ResetData();
}

HAL_Bool DIOData::GetInitialized() {
  return m_initialized;
}

void DIOData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

HAL_Bool DIOData::GetValue() {
  return m_value;
}

void DIOData::SetValue(HAL_Bool value) {
  HAL_Bool oldValue = m_value.exchange(value);
  if (oldValue != value) {
    OnPropertyChanged(&MakeBoolean(value));
  }
}

double DIOData::GetPulseLength() {
  return m_pulseLength;
}

void DIOData::SetPulseLength(double pulseLength) {
  double oldValue = m_pulseLength.exchange(pulseLength);
  if (oldValue != pulseLength) {
    OnPropertyChanged(&MakeDouble(pulseLength));
  }
}

HAL_Bool DIOData::GetIsInput() {
  return m_isInput;
}

void DIOData::SetIsInput(HAL_Bool isInput) {
  HAL_Bool oldValue = m_isInput.exchange(isInput);
  if (oldValue != isInput) {
    OnPropertyChanged(&MakeBoolean(isInput));
  }
}

int32_t DIOData::GetFilterIndex() {
  return m_filterIndex;
}

void DIOData::SetFilterIndex(int32_t filterIndex) {
  int32_t oldValue = m_filterIndex.exchange(filterIndex);
  if (oldValue != filterIndex) {
    OnPropertyChanged(&MakeInt(filterIndex));
  }
}

extern "C" {
HAL_Bool HALSIM_GetDIOInitialized(int32_t index) {
  return SimDIOData[index]->GetInitialized();
}

HAL_Bool HALSIM_GetDIOValue(int32_t index) {
  return SimDIOData[index]->GetValue();
}

void HALSIM_SetDIOValue(int32_t index, HAL_Bool value) {
  SimDIOData[index]->SetValue(value);
}

double HALSIM_GetDIOPulseLength(int32_t index) {
  return SimDIOData[index]->GetPulseLength();
}

HAL_Bool HALSIM_GetDIOIsInput(int32_t index) {
  return SimDIOData[index]->GetIsInput();
}

int32_t HALSIM_GetDIOFilterIndex(int32_t index) {
  return SimDIOData[index]->GetFilterIndex();
}

}
