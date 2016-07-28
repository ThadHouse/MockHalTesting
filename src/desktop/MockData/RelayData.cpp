#include "RelayDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<RelayData>[]> hal::SimRelayData = std::make_unique<std::shared_ptr<RelayData>[]>(kNumRelayHeaders);
void RelayData::ResetData() {
  m_initialized = false;
  m_forward = false;
  m_reverse = false;
  NotifyDataBase::ResetData();
}

HAL_Bool RelayData::GetInitialized() {
  return m_initialized;
}

void RelayData::SetInitialized(HAL_Bool initialized) {
  HAL_Bool oldValue = m_initialized.exchange(initialized);
  if (oldValue != initialized) {
    OnPropertyChanged(&MakeBoolean(initialized));
  }
}

HAL_Bool RelayData::GetForward() {
  return m_forward;
}

void RelayData::SetForward(HAL_Bool forward) {
  HAL_Bool oldValue = m_forward.exchange(forward);
  if (oldValue != forward) {
    OnPropertyChanged(&MakeBoolean(forward));
  }
}

HAL_Bool RelayData::GetReverse() {
  return m_reverse;
}

void RelayData::SetReverse(HAL_Bool reverse) {
  HAL_Bool oldValue = m_reverse.exchange(reverse);
  if (oldValue != reverse) {
    OnPropertyChanged(&MakeBoolean(reverse));
  }
}

extern "C" {
HAL_Bool HALSIM_GetRelayInitialized(int32_t index) {
  return SimRelayData[index]->GetInitialized();
}

HAL_Bool HALSIM_GetRelayForward(int32_t index) {
  return SimRelayData[index]->GetForward();
}

HAL_Bool HALSIM_GetRelayReverse(int32_t index) {
  return SimRelayData[index]->GetReverse();
}

}
