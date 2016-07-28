#pragma once

#include <atomic>
#include <memory>

#include "MockData/EncoderData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class EncoderData : NotifyDataBase {
 public:
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  int32_t GetCount();
  void SetCount(int32_t count);

  double GetPeriod();
  void SetPeriod(double period);

  HAL_Bool GetReset();
  void SetReset(HAL_Bool reset);

  double GetMaxPeriod();
  void SetMaxPeriod(double maxPeriod);

  HAL_Bool GetDirection();
  void SetDirection(HAL_Bool direction);

  HAL_Bool GetReverseDirection();
  void SetReverseDirection(HAL_Bool reverseDirection);

  int32_t GetSamplesToAverage();
  void SetSamplesToAverage(int32_t samplesToAverage);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_initialized = false;
  std::atomic<int32_t> m_count = 0;
  std::atomic<double> m_period = std::numeric_limits<double>::max();
  std::atomic<HAL_Bool> m_reset = false;
  std::atomic<double> m_maxPeriod = 0;
  std::atomic<HAL_Bool> m_direction = false;
  std::atomic<HAL_Bool> m_reverseDirection = false;
  std::atomic<int32_t> m_samplesToAverage = 0;
};
extern std::unique_ptr<std::shared_ptr<EncoderData>[]> SimEncoderData;
}
