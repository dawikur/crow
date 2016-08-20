// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef _EXECUTOR_HPP_
#define _EXECUTOR_HPP_

#include "config.hpp"
#include "event.hpp"
#include "layer.hpp"
#include "report.hpp"
#include "system.hpp"

namespace Crow {

class Executor {
 public:
  Executor() = default;
  Executor(Executor const &) = delete;

  void setup(System::SendReportImpl sendReportImpl, Layer *newLayer) {
    system.setup(sendReportImpl);
    layer = newLayer;
  }

  void operator() (Event const event) {
    updateNeeded = true;

    (*layer)[event.row][event.col](report, event.wasPressed);
  }

  void operator() () {
    if (!updateNeeded) {
      return;
    }
    updateNeeded = false;

    system.sendReport(report.data(), report.size());
  }

 private:
  bool updateNeeded;
  Report report;
  System system;
  Layer *layer;
};

}  // namespace Crow

#endif  // _EXECUTOR_HPP_
