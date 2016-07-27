#pragma once

namespace hal {
class DataBase {
 public:
  virtual void ResetData() = 0;
 protected:
  // TODO: Figure out event handling
};
}
