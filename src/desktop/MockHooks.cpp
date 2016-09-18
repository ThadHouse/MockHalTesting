#include "MockHooks.h"

#include <chrono>
#include <atomic>
#include <cstdio>
#include <thread>

static std::atomic<bool> programStarted {false};

static std::atomic<std::chrono::steady_clock::time_point> programStartTime {std::chrono::steady_clock::now()};

namespace hal {
void RestartTiming() {
  programStartTime = std::chrono::steady_clock::now();
}

int64_t GetFPGATime() {
  std::chrono::steady_clock::time_point start = programStartTime;
  std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(current - start).count();
}

double GetFPGATimestamp() {
  std::chrono::steady_clock::time_point start = programStartTime;
  std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::duration<double>>(current - start).count();
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