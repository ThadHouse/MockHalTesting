#include "LimitedHandleResourceTest.h"
#include "handles/HandlesInternal.h"

#include "gtest/gtest.h"

namespace hal {
  
TEST_F(LimitedHandleResourceTest, EnsureAllHandlesNotAllocated) {
  for (int i = 0; i < COUNT; i++) {
    int32_t status = 0;
    TestHalHandle handle = (TestHalHandle) createHandle(i, HalHandleEnum::DIO);
    auto v = resource.Get(handle, &status);
    ASSERT_EQ(LIMITED_RESOURCE_NOT_ALLOCATED, status);
    ASSERT_FALSE(Allocated()[i]);
  }
}

TEST_F(LimitedHandleResourceTest, AllocateAll) {
  int allocated = 0;
  
  for (int i = 0; i < COUNT; i++) {
    TestStruct st;
    TestHalHandle handle = resource.Allocate(st);
    ASSERT_EQ(handle, createHandle(i, HalHandleEnum::DIO));
    ASSERT_TRUE(Allocated()[i]);
    allocated++;
  }
  
  ASSERT_EQ(COUNT, allocated);
}

TEST_F(LimitedHandleResourceTest, OverAllocated) {
  int allocated = 0;
  
  for (int i = 0; i < COUNT; i++) {
    TestStruct st;
    TestHalHandle handle = resource.Allocate(st);
    ASSERT_EQ(handle, createHandle(i, HalHandleEnum::DIO));
    ASSERT_TRUE(Allocated()[i]);
    allocated++;
  }
  
  ASSERT_EQ(COUNT, allocated);
  
  TestStruct s;
  auto h = resource.Allocate(s);
  ASSERT_EQ(HAL_HANDLE_OUT_OF_HANDLES, h);
}

TEST_F(LimitedHandleResourceTest, ReAllocate) {
  std::vector<TestHalHandle> handles;
  
  for (int i = 0; i < COUNT; i++) {
    TestStruct st;
    TestHalHandle handle = resource.Allocate(st);
    handles.push_back(handle);
  }
  
  TestStruct s;
  auto h = resource.Allocate(s);
  ASSERT_EQ(HAL_HANDLE_OUT_OF_HANDLES, h);
  
  ASSERT_TRUE(Allocated()[2]);
  
  resource.Free(handles[2]);
  
  ASSERT_FALSE(Allocated()[2]);
  
  h = resource.Allocate(s);
  
  ASSERT_TRUE(Allocated()[2]);
  
  ASSERT_EQ(h, createHandle(2, HalHandleEnum::DIO));
}

TEST_F(LimitedHandleResourceTest, GetHandleOutOfRangeErrorNegativeIndex) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(0, HalHandleEnum::DIO);
  // force handle to have index -1
  handle += 0xffff;
  auto v = resource.Get(handle, &status);
  ASSERT_EQ(LIMITED_RESOURCE_INDEX_OUT_OF_RANGE, status);
}

TEST_F(LimitedHandleResourceTest, GetHandleOutOfRangeErrorIndexTooHigh) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(COUNT, HalHandleEnum::DIO);
  auto v = resource.Get(handle, &status);
  ASSERT_EQ(LIMITED_RESOURCE_INDEX_OUT_OF_RANGE, status);
}

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
  ASSERT_EQ(LIMITED_RESOURCE_NOT_ALLOCATED, status);
}

TEST_F(LimitedHandleResourceTest, GetHandleEnsureDifferentAddress) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(s);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(0, status);
  ASSERT_NE(&s, &v);
}
}