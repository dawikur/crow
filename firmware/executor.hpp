// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef _EXECUTOR_HPP_
#define _EXECUTOR_HPP_

#include "config.hpp"
#include "event.hpp"
#include "keyboard.hpp"
#include "layer.hpp"

namespace Crow {

class Executor_ {
 public:
  Executor_() = default;
  Executor_(Executor_ const &) = delete;

  void setLayer(Layer *newLayer) {
    layer = newLayer;
  }

  void operator() () {
    if (!updateNeeded) {
      return;
    }
    updateNeeded = false;

    Keyboard().send();
  }

  void operator() (Event const event) {
    updateNeeded = true;

    (*layer)[event.row][event.col](event.wasPressed);
  }

 private:
  bool updateNeeded;
  Layer *layer;
};

Executor_& Executor() {
  static Executor_ impl;
  return impl;
}

}  // namespace Crow

#endif  // _EXECUTOR_HPP_
