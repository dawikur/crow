// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_ROW_HPP_
#define FIRMWARE_ROW_HPP_

#include "config.hpp"

namespace Crow {

class Row {
 public:
  explicit Row(RawRow const raw = 0) : raw{raw} {}

  bool operator[](Index const index) const {
    return static_cast<bool>(raw & (1 << index));
  }

  bool operator== (Row const other) const {
    return raw == other.raw;
  }

  bool operator!= (Row const other) const {
    return raw != other.raw;
  }

 private:
  RawRow raw;
};

}  // namespace Crow

#endif  // FIRMWARE_ROW_HPP_
