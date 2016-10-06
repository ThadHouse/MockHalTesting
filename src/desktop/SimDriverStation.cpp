#include "SimDriverStation.h"

#include <thread>
#include <chrono>

namespace hal {
  int32_t SimDriverStation::SetErrorData(const char* errors, int32_t errorsLength,
                      int32_t waitMs) 
                      {
                        return 0;
                      }
  int32_t SimDriverStation::SendError(HAL_Bool isError, int32_t errorCode, HAL_Bool isLVCode,
                        const char* details, const char* location,
                        const char* callStack, HAL_Bool printMsg) {
                          return 0;
                        }

  int32_t SimDriverStation::GetControlWord(HAL_ControlWord* controlWord) {
    controlWord->enabled = 1;
    controlWord->autonomous = 0;
    controlWord->test = 0;
    controlWord->eStop = 0;
    controlWord->fmsAttached = 0;
    controlWord->dsAttached = 1;
    controlWord->control_reserved = 0;
    return 0;
  }
  HAL_AllianceStationID SimDriverStation::GetAllianceStation(int32_t* status) {
    return HAL_AllianceStationID_kRed1;
  }
  int32_t SimDriverStation::GetJoystickAxes(int32_t joystickNum, HAL_JoystickAxes* axes) {
    return 0;
  }
  int32_t SimDriverStation::GetJoystickPOVs(int32_t joystickNum, HAL_JoystickPOVs* povs) {
    return 0;
  }
  int32_t SimDriverStation::GetJoystickButtons(int32_t joystickNum,
                                HAL_JoystickButtons* buttons) {
                                  return 0;
                                }
  int32_t SimDriverStation::GetJoystickDescriptor(int32_t joystickNum,
                                    HAL_JoystickDescriptor* desc) {
                                      return 0;
                                    }
  HAL_Bool SimDriverStation::GetJoystickIsXbox(int32_t joystickNum) {
    return false;
  }
  int32_t SimDriverStation::GetJoystickType(int32_t joystickNum) {
    return 0;
  }
  char* SimDriverStation::GetJoystickName(int32_t joystickNum) {
    return nullptr;
  }
  int32_t SimDriverStation::GetJoystickAxisType(int32_t joystickNum, int32_t axis) {
    return 0;
  }
  int32_t SimDriverStation::SetJoystickOutputs(int32_t joystickNum, int64_t outputs,
                                int32_t leftRumble, int32_t rightRumble) {
                                  return 0;
                                }
  double SimDriverStation::GetMatchTime(int32_t* status) {
    return 0;
  }

  void SimDriverStation::WaitForDSData(void) {
    using namespace std::chrono_literals;

    std::this_thread::sleep_for(20ms);
  }
  void SimDriverStation::InitializeDriverStation(void) {
  }

  void SimDriverStation::ObserveUserProgramStarting(void) {

  }
  void SimDriverStation::ObserveUserProgramDisabled(void) {

  }
  void SimDriverStation::ObserveUserProgramAutonomous(void) {

  }
  void SimDriverStation::ObserveUserProgramTeleop(void) {

  }
  void SimDriverStation::ObserveUserProgramTest(void) {

  }
}