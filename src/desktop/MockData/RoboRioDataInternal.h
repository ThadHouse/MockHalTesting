#pragma once

#include <atomic>
#include <memory>

#include "MockData/RoboRioData.h"
#include "MockData/DataBase.h"

namespace hal {
class RoboRioData : DataBase {
 public:
  HAL_Bool GetFPGAButton();
  void SetFPGAButton(HAL_Bool fPGAButton);

  double GetVInVoltage();
  void SetVInVoltage(double vInVoltage);

  double GetVInCurrent();
  void SetVInCurrent(double vInCurrent);

  double GetUserVoltage6V();
  void SetUserVoltage6V(double userVoltage6V);

  double GetUserCurrent6V();
  void SetUserCurrent6V(double userCurrent6V);

  HAL_Bool GetUserActive6V();
  void SetUserActive6V(HAL_Bool userActive6V);

  double GetUserVoltage5V();
  void SetUserVoltage5V(double userVoltage5V);

  double GetUserCurrent5V();
  void SetUserCurrent5V(double userCurrent5V);

  HAL_Bool GetUserActive5V();
  void SetUserActive5V(HAL_Bool userActive5V);

  double GetUserVoltage3V3();
  void SetUserVoltage3V3(double userVoltage3V3);

  double GetUserCurrent3V3();
  void SetUserCurrent3V3(double userCurrent3V3);

  HAL_Bool GetUserActive3V3();
  void SetUserActive3V3(HAL_Bool userActive3V3);

  int32_t GetUserFaults6V();
  void SetUserFaults6V(int32_t userFaults6V);

  int32_t GetUserFaults5V();
  void SetUserFaults5V(int32_t userFaults5V);

  int32_t GetUserFaults3V3();
  void SetUserFaults3V3(int32_t userFaults3V3);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_fPGAButton = false;
  std::atomic<double> m_vInVoltage = 0.0;
  std::atomic<double> m_vInCurrent = 0.0;
  std::atomic<double> m_userVoltage6V = 6.0;
  std::atomic<double> m_userCurrent6V = 0.0;
  std::atomic<HAL_Bool> m_userActive6V = false;
  std::atomic<double> m_userVoltage5V = 5.0;
  std::atomic<double> m_userCurrent5V = 0.0;
  std::atomic<HAL_Bool> m_userActive5V = false;
  std::atomic<double> m_userVoltage3V3 = 3.3;
  std::atomic<double> m_userCurrent3V3 = 0.0;
  std::atomic<HAL_Bool> m_userActive3V3 = false;
  std::atomic<int32_t> m_userFaults6V = 0;
  std::atomic<int32_t> m_userFaults5V = 0;
  std::atomic<int32_t> m_userFaults3V3 = 0;
};
extern std::unique_ptr<std::shared_ptr<RoboRioData>[]> SimRoboRioData;
}
