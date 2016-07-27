#pragma once

#include "DataBase.h"

typedef void (*HAL_NotifyCallback)(const char* name, int32_t nameLen, const struct HAL_Value *value);

namespace hal {
class NotifyDataBase : DataBase {
 public:
  void Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify = false);
  void Cancel(llvm::StringRef key, HAL_NotifyCallback callback);
  
  virtual void ResetData() override;
  
 protected:
  virtual void OnPropertyChangedName(HAL_Value* value, const char* propertyName) override;
};
}