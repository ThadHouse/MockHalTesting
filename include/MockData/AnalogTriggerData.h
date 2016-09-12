#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetAnalogTriggerData(int32_t index);
int32_t HALSIM_RegisterAnalogTriggerInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogTriggerInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetAnalogTriggerInitialized(int32_t index);

int32_t HALSIM_RegisterAnalogTriggerTriggerLowerBoundCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogTriggerTriggerLowerBoundCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogTriggerTriggerLowerBound(int32_t index);

int32_t HALSIM_RegisterAnalogTriggerTriggerUpperBoundCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelAnalogTriggerTriggerUpperBoundCallback(int32_t index, int32_t uid);
double HALSIM_GetAnalogTriggerTriggerUpperBound(int32_t index);

#ifdef __cplusplus
}
#endif

