// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef TEST_FIRMWARE_MOCK_HPP_
#define TEST_FIRMWARE_MOCK_HPP_

#include "config.hpp"

#include "gmock.h"

namespace Crow {

class Hardware {
 public:
  ~Hardware() = default;

  virtual Row getRow(Index const i) = 0;
};

class USBHid {
 public:
  ~USBHid() = default;

  virtual void sendReport(void const *const data, Index const size) = 0;
};

namespace Mock {

class Hardware : public ::Crow::Hardware {
 public:
  MOCK_METHOD1(getRow, Row(Index const));
};

class USBHid : public ::Crow::USBHid {
 public:
  MOCK_METHOD2(sendReport, void(void const *const, Index const));
};

}  // namespace Mock

}  // namespace Crow

#endif  // TEST_FIRMWARE_MOCK_HPP_
