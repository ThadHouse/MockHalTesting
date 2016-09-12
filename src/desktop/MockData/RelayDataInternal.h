#pragma once

#include <atomic>
#include <memory>

#include "MockData/RelayData.h"
#include "MockData/NotifyListenerVector.h"

namespace hal {
class RelayData {
 public:
  int32_t RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelInitializedCallback(int32_t uid);
  void InvokeInitializedCallback(HAL_Value value);
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  int32_t RegisterForwardCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelForwardCallback(int32_t uid);
  void InvokeForwardCallback(HAL_Value value);
  HAL_Bool GetForward();
  void SetForward(HAL_Bool forward);

  int32_t RegisterReverseCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  void CancelReverseCallback(int32_t uid);
  void InvokeReverseCallback(HAL_Value value);
  HAL_Bool GetReverse();
  void SetReverse(HAL_Bool reverse);

  virtual void ResetData();
 private:
  std::mutex m_registerMutex;
  std::atomic<HAL_Bool> m_initialized {false};
  std::shared_ptr<NotifyListenerVector> m_initializedCallbacks = nullptr;
  std::atomic<HAL_Bool> m_forward {false};
  std::shared_ptr<NotifyListenerVector> m_forwardCallbacks = nullptr;
  std::atomic<HAL_Bool> m_reverse {false};
  std::shared_ptr<NotifyListenerVector> m_reverseCallbacks = nullptr;
};
extern RelayData SimRelayData[];
}
