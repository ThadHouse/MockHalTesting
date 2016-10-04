#include "IDriverStation.h"

namespace hal {
class SimDriverStation : public IDriverStation
{
 public:
  virtual int32_t SetErrorData(const char* errors, int32_t errorsLength,
                      int32_t waitMs);
  virtual int32_t SendError(HAL_Bool isError, int32_t errorCode, HAL_Bool isLVCode,
                        const char* details, const char* location,
                        const char* callStack, HAL_Bool printMsg);

  virtual int32_t GetControlWord(HAL_ControlWord* controlWord);
  virtual HAL_AllianceStationID GetAllianceStation(int32_t* status);
  virtual int32_t GetJoystickAxes(int32_t joystickNum, HAL_JoystickAxes* axes);
  virtual int32_t GetJoystickPOVs(int32_t joystickNum, HAL_JoystickPOVs* povs);
  virtual int32_t GetJoystickButtons(int32_t joystickNum,
                                HAL_JoystickButtons* buttons);
  virtual int32_t GetJoystickDescriptor(int32_t joystickNum,
                                    HAL_JoystickDescriptor* desc);
  virtual HAL_Bool GetJoystickIsXbox(int32_t joystickNum);
  virtual int32_t GetJoystickType(int32_t joystickNum);
  virtual char* GetJoystickName(int32_t joystickNum);
  virtual int32_t GetJoystickAxisType(int32_t joystickNum, int32_t axis);
  virtual int32_t SetJoystickOutputs(int32_t joystickNum, int64_t outputs,
                                int32_t leftRumble, int32_t rightRumble);
  virtual double GetMatchTime(int32_t* status);

  virtual void WaitForDSData();
  virtual void InitializeDriverStation(void);

  virtual void ObserveUserProgramStarting(void);
  virtual void ObserveUserProgramDisabled(void);
  virtual void ObserveUserProgramAutonomous(void);
  virtual void ObserveUserProgramTeleop(void);
  virtual void ObserveUserProgramTest(void);
};
}