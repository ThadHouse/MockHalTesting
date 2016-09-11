#include "AccelerometerDataInternal.h"

#include "../PortsInternal.h"

using namespace hal;

std::unique_ptr<std::shared_ptr<AccelerometerData>[]> hal::SimAccelerometerData = std::make_unique<std::shared_ptr<AccelerometerData>[]>(1);
void AccelerometerData::ResetData() {
  m_active = false;
  m_activeCallbacks = nullptr;
  m_range = (HAL_AccelerometerRange)0;
  m_rangeCallbacks = nullptr;
  m_x = 0.0;
  m_xCallbacks = nullptr;
  m_y = 0.0;
  m_yCallbacks = nullptr;
  m_z = 0.0;
  m_zCallbacks = nullptr;
}

int32_t AccelerometerData::RegisterActiveCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Return an invalid value on a null callback
  if (callback == nullptr) return -1;
  const char* variableName = "Active";
  // Create a copy of the callbacks to to add to
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_activeCallbacks);
  // Add callbacks to copy to ensure an existing list never changes
  int uid = newCallbacks->emplace_back(param, callback);
  if (initialNotify) {
    callback(variableName, param, &MakeBoolean(GetActive()));
  }
  m_activeCallbacks = newCallbacks;
  return uid;
}
void AccelerometerData::CancelActiveCallback(int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_activeCallbacks);
  newCallbacks->erase(uid);
  m_activeCallbacks = newCallbacks;
}
void AccelerometerData::InvokeActiveCallback(const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (m_activeCallbacks == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = m_activeCallbacks;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback("Active", listener.param, value);
  }
}

HAL_Bool AccelerometerData::GetActive() {
  return m_active;
}

void AccelerometerData::SetActive(HAL_Bool active) {
  HAL_Bool oldValue = m_active.exchange(active);
  if (oldValue != active) {
    InvokeActiveCallback(&MakeBoolean(active));
  }
}

int32_t AccelerometerData::RegisterRangeCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Return an invalid value on a null callback
  if (callback == nullptr) return -1;
  const char* variableName = "Range";
  // Create a copy of the callbacks to to add to
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_rangeCallbacks);
  // Add callbacks to copy to ensure an existing list never changes
  int uid = newCallbacks->emplace_back(param, callback);
  if (initialNotify) {
    callback(variableName, param, &MakeEnum(GetRange()));
  }
  m_activeCallbacks = newCallbacks;
  return uid;
}
void AccelerometerData::CancelRangeCallback(int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_rangeCallbacks);
  newCallbacks->erase(uid);
  m_activeCallbacks = newCallbacks;
}
void AccelerometerData::InvokeRangeCallback(const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (m_rangeCallbacks == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = m_rangeCallbacks;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback("Range", listener.param, value);
  }
}

HAL_AccelerometerRange AccelerometerData::GetRange() {
  return m_range;
}

void AccelerometerData::SetRange(HAL_AccelerometerRange range) {
  HAL_AccelerometerRange oldValue = m_range.exchange(range);
  if (oldValue != range) {
    InvokeRangeCallback(&MakeEnum(range));
  }
}

int32_t AccelerometerData::RegisterXCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Return an invalid value on a null callback
  if (callback == nullptr) return -1;
  const char* variableName = "X";
  // Create a copy of the callbacks to to add to
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_xCallbacks);
  // Add callbacks to copy to ensure an existing list never changes
  int uid = newCallbacks->emplace_back(param, callback);
  if (initialNotify) {
    callback(variableName, param, &MakeDouble(GetX()));
  }
  m_activeCallbacks = newCallbacks;
  return uid;
}
void AccelerometerData::CancelXCallback(int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_xCallbacks);
  newCallbacks->erase(uid);
  m_activeCallbacks = newCallbacks;
}
void AccelerometerData::InvokeXCallback(const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (m_xCallbacks == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = m_xCallbacks;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback("X", listener.param, value);
  }
}

double AccelerometerData::GetX() {
  return m_x;
}

void AccelerometerData::SetX(double x) {
  double oldValue = m_x.exchange(x);
  if (oldValue != x) {
    InvokeXCallback(&MakeDouble(x));
  }
}

int32_t AccelerometerData::RegisterYCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Return an invalid value on a null callback
  if (callback == nullptr) return -1;
  const char* variableName = "Y";
  // Create a copy of the callbacks to to add to
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_yCallbacks);
  // Add callbacks to copy to ensure an existing list never changes
  int uid = newCallbacks->emplace_back(param, callback);
  if (initialNotify) {
    callback(variableName, param, &MakeDouble(GetY()));
  }
  m_activeCallbacks = newCallbacks;
  return uid;
}
void AccelerometerData::CancelYCallback(int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_yCallbacks);
  newCallbacks->erase(uid);
  m_activeCallbacks = newCallbacks;
}
void AccelerometerData::InvokeYCallback(const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (m_yCallbacks == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = m_yCallbacks;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback("Y", listener.param, value);
  }
}

