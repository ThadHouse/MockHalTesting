/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/SPI.h"

#include <atomic>

#include "DigitalInternal.h"
#include "HAL/DIO.h"
#include "HAL/HAL.h"
#include "HAL/cpp/make_unique.h"
#include "HAL/cpp/priority_mutex.h"
#include "spilib/spi-lib.h"

static_assert(sizeof(uint32_t) <= sizeof(void*),
              "This file shoves uint32_ts into pointers.");

using namespace hal;

static int32_t m_spiCS0Handle = 0;
static int32_t m_spiCS1Handle = 0;
static int32_t m_spiCS2Handle = 0;
static int32_t m_spiCS3Handle = 0;
static int32_t m_spiMXPHandle = 0;
static priority_recursive_mutex spiOnboardMutex;
static priority_recursive_mutex spiMXPMutex;
static tSPI* spiSystem;

static HAL_DigitalHandle spiMXPDigitalHandle1 = HAL_kInvalidHandle;
static HAL_DigitalHandle spiMXPDigitalHandle2 = HAL_kInvalidHandle;
static HAL_DigitalHandle spiMXPDigitalHandle3 = HAL_kInvalidHandle;
static HAL_DigitalHandle spiMXPDigitalHandle4 = HAL_kInvalidHandle;

/**
 * Get the semaphore for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @return The semaphore for the SPI port.
 */
static priority_recursive_mutex& spiGetMutex(int32_t port) {
  if (port < 4)
    return spiOnboardMutex;
  else
    return spiMXPMutex;
}

extern "C" {

struct SPIAccumulator {
  std::atomic<HAL_NotifierHandle> notifier{0};
  uint64_t triggerTime;
  int32_t period;

  int64_t value = 0;
  uint32_t count = 0;
  int32_t last_value = 0;

  int32_t center = 0;
  int32_t deadband = 0;

  uint8_t cmd[4];  // command to send (up to 4 bytes)
  int32_t valid_mask;
  int32_t valid_value;
  int32_t data_max;       // one more than max data value
  int32_t data_msb_mask;  // data field MSB mask (for signed)
  uint8_t data_shift;     // data field shift right amount, in bits
  uint8_t xfer_size;      // SPI transfer size, in bytes (up to 4)
  uint8_t port;
  bool is_signed;   // is data field signed?
  bool big_endian;  // is response big endian?
};
std::unique_ptr<SPIAccumulator> spiAccumulators[5];

/*
 * Initialize the spi port. Opens the port if necessary and saves the handle.
 * If opening the MXP port, also sets up the pin functions appropriately
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_InitializeSPI(int32_t port, int32_t* status) {
  if (spiSystem == nullptr) spiSystem = tSPI::create(status);
  if (HAL_GetSPIHandle(port) != 0) return;
  switch (port) {
    case 0:
      HAL_SetSPIHandle(0, spilib_open("/dev/spidev0.0"));
      break;
    case 1:
      HAL_SetSPIHandle(1, spilib_open("/dev/spidev0.1"));
      break;
    case 2:
      HAL_SetSPIHandle(2, spilib_open("/dev/spidev0.2"));
      break;
    case 3:
      HAL_SetSPIHandle(3, spilib_open("/dev/spidev0.3"));
      break;
    case 4:
      initializeDigital(status);
      if (*status != 0) return;
      if ((spiMXPDigitalHandle1 = HAL_InitializeDIOPort(
               HAL_GetPort(14), false, status)) == HAL_kInvalidHandle) {
        printf("Failed to allocate DIO 14\n");
        return;
      }
      if ((spiMXPDigitalHandle2 = HAL_InitializeDIOPort(
               HAL_GetPort(15), false, status)) == HAL_kInvalidHandle) {
        printf("Failed to allocate DIO 15\n");
        HAL_FreeDIOPort(spiMXPDigitalHandle1);  // free the first port allocated
        return;
      }
      if ((spiMXPDigitalHandle3 = HAL_InitializeDIOPort(
               HAL_GetPort(16), false, status)) == HAL_kInvalidHandle) {
        printf("Failed to allocate DIO 16\n");
        HAL_FreeDIOPort(spiMXPDigitalHandle1);  // free the first port allocated
        HAL_FreeDIOPort(
            spiMXPDigitalHandle2);  // free the second port allocated
        return;
      }
      if ((spiMXPDigitalHandle4 = HAL_InitializeDIOPort(
               HAL_GetPort(17), false, status)) == HAL_kInvalidHandle) {
        printf("Failed to allocate DIO 17\n");
        HAL_FreeDIOPort(spiMXPDigitalHandle1);  // free the first port allocated
        HAL_FreeDIOPort(
            spiMXPDigitalHandle2);  // free the second port allocated
        HAL_FreeDIOPort(spiMXPDigitalHandle3);  // free the third port allocated
        return;
      }
      digitalSystem->writeEnableMXPSpecialFunction(
          digitalSystem->readEnableMXPSpecialFunction(status) | 0x00F0, status);
      HAL_SetSPIHandle(4, spilib_open("/dev/spidev1.0"));
      break;
    default:
      *status = PARAMETER_OUT_OF_RANGE;
      break;
  }
  return;
}

/**
 * Generic transaction.
 *
 * This is a lower-level interface to the spi hardware giving you more control
 * over each transaction.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param dataToSend Buffer of data to send as part of the transaction.
 * @param dataReceived Buffer to read data into.
 * @param size Number of bytes to transfer. [0..7]
 * @return Number of bytes transferred, -1 for error
 */
int32_t HAL_TransactionSPI(int32_t port, uint8_t* dataToSend,
                           uint8_t* dataReceived, int32_t size) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  return spilib_writeread(
      HAL_GetSPIHandle(port), reinterpret_cast<const char*>(dataToSend),
      reinterpret_cast<char*>(dataReceived), static_cast<int32_t>(size));
}

