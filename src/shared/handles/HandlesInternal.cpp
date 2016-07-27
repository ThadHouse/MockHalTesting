/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/handles/HandlesInternal.h"

namespace hal {
HAL_PortHandle createPortHandle(uint8_t pin, uint8_t module) {
  // set last 8 bits, then shift to first 8 bits
  HAL_PortHandle handle = static_cast<HAL_PortHandle>(HAL_HandleEnum::Port);
  handle = handle << 24;
  // shift module and add to 3rd set of 8 bits
  int32_t temp = module;
  temp = (temp << 8) & 0xff00;
  handle += temp;
  // add pin to last 8 bits
  handle += pin;
  return handle;
}

HAL_Handle createHandle(int16_t index, HAL_HandleEnum handleType) {
  if (index < 0) return HAL_kInvalidHandle;
  uint8_t hType = static_cast<uint8_t>(handleType);
  if (hType == 0 || hType > 127) return HAL_kInvalidHandle;
  // set last 8 bits, then shift to first 8 bits
  HAL_Handle handle = hType;
  handle = handle << 24;
  // add index to set last 16 bits
  handle += index;
  return handle;
}
}  // namespace hal
