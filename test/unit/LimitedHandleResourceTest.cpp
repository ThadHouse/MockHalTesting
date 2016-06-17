#include "LimitedHandleResourceTest.h"
#include "handles/HandlesInternal.h"

#include "gtest/gtest.h"

namespace hal {
  
TEST_F(LimitedHandleResourceTest, EnsureAllHandlesNotAllocated) {
  for (int i = 0; i < COUNT; i++) {
    TestHalHandle handle = (TestHalHandle) createHandle(i, HalHandleEnum::DIO);
    auto v = resource.Get(handle);
    ASSERT_EQ(nullptr, v);
    ASSERT_EQ(Allocated()[i], nullptr);
  }
}

TEST_F(LimitedHandleResourceTest, AllocateAll) {
  int allocated = 0;
  
  for (int i = 0; i < COUNT; i++) {
    TestHalHandle handle = resource.Allocate();
    ASSERT_EQ(handle, createHandle(i, HalHandleEnum::DIO));
    ASSERT_NE(Allocated()[i], nullptr);
    allocated++;
  }
  
  ASSERT_EQ(COUNT, allocated);
}

TEST_F(LimitedHandleResourceTest, OverAllocated) {
  int allocated = 0;
  
  for (int i = 0; i < COUNT; i++) {
    TestHalHandle handle = resource.Allocate();
    ASSERT_EQ(handle, createHandle(i, HalHandleEnum::DIO));
    ASSERT_NE(Allocated()[i], nullptr);
    allocated++;
  }
  
  ASSERT_EQ(COUNT, allocated);
  
  auto h = resource.Allocate();
  ASSERT_EQ(HAL_HANDLE_OUT_OF_HANDLES, h);
}

TEST_F(LimitedHandleResourceTest, ReAllocate) {
  std::vector<TestHalHandle> handles;
  
  for (int i = 0; i < COUNT; i++) {
    TestHalHandle handle = resource.Allocate();
    handles.push_back(handle);
  }
  
  auto h = resource.Allocate();
  ASSERT_EQ(HAL_HANDLE_OUT_OF_HANDLES, h);
  
  ASSERT_NE(Allocated()[2], nullptr);
  
  resource.Free(handles[2]);
  
  ASSERT_EQ(Allocated()[2], nullptr);
  
  h = resource.Allocate();
  
  ASSERT_NE(Allocated()[2], nullptr);
  
  ASSERT_EQ(h, createHandle(2, HalHandleEnum::DIO));
}

TEST_F(LimitedHandleResourceTest, GetHandleOutOfRangeErrorNegativeIndex) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(0, HalHandleEnum::DIO);
  // force handle to have index -1
  handle += 0xffff;
  auto v = resource.Get(handle);
  ASSERT_EQ(v, nullptr);
}

TEST_F(LimitedHandleResourceTest, GetHandleOutOfRangeErrorIndexTooHigh) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(COUNT, HalHandleEnum::DIO);
  auto v = resource.Get(handle);
  ASSERT_EQ(v, nullptr);
}
/*
TEST_F(LimitedHandleResourceTest, GetHandleProperlyAllocated) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(s);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(0, status);
  ASSERT_EQ(5, v.t1);
  ASSERT_EQ(8, v.t2);
}

TEST_F(LimitedHandleResourceTest, GetHandleUnAllocated) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(s);
  ASSERT_EQ(h, createHandle(0, HalHandleEnum::DIO));
  resource.Free(h);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(LimitedResourceNotAllocated, status);
}
*/
}