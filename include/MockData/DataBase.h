#pragma once

#include "HALValue.h"

#define OnPropertyChanged(context) \
  OnPropertyChangedName((context), __func__)

namespace hal {
class DataBase {
 public:
  virtual void ResetData() = 0;
 protected:
  virtual void OnPropertyChangedName(HAL_Value* value, const char* propertyName);
};
}
