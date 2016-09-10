#include "CanTalonDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<CanTalonData>[]> hal::SimCanTalonData = std::make_unique<std::shared_ptr<CanTalonData>[]>(kNumCanTalons);
void CanTalonData::ResetData() {
  m_profileParamSlot0_P = 0.0;
  m_profileParamSlot0_I = 0.0;
  m_profileParamSlot0_D = 0.0;
  m_profileParamSlot0_F = 0.0;
  m_profileParamSlot0_IZone = 0;
  m_profileParamSlot0_CloseLoopRampRate = 0;
  m_profileParamSlot1_P = 0.0;
  m_profileParamSlot1_I = 0.0;
  m_profileParamSlot1_D = 0.0;
  m_profileParamSlot1_F = 0.0;
  m_profileParamSlot1_IZone = 0;
  m_profileParamSlot1_CloseLoopRampRate = 0;
  m_profileParamSoftLimitForThreshold = 0.0;
  m_profileParamSoftLimitRevThreshold = 0.0;
  m_profileParamSoftLimitForEnable = 0.0;
  m_profileParamSoftLimitRevEnable = 0.0;
  m_onBoot_BrakeMode = 0.0;
  m_onBoot_LimitSwitch_Forward_NormallyClosed = 0.0;
  m_onBoot_LimitSwitch_Reverse_NormallyClosed = 0.0;
  m_onBoot_LimitSwitch_Forward_Disable = 0.0;
  m_onBoot_LimitSwitch_Reverse_Disable = 0.0;
  m_fault_OverTemp = 0.0;
  m_fault_UnderVoltage = 0.0;
  m_fault_ForLim = 0.0;
  m_fault_RevLim = 0.0;
  m_fault_HardwareFailure = 0.0;
  m_fault_ForSoftLim = 0.0;
  m_fault_RevSoftLim = 0.0;
  m_stckyFault_OverTemp = 0.0;
  m_stckyFault_UnderVoltage = 0.0;
  m_stckyFault_ForLim = 0.0;
  m_stckyFault_RevLim = 0.0;
  m_stckyFault_ForSoftLim = 0.0;
  m_stckyFault_RevSoftLim = 0.0;
  m_appliedThrottle = 0.0;
  m_closeLoopErr = 0.0;
  m_feedbackDeviceSelect = 0.0;
  m_revMotDuringCloseLoopEn = false;
  m_modeSelect = 0.0;
  m_profileSlotSelect = 0.0;
  m_rampThrottle = 0.0;
  m_revFeedbackSensor = false;
  m_limitSwitchEn = 0.0;
  m_limitSwitchClosedFor = false;
  m_limitSwitchClosedRev = false;
  m_sensorPosition = 0.0;
  m_sensorVelocity = 0.0;
  m_current = 0.0;
  m_brakeIsEnabled = false;
  m_encPosition = 0.0;
  m_encVel = 0.0;
  m_encIndexRiseEvents = 0.0;
  m_quadApin = 0.0;
  m_quadBpin = 0.0;
  m_quadIdxpin = 0.0;
  m_analogInWithOv = 0.0;
  m_analogInVel = 0.0;
  m_temp = 0.0;
  m_batteryV = 0.0;
  m_resetCount = 0.0;
  m_resetFlags = 0.0;
  m_firmVers = 0.0;
  m_settingsChanged = 0.0;
  m_quadFilterEn = 0.0;
  m_pidIaccum = 0.0;
  m_ainPosition = 0.0;
  m_profileParamSlot0_AllowableClosedLoopErr = 0.0;
  m_profileParamSlot1_AllowableClosedLoopErr = 0.0;
  m_numberEncoderCPR = 0.0;
  m_numberPotTurns = 0.0;
  m_m_overrideLimitSwitch = 0.0;
  m_m_overrideBrakeType = 0.0;
  m_m_demand = 0.0;
  m_m_percentVBusValue = 0.0;
  m_m_voltageCompensationRate = 0.0;
  NotifyDataBase::ResetData();
}

double CanTalonData::GetProfileParamSlot0_P() {
  return m_profileParamSlot0_P;
}

void CanTalonData::SetProfileParamSlot0_P(double profileParamSlot0_P) {
  double oldValue = m_profileParamSlot0_P.exchange(profileParamSlot0_P);
  if (oldValue != profileParamSlot0_P) {
    OnPropertyChanged(&MakeDouble(profileParamSlot0_P));
  }
}

double CanTalonData::GetProfileParamSlot0_I() {
  return m_profileParamSlot0_I;
}

void CanTalonData::SetProfileParamSlot0_I(double profileParamSlot0_I) {
  double oldValue = m_profileParamSlot0_I.exchange(profileParamSlot0_I);
  if (oldValue != profileParamSlot0_I) {
    OnPropertyChanged(&MakeDouble(profileParamSlot0_I));
  }
}

double CanTalonData::GetProfileParamSlot0_D() {
  return m_profileParamSlot0_D;
}

void CanTalonData::SetProfileParamSlot0_D(double profileParamSlot0_D) {
  double oldValue = m_profileParamSlot0_D.exchange(profileParamSlot0_D);
  if (oldValue != profileParamSlot0_D) {
    OnPropertyChanged(&MakeDouble(profileParamSlot0_D));
  }
}

double CanTalonData::GetProfileParamSlot0_F() {
  return m_profileParamSlot0_F;
}

void CanTalonData::SetProfileParamSlot0_F(double profileParamSlot0_F) {
  double oldValue = m_profileParamSlot0_F.exchange(profileParamSlot0_F);
  if (oldValue != profileParamSlot0_F) {
    OnPropertyChanged(&MakeDouble(profileParamSlot0_F));
  }
}

int32_t CanTalonData::GetProfileParamSlot0_IZone() {
  return m_profileParamSlot0_IZone;
}

void CanTalonData::SetProfileParamSlot0_IZone(int32_t profileParamSlot0_IZone) {
  int32_t oldValue = m_profileParamSlot0_IZone.exchange(profileParamSlot0_IZone);
  if (oldValue != profileParamSlot0_IZone) {
    OnPropertyChanged(&MakeInt(profileParamSlot0_IZone));
  }
}

int32_t CanTalonData::GetProfileParamSlot0_CloseLoopRampRate() {
  return m_profileParamSlot0_CloseLoopRampRate;
}

void CanTalonData::SetProfileParamSlot0_CloseLoopRampRate(int32_t profileParamSlot0_CloseLoopRampRate) {
  int32_t oldValue = m_profileParamSlot0_CloseLoopRampRate.exchange(profileParamSlot0_CloseLoopRampRate);
  if (oldValue != profileParamSlot0_CloseLoopRampRate) {
    OnPropertyChanged(&MakeInt(profileParamSlot0_CloseLoopRampRate));
  }
}

double CanTalonData::GetProfileParamSlot1_P() {
  return m_profileParamSlot1_P;
}

void CanTalonData::SetProfileParamSlot1_P(double profileParamSlot1_P) {
  double oldValue = m_profileParamSlot1_P.exchange(profileParamSlot1_P);
  if (oldValue != profileParamSlot1_P) {
    OnPropertyChanged(&MakeDouble(profileParamSlot1_P));
  }
}

double CanTalonData::GetProfileParamSlot1_I() {
  return m_profileParamSlot1_I;
}

void CanTalonData::SetProfileParamSlot1_I(double profileParamSlot1_I) {
  double oldValue = m_profileParamSlot1_I.exchange(profileParamSlot1_I);
  if (oldValue != profileParamSlot1_I) {
    OnPropertyChanged(&MakeDouble(profileParamSlot1_I));
  }
}

double CanTalonData::GetProfileParamSlot1_D() {
  return m_profileParamSlot1_D;
}

