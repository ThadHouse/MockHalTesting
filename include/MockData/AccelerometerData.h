#pragma once

#include <atomic>

#include "HAL/Accelerometer.h"

#ifdef __cplusplus
extern "C" {
#endif

HAL_Bool HALSIM_GetAcceleromterActive(void);
HAL_AccelerometerRange HALSIM_GetAccelerometerRange(void);
double HALSIM_GetAccelerometerX(void);
double HALSIM_GetAccelerometerY(void);
double HALSIM_GetAccelerometerZ(void);

void HALSIM_SetAccelerometerX(double x);
void HALSIM_SetAccelerometerY(double y);
void HALSIM_SetAccelerometerZ(double z);


#ifdef __cplusplus
}
#endif