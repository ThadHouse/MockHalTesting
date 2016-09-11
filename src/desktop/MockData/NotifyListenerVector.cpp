#include "MockData/NotifyListenerVector.h"

using namespace hal;

unsigned int NotifyListenerVector::emplace_back(void* param, HAL_NotifyCallback callback) {
  unsigned int uid;
  if (m_free.empty()) {
    uid = m_vector.size();
    m_vector.emplace_back(param, callback);
  } else {
    uid = m_free.back();
    m_free.pop_back();
    m_vector[uid] = NotifyListener(param, callback);
  }
  return uid + 1;
}

void NotifyListenerVector::erase(unsigned int uid) {
  --uid;
  if (uid >= m_vector.size() || !m_vector[uid]) return;
  m_free.push_back(uid);
  m_vector[uid] = NotifyListener();
}