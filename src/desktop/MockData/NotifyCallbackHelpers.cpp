#include "NotifyCallbackHelpers.h"

using namespace hal;

std::shared_ptr<NotifyListenerVector> RegisterCallback(std::shared_ptr<NotifyListenerVector> currentVector, const char* name, HAL_NotifyCallback callback, void* param, const HAL_Value* value, int32_t* newUid) {
  if (callback == nullptr) {
    *newUid = -1;
    return nullptr;
  }
  auto newCallbacks = std::make_shared<NotifyListenerVector>(*currentVector);
  *newUid = newCallbacks->emplace_back(param, callback);
  if (value != nullptr) {
    callback(name, param, value);
  }
  return newCallbacks;
}

std::shared_ptr<NotifyListenerVector> CancelCallback(std::shared_ptr<NotifyListenerVector> currentVector, int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<NotifyListenerVector>(*currentVector);
  newCallbacks->erase(uid);
  return newCallbacks;
}

void InvokeCallback(std::shared_ptr<NotifyListenerVector> currentVector, const char* name, const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (currentVector == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = currentVector;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback(name, listener.param, value);
  }
}