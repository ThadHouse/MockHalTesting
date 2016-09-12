#pragma once

#include <memory>

#include "MockData/NotifyListenerVector.h"

std::shared_ptr<hal::NotifyListenerVector> RegisterCallback(std::shared_ptr<hal::NotifyListenerVector> currentVector, 
                                                       const char* name, HAL_NotifyCallback callback, 
                                                       void* param, int32_t* newUid);

std::shared_ptr<hal::NotifyListenerVector> CancelCallback(std::shared_ptr<hal::NotifyListenerVector> currentVector, int32_t uid);

void InvokeCallback(std::shared_ptr<hal::NotifyListenerVector> currentVector, const char* name, const HAL_Value* value);