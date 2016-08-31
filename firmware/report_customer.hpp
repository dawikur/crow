// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_CUSTOMER_HPP_
#define FIRMWARE_REPORT_CUSTOMER_HPP_

#include "config.hpp"

namespace Crow {
namespace Reports {

class Customer {
 public:
  Customer() : changed{false} {}

  explicit operator bool () const {
    return changed;
  }

  void commit() {
    changed = false;
  }

  void media(Index const key, bool const wasPressed) {
    changed = true;
  }

  static Index constexpr id() { return 3; }
  void const *data() const { return nullptr; }
  Index size() const { return 0; }

 private:
  bool changed;
};


static uint8_t const CustomerDescriptor[] PROGMEM = {
};

}  // namespace Report
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
