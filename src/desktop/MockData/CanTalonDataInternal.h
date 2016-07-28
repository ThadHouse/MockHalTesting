#pragma once

#include <atomic>
#include <memory>

#include "MockData/CanTalonData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class CanTalonData : NotifyDataBase {
 public:
  double GetProfileParamSlot0_P();
  void SetProfileParamSlot0_P(double profileParamSlot0_P);

  double GetProfileParamSlot0_I();
  void SetProfileParamSlot0_I(double profileParamSlot0_I);

  double GetProfileParamSlot0_D();
  void SetProfileParamSlot0_D(double profileParamSlot0_D);

  double GetProfileParamSlot0_F();
  void SetProfileParamSlot0_F(double profileParamSlot0_F);

  int32_t GetProfileParamSlot0_IZone();
  void SetProfileParamSlot0_IZone(int32_t profileParamSlot0_IZone);

  int32_t GetProfileParamSlot0_CloseLoopRampRate();
  void SetProfileParamSlot0_CloseLoopRampRate(int32_t profileParamSlot0_CloseLoopRampRate);

  double GetProfileParamSlot1_P();
  void SetProfileParamSlot1_P(double profileParamSlot1_P);

  double GetProfileParamSlot1_I();
  void SetProfileParamSlot1_I(double profileParamSlot1_I);

  double GetProfileParamSlot1_D();
  void SetProfileParamSlot1_D(double profileParamSlot1_D);

  double GetProfileParamSlot1_F();
  void SetProfileParamSlot1_F(double profileParamSlot1_F);

  int32_t GetProfileParamSlot1_IZone();
  void SetProfileParamSlot1_IZone(int32_t profileParamSlot1_IZone);

  int32_t GetProfileParamSlot1_CloseLoopRampRate();
  void SetProfileParamSlot1_CloseLoopRampRate(int32_t profileParamSlot1_CloseLoopRampRate);

  double GetProfileParamSoftLimitForThreshold();
  void SetProfileParamSoftLimitForThreshold(double profileParamSoftLimitForThreshold);

  double GetProfileParamSoftLimitRevThreshold();
  void SetProfileParamSoftLimitRevThreshold(double profileParamSoftLimitRevThreshold);

  double GetProfileParamSoftLimitForEnable();
  void SetProfileParamSoftLimitForEnable(double profileParamSoftLimitForEnable);

  double GetProfileParamSoftLimitRevEnable();
  void SetProfileParamSoftLimitRevEnable(double profileParamSoftLimitRevEnable);

  double GetOnBoot_BrakeMode();
  void SetOnBoot_BrakeMode(double onBoot_BrakeMode);

  double GetOnBoot_LimitSwitch_Forward_NormallyClosed();
  void SetOnBoot_LimitSwitch_Forward_NormallyClosed(double onBoot_LimitSwitch_Forward_NormallyClosed);

  double GetOnBoot_LimitSwitch_Reverse_NormallyClosed();
  void SetOnBoot_LimitSwitch_Reverse_NormallyClosed(double onBoot_LimitSwitch_Reverse_NormallyClosed);

  double GetOnBoot_LimitSwitch_Forward_Disable();
  void SetOnBoot_LimitSwitch_Forward_Disable(double onBoot_LimitSwitch_Forward_Disable);

  double GetOnBoot_LimitSwitch_Reverse_Disable();
  void SetOnBoot_LimitSwitch_Reverse_Disable(double onBoot_LimitSwitch_Reverse_Disable);

  double GetFault_OverTemp();
  void SetFault_OverTemp(double fault_OverTemp);

  double GetFault_UnderVoltage();
  void SetFault_UnderVoltage(double fault_UnderVoltage);

  double GetFault_ForLim();
  void SetFault_ForLim(double fault_ForLim);

  double GetFault_RevLim();
  void SetFault_RevLim(double fault_RevLim);

  double GetFault_HardwareFailure();
  void SetFault_HardwareFailure(double fault_HardwareFailure);

  double GetFault_ForSoftLim();
  void SetFault_ForSoftLim(double fault_ForSoftLim);

  double GetFault_RevSoftLim();
  void SetFault_RevSoftLim(double fault_RevSoftLim);

  double GetStckyFault_OverTemp();
  void SetStckyFault_OverTemp(double stckyFault_OverTemp);

  double GetStckyFault_UnderVoltage();
  void SetStckyFault_UnderVoltage(double stckyFault_UnderVoltage);

  double GetStckyFault_ForLim();
  void SetStckyFault_ForLim(double stckyFault_ForLim);

  double GetStckyFault_RevLim();
  void SetStckyFault_RevLim(double stckyFault_RevLim);

  double GetStckyFault_ForSoftLim();
  void SetStckyFault_ForSoftLim(double stckyFault_ForSoftLim);

  double GetStckyFault_RevSoftLim();
  void SetStckyFault_RevSoftLim(double stckyFault_RevSoftLim);

  double GetAppliedThrottle();
  void SetAppliedThrottle(double appliedThrottle);

  double GetCloseLoopErr();
  void SetCloseLoopErr(double closeLoopErr);

  double GetFeedbackDeviceSelect();
  void SetFeedbackDeviceSelect(double feedbackDeviceSelect);

  HAL_Bool GetRevMotDuringCloseLoopEn();
  void SetRevMotDuringCloseLoopEn(HAL_Bool revMotDuringCloseLoopEn);

  double GetModeSelect();
  void SetModeSelect(double modeSelect);

  double GetProfileSlotSelect();
  void SetProfileSlotSelect(double profileSlotSelect);

  double GetRampThrottle();
  void SetRampThrottle(double rampThrottle);

  HAL_Bool GetRevFeedbackSensor();
  void SetRevFeedbackSensor(HAL_Bool revFeedbackSensor);

  double GetLimitSwitchEn();
  void SetLimitSwitchEn(double limitSwitchEn);

  HAL_Bool GetLimitSwitchClosedFor();
  void SetLimitSwitchClosedFor(HAL_Bool limitSwitchClosedFor);

  HAL_Bool GetLimitSwitchClosedRev();
  void SetLimitSwitchClosedRev(HAL_Bool limitSwitchClosedRev);

  double GetSensorPosition();
  void SetSensorPosition(double sensorPosition);

  double GetSensorVelocity();
  void SetSensorVelocity(double sensorVelocity);

  double GetCurrent();
  void SetCurrent(double current);

  HAL_Bool GetBrakeIsEnabled();
  void SetBrakeIsEnabled(HAL_Bool brakeIsEnabled);

  double GetEncPosition();
  void SetEncPosition(double encPosition);

  double GetEncVel();
  void SetEncVel(double encVel);

  double GetEncIndexRiseEvents();
  void SetEncIndexRiseEvents(double encIndexRiseEvents);

  double GetQuadApin();
  void SetQuadApin(double quadApin);

  double GetQuadBpin();
  void SetQuadBpin(double quadBpin);

  double GetQuadIdxpin();
  void SetQuadIdxpin(double quadIdxpin);

  double GetAnalogInWithOv();
  void SetAnalogInWithOv(double analogInWithOv);

  double GetAnalogInVel();
  void SetAnalogInVel(double analogInVel);

  double GetTemp();
  void SetTemp(double temp);

  double GetBatteryV();
  void SetBatteryV(double batteryV);

  double GetResetCount();
  void SetResetCount(double resetCount);

  double GetResetFlags();
  void SetResetFlags(double resetFlags);

  double GetFirmVers();
  void SetFirmVers(double firmVers);

  double GetSettingsChanged();
  void SetSettingsChanged(double settingsChanged);

  double GetQuadFilterEn();
  void SetQuadFilterEn(double quadFilterEn);

  double GetPidIaccum();
  void SetPidIaccum(double pidIaccum);

  double GetAinPosition();
  void SetAinPosition(double ainPosition);

  double GetProfileParamSlot0_AllowableClosedLoopErr();
  void SetProfileParamSlot0_AllowableClosedLoopErr(double profileParamSlot0_AllowableClosedLoopErr);

  double GetProfileParamSlot1_AllowableClosedLoopErr();
  void SetProfileParamSlot1_AllowableClosedLoopErr(double profileParamSlot1_AllowableClosedLoopErr);

  double GetNumberEncoderCPR();
  void SetNumberEncoderCPR(double numberEncoderCPR);

  double GetNumberPotTurns();
  void SetNumberPotTurns(double numberPotTurns);

  double Getm_overrideLimitSwitch();
  void Setm_overrideLimitSwitch(double m_overrideLimitSwitch);

  double Getm_overrideBrakeType();
  void Setm_overrideBrakeType(double m_overrideBrakeType);

  double Getm_demand();
  void Setm_demand(double m_demand);

  double Getm_percentVBusValue();
  void Setm_percentVBusValue(double m_percentVBusValue);

  double Getm_voltageCompensationRate();
  void Setm_voltageCompensationRate(double m_voltageCompensationRate);

  virtual void ResetData() override;
 private:
  std::atomic<double> m_profileParamSlot0_P = 0.0;
  std::atomic<double> m_profileParamSlot0_I = 0.0;
  std::atomic<double> m_profileParamSlot0_D = 0.0;
  std::atomic<double> m_profileParamSlot0_F = 0.0;
  std::atomic<int32_t> m_profileParamSlot0_IZone = 0;
  std::atomic<int32_t> m_profileParamSlot0_CloseLoopRampRate = 0;
  std::atomic<double> m_profileParamSlot1_P = 0.0;
  std::atomic<double> m_profileParamSlot1_I = 0.0;
  std::atomic<double> m_profileParamSlot1_D = 0.0;
  std::atomic<double> m_profileParamSlot1_F = 0.0;
  std::atomic<int32_t> m_profileParamSlot1_IZone = 0;
  std::atomic<int32_t> m_profileParamSlot1_CloseLoopRampRate = 0;
  std::atomic<double> m_profileParamSoftLimitForThreshold = 0.0;
  std::atomic<double> m_profileParamSoftLimitRevThreshold = 0.0;
  std::atomic<double> m_profileParamSoftLimitForEnable = 0.0;
  std::atomic<double> m_profileParamSoftLimitRevEnable = 0.0;
  std::atomic<double> m_onBoot_BrakeMode = 0.0;
  std::atomic<double> m_onBoot_LimitSwitch_Forward_NormallyClosed = 0.0;
  std::atomic<double> m_onBoot_LimitSwitch_Reverse_NormallyClosed = 0.0;
  std::atomic<double> m_onBoot_LimitSwitch_Forward_Disable = 0.0;
  std::atomic<double> m_onBoot_LimitSwitch_Reverse_Disable = 0.0;
  std::atomic<double> m_fault_OverTemp = 0.0;
  std::atomic<double> m_fault_UnderVoltage = 0.0;
  std::atomic<double> m_fault_ForLim = 0.0;
  std::atomic<double> m_fault_RevLim = 0.0;
  std::atomic<double> m_fault_HardwareFailure = 0.0;
  std::atomic<double> m_fault_ForSoftLim = 0.0;
  std::atomic<double> m_fault_RevSoftLim = 0.0;
  std::atomic<double> m_stckyFault_OverTemp = 0.0;
  std::atomic<double> m_stckyFault_UnderVoltage = 0.0;
  std::atomic<double> m_stckyFault_ForLim = 0.0;
  std::atomic<double> m_stckyFault_RevLim = 0.0;
  std::atomic<double> m_stckyFault_ForSoftLim = 0.0;
  std::atomic<double> m_stckyFault_RevSoftLim = 0.0;
  std::atomic<double> m_appliedThrottle = 0.0;
  std::atomic<double> m_closeLoopErr = 0.0;
  std::atomic<double> m_feedbackDeviceSelect = 0.0;
  std::atomic<HAL_Bool> m_revMotDuringCloseLoopEn = false;
  std::atomic<double> m_modeSelect = 0.0;
  std::atomic<double> m_profileSlotSelect = 0.0;
  std::atomic<double> m_rampThrottle = 0.0;
  std::atomic<HAL_Bool> m_revFeedbackSensor = false;
  std::atomic<double> m_limitSwitchEn = 0.0;
  std::atomic<HAL_Bool> m_limitSwitchClosedFor = false;
  std::atomic<HAL_Bool> m_limitSwitchClosedRev = false;
  std::atomic<double> m_sensorPosition = 0.0;
  std::atomic<double> m_sensorVelocity = 0.0;
  std::atomic<double> m_current = 0.0;
  std::atomic<HAL_Bool> m_brakeIsEnabled = false;
  std::atomic<double> m_encPosition = 0.0;
  std::atomic<double> m_encVel = 0.0;
  std::atomic<double> m_encIndexRiseEvents = 0.0;
  std::atomic<double> m_quadApin = 0.0;
  std::atomic<double> m_quadBpin = 0.0;
  std::atomic<double> m_quadIdxpin = 0.0;
  std::atomic<double> m_analogInWithOv = 0.0;
  std::atomic<double> m_analogInVel = 0.0;
  std::atomic<double> m_temp = 0.0;
  std::atomic<double> m_batteryV = 0.0;
  std::atomic<double> m_resetCount = 0.0;
  std::atomic<double> m_resetFlags = 0.0;
  std::atomic<double> m_firmVers = 0.0;
  std::atomic<double> m_settingsChanged = 0.0;
  std::atomic<double> m_quadFilterEn = 0.0;
  std::atomic<double> m_pidIaccum = 0.0;
  std::atomic<double> m_ainPosition = 0.0;
  std::atomic<double> m_profileParamSlot0_AllowableClosedLoopErr = 0.0;
  std::atomic<double> m_profileParamSlot1_AllowableClosedLoopErr = 0.0;
  std::atomic<double> m_numberEncoderCPR = 0.0;
  std::atomic<double> m_numberPotTurns = 0.0;
  std::atomic<double> m_m_overrideLimitSwitch = 0.0;
  std::atomic<double> m_m_overrideBrakeType = 0.0;
  std::atomic<double> m_m_demand = 0.0;
  std::atomic<double> m_m_percentVBusValue = 0.0;
  std::atomic<double> m_m_voltageCompensationRate = 0.0;
};
extern std::unique_ptr<std::shared_ptr<CanTalonData>[]> SimCanTalonData;
}
