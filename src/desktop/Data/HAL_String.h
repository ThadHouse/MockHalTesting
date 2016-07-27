#pragma once

#ifdef __cplusplu
extern "C" {
#endif

/** A HAL String. */
struct HAL_String {
  /** String contents (UTF-8).
   * The string is NOT required to be zero-terminated.
   * When returned by the library, this is zero-terminated and allocated with
   * malloc().
   */
  char *str;

  /** Length of the string in bytes.  If the string happens to be zero
   * terminated, this does not include the zero-termination.
   */
  size_t len;
};