#include "MockHooks.h"

#include <chrono>
#include <atomic>
#include <cstdio>
#include <thread>
#include "support/timestamp.h"

static std::atomic<bool> programStarted {false};

static std::atomic<uint64_t> programStartTime {wpi::Now() / 10};

namespace hal {
void RestartTiming() {
  programStartTime = wpi::Now() / 10;
}

int64_t GetFPGATime() {
  auto now = wpi::Now() / 10;
  auto currentTime = now - programStartTime;
  return currentTime; 
}

double GetFPGATimestamp() {
  auto now = wpi::Now() / 10;
  auto currentTime = now - programStartTime;
  return currentTime * 1.0e-6;
}

void SetProgramStarted() {
  programStarted = true;
}
}

extern "C" {
void HALSIM_WaitForProgramStart(void) {
  using namespace std::chrono_literals;
  int count = 0;
  while (!programStarted) {
    count++;
    std::printf("Waiting for program start signal: %d\n", count);
    std::this_thread::sleep_for(500ms);
  }
}
}