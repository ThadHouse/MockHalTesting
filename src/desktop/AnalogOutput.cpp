#include "HAL/AnalogOutput.h"

#include "HAL/Errors.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/IndexedHandleResource.h"
#include "PortsInternal.h"
#include "MockData/AnalogOutDataInternal.h"

using namespace hal;

namespace {
struct AnalogOutput {
  uint8_t channel;
};
}

static IndexedHandleResource<HAL_AnalogOutputHandle, AnalogOutput,
                             kNumAnalogOutputs, HAL_HandleEnum::AnalogOutput>
    analogOutputHandles;

extern "C" {
HAL_AnalogOutputHandle HAL_InitializeAnalogOutputPort(HAL_PortHandle portHandle, int32_t* status) {
  int16_t channel = getPortHandleChannel(portHandle);
  if (channel == InvalidHandleIndex) {
    *status = PARAMETER_OUT_OF_RANGE;
    return HAL_kInvalidHandle;
  }

  HAL_AnalogOutputHandle handle = analogOutputHandles.Allocate(channel, status);

  if (*status != 0)
    return HAL_kInvalidHandle;  // failed to allocate. Pass error back.

  auto port = analogOutputHandles.Get(handle);
  if (port == nullptr) {  // would only error on thread issue
    *status = HAL_HANDLE_ERROR;
    return HAL_kInvalidHandle;
  }

  port->channel = static_cast<uint8_t>(channel);

  // Initialize sim analog input
  SimAnalogOutData[channel].SetInitialized(true);
  return handle;
}

void HAL_FreeAnalogOutputPort(HAL_AnalogOutputHandle analogOutputHandle) {
  // no status, so no need to check for a proper free.
  auto port = analogOutputHandles.Get(analogOutputHandle);
  if (port == nullptr) return;
  analogOutputHandles.Free(analogOutputHandle);
  SimAnalogOutData[port->channel].SetInitialized(false);
}

HAL_Bool HAL_CheckAnalogOutputChannel(int32_t channel) {
  return channel < kNumAnalogOutputs && channel >= 0;
}

void HAL_SetAnalogOutput(HAL_AnalogOutputHandle analogOutputHandle,
                         double voltage, int32_t* status) {
  auto port = analogOutputHandles.Get(analogOutputHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  SimAnalogOutData[port->channel].SetVoltage(voltage);
}

double HAL_GetAnalogOutput(HAL_AnalogOutputHandle analogOutputHandle,
                           int32_t* status) {
  auto port = analogOutputHandles.Get(analogOutputHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0.0;
  }

  return SimAnalogOutData[port->channel].GetVoltage();
}
}
