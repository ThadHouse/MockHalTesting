#include "HAL/AnalogAccumulator.h"

#include "AnalogInternal.h"
#include "MockData/AnalogInDataInternal.h"

using namespace hal;

extern "C" {
HAL_Bool HAL_IsAccumulatorChannel(HAL_AnalogInputHandle analogPortHandle,
                                  int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return false;
  }
  for (int32_t i = 0; i < kNumAccumulators; i++) {
    if (port->channel == kAccumulatorChannels[i]) return true;
  }
  return false;
}
void HAL_InitAccumulator(HAL_AnalogInputHandle analogPortHandle,
                         int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  if (!HAL_IsAccumulatorChannel(analogPortHandle, status)) {
    *status = HAL_INVALID_ACCUMULATOR_CHANNEL;
    return;
  }

  SimAnalogInData[port->channel].SetAccumulatorInitialized(true);
}
void HAL_ResetAccumulator(HAL_AnalogInputHandle analogPortHandle,
                          int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  SimAnalogInData[port->channel].SetAccumulatorCenter(0);
  SimAnalogInData[port->channel].SetAccumulatorCount(0);
  SimAnalogInData[port->channel].SetAccumulatorValue(0);
}
void HAL_SetAccumulatorCenter(HAL_AnalogInputHandle analogPortHandle,
                              int32_t center, int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  SimAnalogInData[port->channel].SetAccumulatorCenter(center);
}
void HAL_SetAccumulatorDeadband(HAL_AnalogInputHandle analogPortHandle,
                                int32_t deadband, int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  SimAnalogInData[port->channel].SetAccumulatorDeadband(deadband);
}
int64_t HAL_GetAccumulatorValue(HAL_AnalogInputHandle analogPortHandle,
                                int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return SimAnalogInData[port->channel].GetAccumulatorValue();
}
int64_t HAL_GetAccumulatorCount(HAL_AnalogInputHandle analogPortHandle,
                                int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return SimAnalogInData[port->channel].GetAccumulatorCount();
}
void HAL_GetAccumulatorOutput(HAL_AnalogInputHandle analogPortHandle,
                              int64_t* value, int64_t* count, int32_t* status) {
  auto port = analogInputHandles.Get(analogPortHandle);
  if (port == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  *count = SimAnalogInData[port->channel].GetAccumulatorCount();
  *value = SimAnalogInData[port->channel].GetAccumulatorValue();
}
}