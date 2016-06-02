#pragma once

#include "handles/LimitedHandleResource.h"
#include "HAL/Handles.h"

#include "gtest/gtest.h" 

#define COUNT 8
namespace hal {

typedef HalHandle TestHalHandle;

struct TestStruct {
  int t1;
  int t2;
};

class LimitedHandleResourceTest : public ::testing::Test {
 public:
  LimitedHandleResource<TestHalHandle, TestStruct, COUNT, HalHandleEnum::DIO> resource;
  
  bool* Allocated() { return resource.m_allocated; }
};

}