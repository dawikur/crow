// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#include "firmware.hpp"

#include <vector>

#include "gtest.h"

#include "mock.hpp"

namespace Functions {

Crow::Mock::Hardware *_hardware;
Crow::Mock::USBHid *_usbHid;

Crow::Row getRow(Crow::Index const i) {
  return _hardware->getRow(i);
}

void sendReport(void const *const data, Crow::Index const size) {
  return _usbHid->sendReport(data, size);
}

}  // namespace Functions

class firmware_test : public ::testing::Test {
 protected:
  void SetUp() override {
    Functions::_hardware = &hardware;
    Functions::_usbHid = &usbHid;
    firmware.setup(Functions::getRow, Functions::sendReport);
  }

  void TearDown() override {
    Functions::_usbHid = nullptr;
    Functions::_hardware = nullptr;
  }

  void expect_rows(std::vector<Crow::RawRow> const &rows) {
    for (Crow::Index index = 0; index < Crow::RowsCount; ++index) {
      EXPECT_CALL(hardware, getRow(index))
        .WillOnce(::testing::Return(Crow::Row{rows[index]}));
    }
  }

  Crow::Firmware firmware;

  Crow::Mock::Hardware hardware;
  Crow::Mock::USBHid usbHid;
};

TEST_F(firmware_test, not_pressing_any_key_will_not_send_report) {
  expect_rows({0, 0, 0, 0, 0});

  firmware.loop();
}

