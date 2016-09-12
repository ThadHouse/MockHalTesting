/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/Relay.h"

#include "HAL/handles/IndexedHandleResource.h"
#include "PortsInternal.h"
#include "MockData/RelayDataInternal.h"

using namespace hal;

namespace {
struct Relay {
  uint8_t channel;
  bool fwd;
};
}

static IndexedHandleResource<HAL_RelayHandle, Relay, kNumRelayChannels,
                             HAL_HandleEnum::Relay>
    relayHandles;

extern "C" {
HAL_RelayHandle HAL_InitializeRelayPort(HAL_PortHandle portHandle, HAL_Bool fwd,
                                        int32_t* status) {
  if (*status != 0) return HAL_kInvalidHandle;

  int16_t channel = getPortHandleChannel(portHandle);
  if (channel == InvalidHandleIndex) {
    *status = PARAMETER_OUT_OF_RANGE;
    return HAL_kInvalidHandle;
  }

  if (!fwd) channel += kNumRelayHeaders;  // add 4 to reverse channels

  auto handle = relayHandles.Allocate(channel, status);

  if (*status != 0)
    return HAL_kInvalidHandle;  // failed to allocate. Pass error back.

  auto port = relayHandles.Get(handle);
  if (port == nullptr) {  // would only occur on thread issue.
    *status = HAL_HANDLE_ERROR;
    return HAL_kInvalidHandle;
  }

  if (!fwd) {
    // Subtract number of headers to put channel in range
    channel -= kNumRelayHeaders;

    port->fwd = false;  // set to reverse
  } else {
    port->fwd = true;  // set to forward
  }

  port->channel = static_cast<uint8_t>(channel);

  SimRelayData[channel].SetInitialized(true);
  return handle;
}

void HAL_FreeRelayPort(HAL_RelayHandle relayPortHandle) {
  auto port = relayHandles.Get(relayPortHandle);
  relayHandles.Free(relayPortHandle);
  if (port == nullptr) return;
  SimRelayData[port->channel].SetInitialized(false);
}

HAL_Bool HAL_CheckRelayChannel(int32_t channel) {
  // roboRIO only has 4 headers, and the FPGA has
  // seperate functions for forward and reverse,
  // instead of seperate channel IDs
  return channel < kNumRelayHeaders && channel >= 0;
}


}