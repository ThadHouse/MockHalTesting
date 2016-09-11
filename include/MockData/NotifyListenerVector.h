#pragma once

#include <queue>
#include <vector>
#include <mutex>

#include "NotifyListener.h"

namespace hal {
// Vector which provides an integrated freelist for removal and reuse of
// individual elements.
class NotifyListenerVector {
 public:
  typedef typename std::vector<NotifyListener>::size_type size_type;

  size_type size() const { return m_vector.size(); }
  NotifyListener& operator[](size_type i) { return m_vector[i]; }
  const NotifyListener& operator[](size_type i) const { return m_vector[i]; }

  // Add a new NotifyListener to the vector.  If there are elements on the freelist,
  // reuses the last one; otherwise adds to the end of the vector.
  // Returns the resulting element index (+1).
  unsigned int emplace_back(void* param, HAL_NotifyCallback callback);

  // Removes the identified element by replacing it with a default-constructed
  // one.  The element is added to the freelist for later reuse.
  void erase(unsigned int uid);

 private:
  std::vector<NotifyListener> m_vector;
  std::vector<unsigned int> m_free;
};

}  // namespace hal