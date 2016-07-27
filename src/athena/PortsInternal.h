/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <stdint.h>

#include "ChipObject.h"

namespace hal {
constexpr int32_t kNumAccumulators = tAccumulator::kNumSystems;
constexpr int32_t kNumAnalogTriggers = tAnalogTrigger::kNumSystems;
constexpr int32_t kNumAnalogInputs = 8;
constexpr int32_t kNumAnalogOutputs = tAO::kNumMXPRegisters;
constexpr int32_t kNumCounters = tCounter::kNumSystems;
constexpr int32_t kNumDigitalHeaders = 10;
constexpr int32_t kNumPWMHeaders = tPWM::kNumHdrRegisters;
constexpr int32_t kNumDigitalPins = 26;
constexpr int32_t kNumPWMPins = tPWM::kNumMXPRegisters + kNumPWMHeaders;
constexpr int32_t kNumDigitalPWMOutputs =
    tDIO::kNumPWMDutyCycleAElements + tDIO::kNumPWMDutyCycleBElements;
constexpr int32_t kNumEncoders = tEncoder::kNumSystems;
constexpr int32_t kNumInterrupts = tInterrupt::kNumSystems;
constexpr int32_t kNumRelayPins = 8;
constexpr int32_t kNumRelayHeaders = kNumRelayPins / 2;
constexpr int32_t kNumPCMModules = 63;
constexpr int32_t kNumSolenoidPins = 8;
constexpr int32_t kNumPDPModules = 63;
constexpr int32_t kNumPDPChannels = 16;
constexpr int32_t kNumCanTalons = 63;
}  // namespace hal
