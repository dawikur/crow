// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_LAYER_HPP_
#define FIRMWARE_LAYER_HPP_

#include "types.hpp"
#include "report.hpp"

namespace Crow {

class Layer {
  public:
    using Function   = void (*)(Report &, Layer &, bool const);
    using Raw        = const Function[RowsCount][ColsCount];

    constexpr static Index Base = 0;

    Layer(Raw const *const raw)
        : raw{raw}
        , current{0}
        , isLocked{false} {}

    Layer()              = delete;
    Layer(Layer const &) = delete;

    auto operator[](Index const index) -> Function const * {
        return raw[current][index];
    }

    void change(Index const from, Index const to) {
        current = isLocked ? from : to;
    }

    void toggleLock(Index const from) {
        if (isLocked) {
            isLocked = false;
            current = from;
        } else {
            isLocked = true;
        }
    }

  private:
    Raw *      raw;
    Index      current;
    bool       isLocked;
};

}  // namespace Crow

#endif  // FIRMWARE_LAYER_HPP_
