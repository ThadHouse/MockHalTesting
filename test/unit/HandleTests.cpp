#include "handles/HandlesInternal.h"

#include "gtest/gtest.h"

namespace hal {

class HandleTests : public ::testing::Test {};

TEST_F(HandleTests, CreateHandleNegativeIndex) {
  HalHandle handle = createHandle(-1, HalHandleEnum::DIO);
  ASSERT_EQ(HAL_HANDLE_NEGATIVE_INDEX, handle);
}

TEST_F(HandleTests, CreateHandleEnumOutOfRangeZero) {
  HalHandle handle = createHandle(5, (HalHandleEnum) 0);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, handle);
}

TEST_F(HandleTests, CreateHandleEnumOutOfRangeUnderflow) {
  HalHandle handle = createHandle(5, (HalHandleEnum) -1);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, handle);
}

TEST_F(HandleTests, CreateHandleEnumOutOfRangeOverflow) {
  HalHandle handle = createHandle(5, (HalHandleEnum) 128);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, handle);
}

TEST_F(HandleTests, CreatedHandleGetType) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(HalHandleEnum::DIO, getHandleType(handle));
}

TEST_F(HandleTests, CreatedHandGetIndex) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(3, getHandleIndex(handle));
}

TEST_F(HandleTests, CreatedHandleValidTypeComparison) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_TRUE(isHandleType(handle, HalHandleEnum::DIO));
}

TEST_F(HandleTests, CreatedHandleValidTypeComparisonFailure) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_FALSE(isHandleType(handle, HalHandleEnum::Port));
}

TEST_F(HandleTests, CreatedHandleGetTypedIndexValidType) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(3, getHandleTypedIndex(handle, HalHandleEnum::DIO));
}

TEST_F(HandleTests, CreatedHandleGetTypedIndexInvalidType) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, getHandleTypedIndex(handle, HalHandleEnum::Port));
}

TEST_F(HandleTests, CreatedPortHandleGetPin) {
  HalPortHandle handle = createPortHandle(3, 2);
  ASSERT_EQ(3, getPortHandlePin(handle));
}

TEST_F(HandleTests, CreatedPortHandleGetModule) {
  HalPortHandle handle = createPortHandle(3, 2);
  ASSERT_EQ(2, getPortHandleModule(handle));
}

TEST_F(HandleTests, CreatedPortHandleGetPinInvalidType) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, getPortHandlePin(handle));
}

TEST_F(HandleTests, CreatedPortHandleGetModuleInvalidType) {
  HalHandle handle = createHandle(3, HalHandleEnum::DIO);
  ASSERT_EQ(HAL_HANDLE_INVALID_TYPE, getPortHandleModule(handle));
}
}