#include "RoboRioDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<RoboRioData>[]> hal::SimRoboRioData = std::make_unique<std::shared_ptr<RoboRioData>[]>(1);
void RoboRioData::ResetData() {
  m_fPGAButton = false;
  m_vInVoltage = 0.0;
  m_vInCurrent = 0.0;
  m_userVoltage6V = 6.0;
  m_userCurrent6V = 0.0;
  m_userActive6V = false;
  m_userVoltage5V = 5.0;
  m_userCurrent5V = 0.0;
  m_userActive5V = false;
  m_userVoltage3V3 = 3.3;
  m_userCurrent3V3 = 0.0;
  m_userActive3V3 = false;
  m_userFaults6V = 0;
  m_userFaults5V = 0;
  m_userFaults3V3 = 0;
}

HAL_Bool RoboRioData::GetFPGAButton() {
  return m_fPGAButton;
}

void RoboRioData::SetFPGAButton(HAL_Bool fPGAButton) {
  HAL_Bool oldValue = m_fPGAButton.exchange(fPGAButton);
  if (oldValue != fPGAButton) {
    OnPropertyChanged(&MakeBoolean(fPGAButton));
  }
}

double RoboRioData::GetVInVoltage() {
  return m_vInVoltage;
}

void RoboRioData::SetVInVoltage(double vInVoltage) {
  double oldValue = m_vInVoltage.exchange(vInVoltage);
  if (oldValue != vInVoltage) {
    OnPropertyChanged(&MakeDouble(vInVoltage));
  }
}

double RoboRioData::GetVInCurrent() {
  return m_vInCurrent;
}

void RoboRioData::SetVInCurrent(double vInCurrent) {
  double oldValue = m_vInCurrent.exchange(vInCurrent);
  if (oldValue != vInCurrent) {
    OnPropertyChanged(&MakeDouble(vInCurrent));
  }
}

double RoboRioData::GetUserVoltage6V() {
  return m_userVoltage6V;
}

void RoboRioData::SetUserVoltage6V(double userVoltage6V) {
  double oldValue = m_userVoltage6V.exchange(userVoltage6V);
  if (oldValue != userVoltage6V) {
    OnPropertyChanged(&MakeDouble(userVoltage6V));
  }
}

double RoboRioData::GetUserCurrent6V() {
  return m_userCurrent6V;
}

void RoboRioData::SetUserCurrent6V(double userCurrent6V) {
  double oldValue = m_userCurrent6V.exchange(userCurrent6V);
  if (oldValue != userCurrent6V) {
    OnPropertyChanged(&MakeDouble(userCurrent6V));
  }
}

HAL_Bool RoboRioData::GetUserActive6V() {
  return m_userActive6V;
}

void RoboRioData::SetUserActive6V(HAL_Bool userActive6V) {
  HAL_Bool oldValue = m_userActive6V.exchange(userActive6V);
  if (oldValue != userActive6V) {
    OnPropertyChanged(&MakeBoolean(userActive6V));
  }
}

double RoboRioData::GetUserVoltage5V() {
  return m_userVoltage5V;
}

void RoboRioData::SetUserVoltage5V(double userVoltage5V) {
  double oldValue = m_userVoltage5V.exchange(userVoltage5V);
  if (oldValue != userVoltage5V) {
    OnPropertyChanged(&MakeDouble(userVoltage5V));
  }
}

double RoboRioData::GetUserCurrent5V() {
  return m_userCurrent5V;
}

void RoboRioData::SetUserCurrent5V(double userCurrent5V) {
  double oldValue = m_userCurrent5V.exchange(userCurrent5V);
  if (oldValue != userCurrent5V) {
    OnPropertyChanged(&MakeDouble(userCurrent5V));
  }
}

HAL_Bool RoboRioData::GetUserActive5V() {
  return m_userActive5V;
}

void RoboRioData::SetUserActive5V(HAL_Bool userActive5V) {
  HAL_Bool oldValue = m_userActive5V.exchange(userActive5V);
  if (oldValue != userActive5V) {
    OnPropertyChanged(&MakeBoolean(userActive5V));
  }
}

double RoboRioData::GetUserVoltage3V3() {
  return m_userVoltage3V3;
}

