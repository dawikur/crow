// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_BASE_HPP_
#define FIRMWARE_REPORT_BASE_HPP_

#include "config.hpp"

namespace Crow {
namespace Reports {

template <Index Id, class RawReport>
class Base {
 public:
  Base() : changed{false} {}

  explicit operator bool() const { return changed; }

  void commit() { changed = false; }

  static Index constexpr id() { return Id; }
  void const *data() const { return &raw; }
  Index       size() const { return sizeof(raw); }

 protected:
  void markChanged() { changed = true; }
  
  RawReport raw;

 private:
  bool changed;
};

}  // namespace Reports
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
