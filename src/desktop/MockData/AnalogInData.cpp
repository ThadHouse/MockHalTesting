#include "AnalogInDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<AnalogInData>[]> hal::SimAnalogInData = std::make_unique<std::shared_ptr<AnalogInData>[]>(kNumAnalogInputs);
void AnalogInData::ResetData() {
  m_initialized = false;
  m_averageBits = 7;
  m_oversampleBits = 0;
  m_voltage = 0.0;
  m_accumulatorInitialized = false;
  m_accumulatorValue = 0;
  m_accumulatorCount = 0;
  m_accumlatorCenter = 0;
  m_accumlatorDeadband = 0;
  NotifyDataBase::ResetData();
}

HAL_Bool AnalogInData::GetInitialized() {
  return m_initialized;
}

void AnalogInData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

int32_t AnalogInData::GetAverageBits() {
  return m_averageBits;
}

void AnalogInData::SetAverageBits(int32_t averageBits) {
  int32_t oldValue = m_averageBits.exchange(averageBits);
  if (oldValue != averageBits) {
    OnPropertyChanged(&MakeInt(averageBits));
  }
}

int32_t AnalogInData::GetOversampleBits() {
  return m_oversampleBits;
}

void AnalogInData::SetOversampleBits(int32_t oversampleBits) {
  int32_t oldValue = m_oversampleBits.exchange(oversampleBits);
  if (oldValue != oversampleBits) {
    OnPropertyChanged(&MakeInt(oversampleBits));
  }
}

double AnalogInData::GetVoltage() {
  return m_voltage;
}

void AnalogInData::SetVoltage(double voltage) {
  double oldValue = m_voltage.exchange(voltage);
  if (oldValue != voltage) {
    OnPropertyChanged(&MakeDouble(voltage));
  }
}

HAL_Bool AnalogInData::GetAccumulatorInitialized() {
  return m_accumulatorInitialized;
}

void AnalogInData::SetAccumulatorInitialized(HAL_Bool accumulatorInitialized) {
  HAL_Bool oldValue = m_accumulatorInitialized.exchange(accumulatorInitialized);
  if (oldValue != accumulatorInitialized) {
    OnPropertyChanged(&MakeBoolean(accumulatorInitialized));
  }
}

int64_t AnalogInData::GetAccumulatorValue() {
  return m_accumulatorValue;
}

void AnalogInData::SetAccumulatorValue(int64_t accumulatorValue) {
  int64_t oldValue = m_accumulatorValue.exchange(accumulatorValue);
  if (oldValue != accumulatorValue) {
    OnPropertyChanged(&MakeLong(accumulatorValue));
  }
}

int64_t AnalogInData::GetAccumulatorCount() {
  return m_accumulatorCount;
}

void AnalogInData::SetAccumulatorCount(int64_t accumulatorCount) {
  int64_t oldValue = m_accumulatorCount.exchange(accumulatorCount);
  if (oldValue != accumulatorCount) {
    OnPropertyChanged(&MakeLong(accumulatorCount));
  }
}

int32_t AnalogInData::GetAccumlatorCenter() {
  return m_accumlatorCenter;
}

void AnalogInData::SetAccumlatorCenter(int32_t accumlatorCenter) {
  int32_t oldValue = m_accumlatorCenter.exchange(accumlatorCenter);
  if (oldValue != accumlatorCenter) {
    OnPropertyChanged(&MakeInt(accumlatorCenter));
  }
}

int32_t AnalogInData::GetAccumlatorDeadband() {
  return m_accumlatorDeadband;
}

void AnalogInData::SetAccumlatorDeadband(int32_t accumlatorDeadband) {
  int32_t oldValue = m_accumlatorDeadband.exchange(accumlatorDeadband);
  if (oldValue != accumlatorDeadband) {
    OnPropertyChanged(&MakeInt(accumlatorDeadband));
  }
}

extern "C" {
HAL_Bool HALSIM_GetAnalogInInitialized(int32_t index) {
  return SimAnalogInData[index]->GetInitialized();
}

int32_t HALSIM_GetAnalogInAverageBits(int32_t index) {
  return SimAnalogInData[index]->GetAverageBits();
}

int32_t HALSIM_GetAnalogInOversampleBits(int32_t index) {
  return SimAnalogInData[index]->GetOversampleBits();
}

double HALSIM_GetAnalogInVoltage(int32_t index) {
  return SimAnalogInData[index]->GetVoltage();
}

void HALSIM_SetAnalogInVoltage(int32_t index, double voltage) {
  SimAnalogInData[index]->SetVoltage(voltage);
}

HAL_Bool HALSIM_GetAnalogInAccumulatorInitialized(int32_t index) {
  return SimAnalogInData[index]->GetAccumulatorInitialized();
}

int64_t HALSIM_GetAnalogInAccumulatorValue(int32_t index) {
  return SimAnalogInData[index]->GetAccumulatorValue();
}

void HALSIM_SetAnalogInAccumulatorValue(int32_t index, int64_t accumulatorValue) {
  SimAnalogInData[index]->SetAccumulatorValue(accumulatorValue);
}

int64_t HALSIM_GetAnalogInAccumulatorCount(int32_t index) {
  return SimAnalogInData[index]->GetAccumulatorCount();
}

void HALSIM_SetAnalogInAccumulatorCount(int32_t index, int64_t accumulatorCount) {
  SimAnalogInData[index]->SetAccumulatorCount(accumulatorCount);
}

int32_t HALSIM_GetAnalogInAccumlatorCenter(int32_t index) {
  return SimAnalogInData[index]->GetAccumlatorCenter();
}

int32_t HALSIM_GetAnalogInAccumlatorDeadband(int32_t index) {
  return SimAnalogInData[index]->GetAccumlatorDeadband();
}

}
