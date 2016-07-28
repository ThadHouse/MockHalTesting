#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetAccelerometerActive(int32_t index);

HAL_AccelerometerRange HALSIM_GetAccelerometerRange(int32_t index);

double HALSIM_GetAccelerometerX(int32_t index);

double HALSIM_GetAccelerometerY(int32_t index);

double HALSIM_GetAccelerometerZ(int32_t index);

#ifdef __cplusplus
}
#endif

