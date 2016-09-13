#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetRelayData(int32_t index);
int32_t HALSIM_RegisterRelayInitializedForwardCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelRelayInitializedForwardCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetRelayForwardInitialized(int32_t index);

int32_t HALSIM_RegisterRelayInitializedReverseCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelRelayInitializedReverseCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetRelayReverseInitialized(int32_t index);

int32_t HALSIM_RegisterRelayForwardCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelRelayForwardCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetRelayForward(int32_t index);

int32_t HALSIM_RegisterRelayReverseCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelRelayReverseCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetRelayReverse(int32_t index);

#ifdef __cplusplus
}
#endif