void CanTalonData::SetProfileParamSlot1_D(double profileParamSlot1_D) {
  double oldValue = m_profileParamSlot1_D.exchange(profileParamSlot1_D);
  if (oldValue != profileParamSlot1_D) {
    OnPropertyChanged(&MakeDouble(profileParamSlot1_D));
  }
}

double CanTalonData::GetProfileParamSlot1_F() {
  return m_profileParamSlot1_F;
}

void CanTalonData::SetProfileParamSlot1_F(double profileParamSlot1_F) {
  double oldValue = m_profileParamSlot1_F.exchange(profileParamSlot1_F);
  if (oldValue != profileParamSlot1_F) {
    OnPropertyChanged(&MakeDouble(profileParamSlot1_F));
  }
}

int32_t CanTalonData::GetProfileParamSlot1_IZone() {
  return m_profileParamSlot1_IZone;
}

void CanTalonData::SetProfileParamSlot1_IZone(int32_t profileParamSlot1_IZone) {
  int32_t oldValue = m_profileParamSlot1_IZone.exchange(profileParamSlot1_IZone);
  if (oldValue != profileParamSlot1_IZone) {
    OnPropertyChanged(&MakeInt(profileParamSlot1_IZone));
  }
}

int32_t CanTalonData::GetProfileParamSlot1_CloseLoopRampRate() {
  return m_profileParamSlot1_CloseLoopRampRate;
}

void CanTalonData::SetProfileParamSlot1_CloseLoopRampRate(int32_t profileParamSlot1_CloseLoopRampRate) {
  int32_t oldValue = m_profileParamSlot1_CloseLoopRampRate.exchange(profileParamSlot1_CloseLoopRampRate);
  if (oldValue != profileParamSlot1_CloseLoopRampRate) {
    OnPropertyChanged(&MakeInt(profileParamSlot1_CloseLoopRampRate));
  }
}

double CanTalonData::GetProfileParamSoftLimitForThreshold() {
  return m_profileParamSoftLimitForThreshold;
}

void CanTalonData::SetProfileParamSoftLimitForThreshold(double profileParamSoftLimitForThreshold) {
  double oldValue = m_profileParamSoftLimitForThreshold.exchange(profileParamSoftLimitForThreshold);
  if (oldValue != profileParamSoftLimitForThreshold) {
    OnPropertyChanged(&MakeDouble(profileParamSoftLimitForThreshold));
  }
}

double CanTalonData::GetProfileParamSoftLimitRevThreshold() {
  return m_profileParamSoftLimitRevThreshold;
}

void CanTalonData::SetProfileParamSoftLimitRevThreshold(double profileParamSoftLimitRevThreshold) {
  double oldValue = m_profileParamSoftLimitRevThreshold.exchange(profileParamSoftLimitRevThreshold);
  if (oldValue != profileParamSoftLimitRevThreshold) {
    OnPropertyChanged(&MakeDouble(profileParamSoftLimitRevThreshold));
  }
}

double CanTalonData::GetProfileParamSoftLimitForEnable() {
  return m_profileParamSoftLimitForEnable;
}

void CanTalonData::SetProfileParamSoftLimitForEnable(double profileParamSoftLimitForEnable) {
  double oldValue = m_profileParamSoftLimitForEnable.exchange(profileParamSoftLimitForEnable);
  if (oldValue != profileParamSoftLimitForEnable) {
    OnPropertyChanged(&MakeDouble(profileParamSoftLimitForEnable));
  }
}

double CanTalonData::GetProfileParamSoftLimitRevEnable() {
  return m_profileParamSoftLimitRevEnable;
}

void CanTalonData::SetProfileParamSoftLimitRevEnable(double profileParamSoftLimitRevEnable) {
  double oldValue = m_profileParamSoftLimitRevEnable.exchange(profileParamSoftLimitRevEnable);
  if (oldValue != profileParamSoftLimitRevEnable) {
    OnPropertyChanged(&MakeDouble(profileParamSoftLimitRevEnable));
  }
}

double CanTalonData::GetOnBoot_BrakeMode() {
  return m_onBoot_BrakeMode;
}

void CanTalonData::SetOnBoot_BrakeMode(double onBoot_BrakeMode) {
  double oldValue = m_onBoot_BrakeMode.exchange(onBoot_BrakeMode);
  if (oldValue != onBoot_BrakeMode) {
    OnPropertyChanged(&MakeDouble(onBoot_BrakeMode));
  }
}

double CanTalonData::GetOnBoot_LimitSwitch_Forward_NormallyClosed() {
  return m_onBoot_LimitSwitch_Forward_NormallyClosed;
}

void CanTalonData::SetOnBoot_LimitSwitch_Forward_NormallyClosed(double onBoot_LimitSwitch_Forward_NormallyClosed) {
  double oldValue = m_onBoot_LimitSwitch_Forward_NormallyClosed.exchange(onBoot_LimitSwitch_Forward_NormallyClosed);
  if (oldValue != onBoot_LimitSwitch_Forward_NormallyClosed) {
    OnPropertyChanged(&MakeDouble(onBoot_LimitSwitch_Forward_NormallyClosed));
  }
}

double CanTalonData::GetOnBoot_LimitSwitch_Reverse_NormallyClosed() {
  return m_onBoot_LimitSwitch_Reverse_NormallyClosed;
}

void CanTalonData::SetOnBoot_LimitSwitch_Reverse_NormallyClosed(double onBoot_LimitSwitch_Reverse_NormallyClosed) {
  double oldValue = m_onBoot_LimitSwitch_Reverse_NormallyClosed.exchange(onBoot_LimitSwitch_Reverse_NormallyClosed);
  if (oldValue != onBoot_LimitSwitch_Reverse_NormallyClosed) {
    OnPropertyChanged(&MakeDouble(onBoot_LimitSwitch_Reverse_NormallyClosed));
  }
}

double CanTalonData::GetOnBoot_LimitSwitch_Forward_Disable() {
  return m_onBoot_LimitSwitch_Forward_Disable;
}

void CanTalonData::SetOnBoot_LimitSwitch_Forward_Disable(double onBoot_LimitSwitch_Forward_Disable) {
  double oldValue = m_onBoot_LimitSwitch_Forward_Disable.exchange(onBoot_LimitSwitch_Forward_Disable);
  if (oldValue != onBoot_LimitSwitch_Forward_Disable) {
    OnPropertyChanged(&MakeDouble(onBoot_LimitSwitch_Forward_Disable));
  }
}

double CanTalonData::GetOnBoot_LimitSwitch_Reverse_Disable() {
  return m_onBoot_LimitSwitch_Reverse_Disable;
}

void CanTalonData::SetOnBoot_LimitSwitch_Reverse_Disable(double onBoot_LimitSwitch_Reverse_Disable) {
  double oldValue = m_onBoot_LimitSwitch_Reverse_Disable.exchange(onBoot_LimitSwitch_Reverse_Disable);
  if (oldValue != onBoot_LimitSwitch_Reverse_Disable) {
    OnPropertyChanged(&MakeDouble(onBoot_LimitSwitch_Reverse_Disable));
  }
}

double CanTalonData::GetFault_OverTemp() {
  return m_fault_OverTemp;
}

void CanTalonData::SetFault_OverTemp(double fault_OverTemp) {
  double oldValue = m_fault_OverTemp.exchange(fault_OverTemp);
  if (oldValue != fault_OverTemp) {
    OnPropertyChanged(&MakeDouble(fault_OverTemp));
  }
}

double CanTalonData::GetFault_UnderVoltage() {
  return m_fault_UnderVoltage;
}

void CanTalonData::SetFault_UnderVoltage(double fault_UnderVoltage) {
  double oldValue = m_fault_UnderVoltage.exchange(fault_UnderVoltage);
  if (oldValue != fault_UnderVoltage) {
    OnPropertyChanged(&MakeDouble(fault_UnderVoltage));
  }
}

