#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

double HALSIM_GetCanTalonProfileParamSlot0_P(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot0_I(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot0_D(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot0_F(int32_t index);

int32_t HALSIM_GetCanTalonProfileParamSlot0_IZone(int32_t index);

int32_t HALSIM_GetCanTalonProfileParamSlot0_CloseLoopRampRate(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot1_P(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot1_I(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot1_D(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot1_F(int32_t index);

int32_t HALSIM_GetCanTalonProfileParamSlot1_IZone(int32_t index);

int32_t HALSIM_GetCanTalonProfileParamSlot1_CloseLoopRampRate(int32_t index);

double HALSIM_GetCanTalonProfileParamSoftLimitForThreshold(int32_t index);

double HALSIM_GetCanTalonProfileParamSoftLimitRevThreshold(int32_t index);

double HALSIM_GetCanTalonProfileParamSoftLimitForEnable(int32_t index);

double HALSIM_GetCanTalonProfileParamSoftLimitRevEnable(int32_t index);

double HALSIM_GetCanTalonOnBoot_BrakeMode(int32_t index);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_NormallyClosed(int32_t index);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_NormallyClosed(int32_t index);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_Disable(int32_t index);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_Disable(int32_t index);

double HALSIM_GetCanTalonFault_OverTemp(int32_t index);

double HALSIM_GetCanTalonFault_UnderVoltage(int32_t index);

double HALSIM_GetCanTalonFault_ForLim(int32_t index);

double HALSIM_GetCanTalonFault_RevLim(int32_t index);

double HALSIM_GetCanTalonFault_HardwareFailure(int32_t index);

double HALSIM_GetCanTalonFault_ForSoftLim(int32_t index);

double HALSIM_GetCanTalonFault_RevSoftLim(int32_t index);

double HALSIM_GetCanTalonStckyFault_OverTemp(int32_t index);

double HALSIM_GetCanTalonStckyFault_UnderVoltage(int32_t index);

double HALSIM_GetCanTalonStckyFault_ForLim(int32_t index);

double HALSIM_GetCanTalonStckyFault_RevLim(int32_t index);

double HALSIM_GetCanTalonStckyFault_ForSoftLim(int32_t index);

double HALSIM_GetCanTalonStckyFault_RevSoftLim(int32_t index);

double HALSIM_GetCanTalonAppliedThrottle(int32_t index);

double HALSIM_GetCanTalonCloseLoopErr(int32_t index);

double HALSIM_GetCanTalonFeedbackDeviceSelect(int32_t index);

HAL_Bool HALSIM_GetCanTalonRevMotDuringCloseLoopEn(int32_t index);

double HALSIM_GetCanTalonModeSelect(int32_t index);

double HALSIM_GetCanTalonProfileSlotSelect(int32_t index);

double HALSIM_GetCanTalonRampThrottle(int32_t index);

HAL_Bool HALSIM_GetCanTalonRevFeedbackSensor(int32_t index);

double HALSIM_GetCanTalonLimitSwitchEn(int32_t index);

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedFor(int32_t index);

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedRev(int32_t index);

double HALSIM_GetCanTalonSensorPosition(int32_t index);

double HALSIM_GetCanTalonSensorVelocity(int32_t index);

double HALSIM_GetCanTalonCurrent(int32_t index);

HAL_Bool HALSIM_GetCanTalonBrakeIsEnabled(int32_t index);

double HALSIM_GetCanTalonEncPosition(int32_t index);

double HALSIM_GetCanTalonEncVel(int32_t index);

double HALSIM_GetCanTalonEncIndexRiseEvents(int32_t index);

double HALSIM_GetCanTalonQuadApin(int32_t index);

double HALSIM_GetCanTalonQuadBpin(int32_t index);

double HALSIM_GetCanTalonQuadIdxpin(int32_t index);

double HALSIM_GetCanTalonAnalogInWithOv(int32_t index);

double HALSIM_GetCanTalonAnalogInVel(int32_t index);

double HALSIM_GetCanTalonTemp(int32_t index);

double HALSIM_GetCanTalonBatteryV(int32_t index);

double HALSIM_GetCanTalonResetCount(int32_t index);

double HALSIM_GetCanTalonResetFlags(int32_t index);

double HALSIM_GetCanTalonFirmVers(int32_t index);

double HALSIM_GetCanTalonSettingsChanged(int32_t index);

double HALSIM_GetCanTalonQuadFilterEn(int32_t index);

double HALSIM_GetCanTalonPidIaccum(int32_t index);

double HALSIM_GetCanTalonAinPosition(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot0_AllowableClosedLoopErr(int32_t index);

double HALSIM_GetCanTalonProfileParamSlot1_AllowableClosedLoopErr(int32_t index);

double HALSIM_GetCanTalonNumberEncoderCPR(int32_t index);

double HALSIM_GetCanTalonNumberPotTurns(int32_t index);

double HALSIM_GetCanTalonm_overrideLimitSwitch(int32_t index);

double HALSIM_GetCanTalonm_overrideBrakeType(int32_t index);

double HALSIM_GetCanTalonm_demand(int32_t index);

double HALSIM_GetCanTalonm_percentVBusValue(int32_t index);

double HALSIM_GetCanTalonm_voltageCompensationRate(int32_t index);

#ifdef __cplusplus
}
#endif

