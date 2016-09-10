#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetAnalogInInitialized(int32_t index);

int32_t HALSIM_GetAnalogInAverageBits(int32_t index);

int32_t HALSIM_GetAnalogInOversampleBits(int32_t index);

double HALSIM_GetAnalogInVoltage(int32_t index);
void HALSIM_SetAnalogInVoltage(int32_t index, double voltage);

HAL_Bool HALSIM_GetAnalogInAccumulatorInitialized(int32_t index);

int64_t HALSIM_GetAnalogInAccumulatorValue(int32_t index);
void HALSIM_SetAnalogInAccumulatorValue(int32_t index, int64_t accumulatorValue);

int64_t HALSIM_GetAnalogInAccumulatorCount(int32_t index);
void HALSIM_SetAnalogInAccumulatorCount(int32_t index, int64_t accumulatorCount);

int32_t HALSIM_GetAnalogInAccumlatorCenter(int32_t index);

int32_t HALSIM_GetAnalogInAccumlatorDeadband(int32_t index);

#ifdef __cplusplus
}
#endif

