// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_SYSTEM_HPP_
#define FIRMWARE_SYSTEM_HPP_

#include "config.hpp"

namespace Crow {

class System {
 public:
  using SendReportImpl = void (*)(void const *const data, Index const size);

  System() = default;
  System(System const &) = delete;

  void setup(SendReportImpl const newSendReportImpl) {
    sendReportImpl = newSendReportImpl;
  }

  void sendReport(void const *const data, Index const size) {
    (*sendReportImpl)(data, size);
  }

 public:
  SendReportImpl sendReportImpl;
};

}  // namespace Crow

#endif  // FIRMWARE_SYSTEM_HPP_
