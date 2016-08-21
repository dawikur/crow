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
  auto *bytes = reinterpret_cast<uint8_t const *>(data);
  std::vector<uint8_t> buffor(bytes, bytes + size);
  _usbHid->sendReport(buffor);
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

  void expect_report(std::vector<uint8_t> const &bytes) {
    EXPECT_CALL(usbHid, sendReport(bytes)).WillOnce(::testing::Return(1));
  }

  Crow::Firmware firmware;

  Crow::Mock::Hardware hardware;
  Crow::Mock::USBHid usbHid;
};

using namespace Crow::Keymap;

TEST_F(firmware_test, not_pressing_any_key_will_not_send_report) {
  expect_rows({0, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, pressing_one_key_will_send_report_with_that_key) {
  expect_rows({0, 0, 2, 0, 0});
  expect_report({0, 0, Key_A, 0, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, pressing_and_releasing_key_will_send_two_reports) {
  expect_rows({0, 0, 4, 0, 0});
  expect_report({0, 0, Key_S, 0, 0, 0, 0, 0});

  firmware.loop();

  expect_rows({0, 0, 0, 0, 0});
  expect_report({0, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test,
       when_pressing_three_keys_they_will_be_send_in_one_report) {
  expect_rows({32, 4, 64, 0, 0});
  expect_report({0, 0, Key_5, Key_W, Key_H, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, pressed_modifier_will_be_send) {
  expect_rows({0, 0, 1, 0, 0});
  expect_report({
    Modifier_CtrlL, 0, 0, 0, 0, 0, 0, 0,
  });

  firmware.loop();
}

TEST_F(firmware_test, pressed_multiple_modifiers_will_be_send) {
  expect_rows({0, 0, 1, 1, 0});
  expect_report({
    Modifier_CtrlL | Modifier_ShiftL, 0, 0, 0, 0, 0, 0, 0,
  });

  firmware.loop();
}

TEST_F(firmware_test, modifiers_can_be_unpressed) {
  expect_rows({0, 0, 0, 0, 16});
  expect_report({Modifier_AltR, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();

  expect_rows({0, 0, 0, 0, 0});
  expect_report({0, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, modifiers_press_can_be_combined_with_normal_keys) {
  expect_rows({0, 32, 1, 8, 16});
  expect_report({Modifier_AltR | Modifier_CtrlL, 0, Key_T, Key_C, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, first_layer_can_be_reached) {
  expect_rows({0, 0, 0, 0, 1});
  expect_report({0, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();

  expect_rows({2, 0, 0, 0, 1});
  expect_report({0, 0, Key_F1, 0, 0, 0, 0, 0});

  firmware.loop();
}

TEST_F(firmware_test, can_click_on_first_layer_and_than_back_on_default_one) {
  expect_rows({0, 0, 0, 0, 1});
  expect_report({0, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();

  expect_rows({0, 0, 512, 0, 1});
  expect_report({0, 0, Key_Right, 0, 0, 0, 0, 0});

  firmware.loop();


  expect_rows({0, 0, 0, 0, 0});
  expect_report({0, 0, 0, 0, 0, 0, 0, 0});

  firmware.loop();

  expect_rows({4, 0, 0, 0, 0});
  expect_report({0, 0, Key_2, 0, 0, 0, 0, 0});

  firmware.loop();
}

