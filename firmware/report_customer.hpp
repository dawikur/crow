// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_CUSTOMER_HPP_
#define FIRMWARE_REPORT_CUSTOMER_HPP_

#include "config.hpp"

namespace Crow {
namespace Reports {

class Customer {
 public:
  Customer() : changed{false} {}

  explicit operator bool() const { return changed; }

  void commit() { changed = false; }

  void media(Index const key, bool const wasPressed) {
    wasPressed ? process_media_press(key) : process_media_release(key);
    changed = true;
  }

  static Index constexpr id() { return 3; }
  void const *data() const { return &raw; }
  Index       size() const { return sizeof(raw); }

 private:
  void process_media_press(Index const key) { raw |= key; }
  void process_media_release(Index const key) { raw &= ~key; }

  uint16_t raw;
  bool     changed;
};

static uint8_t const CustomerDescriptor[] PROGMEM = {
  0X05, 0X0C,           // USAGE_PAGE (CONSUMER DEVICES)
  0X09, 0X01,           // USAGE (CONSUMER CONTROL)
  0XA1, 0X01,           // COLLECTION (APPLICATION)
  0X85, Customer::id(), //   REPORT_ID (3)
  0X05, 0X0C,           //   USAGE_PAGE (CONSUMER DEVICES)

  0X15, 0X00,           //   LOGICAL_MINIMUM (0)
  0X25, 0X01,           //   LOGICAL_MAXIMUM (1)
  0X75, 0X01,           //   REPORT SIZE (1)
  0X95, 0X10,           //   REPORT_COUNT (16)

  0X09, 0XCD,           //   USAGE (PLAY / PAUSE)                 BIT 0
  0X09, 0XB7,           //   USAGE (STOP)                         BIT 1
  0X09, 0XB6,           //   USAGE (SCAN PREVIOUS TRACK)          BIT 2
  0X09, 0XB5,           //   USAGE (SCAN NEXT TRACK)              BIT 3
  0X09, 0XE2,           //   USAGE (MUTE)                         BIT 4
  0X09, 0XE9,           //   USAGE (VOLUME UP)                    BIT 5
  0X09, 0XEA,           //   USAGE (VOLUME DOWN)                  BIT 6
  0X81, 0X02,           //   INPUT (DATA, VARIABLE, ABSOLUTE)
  0X95, 0X01,           //   REPORT COUNT (1)                     BIT 7
  0X81, 0X01,           //   INPUT (CONSTANT)

  0x09, 0x70,           //   USAGE (BRIGHTNESS DEC)               BIT 0
  0x09, 0x6F,           //   USAGE (BRIGHTNESS INC)               BIT 1
  0X81, 0X02,           //   INPUT (DATA, VARIABLE, ABSOLUTE)
  0X95, 0X05,           //   REPORT COUNT (5)                     BIT 2-7
  0X81, 0X01,           //   INPUT (CONSTANT)

  0XC0                  // END COLLECTION
};

}  // namespace Report
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
