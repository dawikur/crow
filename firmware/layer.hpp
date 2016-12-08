// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_LAYER_HPP_
#define FIRMWARE_LAYER_HPP_

#include "config.hpp"
#include "report.hpp"

namespace Crow {

class Layer {
 public:
  using Function = void (*)(Report &, Layer &, bool const);
  using Raw = const Function[RowsCount][ColsCount];
  using SetCallbackImpl = void(*)(Index const);

  constexpr static Index Base = 0;

  Layer() : raw{nullptr}, setCallbackImpl{nullptr}, current{0}, locked{false} {}
  Layer(Layer const &) = delete;

  void setup(Raw const *const newRaw, SetCallbackImpl const newSetCallbackImpl) {
    raw = newRaw;
    setCallbackImpl = newSetCallbackImpl;
  }

  auto operator[](Index const index) -> Function const* {
    return raw[current][index];
  }

  void set(Index const number) {
    if (!locked) {
      current = number;
      setCallbackImpl(current);
    }
  }

  void toggleLock() {
    locked = !locked;
  }

 private:
  Raw *raw;
  SetCallbackImpl setCallbackImpl;
  Index current;
  bool locked;
};

}  // namespace Crow

#endif  // FIRMWARE_LAYER_HPP_
