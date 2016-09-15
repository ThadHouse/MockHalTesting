#include "HAL/SPI.h"

void HAL_InitializeSPI(int32_t port, int32_t* status) {

}
int32_t HAL_TransactionSPI(int32_t port, uint8_t* dataToSend,
                           uint8_t* dataReceived, int32_t size) {
                             return 0;
                           }
int32_t HAL_WriteSPI(int32_t port, uint8_t* dataToSend, int32_t sendSize) {
  return 0;
}
int32_t HAL_ReadSPI(int32_t port, uint8_t* buffer, int32_t count) {
  return 0;
}
void HAL_CloseSPI(int32_t port) {

}
void HAL_SetSPISpeed(int32_t port, int32_t speed) {

}
void HAL_SetSPIOpts(int32_t port, HAL_Bool msbFirst, HAL_Bool sampleOnTrailing,
                    HAL_Bool clkIdleHigh) {

                    }
void HAL_SetSPIChipSelectActiveHigh(int32_t port, int32_t* status) {

}
void HAL_SetSPIChipSelectActiveLow(int32_t port, int32_t* status) {

}
int32_t HAL_GetSPIHandle(int32_t port) {
  return 0;
}
void HAL_SetSPIHandle(int32_t port, int32_t handle) {

}

void HAL_InitSPIAccumulator(int32_t port, int32_t period, int32_t cmd,
                            int32_t xferSize, int32_t validMask,
                            int32_t validValue, int32_t dataShift,
                            int32_t dataSize, HAL_Bool isSigned,
                            HAL_Bool bigEndian, int32_t* status) {

                            }
void HAL_FreeSPIAccumulator(int32_t port, int32_t* status) {

}
void HAL_ResetSPIAccumulator(int32_t port, int32_t* status) {

}
void HAL_SetSPIAccumulatorCenter(int32_t port, int32_t center, int32_t* status) {

}
void HAL_SetSPIAccumulatorDeadband(int32_t port, int32_t deadband,
                                   int32_t* status) {

                                   }
int32_t HAL_GetSPIAccumulatorLastValue(int32_t port, int32_t* status) {
  return 0;
}
int64_t HAL_GetSPIAccumulatorValue(int32_t port, int32_t* status) {
  return 0;
}
int64_t HAL_GetSPIAccumulatorCount(int32_t port, int32_t* status) {
  return 0;
}
double HAL_GetSPIAccumulatorAverage(int32_t port, int32_t* status) {
  return 0;
}
void HAL_GetSPIAccumulatorOutput(int32_t port, int64_t* value, int64_t* count,
                                 int32_t* status) {

                                 }