/**
 * Execute a write transaction with the device.
 *
 * Write to a device and wait until the transaction is complete.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param datToSend The data to write to the register on the device.
 * @param sendSize The number of bytes to be written
 * @return The number of bytes written. -1 for an error
 */
int32_t HAL_WriteSPI(int32_t port, uint8_t* dataToSend, int32_t sendSize) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  return spilib_write(HAL_GetSPIHandle(port),
                      reinterpret_cast<const char*>(dataToSend),
                      static_cast<int32_t>(sendSize));
}

/**
 * Execute a read from the device.
 *
 *   This method does not write any data out to the device
 *   Most spi devices will require a register address to be written before
 *   they begin returning data
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param buffer A pointer to the array of bytes to store the data read from the
 * device.
 * @param count The number of bytes to read in the transaction. [1..7]
 * @return Number of bytes read. -1 for error.
 */
int32_t HAL_ReadSPI(int32_t port, uint8_t* buffer, int32_t count) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  return spilib_read(HAL_GetSPIHandle(port), reinterpret_cast<char*>(buffer),
                     static_cast<int32_t>(count));
}

/**
 * Close the SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_CloseSPI(int32_t port) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  if (spiAccumulators[port]) {
    int32_t status = 0;
    HAL_FreeSPIAccumulator(port, &status);
  }
  spilib_close(HAL_GetSPIHandle(port));
  HAL_SetSPIHandle(port, 0);
  if (port == 4) {
    HAL_FreeDIOPort(spiMXPDigitalHandle1);
    HAL_FreeDIOPort(spiMXPDigitalHandle2);
    HAL_FreeDIOPort(spiMXPDigitalHandle3);
    HAL_FreeDIOPort(spiMXPDigitalHandle4);
  }
  return;
}

/**
 * Set the clock speed for the SPI bus.
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param speed The speed in Hz (0-1MHz)
 */
void HAL_SetSPISpeed(int32_t port, int32_t speed) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  spilib_setspeed(HAL_GetSPIHandle(port), speed);
}

/**
 * Set the SPI options
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @param msb_first True to write the MSB first, False for LSB first
 * @param sample_on_trailing True to sample on the trailing edge, False to
 * sample on the leading edge
 * @param clk_idle_high True to set the clock to active low, False to set the
 * clock active high
 */
void HAL_SetSPIOpts(int32_t port, HAL_Bool msb_first,
                    HAL_Bool sample_on_trailing, HAL_Bool clk_idle_high) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  spilib_setopts(HAL_GetSPIHandle(port), msb_first, sample_on_trailing,
                 clk_idle_high);
}

