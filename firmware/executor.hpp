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
  Executor(Report::SendImpl const       sendReportImpl,
           Layer::Raw const *const      newLayers,
           Layer::SetCallbackImpl const setCallbackImpl)
    : report{sendReportImpl}, layer{newLayers, setCallbackImpl} {}

  Executor()                 = delete;
  Executor(Executor const &) = delete;

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
