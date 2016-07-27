#include "MockData/NotifyDataBase.h"

using namespace hal;

void NotifyDataBase::Register(llvm::StringRef key, HAL_NotifyCallback callback, bool initialNotify) {
  OnPropertyChanged(nullptr);
}

void NotifyDataBase::Cancel(llvm::StringRef key, HAL_NotifyCallback callback) {
  
}
  
void NotifyDataBase::ResetData() {
  
}

void NotifyDataBase::OnPropertyChangedName(HAL_Value* value, const char* propertyName) {
  
}

void DataBase::OnPropertyChangedName(HAL_Value* value, const char* propertyName) {
  
}