#pragma once

#include <atomic>
#include <memory>

#include "MockData/PWMData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class PWMData : NotifyDataBase {
 public:
  bool GetInitialized();
  void SetInitialized(bool initialized);

  int GetRawValue();
  void SetRawValue(int rawValue);

  double GetSpeed();
  void SetSpeed(double speed);

  double GetPosition();
  void SetPosition(double position);

  int GetPeriodScale();
  void SetPeriodScale(int periodScale);

  bool GetZeroLatch();
  void SetZeroLatch(bool zeroLatch);

  virtual void ResetData() override;
 private:
  std::atomic<bool> m_initialized = false;
  std::atomic<int> m_rawValue = 0;
  std::atomic<double> m_speed = 0;
  std::atomic<double> m_position = 0;
  std::atomic<int> m_periodScale = 0;
  std::atomic<bool> m_zeroLatch = false;
};
extern std::unique_ptr<std::shared_ptr<PWMData>[]> SimPWMData;
}
