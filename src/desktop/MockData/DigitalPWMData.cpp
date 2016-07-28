#include "DigitalPWMDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<DigitalPWMData>[]> hal::SimDigitalPWMData = std::make_unique<std::shared_ptr<DigitalPWMData>[]>(kNumDigitalPWMOutputs);
void DigitalPWMData::ResetData() {
  m_initialized = false;
  m_dutyCycle = false;
  m_pin = 0;
}

HAL_Bool DigitalPWMData::GetInitialized() {
  return m_initialized;
}

void DigitalPWMData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

double DigitalPWMData::GetDutyCycle() {
  return m_dutyCycle;
}

void DigitalPWMData::SetDutyCycle(double dutyCycle) {
  double oldValue = m_dutyCycle.exchange(dutyCycle);
  if (oldValue != dutyCycle) {
    OnPropertyChanged(&MakeDouble(dutyCycle));
  }
}

int32_t DigitalPWMData::GetPin() {
  return m_pin;
}

void DigitalPWMData::SetPin(int32_t pin) {
  int32_t oldValue = m_pin.exchange(pin);
  if (oldValue != pin) {
    OnPropertyChanged(&MakeInt(pin));
  }
}

extern "C" {
HAL_Bool HALSIM_GetDigitalPWMInitialized(int32_t index) {
  return SimDigitalPWMData[index]->GetInitialized();
}

double HALSIM_GetDigitalPWMDutyCycle(int32_t index) {
  return SimDigitalPWMData[index]->GetDutyCycle();
}

int32_t HALSIM_GetDigitalPWMPin(int32_t index) {
  return SimDigitalPWMData[index]->GetPin();
}

}
