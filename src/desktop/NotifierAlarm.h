#include <atomic>
#include <thread>

typedef void (*NotifierAlarmCallback)();

namespace hal {
class NotifierAlarm {
 public:
  NotifierAlarm(NotifierAlarm const&) = delete;
  NotifierAlarm& operator=(NotifierAlarm const&) = delete;

  NotifierAlarm(NotifierAlarmCallback callback);
  ~NotifierAlarm();

  void EnableAlarm();

  void DisableAlarm();

  void WriteTriggerTime(uint64_t triggerTime); 

 private:
  void RunThread();
  std::atomic<uint64_t> m_triggerTime {0};
  std::atomic<bool> m_enabled {false};
  std::atomic<bool> m_continue {true};
  NotifierAlarmCallback m_callback;
  std::thread m_thread;
};
}