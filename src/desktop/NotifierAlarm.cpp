#include "NotifierAlarm.h"

#include "MockHooks.h"

namespace hal {
NotifierAlarm::NotifierAlarm(NotifierAlarmCallback callback) {
  m_callback = callback;

  m_thread = std::thread(&NotifierAlarm::RunThread, this);
}

NotifierAlarm::~NotifierAlarm() {
  m_continue = false;
  m_enabled = true;
  m_thread.join();
}

void NotifierAlarm::RunThread() {
  while (true) {
    while (!m_enabled) std::this_thread::yield();
    if (!m_continue) return;

    uint64_t triggerTime = m_triggerTime;
    // TODO: Figure out timing
    while (triggerTime > GetFPGATime()) {
      triggerTime = m_triggerTime;
      if (!m_continue) return;
    }
    bool enabled =  m_enabled.exchange(false);
    if (enabled) {
      if (m_callback) m_callback();
    }
  }
}

void NotifierAlarm::EnableAlarm() {
  m_enabled = true;
}

void NotifierAlarm::DisableAlarm() {
  m_enabled = false;
}

void NotifierAlarm::WriteTriggerTime(uint64_t triggerTime) {
  m_triggerTime = triggerTime;
}
}
