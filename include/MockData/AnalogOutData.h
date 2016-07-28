#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

double HALSIM_GetAnalogOutVoltage(int32_t index);

HAL_Bool HALSIM_GetAnalogOutInitialized(int32_t index);

#ifdef __cplusplus
}
#endif

