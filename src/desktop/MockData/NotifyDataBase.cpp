#include "MockData/NotifyDataBase.h"

using namespace hal;

int NotifyDataBase::Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify) {
  return 0;
}

void NotifyDataBase::Cancel(llvm::StringRef key, int callbackId) {
  
}
  
void NotifyDataBase::ResetData() {
  
}

void NotifyDataBase::OnPropertyChangedName(HAL_Value* value, const char* propertyName) {
  
}