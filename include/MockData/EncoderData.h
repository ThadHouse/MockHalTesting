#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetEncoderData(int32_t index);
int32_t HALSIM_RegisterEncoderInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetEncoderInitialized(int32_t index);
void HALSIM_SetEncoderInitialized(int32_t index, HAL_Bool initialized);

int32_t HALSIM_RegisterEncoderCountCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderCountCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetEncoderCount(int32_t index);
void HALSIM_SetEncoderCount(int32_t index, int32_t count);

int32_t HALSIM_RegisterEncoderPeriodCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderPeriodCallback(int32_t index, int32_t uid);
double HALSIM_GetEncoderPeriod(int32_t index);
void HALSIM_SetEncoderPeriod(int32_t index, double period);

int32_t HALSIM_RegisterEncoderResetCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderResetCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetEncoderReset(int32_t index);
void HALSIM_SetEncoderReset(int32_t index, HAL_Bool reset);

int32_t HALSIM_RegisterEncoderMaxPeriodCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderMaxPeriodCallback(int32_t index, int32_t uid);
double HALSIM_GetEncoderMaxPeriod(int32_t index);
void HALSIM_SetEncoderMaxPeriod(int32_t index, double maxPeriod);

int32_t HALSIM_RegisterEncoderDirectionCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderDirectionCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetEncoderDirection(int32_t index);
void HALSIM_SetEncoderDirection(int32_t index, HAL_Bool direction);

int32_t HALSIM_RegisterEncoderReverseDirectionCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderReverseDirectionCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetEncoderReverseDirection(int32_t index);
void HALSIM_SetEncoderReverseDirection(int32_t index, HAL_Bool reverseDirection);

int32_t HALSIM_RegisterEncoderSamplesToAverageCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelEncoderSamplesToAverageCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetEncoderSamplesToAverage(int32_t index);
void HALSIM_SetEncoderSamplesToAverage(int32_t index, int32_t samplesToAverage);

#ifdef __cplusplus
}
#endif

