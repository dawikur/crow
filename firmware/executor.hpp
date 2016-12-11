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
  Executor() : report{}, layer{} {}

  Executor(Executor const &) = delete;

  void setup(Report::SendImpl const       sendReportImpl,
             Layer::Raw const *const      newLayers,
             Layer::SetCallbackImpl const setCallbackImpl) {
    report.setup(sendReportImpl);
    layer.setup(newLayers, setCallbackImpl);
  }

  void operator()(Event const event) {
    layer[event.row][event.col](report, layer, event.wasPressed);
  }

  void operator()() { report.send(); }

 private:
  Report report;

  Layer layer;
};

}  // namespace Crow

#endif  // FIRMWARE_EXECUTOR_HPP_
