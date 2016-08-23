// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_LAYER_HPP_
#define CROW_LAYER_HPP_

#include "config.hpp"
#include "report.hpp"

namespace Crow {

class Layer {
 public:
  using Function = void (*)(Report &, Layer &, bool const);
  using Raw = const Function[RowsCount][ColsCount];

  constexpr static Index Base = 0;

  Layer() : raw{nullptr}, current{0}, locked{false} {}
  Layer(Layer const &) = delete;

  void setup(Raw const *const newRaw) { raw = newRaw; }

  auto operator[](Index const index) -> Function const* { return raw[current][index]; }

  void set(Index const number) {
    if (!locked) {
      current = number;
    }
  }

  void toggleLock() {
    locked = !locked;
  }

 private:
  Raw *raw;
  Index current;
  bool locked;
};

}  // namespace Crow

#endif  // CROW_LAYER_HPP_