double AccelerometerData::GetY() {
  return m_y;
}

void AccelerometerData::SetY(double y) {
  double oldValue = m_y.exchange(y);
  if (oldValue != y) {
    InvokeYCallback(&MakeDouble(y));
  }
}

int32_t AccelerometerData::RegisterZCallback(HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  // Return an invalid value on a null callback
  if (callback == nullptr) return -1;
  const char* variableName = "Z";
  // Create a copy of the callbacks to to add to
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_zCallbacks);
  // Add callbacks to copy to ensure an existing list never changes
  int uid = newCallbacks->emplace_back(param, callback);
  if (initialNotify) {
    callback(variableName, param, &MakeDouble(GetZ()));
  }
  m_activeCallbacks = newCallbacks;
  return uid;
}
void AccelerometerData::CancelZCallback(int32_t uid) {
  // Create a copy of the callbacks to erase from
  auto newCallbacks = std::make_shared<UidVector<NotifyListener>>(*m_zCallbacks);
  newCallbacks->erase(uid);
  m_activeCallbacks = newCallbacks;
}
void AccelerometerData::InvokeZCallback(const HAL_Value* value) {
  // Return if no callbacks are assigned
  if (m_zCallbacks == nullptr) return;
  // Get a copy of the shared_ptr, then iterate and callback listeners
  auto newCallbacks = m_zCallbacks;
  for (std::size_t i=0; i<newCallbacks->size(); ++i) {
    if (!(*newCallbacks)[i]) continue; //removed
    auto listener = (*newCallbacks)[i];
    listener.callback("Z", listener.param, value);
  }
}

double AccelerometerData::GetZ() {
  return m_z;
}

void AccelerometerData::SetZ(double z) {
  double oldValue = m_z.exchange(z);
  if (oldValue != z) {
    InvokeZCallback(&MakeDouble(z));
  }
}

extern "C" {
int32_t HALSIM_RegisterAccelerometerActiveCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAccelerometerData[index]->RegisterActiveCallback(callback, param, initialNotify);
}

void HALSIM_CancelAccelerometerActiveCallback(int32_t index, int32_t uid) {
  SimAccelerometerData[index]->CancelActiveCallback(uid);
}

HAL_Bool HALSIM_GetAccelerometerActive(int32_t index) {
  return SimAccelerometerData[index]->GetActive();
}

int32_t HALSIM_RegisterAccelerometerRangeCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAccelerometerData[index]->RegisterRangeCallback(callback, param, initialNotify);
}

void HALSIM_CancelAccelerometerRangeCallback(int32_t index, int32_t uid) {
  SimAccelerometerData[index]->CancelRangeCallback(uid);
}

HAL_AccelerometerRange HALSIM_GetAccelerometerRange(int32_t index) {
  return SimAccelerometerData[index]->GetRange();
}

int32_t HALSIM_RegisterAccelerometerXCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAccelerometerData[index]->RegisterXCallback(callback, param, initialNotify);
}

void HALSIM_CancelAccelerometerXCallback(int32_t index, int32_t uid) {
  SimAccelerometerData[index]->CancelXCallback(uid);
}

double HALSIM_GetAccelerometerX(int32_t index) {
  return SimAccelerometerData[index]->GetX();
}

void HALSIM_SetAccelerometerX(int32_t index, double x) {
  SimAccelerometerData[index]->SetX(x);
}

int32_t HALSIM_RegisterAccelerometerYCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAccelerometerData[index]->RegisterYCallback(callback, param, initialNotify);
}

void HALSIM_CancelAccelerometerYCallback(int32_t index, int32_t uid) {
  SimAccelerometerData[index]->CancelYCallback(uid);
}

double HALSIM_GetAccelerometerY(int32_t index) {
  return SimAccelerometerData[index]->GetY();
}

void HALSIM_SetAccelerometerY(int32_t index, double y) {
  SimAccelerometerData[index]->SetY(y);
}

int32_t HALSIM_RegisterAccelerometerZCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify) {
  return SimAccelerometerData[index]->RegisterZCallback(callback, param, initialNotify);
}

void HALSIM_CancelAccelerometerZCallback(int32_t index, int32_t uid) {
  SimAccelerometerData[index]->CancelZCallback(uid);
}

double HALSIM_GetAccelerometerZ(int32_t index) {
  return SimAccelerometerData[index]->GetZ();
}

void HALSIM_SetAccelerometerZ(int32_t index, double z) {
  SimAccelerometerData[index]->SetZ(z);
}

}
