#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetAnalogOutData(int32_t index);
int32_t HALSIM_RegisterAnalogOutVoltageCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogOutVoltageCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogOutVoltage(int32_t index);
void HALSIM_SetAnalogOutVoltage(int32_t index, double voltage);

int32_t HALSIM_RegisterAnalogOutInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogOutInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAnalogOutInitialized(int32_t index);
void HALSIM_SetAnalogOutInitialized(int32_t index, HAL_Bool initialized);

#ifdef __cplusplus
}
#endif

