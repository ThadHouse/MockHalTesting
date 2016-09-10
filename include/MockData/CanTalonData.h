#pragma once

#include "HAL/HAL.h"

#ifdef __cplusplus
extern "C" {
#endif

double HALSIM_GetCanTalonProfileParamSlot0_P(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_P(int32_t index, double profileParamSlot0_P);

double HALSIM_GetCanTalonProfileParamSlot0_I(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_I(int32_t index, double profileParamSlot0_I);

double HALSIM_GetCanTalonProfileParamSlot0_D(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_D(int32_t index, double profileParamSlot0_D);

double HALSIM_GetCanTalonProfileParamSlot0_F(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_F(int32_t index, double profileParamSlot0_F);

int32_t HALSIM_GetCanTalonProfileParamSlot0_IZone(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_IZone(int32_t index, int32_t profileParamSlot0_IZone);

int32_t HALSIM_GetCanTalonProfileParamSlot0_CloseLoopRampRate(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_CloseLoopRampRate(int32_t index, int32_t profileParamSlot0_CloseLoopRampRate);

double HALSIM_GetCanTalonProfileParamSlot1_P(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_P(int32_t index, double profileParamSlot1_P);

double HALSIM_GetCanTalonProfileParamSlot1_I(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_I(int32_t index, double profileParamSlot1_I);

double HALSIM_GetCanTalonProfileParamSlot1_D(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_D(int32_t index, double profileParamSlot1_D);

double HALSIM_GetCanTalonProfileParamSlot1_F(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_F(int32_t index, double profileParamSlot1_F);

int32_t HALSIM_GetCanTalonProfileParamSlot1_IZone(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_IZone(int32_t index, int32_t profileParamSlot1_IZone);

int32_t HALSIM_GetCanTalonProfileParamSlot1_CloseLoopRampRate(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_CloseLoopRampRate(int32_t index, int32_t profileParamSlot1_CloseLoopRampRate);

double HALSIM_GetCanTalonProfileParamSoftLimitForThreshold(int32_t index);
void HALSIM_SetCanTalonProfileParamSoftLimitForThreshold(int32_t index, double profileParamSoftLimitForThreshold);

double HALSIM_GetCanTalonProfileParamSoftLimitRevThreshold(int32_t index);
void HALSIM_SetCanTalonProfileParamSoftLimitRevThreshold(int32_t index, double profileParamSoftLimitRevThreshold);

double HALSIM_GetCanTalonProfileParamSoftLimitForEnable(int32_t index);
void HALSIM_SetCanTalonProfileParamSoftLimitForEnable(int32_t index, double profileParamSoftLimitForEnable);

double HALSIM_GetCanTalonProfileParamSoftLimitRevEnable(int32_t index);
void HALSIM_SetCanTalonProfileParamSoftLimitRevEnable(int32_t index, double profileParamSoftLimitRevEnable);

double HALSIM_GetCanTalonOnBoot_BrakeMode(int32_t index);
void HALSIM_SetCanTalonOnBoot_BrakeMode(int32_t index, double onBoot_BrakeMode);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_NormallyClosed(int32_t index);
void HALSIM_SetCanTalonOnBoot_LimitSwitch_Forward_NormallyClosed(int32_t index, double onBoot_LimitSwitch_Forward_NormallyClosed);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_NormallyClosed(int32_t index);
void HALSIM_SetCanTalonOnBoot_LimitSwitch_Reverse_NormallyClosed(int32_t index, double onBoot_LimitSwitch_Reverse_NormallyClosed);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_Disable(int32_t index);
void HALSIM_SetCanTalonOnBoot_LimitSwitch_Forward_Disable(int32_t index, double onBoot_LimitSwitch_Forward_Disable);

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_Disable(int32_t index);
void HALSIM_SetCanTalonOnBoot_LimitSwitch_Reverse_Disable(int32_t index, double onBoot_LimitSwitch_Reverse_Disable);

double HALSIM_GetCanTalonFault_OverTemp(int32_t index);
void HALSIM_SetCanTalonFault_OverTemp(int32_t index, double fault_OverTemp);

double HALSIM_GetCanTalonFault_UnderVoltage(int32_t index);
void HALSIM_SetCanTalonFault_UnderVoltage(int32_t index, double fault_UnderVoltage);

double HALSIM_GetCanTalonFault_ForLim(int32_t index);
void HALSIM_SetCanTalonFault_ForLim(int32_t index, double fault_ForLim);

double HALSIM_GetCanTalonFault_RevLim(int32_t index);
void HALSIM_SetCanTalonFault_RevLim(int32_t index, double fault_RevLim);

double HALSIM_GetCanTalonFault_HardwareFailure(int32_t index);
void HALSIM_SetCanTalonFault_HardwareFailure(int32_t index, double fault_HardwareFailure);

double HALSIM_GetCanTalonFault_ForSoftLim(int32_t index);
void HALSIM_SetCanTalonFault_ForSoftLim(int32_t index, double fault_ForSoftLim);

double HALSIM_GetCanTalonFault_RevSoftLim(int32_t index);
void HALSIM_SetCanTalonFault_RevSoftLim(int32_t index, double fault_RevSoftLim);

double HALSIM_GetCanTalonStckyFault_OverTemp(int32_t index);
void HALSIM_SetCanTalonStckyFault_OverTemp(int32_t index, double stckyFault_OverTemp);

double HALSIM_GetCanTalonStckyFault_UnderVoltage(int32_t index);
void HALSIM_SetCanTalonStckyFault_UnderVoltage(int32_t index, double stckyFault_UnderVoltage);

double HALSIM_GetCanTalonStckyFault_ForLim(int32_t index);
void HALSIM_SetCanTalonStckyFault_ForLim(int32_t index, double stckyFault_ForLim);

double HALSIM_GetCanTalonStckyFault_RevLim(int32_t index);
void HALSIM_SetCanTalonStckyFault_RevLim(int32_t index, double stckyFault_RevLim);

double HALSIM_GetCanTalonStckyFault_ForSoftLim(int32_t index);
void HALSIM_SetCanTalonStckyFault_ForSoftLim(int32_t index, double stckyFault_ForSoftLim);

double HALSIM_GetCanTalonStckyFault_RevSoftLim(int32_t index);
void HALSIM_SetCanTalonStckyFault_RevSoftLim(int32_t index, double stckyFault_RevSoftLim);

double HALSIM_GetCanTalonAppliedThrottle(int32_t index);
void HALSIM_SetCanTalonAppliedThrottle(int32_t index, double appliedThrottle);

double HALSIM_GetCanTalonCloseLoopErr(int32_t index);
void HALSIM_SetCanTalonCloseLoopErr(int32_t index, double closeLoopErr);

double HALSIM_GetCanTalonFeedbackDeviceSelect(int32_t index);
void HALSIM_SetCanTalonFeedbackDeviceSelect(int32_t index, double feedbackDeviceSelect);

HAL_Bool HALSIM_GetCanTalonRevMotDuringCloseLoopEn(int32_t index);
void HALSIM_SetCanTalonRevMotDuringCloseLoopEn(int32_t index, HAL_Bool revMotDuringCloseLoopEn);

double HALSIM_GetCanTalonModeSelect(int32_t index);
void HALSIM_SetCanTalonModeSelect(int32_t index, double modeSelect);

double HALSIM_GetCanTalonProfileSlotSelect(int32_t index);
void HALSIM_SetCanTalonProfileSlotSelect(int32_t index, double profileSlotSelect);

double HALSIM_GetCanTalonRampThrottle(int32_t index);
void HALSIM_SetCanTalonRampThrottle(int32_t index, double rampThrottle);

HAL_Bool HALSIM_GetCanTalonRevFeedbackSensor(int32_t index);
void HALSIM_SetCanTalonRevFeedbackSensor(int32_t index, HAL_Bool revFeedbackSensor);

double HALSIM_GetCanTalonLimitSwitchEn(int32_t index);
void HALSIM_SetCanTalonLimitSwitchEn(int32_t index, double limitSwitchEn);

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedFor(int32_t index);
void HALSIM_SetCanTalonLimitSwitchClosedFor(int32_t index, HAL_Bool limitSwitchClosedFor);

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedRev(int32_t index);
void HALSIM_SetCanTalonLimitSwitchClosedRev(int32_t index, HAL_Bool limitSwitchClosedRev);

double HALSIM_GetCanTalonSensorPosition(int32_t index);
void HALSIM_SetCanTalonSensorPosition(int32_t index, double sensorPosition);

double HALSIM_GetCanTalonSensorVelocity(int32_t index);
void HALSIM_SetCanTalonSensorVelocity(int32_t index, double sensorVelocity);

double HALSIM_GetCanTalonCurrent(int32_t index);
void HALSIM_SetCanTalonCurrent(int32_t index, double current);

HAL_Bool HALSIM_GetCanTalonBrakeIsEnabled(int32_t index);
void HALSIM_SetCanTalonBrakeIsEnabled(int32_t index, HAL_Bool brakeIsEnabled);

double HALSIM_GetCanTalonEncPosition(int32_t index);
void HALSIM_SetCanTalonEncPosition(int32_t index, double encPosition);

double HALSIM_GetCanTalonEncVel(int32_t index);
void HALSIM_SetCanTalonEncVel(int32_t index, double encVel);

double HALSIM_GetCanTalonEncIndexRiseEvents(int32_t index);
void HALSIM_SetCanTalonEncIndexRiseEvents(int32_t index, double encIndexRiseEvents);

double HALSIM_GetCanTalonQuadApin(int32_t index);
void HALSIM_SetCanTalonQuadApin(int32_t index, double quadApin);

double HALSIM_GetCanTalonQuadBpin(int32_t index);
void HALSIM_SetCanTalonQuadBpin(int32_t index, double quadBpin);

double HALSIM_GetCanTalonQuadIdxpin(int32_t index);
void HALSIM_SetCanTalonQuadIdxpin(int32_t index, double quadIdxpin);

double HALSIM_GetCanTalonAnalogInWithOv(int32_t index);
void HALSIM_SetCanTalonAnalogInWithOv(int32_t index, double analogInWithOv);

double HALSIM_GetCanTalonAnalogInVel(int32_t index);
void HALSIM_SetCanTalonAnalogInVel(int32_t index, double analogInVel);

double HALSIM_GetCanTalonTemp(int32_t index);
void HALSIM_SetCanTalonTemp(int32_t index, double temp);

double HALSIM_GetCanTalonBatteryV(int32_t index);
void HALSIM_SetCanTalonBatteryV(int32_t index, double batteryV);

double HALSIM_GetCanTalonResetCount(int32_t index);
void HALSIM_SetCanTalonResetCount(int32_t index, double resetCount);

double HALSIM_GetCanTalonResetFlags(int32_t index);
void HALSIM_SetCanTalonResetFlags(int32_t index, double resetFlags);

double HALSIM_GetCanTalonFirmVers(int32_t index);
void HALSIM_SetCanTalonFirmVers(int32_t index, double firmVers);

double HALSIM_GetCanTalonSettingsChanged(int32_t index);
void HALSIM_SetCanTalonSettingsChanged(int32_t index, double settingsChanged);

double HALSIM_GetCanTalonQuadFilterEn(int32_t index);
void HALSIM_SetCanTalonQuadFilterEn(int32_t index, double quadFilterEn);

double HALSIM_GetCanTalonPidIaccum(int32_t index);
void HALSIM_SetCanTalonPidIaccum(int32_t index, double pidIaccum);

double HALSIM_GetCanTalonAinPosition(int32_t index);
void HALSIM_SetCanTalonAinPosition(int32_t index, double ainPosition);

double HALSIM_GetCanTalonProfileParamSlot0_AllowableClosedLoopErr(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot0_AllowableClosedLoopErr(int32_t index, double profileParamSlot0_AllowableClosedLoopErr);

double HALSIM_GetCanTalonProfileParamSlot1_AllowableClosedLoopErr(int32_t index);
void HALSIM_SetCanTalonProfileParamSlot1_AllowableClosedLoopErr(int32_t index, double profileParamSlot1_AllowableClosedLoopErr);

double HALSIM_GetCanTalonNumberEncoderCPR(int32_t index);
void HALSIM_SetCanTalonNumberEncoderCPR(int32_t index, double numberEncoderCPR);

double HALSIM_GetCanTalonNumberPotTurns(int32_t index);
void HALSIM_SetCanTalonNumberPotTurns(int32_t index, double numberPotTurns);

double HALSIM_GetCanTalonm_overrideLimitSwitch(int32_t index);
void HALSIM_SetCanTalonm_overrideLimitSwitch(int32_t index, double m_overrideLimitSwitch);

double HALSIM_GetCanTalonm_overrideBrakeType(int32_t index);
void HALSIM_SetCanTalonm_overrideBrakeType(int32_t index, double m_overrideBrakeType);

double HALSIM_GetCanTalonm_demand(int32_t index);
void HALSIM_SetCanTalonm_demand(int32_t index, double m_demand);

double HALSIM_GetCanTalonm_percentVBusValue(int32_t index);
void HALSIM_SetCanTalonm_percentVBusValue(int32_t index, double m_percentVBusValue);

double HALSIM_GetCanTalonm_voltageCompensationRate(int32_t index);
void HALSIM_SetCanTalonm_voltageCompensationRate(int32_t index, double m_voltageCompensationRate);

#ifdef __cplusplus
}
#endif

