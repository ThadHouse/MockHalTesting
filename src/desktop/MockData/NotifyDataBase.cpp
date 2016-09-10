#include "MockData/NotifyDataBase.h"

using namespace hal;

int NotifyDataBase::Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify) {
  int uid = m_notify_listeners.emplace_back(key, callback);
  // TODO: Implement Initial Notify
  return uid;
}

void NotifyDataBase::Cancel(llvm::StringRef key, int callbackId) {
  m_notify_listeners.erase(callbackId);
}
  
void NotifyDataBase::ResetData() {
  m_notify_listeners.clear();
}

void NotifyDataBase::OnPropertyChangedName(const HAL_Value* value, const char* propertyName) {
  // TODO: Determine if we need locking

  llvm::StringRef name(propertyName);
  // Use index because iterator might get invalidated.
  for (std::size_t i=0; i<m_notify_listeners.size(); ++i) {
    if (!m_notify_listeners[i]) continue; // removed

    // must match key
    if (!name.equals(m_notify_listeners[i].key)) continue;

    auto callback = m_notify_listeners[i].callback;

    callback(propertyName, value);
  }
}