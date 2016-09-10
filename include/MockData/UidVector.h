#include <queue>
#include <vector>
#include <mutex>

namespace hal {
// Vector which provides an integrated freelist for removal and reuse of
// individual elements.
template <typename T>
class UidVector {
 public:
  typedef typename std::vector<T>::size_type size_type;

  size_type size() const { return m_vector.size(); }
  T& operator[](size_type i) { return m_vector[i]; }
  const T& operator[](size_type i) const { return m_vector[i]; }

  // Add a new T to the vector.  If there are elements on the freelist,
  // reuses the last one; otherwise adds to the end of the vector.
  // Returns the resulting element index (+1).
  template <class... Args>
  unsigned int emplace_back(Args&&... args) {
    unsigned int uid;
    if (m_free.empty()) {
      uid = m_vector.size();
      m_vector.emplace_back(std::forward<Args>(args)...);
    } else {
      uid = m_free.back();
      m_free.pop_back();
      m_vector[uid] = T(std::forward<Args>(args)...);
    }
    return uid + 1;
  }

  // Removes the identified element by replacing it with a default-constructed
  // one.  The element is added to the freelist for later reuse.
  void erase(unsigned int uid) {
    --uid;
    if (uid >= m_vector.size() || !m_vector[uid]) return;
    m_free.push_back(uid);
    m_vector[uid] = T();
  }

  void clear() {
    for (std::size_t i=0; i<m_vector.size(); ++i) {
      erase(i);
    }
  }

 private:
  std::vector<T> m_vector;
  std::vector<unsigned int> m_free;
};

}  // anonymous namespace