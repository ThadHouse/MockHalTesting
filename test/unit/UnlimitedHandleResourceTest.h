#pragma once

#include "handles/UnlimitedHandleResource.h"
#include "HAL/Handles.h"

#include "gtest/gtest.h" 
namespace hal {

typedef HalHandle TestHalHandle;

struct TestStruct {
  int t1;
  int t2;
};

class UnlimitedHandleResourceTest : public ::testing::Test {
 public:
  UnlimitedHandleResource<TestHalHandle, TestStruct, HalHandleEnum::DIO> resource;
 
  std::vector< std::shared_ptr<TestStruct> >& structures() { return resource.m_structures; }
};

}