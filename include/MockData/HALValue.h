#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "MockData/llvm/StringRef.h"
#include "HAL_String.h"
#include "HAL/Types.h"

/** HAL data types. */
enum HAL_Type {
  HAL_UNASSIGNED = 0,
  HAL_BOOLEAN = 0x01,
  HAL_DOUBLE = 0x02,
  HAL_STRING = 0x04,
  HAL_RAW = 0x08,
  HAL_ENUM = 0x16,
};

/** HAL Entry Value.  Note this is a typed union. */
struct HAL_Value {
  enum HAL_Type type;
  union {
    HAL_Bool v_boolean;
    int v_enum;
    double v_double;
    struct HAL_String v_string;
    struct HAL_String v_raw;
  } data;
};

inline HAL_Value MakeBoolean(bool v) {
  HAL_Value value;
  value.type = HAL_BOOLEAN;
  value.data.v_boolean = v;
  return value;
}

inline HAL_Value MakeEnum(int v) {
  HAL_Value value;
  value.type = HAL_ENUM;
  value.data.v_enum = v;
  return value;
}