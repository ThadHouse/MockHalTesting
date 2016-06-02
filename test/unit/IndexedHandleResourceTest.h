#pragma once

#include "handles/IndexedHandleResource.h"
#include "HAL/Handles.h"

#include "gtest/gtest.h" 

#define COUNT 8
namespace hal {

typedef HalHandle TestHalHandle;

struct TestStruct {
  int t1;
  int t2;
};

class IndexedHandleResourceTest : public ::testing::Test {
 public:
  IndexedHandleResource<TestHalHandle, TestStruct, COUNT, HalHandleEnum::DIO> resource;
  
  bool* Allocated() { return resource.m_allocated; }
};

}