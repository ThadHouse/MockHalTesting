#include "HAL/DriverStation.h"

#include "IDriverStation.h"

#include "SimDriverStation.h"

#include <atomic>

using namespace hal;

static std::atomic<IDriverStation*> currentDriverStation; 

int32_t HAL_SetErrorData(const char* errors, int32_t errorsLength,
                         int32_t waitMs) {
  auto ds = currentDriverStation.load();
  return ds->SetErrorData(errors, errorsLength, waitMs);
}
int32_t HAL_SendError(HAL_Bool isError, int32_t errorCode, HAL_Bool isLVCode,
                      const char* details, const char* location,
                      const char* callStack, HAL_Bool printMsg) {
  auto ds = currentDriverStation.load();
  return ds->SendError(isError, errorCode, isLVCode, details, location, callStack, printMsg);
}

int32_t HAL_GetControlWord(HAL_ControlWord* controlWord) {
  auto ds = currentDriverStation.load();
  return ds->GetControlWord(controlWord);
}
HAL_AllianceStationID HAL_GetAllianceStation(int32_t* status) {
  auto ds = currentDriverStation.load();
  return ds->GetAllianceStation(status);
}
int32_t HAL_GetJoystickAxes(int32_t joystickNum, HAL_JoystickAxes* axes) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickAxes(joystickNum, axes);
}
int32_t HAL_GetJoystickPOVs(int32_t joystickNum, HAL_JoystickPOVs* povs) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickPOVs(joystickNum, povs);
}
int32_t HAL_GetJoystickButtons(int32_t joystickNum,
                               HAL_JoystickButtons* buttons) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickButtons(joystickNum, buttons);
}
int32_t HAL_GetJoystickDescriptor(int32_t joystickNum,
                                  HAL_JoystickDescriptor* desc) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickDescriptor(joystickNum, desc);
}
HAL_Bool HAL_GetJoystickIsXbox(int32_t joystickNum) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickIsXbox(joystickNum);
}
int32_t HAL_GetJoystickType(int32_t joystickNum) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickType(joystickNum);
}
char* HAL_GetJoystickName(int32_t joystickNum) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickName(joystickNum);
}
int32_t HAL_GetJoystickAxisType(int32_t joystickNum, int32_t axis) {
  auto ds = currentDriverStation.load();
  return ds->GetJoystickAxisType(joystickNum, axis);
}
int32_t HAL_SetJoystickOutputs(int32_t joystickNum, int64_t outputs,
                               int32_t leftRumble, int32_t rightRumble) {
  auto ds = currentDriverStation.load();
  return ds->SetJoystickOutputs(joystickNum, outputs, leftRumble, rightRumble);
}
double HAL_GetMatchTime(int32_t* status) {
  auto ds = currentDriverStation.load();
  return ds->GetMatchTime(status);
}

void HAL_WaitForDSData(void) {
  auto ds = currentDriverStation.load();
  return ds->WaitForDSData();
}
void HAL_InitializeDriverStation(void) {
  if (currentDriverStation.load() == nullptr) {
    currentDriverStation = new SimDriverStation();
  }

  auto ds = currentDriverStation.load();
  return ds->InitializeDriverStation();
}

void HAL_ObserveUserProgramStarting(void) {
  auto ds = currentDriverStation.load();
  return ds->ObserveUserProgramStarting();
}
void HAL_ObserveUserProgramDisabled(void) {
  auto ds = currentDriverStation.load();
  return ds->ObserveUserProgramDisabled();
}
void HAL_ObserveUserProgramAutonomous(void) {
  auto ds = currentDriverStation.load();
  return ds->ObserveUserProgramAutonomous();
}
void HAL_ObserveUserProgramTeleop(void) {
  auto ds = currentDriverStation.load();
  return ds->ObserveUserProgramTeleop();
}
void HAL_ObserveUserProgramTest(void) {
  auto ds = currentDriverStation.load();
  ds->ObserveUserProgramTest();
}