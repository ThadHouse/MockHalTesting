#include "HAL/HAL.h"

#include "FRC_NetworkCommunication/FRCComm.h"

extern "C" {

int HALInitialize(int mode) {
  FRC_NetworkCommunication_Reserve(nullptr);
  return 1;
}
} // extern "C"