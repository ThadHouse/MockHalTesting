#include "UnlimitedHandleResourceTest.h"
#include "handles/HandlesInternal.h"

#include "gtest/gtest.h"

namespace hal {

TEST_F(UnlimitedHandleResourceTest, CreateEmptyStructure) {
  ASSERT_EQ(0, structures().size());
}

TEST_F(UnlimitedHandleResourceTest, CreateAddStructure) {
  // Allocate strucutre, and ensure proper index, type, and vector sise
  auto s = std::make_shared<TestStruct>();
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(0, getHandleTypedIndex(handle, HalHandleEnum::DIO));
  ASSERT_EQ(1, structures().size());
}

TEST_F(UnlimitedHandleResourceTest, StructureDataValidation) {
  auto s = std::make_shared<TestStruct>();
  s->t1 = 5;
  s->t2 = 8;
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(0, getHandleTypedIndex(handle, HalHandleEnum::DIO));
  ASSERT_EQ(1, structures().size());
  auto v = resource.Get(handle);
  ASSERT_NE(nullptr, v);
  ASSERT_EQ(v, s);
  ASSERT_EQ(5, v->t1);
  ASSERT_EQ(8, v->t2);
}

TEST_F(UnlimitedHandleResourceTest, HandleCreateRemoveGetNull) {
  auto s = std::make_shared<TestStruct>();
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(0, getHandleTypedIndex(handle, HalHandleEnum::DIO));
  ASSERT_EQ(1, structures().size());
  auto v = resource.Get(handle);
  ASSERT_NE(nullptr, v);
  resource.Free(handle);
  v = resource.Get(handle);
  ASSERT_EQ(nullptr, v);
}

TEST_F(UnlimitedHandleResourceTest, Create2HandlesReassignNum1) {
  auto s = std::make_shared<TestStruct>();
  // allocate 2 handles
  TestHalHandle handle = resource.Allocate(s);
  s = std::make_shared<TestStruct>();
  TestHalHandle handle2 = resource.Allocate(s);
  ASSERT_EQ(0, getHandleTypedIndex(handle, HalHandleEnum::DIO));
  ASSERT_EQ(1, getHandleTypedIndex(handle2, HalHandleEnum::DIO));
  ASSERT_EQ(2, structures().size());
  resource.Free(handle);
  auto v = resource.Get(handle);
  ASSERT_EQ(nullptr, v);
  s = std::make_shared<TestStruct>();
  TestHalHandle handle3 = resource.Allocate(s);
  ASSERT_EQ(2, structures().size());
  ASSERT_EQ(0, getHandleTypedIndex(handle3, HalHandleEnum::DIO));
  v = resource.Get(handle3);
  ASSERT_NE(nullptr, v);
}

TEST_F(UnlimitedHandleResourceTest, Create2HandlesReassignNum2) {
  auto s = std::make_shared<TestStruct>();
  // allocate 2 handles
  TestHalHandle handle = resource.Allocate(s);
  s = std::make_shared<TestStruct>();
  TestHalHandle handle2 = resource.Allocate(s);
  ASSERT_EQ(0, getHandleTypedIndex(handle, HalHandleEnum::DIO));
  ASSERT_EQ(1, getHandleTypedIndex(handle2, HalHandleEnum::DIO));
  ASSERT_EQ(2, structures().size());
  resource.Free(handle2);
  auto v = resource.Get(handle2);
  ASSERT_EQ(nullptr, v);
  s = std::make_shared<TestStruct>();
  TestHalHandle handle3 = resource.Allocate(s);
  ASSERT_EQ(2, structures().size());
  ASSERT_EQ(1, getHandleTypedIndex(handle3, HalHandleEnum::DIO));
  v = resource.Get(handle3);
  ASSERT_NE(nullptr, v);
}
}