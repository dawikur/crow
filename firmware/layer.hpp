// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_LAYER_HPP_
#define FIRMWARE_LAYER_HPP_

#include "config.hpp"
#include "report.hpp"

namespace Crow {

class Layer {
 public:
  using Function        = void (*)(Report &, Layer &, bool const);
  using Raw             = const Function[RowsCount][ColsCount];
  using SetCallbackImpl = void (*)(Index const);

  constexpr static Index Base = 0;

  Layer(Layer const &) = delete;

  Layer(Raw const *const newRaw, SetCallbackImpl const newSetCallbackImpl)
    : raw{nullptr}, setCallbackImpl{nullptr}, current{0}, isLocked{false} {}

  auto operator[](Index const index) -> Function const * {
    return raw[current][index];
  }

  void change(Index const from, Index const to) {
    current = isLocked ? from : to;
    setCallbackImpl(current);
  }

  void toggleLock() { isLocked = !isLocked; }

 private:
  Raw *           raw;
  SetCallbackImpl setCallbackImpl;
  Index           current;
  bool            isLocked;
};

}  // namespace Crow

#endif  // FIRMWARE_LAYER_HPP_
