#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetRoboRioFPGAButton(int32_t index);
void HALSIM_SetRoboRioFPGAButton(int32_t index, HAL_Bool fPGAButton);

double HALSIM_GetRoboRioVInVoltage(int32_t index);
void HALSIM_SetRoboRioVInVoltage(int32_t index, double vInVoltage);

double HALSIM_GetRoboRioVInCurrent(int32_t index);
void HALSIM_SetRoboRioVInCurrent(int32_t index, double vInCurrent);

double HALSIM_GetRoboRioUserVoltage6V(int32_t index);
void HALSIM_SetRoboRioUserVoltage6V(int32_t index, double userVoltage6V);

double HALSIM_GetRoboRioUserCurrent6V(int32_t index);
void HALSIM_SetRoboRioUserCurrent6V(int32_t index, double userCurrent6V);

HAL_Bool HALSIM_GetRoboRioUserActive6V(int32_t index);
void HALSIM_SetRoboRioUserActive6V(int32_t index, HAL_Bool userActive6V);

double HALSIM_GetRoboRioUserVoltage5V(int32_t index);
void HALSIM_SetRoboRioUserVoltage5V(int32_t index, double userVoltage5V);

double HALSIM_GetRoboRioUserCurrent5V(int32_t index);
void HALSIM_SetRoboRioUserCurrent5V(int32_t index, double userCurrent5V);

HAL_Bool HALSIM_GetRoboRioUserActive5V(int32_t index);
void HALSIM_SetRoboRioUserActive5V(int32_t index, HAL_Bool userActive5V);

double HALSIM_GetRoboRioUserVoltage3V3(int32_t index);
void HALSIM_SetRoboRioUserVoltage3V3(int32_t index, double userVoltage3V3);

double HALSIM_GetRoboRioUserCurrent3V3(int32_t index);
void HALSIM_SetRoboRioUserCurrent3V3(int32_t index, double userCurrent3V3);

HAL_Bool HALSIM_GetRoboRioUserActive3V3(int32_t index);
void HALSIM_SetRoboRioUserActive3V3(int32_t index, HAL_Bool userActive3V3);

int32_t HALSIM_GetRoboRioUserFaults6V(int32_t index);
void HALSIM_SetRoboRioUserFaults6V(int32_t index, int32_t userFaults6V);

int32_t HALSIM_GetRoboRioUserFaults5V(int32_t index);
void HALSIM_SetRoboRioUserFaults5V(int32_t index, int32_t userFaults5V);

int32_t HALSIM_GetRoboRioUserFaults3V3(int32_t index);
void HALSIM_SetRoboRioUserFaults3V3(int32_t index, int32_t userFaults3V3);

#ifdef __cplusplus
}
#endif

