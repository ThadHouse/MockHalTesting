#include "UnlimitedHandleResourceTest.h"

#include "gtest/gtest.h"

namespace hal {

TEST_F(UnlimitedHandleResourceTest, CreateEmptyStructure) {
  ASSERT_EQ(0, structures().size());
}

TEST_F(UnlimitedHandleResourceTest, CreateAddStructure) {
  auto s = std::make_shared<TestStruct>();
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(1, structures().size());
}

TEST_F(UnlimitedHandleResourceTest, StructureDataValidation) {
  auto s = std::make_shared<TestStruct>();
  s->t1 = 5;
  s->t2 = 8;
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(1, structures().size());
  auto v = resource.Get(handle);
  ASSERT_NE(nullptr, v);
  ASSERT_EQ(5, v->t1);
  ASSERT_EQ(8, v->t2);
}

TEST_F(UnlimitedHandleResourceTest, HandleCreateRemoveGetNull) {
  auto s = std::make_shared<TestStruct>();
  s->t1 = 5;
  s->t2 = 8;
  TestHalHandle handle = resource.Allocate(s);
  ASSERT_EQ(1, structures().size());
  auto v = resource.Get(handle);
  ASSERT_NE(nullptr, v);
  resource.Free(handle);
  v = resource.Get(handle);
  ASSERT_EQ(nullptr, v);
}
}