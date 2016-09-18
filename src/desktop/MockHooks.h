#pragma once

#include <stdint.h>

#include <chrono>

namespace hal {
void RestartTiming();

int64_t GetFPGATime();

double GetFPGATimestamp();

void SetProgramStarted();
}

extern "C" {
void HALSIM_WaitForProgramStart(void);
}