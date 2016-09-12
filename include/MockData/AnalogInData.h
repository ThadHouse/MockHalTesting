#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetAnalogInData(int32_t index);
int32_t HALSIM_RegisterAnalogInInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAnalogInInitialized(int32_t index);

int32_t HALSIM_RegisterAnalogInAverageBitsCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAverageBitsCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetAnalogInAverageBits(int32_t index);

int32_t HALSIM_RegisterAnalogInOversampleBitsCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInOversampleBitsCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetAnalogInOversampleBits(int32_t index);

int32_t HALSIM_RegisterAnalogInVoltageCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInVoltageCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogInVoltage(int32_t index);
void HALSIM_SetAnalogInVoltage(int32_t index, double voltage);

int32_t HALSIM_RegisterAnalogInAccumulatorInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAccumulatorInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAnalogInAccumulatorInitialized(int32_t index);

int32_t HALSIM_RegisterAnalogInAccumulatorValueCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAccumulatorValueCallback(int32_t index, int32_t uid);
int64_t HALSIM_GetAnalogInAccumulatorValue(int32_t index);
void HALSIM_SetAnalogInAccumulatorValue(int32_t index, int64_t accumulatorValue);

int32_t HALSIM_RegisterAnalogInAccumulatorCountCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAccumulatorCountCallback(int32_t index, int32_t uid);
int64_t HALSIM_GetAnalogInAccumulatorCount(int32_t index);
void HALSIM_SetAnalogInAccumulatorCount(int32_t index, int64_t accumulatorCount);

int32_t HALSIM_RegisterAnalogInAccumlatorCenterCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAccumlatorCenterCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetAnalogInAccumlatorCenter(int32_t index);

int32_t HALSIM_RegisterAnalogInAccumlatorDeadbandCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogInAccumlatorDeadbandCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetAnalogInAccumlatorDeadband(int32_t index);

#ifdef __cplusplus
}
#endif

