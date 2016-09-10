#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

double HALSIM_GetAnalogGyroAngle(int32_t index);
void HALSIM_SetAnalogGyroAngle(int32_t index, double angle);

double HALSIM_GetAnalogGyroRate(int32_t index);
void HALSIM_SetAnalogGyroRate(int32_t index, double rate);

HAL_Bool HALSIM_GetAnalogGyroInitialized(int32_t index);

#ifdef __cplusplus
}
#endif

