#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetDIOInitialized(int32_t index);

HAL_Bool HALSIM_GetDIOValue(int32_t index);
void HALSIM_SetDIOValue(int32_t index, HAL_Bool value);

double HALSIM_GetDIOPulseLength(int32_t index);

HAL_Bool HALSIM_GetDIOIsInput(int32_t index);

int32_t HALSIM_GetDIOFilterIndex(int32_t index);

#ifdef __cplusplus
}
#endif

