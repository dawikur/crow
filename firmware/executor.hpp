// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_EXECUTOR_HPP_
#define FIRMWARE_EXECUTOR_HPP_

#include "config.hpp"
#include "event.hpp"
#include "layer.hpp"
#include "report.hpp"
#include "system.hpp"

namespace Crow {

class Executor {
 public:
  Executor()
    : updateNeeded{false}, report{}, system{}, layer{} {}

  Executor(Executor const &) = delete;

  void setup(System::SendReportImpl sendReportImpl, Layer::Raw *newLayers) {
    system.setup(sendReportImpl);
    layer.setup(newLayers);
  }

  void operator() (Event const event) {
    updateNeeded = true;

    layer[event.row][event.col](report, layer, event.wasPressed);
  }

  void operator() () {
    if (!updateNeeded) {
      return;
    }
    updateNeeded = false;

    system.sendReport(report.id(), report.data(), report.size());
  }

 private:
  bool updateNeeded;
  Report report;
  System system;

  Layer layer;
};

}  // namespace Crow

#endif  // FIRMWARE_EXECUTOR_HPP_
