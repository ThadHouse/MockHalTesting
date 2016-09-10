#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetSPIAccelerometerActive(int32_t index);

uint32_t HALSIM_GetSPIAccelerometerRange(int32_t index);

double HALSIM_GetSPIAccelerometerX(int32_t index);
void HALSIM_SetSPIAccelerometerX(int32_t index, double x);

double HALSIM_GetSPIAccelerometerY(int32_t index);
void HALSIM_SetSPIAccelerometerY(int32_t index, double y);

double HALSIM_GetSPIAccelerometerZ(int32_t index);
void HALSIM_SetSPIAccelerometerZ(int32_t index, double z);

#ifdef __cplusplus
}
#endif

