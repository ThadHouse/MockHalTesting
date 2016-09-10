#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

bool HALSIM_GetPWMInitialized(int32_t index);

int HALSIM_GetPWMRawValue(int32_t index);
void HALSIM_SetPWMRawValue(int32_t index, int rawValue);

double HALSIM_GetPWMSpeed(int32_t index);
void HALSIM_SetPWMSpeed(int32_t index, double speed);

double HALSIM_GetPWMPosition(int32_t index);
void HALSIM_SetPWMPosition(int32_t index, double position);

int HALSIM_GetPWMPeriodScale(int32_t index);

bool HALSIM_GetPWMZeroLatch(int32_t index);

#ifdef __cplusplus
}
#endif

