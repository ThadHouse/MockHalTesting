#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetEncoderInitialized(int32_t index);

int32_t HALSIM_GetEncoderCount(int32_t index);
void HALSIM_SetEncoderCount(int32_t index, int32_t count);

double HALSIM_GetEncoderPeriod(int32_t index);
void HALSIM_SetEncoderPeriod(int32_t index, double period);

HAL_Bool HALSIM_GetEncoderReset(int32_t index);

double HALSIM_GetEncoderMaxPeriod(int32_t index);

HAL_Bool HALSIM_GetEncoderDirection(int32_t index);
void HALSIM_SetEncoderDirection(int32_t index, HAL_Bool direction);

HAL_Bool HALSIM_GetEncoderReverseDirection(int32_t index);

int32_t HALSIM_GetEncoderSamplesToAverage(int32_t index);

#ifdef __cplusplus
}
#endif

