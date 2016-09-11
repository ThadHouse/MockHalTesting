#pragma once

#include "HAL_Value.h"

#include <memory>

namespace hal {
class DataBase {
 public:
  virtual void ResetData() = 0;
 protected:
};
}