void RoboRioData::SetUserVoltage3V3(double userVoltage3V3) {
  double oldValue = m_userVoltage3V3.exchange(userVoltage3V3);
  if (oldValue != userVoltage3V3) {
    OnPropertyChanged(&MakeDouble(userVoltage3V3));
  }
}

double RoboRioData::GetUserCurrent3V3() {
  return m_userCurrent3V3;
}

void RoboRioData::SetUserCurrent3V3(double userCurrent3V3) {
  double oldValue = m_userCurrent3V3.exchange(userCurrent3V3);
  if (oldValue != userCurrent3V3) {
    OnPropertyChanged(&MakeDouble(userCurrent3V3));
  }
}

HAL_Bool RoboRioData::GetUserActive3V3() {
  return m_userActive3V3;
}

void RoboRioData::SetUserActive3V3(HAL_Bool userActive3V3) {
  HAL_Bool oldValue = m_userActive3V3.exchange(userActive3V3);
  if (oldValue != userActive3V3) {
    OnPropertyChanged(&MakeBoolean(userActive3V3));
  }
}

int32_t RoboRioData::GetUserFaults6V() {
  return m_userFaults6V;
}

void RoboRioData::SetUserFaults6V(int32_t userFaults6V) {
  int32_t oldValue = m_userFaults6V.exchange(userFaults6V);
  if (oldValue != userFaults6V) {
    OnPropertyChanged(&MakeInt(userFaults6V));
  }
}

int32_t RoboRioData::GetUserFaults5V() {
  return m_userFaults5V;
}

void RoboRioData::SetUserFaults5V(int32_t userFaults5V) {
  int32_t oldValue = m_userFaults5V.exchange(userFaults5V);
  if (oldValue != userFaults5V) {
    OnPropertyChanged(&MakeInt(userFaults5V));
  }
}

int32_t RoboRioData::GetUserFaults3V3() {
  return m_userFaults3V3;
}

void RoboRioData::SetUserFaults3V3(int32_t userFaults3V3) {
  int32_t oldValue = m_userFaults3V3.exchange(userFaults3V3);
  if (oldValue != userFaults3V3) {
    OnPropertyChanged(&MakeInt(userFaults3V3));
  }
}

extern "C" {
HAL_Bool HALSIM_GetRoboRioFPGAButton(int32_t index) {
  return SimRoboRioData[index]->GetFPGAButton();
}

double HALSIM_GetRoboRioVInVoltage(int32_t index) {
  return SimRoboRioData[index]->GetVInVoltage();
}

double HALSIM_GetRoboRioVInCurrent(int32_t index) {
  return SimRoboRioData[index]->GetVInCurrent();
}

double HALSIM_GetRoboRioUserVoltage6V(int32_t index) {
  return SimRoboRioData[index]->GetUserVoltage6V();
}

double HALSIM_GetRoboRioUserCurrent6V(int32_t index) {
  return SimRoboRioData[index]->GetUserCurrent6V();
}

HAL_Bool HALSIM_GetRoboRioUserActive6V(int32_t index) {
  return SimRoboRioData[index]->GetUserActive6V();
}

double HALSIM_GetRoboRioUserVoltage5V(int32_t index) {
  return SimRoboRioData[index]->GetUserVoltage5V();
}

double HALSIM_GetRoboRioUserCurrent5V(int32_t index) {
  return SimRoboRioData[index]->GetUserCurrent5V();
}

HAL_Bool HALSIM_GetRoboRioUserActive5V(int32_t index) {
  return SimRoboRioData[index]->GetUserActive5V();
}

double HALSIM_GetRoboRioUserVoltage3V3(int32_t index) {
  return SimRoboRioData[index]->GetUserVoltage3V3();
}

double HALSIM_GetRoboRioUserCurrent3V3(int32_t index) {
  return SimRoboRioData[index]->GetUserCurrent3V3();
}

HAL_Bool HALSIM_GetRoboRioUserActive3V3(int32_t index) {
  return SimRoboRioData[index]->GetUserActive3V3();
}

int32_t HALSIM_GetRoboRioUserFaults6V(int32_t index) {
  return SimRoboRioData[index]->GetUserFaults6V();
}

int32_t HALSIM_GetRoboRioUserFaults5V(int32_t index) {
  return SimRoboRioData[index]->GetUserFaults5V();
}

int32_t HALSIM_GetRoboRioUserFaults3V3(int32_t index) {
  return SimRoboRioData[index]->GetUserFaults3V3();
}

}
