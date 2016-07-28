#pragma once

#include <atomic>
#include <memory>

#include "MockData/RelayData.h"
#include "MockData/NotifyDataBase.h"

namespace hal {
class RelayData : NotifyDataBase {
 public:
  HAL_Bool GetInitialized();
  void SetInitialized(HAL_Bool initialized);

  HAL_Bool GetForward();
  void SetForward(HAL_Bool forward);

  HAL_Bool GetReverse();
  void SetReverse(HAL_Bool reverse);

  virtual void ResetData() override;
 private:
  std::atomic<HAL_Bool> m_initialized = false;
  std::atomic<HAL_Bool> m_forward = false;
  std::atomic<HAL_Bool> m_reverse = false;
};
extern std::unique_ptr<std::shared_ptr<RelayData>[]> SimRelayData;
}
