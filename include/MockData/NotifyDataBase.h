#pragma once

#include "DataBase.h"
#include "UidVector.h"

typedef void (*HAL_NotifyCallback)(const char* name, void* param, const struct HAL_Value *value);

namespace hal {
struct NotifyListener {
    NotifyListener() = default;
    NotifyListener(llvm::StringRef key_, void* param_, HAL_NotifyCallback callback_) 
    : key(key_), callback(callback_), param(param_) {}

    explicit operator bool() const { return bool(callback); }

    std::string key;
    HAL_NotifyCallback callback;
    void* param;
  };


class NotifyDataBase : DataBase {
 public:
  int Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify = false);
  void Cancel(llvm::StringRef key, int callbackId);
  
  virtual void ResetData() override;
  
 protected:
  virtual void OnPropertyChangedName(const HAL_Value* value, const char* propertyName);
  
 private:
  

  UidVector<NotifyListener> m_notify_listeners;
};



}