double CanTalonData::GetFault_ForLim() {
  return m_fault_ForLim;
}

void CanTalonData::SetFault_ForLim(double fault_ForLim) {
  double oldValue = m_fault_ForLim.exchange(fault_ForLim);
  if (oldValue != fault_ForLim) {
    OnPropertyChanged(&MakeDouble(fault_ForLim));
  }
}

double CanTalonData::GetFault_RevLim() {
  return m_fault_RevLim;
}

void CanTalonData::SetFault_RevLim(double fault_RevLim) {
  double oldValue = m_fault_RevLim.exchange(fault_RevLim);
  if (oldValue != fault_RevLim) {
    OnPropertyChanged(&MakeDouble(fault_RevLim));
  }
}

double CanTalonData::GetFault_HardwareFailure() {
  return m_fault_HardwareFailure;
}

void CanTalonData::SetFault_HardwareFailure(double fault_HardwareFailure) {
  double oldValue = m_fault_HardwareFailure.exchange(fault_HardwareFailure);
  if (oldValue != fault_HardwareFailure) {
    OnPropertyChanged(&MakeDouble(fault_HardwareFailure));
  }
}

double CanTalonData::GetFault_ForSoftLim() {
  return m_fault_ForSoftLim;
}

void CanTalonData::SetFault_ForSoftLim(double fault_ForSoftLim) {
  double oldValue = m_fault_ForSoftLim.exchange(fault_ForSoftLim);
  if (oldValue != fault_ForSoftLim) {
    OnPropertyChanged(&MakeDouble(fault_ForSoftLim));
  }
}

double CanTalonData::GetFault_RevSoftLim() {
  return m_fault_RevSoftLim;
}

void CanTalonData::SetFault_RevSoftLim(double fault_RevSoftLim) {
  double oldValue = m_fault_RevSoftLim.exchange(fault_RevSoftLim);
  if (oldValue != fault_RevSoftLim) {
    OnPropertyChanged(&MakeDouble(fault_RevSoftLim));
  }
}

double CanTalonData::GetStckyFault_OverTemp() {
  return m_stckyFault_OverTemp;
}

void CanTalonData::SetStckyFault_OverTemp(double stckyFault_OverTemp) {
  double oldValue = m_stckyFault_OverTemp.exchange(stckyFault_OverTemp);
  if (oldValue != stckyFault_OverTemp) {
    OnPropertyChanged(&MakeDouble(stckyFault_OverTemp));
  }
}

double CanTalonData::GetStckyFault_UnderVoltage() {
  return m_stckyFault_UnderVoltage;
}

void CanTalonData::SetStckyFault_UnderVoltage(double stckyFault_UnderVoltage) {
  double oldValue = m_stckyFault_UnderVoltage.exchange(stckyFault_UnderVoltage);
  if (oldValue != stckyFault_UnderVoltage) {
    OnPropertyChanged(&MakeDouble(stckyFault_UnderVoltage));
  }
}

double CanTalonData::GetStckyFault_ForLim() {
  return m_stckyFault_ForLim;
}

void CanTalonData::SetStckyFault_ForLim(double stckyFault_ForLim) {
  double oldValue = m_stckyFault_ForLim.exchange(stckyFault_ForLim);
  if (oldValue != stckyFault_ForLim) {
    OnPropertyChanged(&MakeDouble(stckyFault_ForLim));
  }
}

double CanTalonData::GetStckyFault_RevLim() {
  return m_stckyFault_RevLim;
}

void CanTalonData::SetStckyFault_RevLim(double stckyFault_RevLim) {
  double oldValue = m_stckyFault_RevLim.exchange(stckyFault_RevLim);
  if (oldValue != stckyFault_RevLim) {
    OnPropertyChanged(&MakeDouble(stckyFault_RevLim));
  }
}

double CanTalonData::GetStckyFault_ForSoftLim() {
  return m_stckyFault_ForSoftLim;
}

void CanTalonData::SetStckyFault_ForSoftLim(double stckyFault_ForSoftLim) {
  double oldValue = m_stckyFault_ForSoftLim.exchange(stckyFault_ForSoftLim);
  if (oldValue != stckyFault_ForSoftLim) {
    OnPropertyChanged(&MakeDouble(stckyFault_ForSoftLim));
  }
}

double CanTalonData::GetStckyFault_RevSoftLim() {
  return m_stckyFault_RevSoftLim;
}

void CanTalonData::SetStckyFault_RevSoftLim(double stckyFault_RevSoftLim) {
  double oldValue = m_stckyFault_RevSoftLim.exchange(stckyFault_RevSoftLim);
  if (oldValue != stckyFault_RevSoftLim) {
    OnPropertyChanged(&MakeDouble(stckyFault_RevSoftLim));
  }
}

double CanTalonData::GetAppliedThrottle() {
  return m_appliedThrottle;
}

void CanTalonData::SetAppliedThrottle(double appliedThrottle) {
  double oldValue = m_appliedThrottle.exchange(appliedThrottle);
  if (oldValue != appliedThrottle) {
    OnPropertyChanged(&MakeDouble(appliedThrottle));
  }
}

double CanTalonData::GetCloseLoopErr() {
  return m_closeLoopErr;
}

void CanTalonData::SetCloseLoopErr(double closeLoopErr) {
  double oldValue = m_closeLoopErr.exchange(closeLoopErr);
  if (oldValue != closeLoopErr) {
    OnPropertyChanged(&MakeDouble(closeLoopErr));
  }
}

double CanTalonData::GetFeedbackDeviceSelect() {
  return m_feedbackDeviceSelect;
}

void CanTalonData::SetFeedbackDeviceSelect(double feedbackDeviceSelect) {
  double oldValue = m_feedbackDeviceSelect.exchange(feedbackDeviceSelect);
  if (oldValue != feedbackDeviceSelect) {
    OnPropertyChanged(&MakeDouble(feedbackDeviceSelect));
  }
}

HAL_Bool CanTalonData::GetRevMotDuringCloseLoopEn() {
  return m_revMotDuringCloseLoopEn;
}

void CanTalonData::SetRevMotDuringCloseLoopEn(HAL_Bool revMotDuringCloseLoopEn) {
  HAL_Bool oldValue = m_revMotDuringCloseLoopEn.exchange(revMotDuringCloseLoopEn);
  if (oldValue != revMotDuringCloseLoopEn) {
    OnPropertyChanged(&MakeBoolean(revMotDuringCloseLoopEn));
  }
}

double CanTalonData::GetModeSelect() {
  return m_modeSelect;
}

void CanTalonData::SetModeSelect(double modeSelect) {
  double oldValue = m_modeSelect.exchange(modeSelect);
  if (oldValue != modeSelect) {
    OnPropertyChanged(&MakeDouble(modeSelect));
  }
}

double CanTalonData::GetProfileSlotSelect() {
  return m_profileSlotSelect;
}

void CanTalonData::SetProfileSlotSelect(double profileSlotSelect) {
  double oldValue = m_profileSlotSelect.exchange(profileSlotSelect);
  if (oldValue != profileSlotSelect) {
    OnPropertyChanged(&MakeDouble(profileSlotSelect));
  }
}

double CanTalonData::GetRampThrottle() {
  return m_rampThrottle;
}

void CanTalonData::SetRampThrottle(double rampThrottle) {
  double oldValue = m_rampThrottle.exchange(rampThrottle);
  if (oldValue != rampThrottle) {
    OnPropertyChanged(&MakeDouble(rampThrottle));
  }
}

HAL_Bool CanTalonData::GetRevFeedbackSensor() {
  return m_revFeedbackSensor;
}

void CanTalonData::SetRevFeedbackSensor(HAL_Bool revFeedbackSensor) {
  HAL_Bool oldValue = m_revFeedbackSensor.exchange(revFeedbackSensor);
  if (oldValue != revFeedbackSensor) {
    OnPropertyChanged(&MakeBoolean(revFeedbackSensor));
  }
}

