// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_EXECUTOR_HPP_
#define FIRMWARE_EXECUTOR_HPP_

#include "config.hpp"
#include "event.hpp"
#include "layer.hpp"
#include "report.hpp"

namespace Crow {

class Executor {
 public:
  Executor()
    : updateNeeded{false}, report{}, layer{} {}

  Executor(Executor const &) = delete;

  void setup(Report::SendImpl sendReportImpl, Layer::Raw *newLayers) {
    report.setup(sendReportImpl);
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

    report.send();
  }

 private:
  bool updateNeeded;
  Report report;

  Layer layer;
};

}  // namespace Crow

#endif  // FIRMWARE_EXECUTOR_HPP_
