#pragma once

#include <atomic>
#include <memory>

#include "MockData/AnalogInData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class AnalogInData : NotifyDataBase {
 public:
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  int32_t GetAverageBits();
  void SetAverageBits(int32_t averageBits);

  int32_t GetOversampleBits();
  void SetOversampleBits(int32_t oversampleBits);

  double GetVoltage();
  void SetVoltage(double voltage);

  HAL_Bool GetAccumulatorInitialized();
  void SetAccumulatorInitialized(HAL_Bool accumulatorInitialized);

  int64_t GetAccumulatorValue();
  void SetAccumulatorValue(int64_t accumulatorValue);

  int64_t GetAccumulatorCount();
  void SetAccumulatorCount(int64_t accumulatorCount);

  int32_t GetAccumlatorCenter();
  void SetAccumlatorCenter(int32_t accumlatorCenter);

  int32_t GetAccumlatorDeadband();
  void SetAccumlatorDeadband(int32_t accumlatorDeadband);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_initialized = false;
  std::atomic<int32_t> m_averageBits = 7;
  std::atomic<int32_t> m_oversampleBits = 0;
  std::atomic<double> m_voltage = 0.0;
  std::atomic<HAL_Bool> m_accumulatorInitialized = false;
  std::atomic<int64_t> m_accumulatorValue = 0;
  std::atomic<int64_t> m_accumulatorCount = 0;
  std::atomic<int32_t> m_accumlatorCenter = 0;
  std::atomic<int32_t> m_accumlatorDeadband = 0;
};
extern std::unique_ptr<std::shared_ptr<AnalogInData>[]> SimAnalogInData;
}
