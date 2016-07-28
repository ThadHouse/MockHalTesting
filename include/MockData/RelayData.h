#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetRelayInitialized(int32_t index);

HAL_Bool HALSIM_GetRelayForward(int32_t index);

HAL_Bool HALSIM_GetRelayReverse(int32_t index);

#ifdef __cplusplus
}
#endif

