/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifdef _WIN32

#include "HAL/Semaphore.h"

#include "Log.h"

// set the logging level
TLogLevel semaphoreLogLevel = logDEBUG;

#define SEMAPHORE_LOG(level)     \
  if (level > semaphoreLogLevel) \
    ;                            \
  else                           \
  Log().Get(level)

extern "C" {

MUTEX_ID initializeMutexNormal() { return new priority_mutex; }

void deleteMutex(MUTEX_ID sem) { delete sem; }

/**
 * Lock the mutex, blocking until it's available.
 */
void takeMutex(MUTEX_ID mutex) { mutex->lock(); }

/**
 * Attempt to lock the mutex.
 * @return true if succeeded in locking the mutex, false otherwise.
 */
bool tryTakeMutex(MUTEX_ID mutex) { return mutex->try_lock(); }

/**
 * Unlock the mutex.
 * @return 0 for success, -1 for error. If -1, the error will be in errno.
 */
void giveMutex(MUTEX_ID mutex) { mutex->unlock(); }

MULTIWAIT_ID initializeMultiWait() { return CreateMutex(NULL, FALSE, NULL); }

void deleteMultiWait(MULTIWAIT_ID cond) { CloseHandle(cond); }

void takeMultiWait(MULTIWAIT_ID cond, MUTEX_ID m) {
  WaitForSingleObject(cond, INFINITE);
}

void giveMultiWait(MULTIWAIT_ID cond) { 
  ReleaseMutex(cond);
}

}  // extern "C"
#endif // _WIN32
