#pragma once

#include "HAL/DriverStation.h"

namespace hal {
class IDriverStation
{
 public:
  virtual int32_t SetErrorData(const char* errors, int32_t errorsLength,
                      int32_t waitMs)  = 0;
  virtual int32_t SendError(HAL_Bool isError, int32_t errorCode, HAL_Bool isLVCode,
                        const char* details, const char* location,
                        const char* callStack, HAL_Bool printMsg) = 0;

  virtual int32_t GetControlWord(HAL_ControlWord* controlWord) = 0;
  virtual HAL_AllianceStationID GetAllianceStation(int32_t* status) = 0;
  virtual int32_t GetJoystickAxes(int32_t joystickNum, HAL_JoystickAxes* axes) = 0;
  virtual int32_t GetJoystickPOVs(int32_t joystickNum, HAL_JoystickPOVs* povs) = 0;
  virtual int32_t GetJoystickButtons(int32_t joystickNum,
                                HAL_JoystickButtons* buttons) = 0;
  virtual int32_t GetJoystickDescriptor(int32_t joystickNum,
                                    HAL_JoystickDescriptor* desc) = 0;
  virtual HAL_Bool GetJoystickIsXbox(int32_t joystickNum) = 0;
  virtual int32_t GetJoystickType(int32_t joystickNum) = 0;
  virtual char* GetJoystickName(int32_t joystickNum) = 0;
  virtual int32_t GetJoystickAxisType(int32_t joystickNum, int32_t axis) = 0;
  virtual int32_t SetJoystickOutputs(int32_t joystickNum, int64_t outputs,
                                int32_t leftRumble, int32_t rightRumble) = 0;
  virtual double GetMatchTime(int32_t* status) = 0;

  virtual void WaitForDSData(void) = 0;
  virtual void InitializeDriverStation(void) = 0;

  virtual void ObserveUserProgramStarting(void) = 0;
  virtual void ObserveUserProgramDisabled(void) = 0;
  virtual void ObserveUserProgramAutonomous(void) = 0;
  virtual void ObserveUserProgramTeleop(void) = 0;
  virtual void ObserveUserProgramTest(void) = 0;
};
}