double CanTalonData::GetLimitSwitchEn() {
  return m_limitSwitchEn;
}

void CanTalonData::SetLimitSwitchEn(double limitSwitchEn) {
  double oldValue = m_limitSwitchEn.exchange(limitSwitchEn);
  if (oldValue != limitSwitchEn) {
    OnPropertyChanged(&MakeDouble(limitSwitchEn));
  }
}

HAL_Bool CanTalonData::GetLimitSwitchClosedFor() {
  return m_limitSwitchClosedFor;
}

void CanTalonData::SetLimitSwitchClosedFor(HAL_Bool limitSwitchClosedFor) {
  HAL_Bool oldValue = m_limitSwitchClosedFor.exchange(limitSwitchClosedFor);
  if (oldValue != limitSwitchClosedFor) {
    OnPropertyChanged(&MakeBoolean(limitSwitchClosedFor));
  }
}

HAL_Bool CanTalonData::GetLimitSwitchClosedRev() {
  return m_limitSwitchClosedRev;
}

void CanTalonData::SetLimitSwitchClosedRev(HAL_Bool limitSwitchClosedRev) {
  HAL_Bool oldValue = m_limitSwitchClosedRev.exchange(limitSwitchClosedRev);
  if (oldValue != limitSwitchClosedRev) {
    OnPropertyChanged(&MakeBoolean(limitSwitchClosedRev));
  }
}

double CanTalonData::GetSensorPosition() {
  return m_sensorPosition;
}

void CanTalonData::SetSensorPosition(double sensorPosition) {
  double oldValue = m_sensorPosition.exchange(sensorPosition);
  if (oldValue != sensorPosition) {
    OnPropertyChanged(&MakeDouble(sensorPosition));
  }
}

double CanTalonData::GetSensorVelocity() {
  return m_sensorVelocity;
}

void CanTalonData::SetSensorVelocity(double sensorVelocity) {
  double oldValue = m_sensorVelocity.exchange(sensorVelocity);
  if (oldValue != sensorVelocity) {
    OnPropertyChanged(&MakeDouble(sensorVelocity));
  }
}

double CanTalonData::GetCurrent() {
  return m_current;
}

void CanTalonData::SetCurrent(double current) {
  double oldValue = m_current.exchange(current);
  if (oldValue != current) {
    OnPropertyChanged(&MakeDouble(current));
  }
}

HAL_Bool CanTalonData::GetBrakeIsEnabled() {
  return m_brakeIsEnabled;
}

void CanTalonData::SetBrakeIsEnabled(HAL_Bool brakeIsEnabled) {
  HAL_Bool oldValue = m_brakeIsEnabled.exchange(brakeIsEnabled);
  if (oldValue != brakeIsEnabled) {
    OnPropertyChanged(&MakeBoolean(brakeIsEnabled));
  }
}

double CanTalonData::GetEncPosition() {
  return m_encPosition;
}

void CanTalonData::SetEncPosition(double encPosition) {
  double oldValue = m_encPosition.exchange(encPosition);
  if (oldValue != encPosition) {
    OnPropertyChanged(&MakeDouble(encPosition));
  }
}

double CanTalonData::GetEncVel() {
  return m_encVel;
}

void CanTalonData::SetEncVel(double encVel) {
  double oldValue = m_encVel.exchange(encVel);
  if (oldValue != encVel) {
    OnPropertyChanged(&MakeDouble(encVel));
  }
}

double CanTalonData::GetEncIndexRiseEvents() {
  return m_encIndexRiseEvents;
}

void CanTalonData::SetEncIndexRiseEvents(double encIndexRiseEvents) {
  double oldValue = m_encIndexRiseEvents.exchange(encIndexRiseEvents);
  if (oldValue != encIndexRiseEvents) {
    OnPropertyChanged(&MakeDouble(encIndexRiseEvents));
  }
}

double CanTalonData::GetQuadApin() {
  return m_quadApin;
}

void CanTalonData::SetQuadApin(double quadApin) {
  double oldValue = m_quadApin.exchange(quadApin);
  if (oldValue != quadApin) {
    OnPropertyChanged(&MakeDouble(quadApin));
  }
}

double CanTalonData::GetQuadBpin() {
  return m_quadBpin;
}

void CanTalonData::SetQuadBpin(double quadBpin) {
  double oldValue = m_quadBpin.exchange(quadBpin);
  if (oldValue != quadBpin) {
    OnPropertyChanged(&MakeDouble(quadBpin));
  }
}

double CanTalonData::GetQuadIdxpin() {
  return m_quadIdxpin;
}

void CanTalonData::SetQuadIdxpin(double quadIdxpin) {
  double oldValue = m_quadIdxpin.exchange(quadIdxpin);
  if (oldValue != quadIdxpin) {
    OnPropertyChanged(&MakeDouble(quadIdxpin));
  }
}

double CanTalonData::GetAnalogInWithOv() {
  return m_analogInWithOv;
}

void CanTalonData::SetAnalogInWithOv(double analogInWithOv) {
  double oldValue = m_analogInWithOv.exchange(analogInWithOv);
  if (oldValue != analogInWithOv) {
    OnPropertyChanged(&MakeDouble(analogInWithOv));
  }
}

double CanTalonData::GetAnalogInVel() {
  return m_analogInVel;
}

void CanTalonData::SetAnalogInVel(double analogInVel) {
  double oldValue = m_analogInVel.exchange(analogInVel);
  if (oldValue != analogInVel) {
    OnPropertyChanged(&MakeDouble(analogInVel));
  }
}

double CanTalonData::GetTemp() {
  return m_temp;
}

void CanTalonData::SetTemp(double temp) {
  double oldValue = m_temp.exchange(temp);
  if (oldValue != temp) {
    OnPropertyChanged(&MakeDouble(temp));
  }
}

double CanTalonData::GetBatteryV() {
  return m_batteryV;
}

void CanTalonData::SetBatteryV(double batteryV) {
  double oldValue = m_batteryV.exchange(batteryV);
  if (oldValue != batteryV) {
    OnPropertyChanged(&MakeDouble(batteryV));
  }
}

double CanTalonData::GetResetCount() {
  return m_resetCount;
}

void CanTalonData::SetResetCount(double resetCount) {
  double oldValue = m_resetCount.exchange(resetCount);
  if (oldValue != resetCount) {
    OnPropertyChanged(&MakeDouble(resetCount));
  }
}

double CanTalonData::GetResetFlags() {
  return m_resetFlags;
}

void CanTalonData::SetResetFlags(double resetFlags) {
  double oldValue = m_resetFlags.exchange(resetFlags);
  if (oldValue != resetFlags) {
    OnPropertyChanged(&MakeDouble(resetFlags));
  }
}

double CanTalonData::GetFirmVers() {
  return m_firmVers;
}

void CanTalonData::SetFirmVers(double firmVers) {
  double oldValue = m_firmVers.exchange(firmVers);
  if (oldValue != firmVers) {
    OnPropertyChanged(&MakeDouble(firmVers));
  }
}

double CanTalonData::GetSettingsChanged() {
  return m_settingsChanged;
}

void CanTalonData::SetSettingsChanged(double settingsChanged) {
  double oldValue = m_settingsChanged.exchange(settingsChanged);
  if (oldValue != settingsChanged) {
    OnPropertyChanged(&MakeDouble(settingsChanged));
  }
}

double CanTalonData::GetQuadFilterEn() {
  return m_quadFilterEn;
}

void CanTalonData::SetQuadFilterEn(double quadFilterEn) {
  double oldValue = m_quadFilterEn.exchange(quadFilterEn);
  if (oldValue != quadFilterEn) {
    OnPropertyChanged(&MakeDouble(quadFilterEn));
  }
}

