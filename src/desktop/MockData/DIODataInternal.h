#pragma once

#include <atomic>
#include <memory>

#include "MockData/DIOData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class DIOData : NotifyDataBase {
 public:
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  HAL_Bool GetValue();
  void SetValue(HAL_Bool value);

  double GetPulseLength();
  void SetPulseLength(double pulseLength);

  HAL_Bool GetIsInput();
  void SetIsInput(HAL_Bool isInput);

  int32_t GetFilterIndex();
  void SetFilterIndex(int32_t filterIndex);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_initialized = false;
  std::atomic<HAL_Bool> m_value = true;
  std::atomic<double> m_pulseLength = 0.0;
  std::atomic<HAL_Bool> m_isInput = true;
  std::atomic<int32_t> m_filterIndex = -1;
};
extern std::unique_ptr<std::shared_ptr<DIOData>[]> SimDIOData;
}
