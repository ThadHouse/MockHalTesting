#include "IndexedHandleResourceTest.h"
#include "handles/HandlesInternal.h"

#include "gtest/gtest.h"

namespace hal {
  
TEST_F(IndexedHandleResourceTest, EnsureAllHandlesNotAllocated) {
  for (int i = 0; i < COUNT; i++) {
   int32_t status = 0;
   TestHalHandle handle = (TestHalHandle) createHandle(i, HalHandleEnum::DIO);
   auto v = resource.Get(handle);
   ASSERT_EQ(nullptr, v);
   ASSERT_EQ(Allocated()[i], nullptr);
  }
}

TEST_F(IndexedHandleResourceTest, AllocateAll) {
  int allocated = 0;
  int32_t status = 0;
  for (int i = 0; i < COUNT; i++) {
    TestHalHandle handle = resource.Allocate(i, &status);
    ASSERT_EQ(0, status);
    ASSERT_EQ(handle, createHandle(i, HalHandleEnum::DIO));
    ASSERT_NE(Allocated()[i], nullptr);
    allocated++;
  }
  
  ASSERT_EQ(COUNT, allocated);
}

TEST_F(IndexedHandleResourceTest, AllocateOutOfRangeErrorNegativeIndex) {
  int32_t status = 0;
  TestHalHandle handle = resource.Allocate(-1, &status);
  ASSERT_EQ(HandleIndexOutOfRange, status);
  ASSERT_EQ(HAL_HANDLE_INDEX_OUT_OF_RANGE, handle);
}

TEST_F(IndexedHandleResourceTest, AllocateOutOfRangeErrorIndexTooHigh) {
  int32_t status = 0;
  TestHalHandle handle = resource.Allocate(COUNT, &status);
  ASSERT_EQ(HandleIndexOutOfRange, status);
  ASSERT_EQ(HAL_HANDLE_INDEX_OUT_OF_RANGE, handle);
}

TEST_F(IndexedHandleResourceTest, AllocateAlreadyAllocated) {
  int32_t status = 0;
  TestHalHandle handle = resource.Allocate(1, &status);
  ASSERT_EQ(status, 0);
  ASSERT_EQ(handle, createHandle(1, HalHandleEnum::DIO));
  TestHalHandle h2 = resource.Allocate(1, &status);
  ASSERT_EQ(HandleAlreadyAllocated, status);
  ASSERT_EQ(HAL_HANDLE_ALREADY_ALLOCATED, h2);
}

TEST_F(IndexedHandleResourceTest, GetHandleOutOfRangeErrorNegativeIndex) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(0, HalHandleEnum::DIO);
  // force handle to have index -1
  handle += 0xffff;
  auto v = resource.Get(handle);
  ASSERT_EQ(nullptr, v);
}

TEST_F(IndexedHandleResourceTest, GetHandleOutOfRangeErrorIndexTooHigh) {
  int32_t status = 0;
  TestHalHandle handle = (TestHalHandle) createHandle(COUNT, HalHandleEnum::DIO);
  auto v = resource.Get(handle);
  ASSERT_EQ(nullptr, v);
}
/*
TEST_F(IndexedHandleResourceTest, GetHandleProperlyAllocated) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(2, s);
  ASSERT_EQ(h, createHandle(2, HalHandleEnum::DIO));
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(0, status);
  ASSERT_EQ(5, v.t1);
  ASSERT_EQ(8, v.t2);
}

TEST_F(IndexedHandleResourceTest, GetHandleUnAllocated) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(2, s);
  ASSERT_EQ(h, createHandle(2, HalHandleEnum::DIO));
  resource.Free(h);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(IndexedResourceNotAllocated, status);
}

TEST_F(IndexedHandleResourceTest, GetHandleReAllocated) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(2, s);
  ASSERT_EQ(h, createHandle(2, HalHandleEnum::DIO));
  ASSERT_TRUE(Allocated()[2]);
  resource.Free(h);
  ASSERT_FALSE(Allocated()[2]);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(IndexedResourceNotAllocated, status);
  auto h2 = resource.Allocate(2, s);
  ASSERT_TRUE(Allocated()[2]);
  status = 0;
  v = resource.Get(h2, &status);
  ASSERT_EQ(0, status);
}

TEST_F(IndexedHandleResourceTest, GetHandleEnsureDifferentAddress) {
  TestStruct s;
  s.t1 = 5;
  s.t2 = 8;
  auto h = resource.Allocate(2, s);
  int32_t status = 0;
  auto v = resource.Get(h, &status);
  ASSERT_EQ(0, status);
  ASSERT_NE(&s, &v);
}
*/
}