double CanTalonData::GetPidIaccum() {
  return m_pidIaccum;
}

void CanTalonData::SetPidIaccum(double pidIaccum) {
  double oldValue = m_pidIaccum.exchange(pidIaccum);
  if (oldValue != pidIaccum) {
    OnPropertyChanged(&MakeDouble(pidIaccum));
  }
}

double CanTalonData::GetAinPosition() {
  return m_ainPosition;
}

void CanTalonData::SetAinPosition(double ainPosition) {
  double oldValue = m_ainPosition.exchange(ainPosition);
  if (oldValue != ainPosition) {
    OnPropertyChanged(&MakeDouble(ainPosition));
  }
}

double CanTalonData::GetProfileParamSlot0_AllowableClosedLoopErr() {
  return m_profileParamSlot0_AllowableClosedLoopErr;
}

void CanTalonData::SetProfileParamSlot0_AllowableClosedLoopErr(double profileParamSlot0_AllowableClosedLoopErr) {
  double oldValue = m_profileParamSlot0_AllowableClosedLoopErr.exchange(profileParamSlot0_AllowableClosedLoopErr);
  if (oldValue != profileParamSlot0_AllowableClosedLoopErr) {
    OnPropertyChanged(&MakeDouble(profileParamSlot0_AllowableClosedLoopErr));
  }
}

double CanTalonData::GetProfileParamSlot1_AllowableClosedLoopErr() {
  return m_profileParamSlot1_AllowableClosedLoopErr;
}

void CanTalonData::SetProfileParamSlot1_AllowableClosedLoopErr(double profileParamSlot1_AllowableClosedLoopErr) {
  double oldValue = m_profileParamSlot1_AllowableClosedLoopErr.exchange(profileParamSlot1_AllowableClosedLoopErr);
  if (oldValue != profileParamSlot1_AllowableClosedLoopErr) {
    OnPropertyChanged(&MakeDouble(profileParamSlot1_AllowableClosedLoopErr));
  }
}

double CanTalonData::GetNumberEncoderCPR() {
  return m_numberEncoderCPR;
}

void CanTalonData::SetNumberEncoderCPR(double numberEncoderCPR) {
  double oldValue = m_numberEncoderCPR.exchange(numberEncoderCPR);
  if (oldValue != numberEncoderCPR) {
    OnPropertyChanged(&MakeDouble(numberEncoderCPR));
  }
}

double CanTalonData::GetNumberPotTurns() {
  return m_numberPotTurns;
}

void CanTalonData::SetNumberPotTurns(double numberPotTurns) {
  double oldValue = m_numberPotTurns.exchange(numberPotTurns);
  if (oldValue != numberPotTurns) {
    OnPropertyChanged(&MakeDouble(numberPotTurns));
  }
}

double CanTalonData::Getm_overrideLimitSwitch() {
  return m_m_overrideLimitSwitch;
}

void CanTalonData::Setm_overrideLimitSwitch(double m_overrideLimitSwitch) {
  double oldValue = m_m_overrideLimitSwitch.exchange(m_overrideLimitSwitch);
  if (oldValue != m_overrideLimitSwitch) {
    OnPropertyChanged(&MakeDouble(m_overrideLimitSwitch));
  }
}

double CanTalonData::Getm_overrideBrakeType() {
  return m_m_overrideBrakeType;
}

void CanTalonData::Setm_overrideBrakeType(double m_overrideBrakeType) {
  double oldValue = m_m_overrideBrakeType.exchange(m_overrideBrakeType);
  if (oldValue != m_overrideBrakeType) {
    OnPropertyChanged(&MakeDouble(m_overrideBrakeType));
  }
}

double CanTalonData::Getm_demand() {
  return m_m_demand;
}

void CanTalonData::Setm_demand(double m_demand) {
  double oldValue = m_m_demand.exchange(m_demand);
  if (oldValue != m_demand) {
    OnPropertyChanged(&MakeDouble(m_demand));
  }
}

double CanTalonData::Getm_percentVBusValue() {
  return m_m_percentVBusValue;
}

void CanTalonData::Setm_percentVBusValue(double m_percentVBusValue) {
  double oldValue = m_m_percentVBusValue.exchange(m_percentVBusValue);
  if (oldValue != m_percentVBusValue) {
    OnPropertyChanged(&MakeDouble(m_percentVBusValue));
  }
}

double CanTalonData::Getm_voltageCompensationRate() {
  return m_m_voltageCompensationRate;
}

void CanTalonData::Setm_voltageCompensationRate(double m_voltageCompensationRate) {
  double oldValue = m_m_voltageCompensationRate.exchange(m_voltageCompensationRate);
  if (oldValue != m_voltageCompensationRate) {
    OnPropertyChanged(&MakeDouble(m_voltageCompensationRate));
  }
}

