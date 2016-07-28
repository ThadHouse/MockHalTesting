#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetRoboRioFPGAButton(int32_t index);

double HALSIM_GetRoboRioVInVoltage(int32_t index);

double HALSIM_GetRoboRioVInCurrent(int32_t index);

double HALSIM_GetRoboRioUserVoltage6V(int32_t index);

double HALSIM_GetRoboRioUserCurrent6V(int32_t index);

HAL_Bool HALSIM_GetRoboRioUserActive6V(int32_t index);

double HALSIM_GetRoboRioUserVoltage5V(int32_t index);

double HALSIM_GetRoboRioUserCurrent5V(int32_t index);

HAL_Bool HALSIM_GetRoboRioUserActive5V(int32_t index);

double HALSIM_GetRoboRioUserVoltage3V3(int32_t index);

double HALSIM_GetRoboRioUserCurrent3V3(int32_t index);

HAL_Bool HALSIM_GetRoboRioUserActive3V3(int32_t index);

int32_t HALSIM_GetRoboRioUserFaults6V(int32_t index);

int32_t HALSIM_GetRoboRioUserFaults5V(int32_t index);

int32_t HALSIM_GetRoboRioUserFaults3V3(int32_t index);

#ifdef __cplusplus
}
#endif

