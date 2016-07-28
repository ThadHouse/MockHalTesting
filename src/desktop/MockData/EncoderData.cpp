#include "EncoderDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<EncoderData>[]> hal::SimEncoderData = std::make_unique<std::shared_ptr<EncoderData>[]>(kNumEncoders);
void EncoderData::ResetData() {
  m_initialized = false;
  m_count = 0;
  m_period = std::numeric_limits<double>::max();
  m_reset = false;
  m_maxPeriod = 0;
  m_direction = false;
  m_reverseDirection = false;
  m_samplesToAverage = 0;
  NotifyDataBase::ResetData();
}

HAL_Bool EncoderData::GetInitialized() {
  return m_initialized;
}

void EncoderData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

int32_t EncoderData::GetCount() {
  return m_count;
}

void EncoderData::SetCount(int32_t count) {
  int32_t oldValue = m_count.exchange(count);
  if (oldValue != count) {
    OnPropertyChanged(&MakeInt(count));
  }
}

double EncoderData::GetPeriod() {
  return m_period;
}

void EncoderData::SetPeriod(double period) {
  double oldValue = m_period.exchange(period);
  if (oldValue != period) {
    OnPropertyChanged(&MakeDouble(period));
  }
}

HAL_Bool EncoderData::GetReset() {
  return m_reset;
}

void EncoderData::SetReset(HAL_Bool reset) {
  HAL_Bool oldValue = m_reset.exchange(reset);
  if (oldValue != reset) {
    OnPropertyChanged(&MakeBoolean(reset));
  }
}

double EncoderData::GetMaxPeriod() {
  return m_maxPeriod;
}

void EncoderData::SetMaxPeriod(double maxPeriod) {
  double oldValue = m_maxPeriod.exchange(maxPeriod);
  if (oldValue != maxPeriod) {
    OnPropertyChanged(&MakeDouble(maxPeriod));
  }
}

HAL_Bool EncoderData::GetDirection() {
  return m_direction;
}

void EncoderData::SetDirection(HAL_Bool direction) {
  HAL_Bool oldValue = m_direction.exchange(direction);
  if (oldValue != direction) {
    OnPropertyChanged(&MakeBoolean(direction));
  }
}

HAL_Bool EncoderData::GetReverseDirection() {
  return m_reverseDirection;
}

void EncoderData::SetReverseDirection(HAL_Bool reverseDirection) {
  HAL_Bool oldValue = m_reverseDirection.exchange(reverseDirection);
  if (oldValue != reverseDirection) {
    OnPropertyChanged(&MakeBoolean(reverseDirection));
  }
}

int32_t EncoderData::GetSamplesToAverage() {
  return m_samplesToAverage;
}

void EncoderData::SetSamplesToAverage(int32_t samplesToAverage) {
  int32_t oldValue = m_samplesToAverage.exchange(samplesToAverage);
  if (oldValue != samplesToAverage) {
    OnPropertyChanged(&MakeInt(samplesToAverage));
  }
}

extern "C" {
HAL_Bool HALSIM_GetEncoderInitialized(int32_t index) {
  return SimEncoderData[index]->GetInitialized();
}

int32_t HALSIM_GetEncoderCount(int32_t index) {
  return SimEncoderData[index]->GetCount();
}

double HALSIM_GetEncoderPeriod(int32_t index) {
  return SimEncoderData[index]->GetPeriod();
}

HAL_Bool HALSIM_GetEncoderReset(int32_t index) {
  return SimEncoderData[index]->GetReset();
}

double HALSIM_GetEncoderMaxPeriod(int32_t index) {
  return SimEncoderData[index]->GetMaxPeriod();
}

HAL_Bool HALSIM_GetEncoderDirection(int32_t index) {
  return SimEncoderData[index]->GetDirection();
}

HAL_Bool HALSIM_GetEncoderReverseDirection(int32_t index) {
  return SimEncoderData[index]->GetReverseDirection();
}

int32_t HALSIM_GetEncoderSamplesToAverage(int32_t index) {
  return SimEncoderData[index]->GetSamplesToAverage();
}

}