/**
 * Set the CS Active high for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_SetSPIChipSelectActiveHigh(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  if (port < 4) {
    spiSystem->writeChipSelectActiveHigh_Hdr(
        spiSystem->readChipSelectActiveHigh_Hdr(status) | (1 << port), status);
  } else {
    spiSystem->writeChipSelectActiveHigh_MXP(1, status);
  }
}

/**
 * Set the CS Active low for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 */
void HAL_SetSPIChipSelectActiveLow(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  if (port < 4) {
    spiSystem->writeChipSelectActiveHigh_Hdr(
        spiSystem->readChipSelectActiveHigh_Hdr(status) & ~(1 << port), status);
  } else {
    spiSystem->writeChipSelectActiveHigh_MXP(0, status);
  }
}

/**
 * Get the stored handle for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for MXP
 * @return The stored handle for the SPI port. 0 represents no stored handle.
 */
int32_t HAL_GetSPIHandle(int32_t port) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  switch (port) {
    case 0:
      return m_spiCS0Handle;
    case 1:
      return m_spiCS1Handle;
    case 2:
      return m_spiCS2Handle;
    case 3:
      return m_spiCS3Handle;
    case 4:
      return m_spiMXPHandle;
    default:
      return 0;
  }
}

/**
 * Set the stored handle for a SPI port
 *
 * @param port The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for
 * MXP.
 * @param handle The value of the handle for the port.
 */
void HAL_SetSPIHandle(int32_t port, int32_t handle) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  switch (port) {
    case 0:
      m_spiCS0Handle = handle;
      break;
    case 1:
      m_spiCS1Handle = handle;
      break;
    case 2:
      m_spiCS2Handle = handle;
      break;
    case 3:
      m_spiCS3Handle = handle;
      break;
    case 4:
      m_spiMXPHandle = handle;
      break;
    default:
      break;
  }
}

static void spiAccumulatorProcess(uint64_t currentTime, void* param) {
  SPIAccumulator* accum = static_cast<SPIAccumulator*>(param);

  // perform SPI transaction
  uint8_t resp_b[4];
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(accum->port));
  spilib_writeread(
      HAL_GetSPIHandle(accum->port), reinterpret_cast<const char*>(accum->cmd),
      reinterpret_cast<char*>(resp_b), static_cast<int32_t>(accum->xfer_size));

  // convert from bytes
  uint32_t resp = 0;
  if (accum->big_endian) {
    for (int i = 0; i < accum->xfer_size; ++i) {
      resp <<= 8;
      resp |= resp_b[i] & 0xff;
    }
  } else {
    for (int i = accum->xfer_size - 1; i >= 0; --i) {
      resp <<= 8;
      resp |= resp_b[i] & 0xff;
    }
  }

  // process response
  if ((resp & accum->valid_mask) == static_cast<uint32_t>(accum->valid_value)) {
    // valid sensor data; extract data field
    int32_t data = static_cast<int32_t>(resp >> accum->data_shift);
    data &= accum->data_max - 1;
    // 2s complement conversion if signed MSB is set
    if (accum->is_signed && (data & accum->data_msb_mask) != 0)
      data -= accum->data_max;
    // center offset
    data -= accum->center;
    // only accumulate if outside deadband
    if (data < -accum->deadband || data > accum->deadband) accum->value += data;
    ++accum->count;
    accum->last_value = data;
  } else {
    // no data from the sensor; just clear the last value
    accum->last_value = 0;
  }

  // reschedule timer
  accum->triggerTime += accum->period;
  // handle timer slip
  if (accum->triggerTime < currentTime)
    accum->triggerTime = currentTime + accum->period;
  int32_t status = 0;
  HAL_UpdateNotifierAlarm(accum->notifier, accum->triggerTime, &status);
}

/**
 * Initialize a SPI accumulator.
 *
 * @param port SPI port
 * @param period Time between reads, in us
 * @param cmd SPI command to send to request data
 * @param xfer_size SPI transfer size, in bytes
 * @param valid_mask Mask to apply to received data for validity checking
 * @param valid_data After valid_mask is applied, required matching value for
 *                   validity checking
 * @param data_shift Bit shift to apply to received data to get actual data
 *                   value
 * @param data_size Size (in bits) of data field
 * @param is_signed Is data field signed?
 * @param big_endian Is device big endian?
 */
