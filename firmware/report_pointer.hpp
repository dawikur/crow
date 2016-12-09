// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_POINTER_HPP_
#define FIRMWARE_REPORT_POINTER_HPP_

#include "config.hpp"

namespace Crow {
namespace Reports {

class Pointer {
 public:
  Pointer() : raw{0}, changed{false} {}

  explicit operator bool() const { return changed; }

  void commit() { changed = false; }

  static Index constexpr id() { return 4; }
  void const *data() const { return &raw; }
  Index       size() const { return sizeof(raw); }

 private:
  uint16_t raw;
  bool     changed;
};

static uint8_t const PointerDescriptor[] PROGMEM = {
};

}  // namespace Reports
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
