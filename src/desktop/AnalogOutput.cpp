#include "HAL/AnalogOutput.h"

#include "HAL/Errors.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/IndexedHandleResource.h"
#include "PortsInternal.h"

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
  return handle;
}
}
