#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

double HALSIM_GetAnalogGyroAngle(int32_t index);

double HALSIM_GetAnalogGyroRate(int32_t index);

HAL_Bool HALSIM_GetAnalogGyroInitialized(int32_t index);

#ifdef __cplusplus
}
#endif