void HAL_InitSPIAccumulator(int32_t port, int32_t period, int32_t cmd,
                            int32_t xfer_size, int32_t valid_mask,
                            int32_t valid_value, int32_t data_shift,
                            int32_t data_size, HAL_Bool is_signed,
                            HAL_Bool big_endian, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  if (port > 4) return;
  if (!spiAccumulators[port])
    spiAccumulators[port] = std::make_unique<SPIAccumulator>();
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (big_endian) {
    for (int i = xfer_size - 1; i >= 0; --i) {
      accum->cmd[i] = cmd & 0xff;
      cmd >>= 8;
    }
  } else {
    accum->cmd[0] = cmd & 0xff;
    cmd >>= 8;
    accum->cmd[1] = cmd & 0xff;
    cmd >>= 8;
    accum->cmd[2] = cmd & 0xff;
    cmd >>= 8;
    accum->cmd[3] = cmd & 0xff;
  }
  accum->period = period;
  accum->xfer_size = xfer_size;
  accum->valid_mask = valid_mask;
  accum->valid_value = valid_value;
  accum->data_shift = data_shift;
  accum->data_max = (1 << data_size);
  accum->data_msb_mask = (1 << (data_size - 1));
  accum->is_signed = is_signed;
  accum->big_endian = big_endian;
  if (!accum->notifier) {
    accum->notifier =
        HAL_InitializeNotifier(spiAccumulatorProcess, accum, status);
    accum->triggerTime = HAL_GetFPGATime(status) + period;
    if (*status != 0) return;
    HAL_UpdateNotifierAlarm(accum->notifier, accum->triggerTime, status);
  }
}

/**
 * Frees a SPI accumulator.
 */
void HAL_FreeSPIAccumulator(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return;
  }
  HAL_NotifierHandle handle = accum->notifier.exchange(0);
  HAL_CleanNotifier(handle, status);
  spiAccumulators[port] = nullptr;
}

/**
 * Resets the accumulator to zero.
 */
void HAL_ResetSPIAccumulator(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return;
  }
  accum->value = 0;
  accum->count = 0;
  accum->last_value = 0;
}

/**
 * Set the center value of the accumulator.
 *
 * The center value is subtracted from each value before it is added to the
 * accumulator. This
 * is used for the center value of devices like gyros and accelerometers to make
 * integration work
 * and to take the device offset into account when integrating.
 */
void HAL_SetSPIAccumulatorCenter(int32_t port, int32_t center,
                                 int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return;
  }
  accum->center = center;
}

/**
 * Set the accumulator's deadband.
 */
void HAL_SetSPIAccumulatorDeadband(int32_t port, int32_t deadband,
                                   int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return;
  }
  accum->deadband = deadband;
}

/**
 * Read the last value read by the accumulator engine.
 */
int32_t HAL_GetSPIAccumulatorLastValue(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return 0;
  }
  return accum->last_value;
}

/**
 * Read the accumulated value.
 *
 * @return The 64-bit value accumulated since the last Reset().
 */
int64_t HAL_GetSPIAccumulatorValue(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return 0;
  }
  return accum->value;
}

/**
 * Read the number of accumulated values.
 *
 * Read the count of the accumulated values since the accumulator was last
 * Reset().
 *
 * @return The number of times samples from the channel were accumulated.
 */
int64_t HAL_GetSPIAccumulatorCount(int32_t port, int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    return 0;
  }
  return accum->count;
}

/**
 * Read the average of the accumulated value.
 *
 * @return The accumulated average value (value / count).
 */
double HAL_GetSPIAccumulatorAverage(int32_t port, int32_t* status) {
  int64_t value;
  int64_t count;
  HAL_GetAccumulatorOutput(port, &value, &count, status);
  if (count == 0) return 0.0;
  return static_cast<double>(value) / count;
}

/**
 * Read the accumulated value and the number of accumulated values atomically.
 *
 * This function reads the value and count atomically.
 * This can be used for averaging.
 *
 * @param value Pointer to the 64-bit accumulated output.
 * @param count Pointer to the number of accumulation cycles.
 */
void HAL_GetSPIAccumulatorOutput(int32_t port, int64_t* value, int64_t* count,
                                 int32_t* status) {
  std::lock_guard<priority_recursive_mutex> sync(spiGetMutex(port));
  SPIAccumulator* accum = spiAccumulators[port].get();
  if (!accum) {
    *status = NULL_PARAMETER;
    *value = 0;
    *count = 0;
    return;
  }
  *value = accum->value;
  *count = accum->count;
}
}