extern "C" {
double HALSIM_GetCanTalonProfileParamSlot0_P(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_P();
}

void HALSIM_SetCanTalonProfileParamSlot0_P(int32_t index, double profileParamSlot0_P) {
  SimCanTalonData[index]->SetProfileParamSlot0_P(profileParamSlot0_P);
}

double HALSIM_GetCanTalonProfileParamSlot0_I(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_I();
}

void HALSIM_SetCanTalonProfileParamSlot0_I(int32_t index, double profileParamSlot0_I) {
  SimCanTalonData[index]->SetProfileParamSlot0_I(profileParamSlot0_I);
}

double HALSIM_GetCanTalonProfileParamSlot0_D(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_D();
}

void HALSIM_SetCanTalonProfileParamSlot0_D(int32_t index, double profileParamSlot0_D) {
  SimCanTalonData[index]->SetProfileParamSlot0_D(profileParamSlot0_D);
}

double HALSIM_GetCanTalonProfileParamSlot0_F(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_F();
}

void HALSIM_SetCanTalonProfileParamSlot0_F(int32_t index, double profileParamSlot0_F) {
  SimCanTalonData[index]->SetProfileParamSlot0_F(profileParamSlot0_F);
}

int32_t HALSIM_GetCanTalonProfileParamSlot0_IZone(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_IZone();
}

void HALSIM_SetCanTalonProfileParamSlot0_IZone(int32_t index, int32_t profileParamSlot0_IZone) {
  SimCanTalonData[index]->SetProfileParamSlot0_IZone(profileParamSlot0_IZone);
}

int32_t HALSIM_GetCanTalonProfileParamSlot0_CloseLoopRampRate(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_CloseLoopRampRate();
}

void HALSIM_SetCanTalonProfileParamSlot0_CloseLoopRampRate(int32_t index, int32_t profileParamSlot0_CloseLoopRampRate) {
  SimCanTalonData[index]->SetProfileParamSlot0_CloseLoopRampRate(profileParamSlot0_CloseLoopRampRate);
}

double HALSIM_GetCanTalonProfileParamSlot1_P(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_P();
}

void HALSIM_SetCanTalonProfileParamSlot1_P(int32_t index, double profileParamSlot1_P) {
  SimCanTalonData[index]->SetProfileParamSlot1_P(profileParamSlot1_P);
}

double HALSIM_GetCanTalonProfileParamSlot1_I(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_I();
}

void HALSIM_SetCanTalonProfileParamSlot1_I(int32_t index, double profileParamSlot1_I) {
  SimCanTalonData[index]->SetProfileParamSlot1_I(profileParamSlot1_I);
}

double HALSIM_GetCanTalonProfileParamSlot1_D(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_D();
}

void HALSIM_SetCanTalonProfileParamSlot1_D(int32_t index, double profileParamSlot1_D) {
  SimCanTalonData[index]->SetProfileParamSlot1_D(profileParamSlot1_D);
}

double HALSIM_GetCanTalonProfileParamSlot1_F(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_F();
}

void HALSIM_SetCanTalonProfileParamSlot1_F(int32_t index, double profileParamSlot1_F) {
  SimCanTalonData[index]->SetProfileParamSlot1_F(profileParamSlot1_F);
}

int32_t HALSIM_GetCanTalonProfileParamSlot1_IZone(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_IZone();
}

void HALSIM_SetCanTalonProfileParamSlot1_IZone(int32_t index, int32_t profileParamSlot1_IZone) {
  SimCanTalonData[index]->SetProfileParamSlot1_IZone(profileParamSlot1_IZone);
}

int32_t HALSIM_GetCanTalonProfileParamSlot1_CloseLoopRampRate(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_CloseLoopRampRate();
}

void HALSIM_SetCanTalonProfileParamSlot1_CloseLoopRampRate(int32_t index, int32_t profileParamSlot1_CloseLoopRampRate) {
  SimCanTalonData[index]->SetProfileParamSlot1_CloseLoopRampRate(profileParamSlot1_CloseLoopRampRate);
}

double HALSIM_GetCanTalonProfileParamSoftLimitForThreshold(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSoftLimitForThreshold();
}

void HALSIM_SetCanTalonProfileParamSoftLimitForThreshold(int32_t index, double profileParamSoftLimitForThreshold) {
  SimCanTalonData[index]->SetProfileParamSoftLimitForThreshold(profileParamSoftLimitForThreshold);
}

double HALSIM_GetCanTalonProfileParamSoftLimitRevThreshold(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSoftLimitRevThreshold();
}

void HALSIM_SetCanTalonProfileParamSoftLimitRevThreshold(int32_t index, double profileParamSoftLimitRevThreshold) {
  SimCanTalonData[index]->SetProfileParamSoftLimitRevThreshold(profileParamSoftLimitRevThreshold);
}

double HALSIM_GetCanTalonProfileParamSoftLimitForEnable(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSoftLimitForEnable();
}

void HALSIM_SetCanTalonProfileParamSoftLimitForEnable(int32_t index, double profileParamSoftLimitForEnable) {
  SimCanTalonData[index]->SetProfileParamSoftLimitForEnable(profileParamSoftLimitForEnable);
}

double HALSIM_GetCanTalonProfileParamSoftLimitRevEnable(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSoftLimitRevEnable();
}

void HALSIM_SetCanTalonProfileParamSoftLimitRevEnable(int32_t index, double profileParamSoftLimitRevEnable) {
  SimCanTalonData[index]->SetProfileParamSoftLimitRevEnable(profileParamSoftLimitRevEnable);
}

double HALSIM_GetCanTalonOnBoot_BrakeMode(int32_t index) {
  return SimCanTalonData[index]->GetOnBoot_BrakeMode();
}

void HALSIM_SetCanTalonOnBoot_BrakeMode(int32_t index, double onBoot_BrakeMode) {
  SimCanTalonData[index]->SetOnBoot_BrakeMode(onBoot_BrakeMode);
}

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_NormallyClosed(int32_t index) {
  return SimCanTalonData[index]->GetOnBoot_LimitSwitch_Forward_NormallyClosed();
}

void HALSIM_SetCanTalonOnBoot_LimitSwitch_Forward_NormallyClosed(int32_t index, double onBoot_LimitSwitch_Forward_NormallyClosed) {
  SimCanTalonData[index]->SetOnBoot_LimitSwitch_Forward_NormallyClosed(onBoot_LimitSwitch_Forward_NormallyClosed);
}

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_NormallyClosed(int32_t index) {
  return SimCanTalonData[index]->GetOnBoot_LimitSwitch_Reverse_NormallyClosed();
}

void HALSIM_SetCanTalonOnBoot_LimitSwitch_Reverse_NormallyClosed(int32_t index, double onBoot_LimitSwitch_Reverse_NormallyClosed) {
  SimCanTalonData[index]->SetOnBoot_LimitSwitch_Reverse_NormallyClosed(onBoot_LimitSwitch_Reverse_NormallyClosed);
}

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Forward_Disable(int32_t index) {
  return SimCanTalonData[index]->GetOnBoot_LimitSwitch_Forward_Disable();
}

void HALSIM_SetCanTalonOnBoot_LimitSwitch_Forward_Disable(int32_t index, double onBoot_LimitSwitch_Forward_Disable) {
  SimCanTalonData[index]->SetOnBoot_LimitSwitch_Forward_Disable(onBoot_LimitSwitch_Forward_Disable);
}

double HALSIM_GetCanTalonOnBoot_LimitSwitch_Reverse_Disable(int32_t index) {
  return SimCanTalonData[index]->GetOnBoot_LimitSwitch_Reverse_Disable();
}

void HALSIM_SetCanTalonOnBoot_LimitSwitch_Reverse_Disable(int32_t index, double onBoot_LimitSwitch_Reverse_Disable) {
  SimCanTalonData[index]->SetOnBoot_LimitSwitch_Reverse_Disable(onBoot_LimitSwitch_Reverse_Disable);
}

double HALSIM_GetCanTalonFault_OverTemp(int32_t index) {
  return SimCanTalonData[index]->GetFault_OverTemp();
}

void HALSIM_SetCanTalonFault_OverTemp(int32_t index, double fault_OverTemp) {
  SimCanTalonData[index]->SetFault_OverTemp(fault_OverTemp);
}

double HALSIM_GetCanTalonFault_UnderVoltage(int32_t index) {
  return SimCanTalonData[index]->GetFault_UnderVoltage();
}

void HALSIM_SetCanTalonFault_UnderVoltage(int32_t index, double fault_UnderVoltage) {
  SimCanTalonData[index]->SetFault_UnderVoltage(fault_UnderVoltage);
}

double HALSIM_GetCanTalonFault_ForLim(int32_t index) {
  return SimCanTalonData[index]->GetFault_ForLim();
}

void HALSIM_SetCanTalonFault_ForLim(int32_t index, double fault_ForLim) {
  SimCanTalonData[index]->SetFault_ForLim(fault_ForLim);
}

double HALSIM_GetCanTalonFault_RevLim(int32_t index) {
  return SimCanTalonData[index]->GetFault_RevLim();
}

void HALSIM_SetCanTalonFault_RevLim(int32_t index, double fault_RevLim) {
  SimCanTalonData[index]->SetFault_RevLim(fault_RevLim);
}

double HALSIM_GetCanTalonFault_HardwareFailure(int32_t index) {
  return SimCanTalonData[index]->GetFault_HardwareFailure();
}

void HALSIM_SetCanTalonFault_HardwareFailure(int32_t index, double fault_HardwareFailure) {
  SimCanTalonData[index]->SetFault_HardwareFailure(fault_HardwareFailure);
}

double HALSIM_GetCanTalonFault_ForSoftLim(int32_t index) {
  return SimCanTalonData[index]->GetFault_ForSoftLim();
}

void HALSIM_SetCanTalonFault_ForSoftLim(int32_t index, double fault_ForSoftLim) {
  SimCanTalonData[index]->SetFault_ForSoftLim(fault_ForSoftLim);
}

double HALSIM_GetCanTalonFault_RevSoftLim(int32_t index) {
  return SimCanTalonData[index]->GetFault_RevSoftLim();
}

void HALSIM_SetCanTalonFault_RevSoftLim(int32_t index, double fault_RevSoftLim) {
  SimCanTalonData[index]->SetFault_RevSoftLim(fault_RevSoftLim);
}

double HALSIM_GetCanTalonStckyFault_OverTemp(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_OverTemp();
}

void HALSIM_SetCanTalonStckyFault_OverTemp(int32_t index, double stckyFault_OverTemp) {
  SimCanTalonData[index]->SetStckyFault_OverTemp(stckyFault_OverTemp);
}

double HALSIM_GetCanTalonStckyFault_UnderVoltage(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_UnderVoltage();
}

void HALSIM_SetCanTalonStckyFault_UnderVoltage(int32_t index, double stckyFault_UnderVoltage) {
  SimCanTalonData[index]->SetStckyFault_UnderVoltage(stckyFault_UnderVoltage);
}

double HALSIM_GetCanTalonStckyFault_ForLim(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_ForLim();
}

void HALSIM_SetCanTalonStckyFault_ForLim(int32_t index, double stckyFault_ForLim) {
  SimCanTalonData[index]->SetStckyFault_ForLim(stckyFault_ForLim);
}

double HALSIM_GetCanTalonStckyFault_RevLim(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_RevLim();
}

void HALSIM_SetCanTalonStckyFault_RevLim(int32_t index, double stckyFault_RevLim) {
  SimCanTalonData[index]->SetStckyFault_RevLim(stckyFault_RevLim);
}

double HALSIM_GetCanTalonStckyFault_ForSoftLim(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_ForSoftLim();
}

void HALSIM_SetCanTalonStckyFault_ForSoftLim(int32_t index, double stckyFault_ForSoftLim) {
  SimCanTalonData[index]->SetStckyFault_ForSoftLim(stckyFault_ForSoftLim);
}

double HALSIM_GetCanTalonStckyFault_RevSoftLim(int32_t index) {
  return SimCanTalonData[index]->GetStckyFault_RevSoftLim();
}

void HALSIM_SetCanTalonStckyFault_RevSoftLim(int32_t index, double stckyFault_RevSoftLim) {
  SimCanTalonData[index]->SetStckyFault_RevSoftLim(stckyFault_RevSoftLim);
}

double HALSIM_GetCanTalonAppliedThrottle(int32_t index) {
  return SimCanTalonData[index]->GetAppliedThrottle();
}

void HALSIM_SetCanTalonAppliedThrottle(int32_t index, double appliedThrottle) {
  SimCanTalonData[index]->SetAppliedThrottle(appliedThrottle);
}

double HALSIM_GetCanTalonCloseLoopErr(int32_t index) {
  return SimCanTalonData[index]->GetCloseLoopErr();
}

void HALSIM_SetCanTalonCloseLoopErr(int32_t index, double closeLoopErr) {
  SimCanTalonData[index]->SetCloseLoopErr(closeLoopErr);
}

double HALSIM_GetCanTalonFeedbackDeviceSelect(int32_t index) {
  return SimCanTalonData[index]->GetFeedbackDeviceSelect();
}

void HALSIM_SetCanTalonFeedbackDeviceSelect(int32_t index, double feedbackDeviceSelect) {
  SimCanTalonData[index]->SetFeedbackDeviceSelect(feedbackDeviceSelect);
}

HAL_Bool HALSIM_GetCanTalonRevMotDuringCloseLoopEn(int32_t index) {
  return SimCanTalonData[index]->GetRevMotDuringCloseLoopEn();
}

void HALSIM_SetCanTalonRevMotDuringCloseLoopEn(int32_t index, HAL_Bool revMotDuringCloseLoopEn) {
  SimCanTalonData[index]->SetRevMotDuringCloseLoopEn(revMotDuringCloseLoopEn);
}

double HALSIM_GetCanTalonModeSelect(int32_t index) {
  return SimCanTalonData[index]->GetModeSelect();
}

void HALSIM_SetCanTalonModeSelect(int32_t index, double modeSelect) {
  SimCanTalonData[index]->SetModeSelect(modeSelect);
}

double HALSIM_GetCanTalonProfileSlotSelect(int32_t index) {
  return SimCanTalonData[index]->GetProfileSlotSelect();
}

void HALSIM_SetCanTalonProfileSlotSelect(int32_t index, double profileSlotSelect) {
  SimCanTalonData[index]->SetProfileSlotSelect(profileSlotSelect);
}

double HALSIM_GetCanTalonRampThrottle(int32_t index) {
  return SimCanTalonData[index]->GetRampThrottle();
}

void HALSIM_SetCanTalonRampThrottle(int32_t index, double rampThrottle) {
  SimCanTalonData[index]->SetRampThrottle(rampThrottle);
}

HAL_Bool HALSIM_GetCanTalonRevFeedbackSensor(int32_t index) {
  return SimCanTalonData[index]->GetRevFeedbackSensor();
}

void HALSIM_SetCanTalonRevFeedbackSensor(int32_t index, HAL_Bool revFeedbackSensor) {
  SimCanTalonData[index]->SetRevFeedbackSensor(revFeedbackSensor);
}

double HALSIM_GetCanTalonLimitSwitchEn(int32_t index) {
  return SimCanTalonData[index]->GetLimitSwitchEn();
}

void HALSIM_SetCanTalonLimitSwitchEn(int32_t index, double limitSwitchEn) {
  SimCanTalonData[index]->SetLimitSwitchEn(limitSwitchEn);
}

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedFor(int32_t index) {
  return SimCanTalonData[index]->GetLimitSwitchClosedFor();
}

void HALSIM_SetCanTalonLimitSwitchClosedFor(int32_t index, HAL_Bool limitSwitchClosedFor) {
  SimCanTalonData[index]->SetLimitSwitchClosedFor(limitSwitchClosedFor);
}

HAL_Bool HALSIM_GetCanTalonLimitSwitchClosedRev(int32_t index) {
  return SimCanTalonData[index]->GetLimitSwitchClosedRev();
}

void HALSIM_SetCanTalonLimitSwitchClosedRev(int32_t index, HAL_Bool limitSwitchClosedRev) {
  SimCanTalonData[index]->SetLimitSwitchClosedRev(limitSwitchClosedRev);
}

double HALSIM_GetCanTalonSensorPosition(int32_t index) {
  return SimCanTalonData[index]->GetSensorPosition();
}

void HALSIM_SetCanTalonSensorPosition(int32_t index, double sensorPosition) {
  SimCanTalonData[index]->SetSensorPosition(sensorPosition);
}

double HALSIM_GetCanTalonSensorVelocity(int32_t index) {
  return SimCanTalonData[index]->GetSensorVelocity();
}

void HALSIM_SetCanTalonSensorVelocity(int32_t index, double sensorVelocity) {
  SimCanTalonData[index]->SetSensorVelocity(sensorVelocity);
}

double HALSIM_GetCanTalonCurrent(int32_t index) {
  return SimCanTalonData[index]->GetCurrent();
}

void HALSIM_SetCanTalonCurrent(int32_t index, double current) {
  SimCanTalonData[index]->SetCurrent(current);
}

HAL_Bool HALSIM_GetCanTalonBrakeIsEnabled(int32_t index) {
  return SimCanTalonData[index]->GetBrakeIsEnabled();
}

void HALSIM_SetCanTalonBrakeIsEnabled(int32_t index, HAL_Bool brakeIsEnabled) {
  SimCanTalonData[index]->SetBrakeIsEnabled(brakeIsEnabled);
}

double HALSIM_GetCanTalonEncPosition(int32_t index) {
  return SimCanTalonData[index]->GetEncPosition();
}

void HALSIM_SetCanTalonEncPosition(int32_t index, double encPosition) {
  SimCanTalonData[index]->SetEncPosition(encPosition);
}

double HALSIM_GetCanTalonEncVel(int32_t index) {
  return SimCanTalonData[index]->GetEncVel();
}

void HALSIM_SetCanTalonEncVel(int32_t index, double encVel) {
  SimCanTalonData[index]->SetEncVel(encVel);
}

double HALSIM_GetCanTalonEncIndexRiseEvents(int32_t index) {
  return SimCanTalonData[index]->GetEncIndexRiseEvents();
}

void HALSIM_SetCanTalonEncIndexRiseEvents(int32_t index, double encIndexRiseEvents) {
  SimCanTalonData[index]->SetEncIndexRiseEvents(encIndexRiseEvents);
}

double HALSIM_GetCanTalonQuadApin(int32_t index) {
  return SimCanTalonData[index]->GetQuadApin();
}

void HALSIM_SetCanTalonQuadApin(int32_t index, double quadApin) {
  SimCanTalonData[index]->SetQuadApin(quadApin);
}

double HALSIM_GetCanTalonQuadBpin(int32_t index) {
  return SimCanTalonData[index]->GetQuadBpin();
}

void HALSIM_SetCanTalonQuadBpin(int32_t index, double quadBpin) {
  SimCanTalonData[index]->SetQuadBpin(quadBpin);
}

double HALSIM_GetCanTalonQuadIdxpin(int32_t index) {
  return SimCanTalonData[index]->GetQuadIdxpin();
}

void HALSIM_SetCanTalonQuadIdxpin(int32_t index, double quadIdxpin) {
  SimCanTalonData[index]->SetQuadIdxpin(quadIdxpin);
}

double HALSIM_GetCanTalonAnalogInWithOv(int32_t index) {
  return SimCanTalonData[index]->GetAnalogInWithOv();
}

void HALSIM_SetCanTalonAnalogInWithOv(int32_t index, double analogInWithOv) {
  SimCanTalonData[index]->SetAnalogInWithOv(analogInWithOv);
}

double HALSIM_GetCanTalonAnalogInVel(int32_t index) {
  return SimCanTalonData[index]->GetAnalogInVel();
}

void HALSIM_SetCanTalonAnalogInVel(int32_t index, double analogInVel) {
  SimCanTalonData[index]->SetAnalogInVel(analogInVel);
}

double HALSIM_GetCanTalonTemp(int32_t index) {
  return SimCanTalonData[index]->GetTemp();
}

void HALSIM_SetCanTalonTemp(int32_t index, double temp) {
  SimCanTalonData[index]->SetTemp(temp);
}

double HALSIM_GetCanTalonBatteryV(int32_t index) {
  return SimCanTalonData[index]->GetBatteryV();
}

void HALSIM_SetCanTalonBatteryV(int32_t index, double batteryV) {
  SimCanTalonData[index]->SetBatteryV(batteryV);
}

double HALSIM_GetCanTalonResetCount(int32_t index) {
  return SimCanTalonData[index]->GetResetCount();
}

void HALSIM_SetCanTalonResetCount(int32_t index, double resetCount) {
  SimCanTalonData[index]->SetResetCount(resetCount);
}

double HALSIM_GetCanTalonResetFlags(int32_t index) {
  return SimCanTalonData[index]->GetResetFlags();
}

void HALSIM_SetCanTalonResetFlags(int32_t index, double resetFlags) {
  SimCanTalonData[index]->SetResetFlags(resetFlags);
}

double HALSIM_GetCanTalonFirmVers(int32_t index) {
  return SimCanTalonData[index]->GetFirmVers();
}

void HALSIM_SetCanTalonFirmVers(int32_t index, double firmVers) {
  SimCanTalonData[index]->SetFirmVers(firmVers);
}

double HALSIM_GetCanTalonSettingsChanged(int32_t index) {
  return SimCanTalonData[index]->GetSettingsChanged();
}

void HALSIM_SetCanTalonSettingsChanged(int32_t index, double settingsChanged) {
  SimCanTalonData[index]->SetSettingsChanged(settingsChanged);
}

double HALSIM_GetCanTalonQuadFilterEn(int32_t index) {
  return SimCanTalonData[index]->GetQuadFilterEn();
}

void HALSIM_SetCanTalonQuadFilterEn(int32_t index, double quadFilterEn) {
  SimCanTalonData[index]->SetQuadFilterEn(quadFilterEn);
}

double HALSIM_GetCanTalonPidIaccum(int32_t index) {
  return SimCanTalonData[index]->GetPidIaccum();
}

void HALSIM_SetCanTalonPidIaccum(int32_t index, double pidIaccum) {
  SimCanTalonData[index]->SetPidIaccum(pidIaccum);
}

double HALSIM_GetCanTalonAinPosition(int32_t index) {
  return SimCanTalonData[index]->GetAinPosition();
}

void HALSIM_SetCanTalonAinPosition(int32_t index, double ainPosition) {
  SimCanTalonData[index]->SetAinPosition(ainPosition);
}

double HALSIM_GetCanTalonProfileParamSlot0_AllowableClosedLoopErr(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot0_AllowableClosedLoopErr();
}

void HALSIM_SetCanTalonProfileParamSlot0_AllowableClosedLoopErr(int32_t index, double profileParamSlot0_AllowableClosedLoopErr) {
  SimCanTalonData[index]->SetProfileParamSlot0_AllowableClosedLoopErr(profileParamSlot0_AllowableClosedLoopErr);
}

double HALSIM_GetCanTalonProfileParamSlot1_AllowableClosedLoopErr(int32_t index) {
  return SimCanTalonData[index]->GetProfileParamSlot1_AllowableClosedLoopErr();
}

void HALSIM_SetCanTalonProfileParamSlot1_AllowableClosedLoopErr(int32_t index, double profileParamSlot1_AllowableClosedLoopErr) {
  SimCanTalonData[index]->SetProfileParamSlot1_AllowableClosedLoopErr(profileParamSlot1_AllowableClosedLoopErr);
}

double HALSIM_GetCanTalonNumberEncoderCPR(int32_t index) {
  return SimCanTalonData[index]->GetNumberEncoderCPR();
}

void HALSIM_SetCanTalonNumberEncoderCPR(int32_t index, double numberEncoderCPR) {
  SimCanTalonData[index]->SetNumberEncoderCPR(numberEncoderCPR);
}

double HALSIM_GetCanTalonNumberPotTurns(int32_t index) {
  return SimCanTalonData[index]->GetNumberPotTurns();
}

void HALSIM_SetCanTalonNumberPotTurns(int32_t index, double numberPotTurns) {
  SimCanTalonData[index]->SetNumberPotTurns(numberPotTurns);
}

double HALSIM_GetCanTalonm_overrideLimitSwitch(int32_t index) {
  return SimCanTalonData[index]->Getm_overrideLimitSwitch();
}

void HALSIM_SetCanTalonm_overrideLimitSwitch(int32_t index, double m_overrideLimitSwitch) {
  SimCanTalonData[index]->Setm_overrideLimitSwitch(m_overrideLimitSwitch);
}

double HALSIM_GetCanTalonm_overrideBrakeType(int32_t index) {
  return SimCanTalonData[index]->Getm_overrideBrakeType();
}

void HALSIM_SetCanTalonm_overrideBrakeType(int32_t index, double m_overrideBrakeType) {
  SimCanTalonData[index]->Setm_overrideBrakeType(m_overrideBrakeType);
}

double HALSIM_GetCanTalonm_demand(int32_t index) {
  return SimCanTalonData[index]->Getm_demand();
}

void HALSIM_SetCanTalonm_demand(int32_t index, double m_demand) {
  SimCanTalonData[index]->Setm_demand(m_demand);
}

double HALSIM_GetCanTalonm_percentVBusValue(int32_t index) {
  return SimCanTalonData[index]->Getm_percentVBusValue();
}

void HALSIM_SetCanTalonm_percentVBusValue(int32_t index, double m_percentVBusValue) {
  SimCanTalonData[index]->Setm_percentVBusValue(m_percentVBusValue);
}

double HALSIM_GetCanTalonm_voltageCompensationRate(int32_t index) {
  return SimCanTalonData[index]->Getm_voltageCompensationRate();
}

void HALSIM_SetCanTalonm_voltageCompensationRate(int32_t index, double m_voltageCompensationRate) {
  SimCanTalonData[index]->Setm_voltageCompensationRate(m_voltageCompensationRate);
}

}
