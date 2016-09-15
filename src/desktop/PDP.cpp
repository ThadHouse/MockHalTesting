#pragma once

#include "HAL/PDP.h"

#include "MockData/PDPDataInternal.h"
#include "PortsInternal.h"

using namespace hal;

extern "C" {
void HAL_InitializePDP(int32_t module, int32_t* status) {
  SimPDPData[module].SetInitialized(true);
}
HAL_Bool HAL_CheckPDPModule(int32_t module) {
  return module < kNumPDPModules && module >= 0;
}

HAL_Bool HAL_CheckPDPChannel(int32_t channel) {
  return channel < kNumPDPChannels && channel >= 0;
}
double HAL_GetPDPTemperature(int32_t module, int32_t* status) {
  return SimPDPData[module].GetTemperature();
}
double HAL_GetPDPVoltage(int32_t module, int32_t* status) {
  return SimPDPData[module].GetVoltage();
}
double HAL_GetPDPChannelCurrent(int32_t module, int32_t channel,
                                int32_t* status) {
  return SimPDPData[module].GetCurrent(channel);
}
double HAL_GetPDPTotalCurrent(int32_t module, int32_t* status) {
  return 0.0;
}
double HAL_GetPDPTotalPower(int32_t module, int32_t* status) {
  return 0.0;
}
double HAL_GetPDPTotalEnergy(int32_t module, int32_t* status) {
  return 0.0;
}
void HAL_ResetPDPTotalEnergy(int32_t module, int32_t* status) {
  
}
void HAL_ClearPDPStickyFaults(int32_t module, int32_t* status) {

}
}