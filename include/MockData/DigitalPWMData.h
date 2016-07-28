#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetDigitalPWMInitialized(int32_t index);

double HALSIM_GetDigitalPWMDutyCycle(int32_t index);

int32_t HALSIM_GetDigitalPWMPin(int32_t index);

#ifdef __cplusplus
}
#endif

