#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetDigitalPWMData(int32_t index);
int32_t HALSIM_RegisterDigitalPWMInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetDigitalPWMInitialized(int32_t index);

int32_t HALSIM_RegisterDigitalPWMDutyCycleCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMDutyCycleCallback(int32_t index, int32_t uid);
double HALSIM_GetDigitalPWMDutyCycle(int32_t index);

int32_t HALSIM_RegisterDigitalPWMPinCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMPinCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetDigitalPWMPin(int32_t index);

#ifdef __cplusplus
}
#endif

