#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetSPIAccelerometerActive(int32_t index);

uint8_t HALSIM_GetSPIAccelerometerRange(int32_t index);

double HALSIM_GetSPIAccelerometerX(int32_t index);

double HALSIM_GetSPIAccelerometerY(int32_t index);

double HALSIM_GetSPIAccelerometerZ(int32_t index);

#ifdef __cplusplus
}
#endif

