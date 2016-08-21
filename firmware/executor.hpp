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
  Executor()
    : updateNeeded{false}, report{}, system{}, current{0}, layers{nullptr} {}

  Executor(Executor const &) = delete;

  void setup(System::SendReportImpl sendReportImpl, Layer *newLayers) {
    system.setup(sendReportImpl);
    layers = newLayers;
  }

  void operator() (Event const event) {
    updateNeeded = true;

    layers[current][event.row][event.col](report, current, event.wasPressed);
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

  Index current;
  Layer *layers;
};

}  // namespace Crow

#endif  // _EXECUTOR_HPP_
