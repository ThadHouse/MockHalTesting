#include "HAL/Encoder.h"

#include "MockData/EncoderDataInternal.h"
#include "HAL/Counter.h"
#include "HAL/Errors.h"
#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/LimitedHandleResource.h"
#include "PortsInternal.h"

using namespace hal;

namespace {
struct Encoder{
  HAL_Handle nativeHandle;
  HAL_EncoderEncodingType encodingType;
  uint8_t index;
};
struct Empty {
};
}

static LimitedHandleResource<HAL_EncoderHandle, Encoder,
                             kNumEncoders + kNumCounters,
                             HAL_HandleEnum::Encoder>
    encoderHandles;

static LimitedHandleResource<HAL_FPGAEncoderHandle, Empty,
                             kNumEncoders,
                             HAL_HandleEnum::FPGAEncoder>
    fpgaEncoderHandles;

HAL_EncoderHandle HAL_InitializeEncoder(
    HAL_Handle digitalSourceHandleA, HAL_AnalogTriggerType analogTriggerTypeA,
    HAL_Handle digitalSourceHandleB, HAL_AnalogTriggerType analogTriggerTypeB,
    HAL_Bool reverseDirection, HAL_EncoderEncodingType encodingType,
    int32_t* status) {
  HAL_Handle nativeHandle = HAL_kInvalidHandle;
  if (encodingType == HAL_EncoderEncodingType::HAL_Encoder_k4X) {
    // k4x, allocate encoder
    nativeHandle = fpgaEncoderHandles.Allocate();
  } else {
    // k2x or k1x, allocate counter
  }
  if (nativeHandle == HAL_kInvalidHandle) {
    *status = NO_AVAILABLE_RESOURCES;
    return HAL_kInvalidHandle;
  }
  auto handle = encoderHandles.Allocate();
  if (handle == HAL_kInvalidHandle) {
    *status = NO_AVAILABLE_RESOURCES;
    return HAL_kInvalidHandle;
  }
  auto encoder = encoderHandles.Get(handle);
  if (encoder == nullptr) {  // would only occur on thread issue
    *status = HAL_HANDLE_ERROR;
    return HAL_kInvalidHandle;
  }
  int16_t index = getHandleIndex(handle);
  SimEncoderData[index].SetInitialized(true);
  // TODO: Add encoding type to Sim data
  encoder->index = index;
  encoder->nativeHandle = nativeHandle;
  encoder->encodingType = encodingType;
  return handle;
}

void HAL_FreeEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
  encoderHandles.Free(encoderHandle);
  if (encoder == nullptr) return;
  if (isHandleType(encoder->nativeHandle, HAL_HandleEnum::FPGAEncoder)) {
    fpgaEncoderHandles.Free(encoder->nativeHandle);
  } else {
    // Free counter handle
  }
  SimEncoderData[encoder->index].SetInitialized(false);
}

static inline double DecodingScaleFactor(Encoder* encoder) {
  switch (encoder->encodingType) {
    case HAL_Encoder_k1X:
      return 1.0;
    case HAL_Encoder_k2X:
      return 0.5;
    case HAL_Encoder_k4X:
      return 0.25;
    default:
      return 0.0;
  }
}

int32_t HAL_GetEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
  if (encoder == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return SimEncoderData[encoder->index].GetCount();
}
int32_t HAL_GetEncoderRaw(HAL_EncoderHandle encoderHandle, int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
  if (encoder == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return SimEncoderData[encoder->index].GetCount() / DecodingScaleFactor(encoder.get());
}
int32_t HAL_GetEncoderEncodingScale(HAL_EncoderHandle encoderHandle,
                                    int32_t* status) {
  // TODO: Find Encoding Scale
  return 0;
}
void HAL_ResetEncoder(HAL_EncoderHandle encoderHandle, int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
  if (encoder == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return;
  }

  SimEncoderData[encoder->index].SetCount(0);
  SimEncoderData[encoder->index].SetPeriod(std::numeric_limits<double>::max());
  //SimEncoderData[encoder->index].SetReset(true);
}
double HAL_GetEncoderPeriod(HAL_EncoderHandle encoderHandle, int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
  if (encoder == nullptr) {
    *status = HAL_HANDLE_ERROR;
    return 0;
  }

  return SimEncoderData[encoder->index].GetPeriod();
}
void HAL_SetEncoderMaxPeriod(HAL_EncoderHandle encoderHandle, double maxPeriod,
                             int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
    if (encoder == nullptr) {
      *status = HAL_HANDLE_ERROR;
      return;
    }

    SimEncoderData[encoder->index].SetMaxPeriod(maxPeriod);
}
HAL_Bool HAL_GetEncoderStopped(HAL_EncoderHandle encoderHandle,
                               int32_t* status) {
  auto encoder = encoderHandles.Get(encoderHandle);
    if (encoder == nullptr) {
      *status = HAL_HANDLE_ERROR;
      return 0;
    }

    return SimEncoderData[encoder->index].GetPeriod() > SimEncoderData[encoder->index].GetMaxPeriod();
}
HAL_Bool HAL_GetEncoderDirection(HAL_EncoderHandle encoderHandle,
                                 int32_t* status);
double HAL_GetEncoderDistance(HAL_EncoderHandle encoderHandle, int32_t* status);
double HAL_GetEncoderRate(HAL_EncoderHandle encoderHandle, int32_t* status);
void HAL_SetEncoderMinRate(HAL_EncoderHandle encoderHandle, double minRate,
                           int32_t* status);
void HAL_SetEncoderDistancePerPulse(HAL_EncoderHandle encoderHandle,
                                    double distancePerPulse, int32_t* status);
void HAL_SetEncoderReverseDirection(HAL_EncoderHandle encoderHandle,
                                    HAL_Bool reverseDirection, int32_t* status);
void HAL_SetEncoderSamplesToAverage(HAL_EncoderHandle encoderHandle,
                                    int32_t samplesToAverage, int32_t* status);
int32_t HAL_GetEncoderSamplesToAverage(HAL_EncoderHandle encoderHandle,
                                       int32_t* status);

void HAL_SetEncoderIndexSource(HAL_EncoderHandle encoderHandle,
                               HAL_Handle digitalSourceHandle,
                               HAL_AnalogTriggerType analogTriggerType,
                               HAL_EncoderIndexingType type, int32_t* status);

int32_t HAL_GetEncoderFPGAIndex(HAL_EncoderHandle encoderHandle,
                                int32_t* status);

double HAL_GetEncoderDecodingScaleFactor(HAL_EncoderHandle encoderHandle,
                                         int32_t* status);

double HAL_GetEncoderDistancePerPulse(HAL_EncoderHandle encoderHandle,
                                      int32_t* status);

HAL_EncoderEncodingType HAL_GetEncoderEncodingType(
    HAL_EncoderHandle encoderHandle, int32_t* status);
