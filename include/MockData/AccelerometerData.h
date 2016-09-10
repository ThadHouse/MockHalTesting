#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetAccelerometerActive(int32_t index);

HAL_AccelerometerRange HALSIM_GetAccelerometerRange(int32_t index);

double HALSIM_GetAccelerometerX(int32_t index);
void HALSIM_SetAccelerometerX(int32_t index, double x);

double HALSIM_GetAccelerometerY(int32_t index);
void HALSIM_SetAccelerometerY(int32_t index, double y);

double HALSIM_GetAccelerometerZ(int32_t index);
void HALSIM_SetAccelerometerZ(int32_t index, double z);

#ifdef __cplusplus
}
#endif

