#pragma once

#include "DataBase.h"
#include "UidVector.h"

typedef void (*HAL_NotifyCallback)(const char* name, const struct HAL_Value *value);

namespace hal {
class NotifyDataBase : DataBase {
 public:
  int Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify = false);
  void Cancel(llvm::StringRef key, int callbackId);
  
  virtual void ResetData() override;
  
 protected:
  virtual void OnPropertyChangedName(const HAL_Value* value, const char* propertyName) override;
  
 private:
  struct NotifyListener {
    NotifyListener() = default;
    NotifyListener(llvm::StringRef key_, HAL_NotifyCallback callback_) : key(key_), callback(callback_) {}

    explicit operator bool() const { return bool(callback); }

    std::string key;
    HAL_NotifyCallback callback;
  };

  UidVector<NotifyListener> m_notify_listeners;
};
}