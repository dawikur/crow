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
    using SetCurrent = void (*)(Index const);

    constexpr static Index Base = 0;

    Layer(Raw const *const raw, SetCurrent const setCurrent)
        : raw{raw}
        , setCurrent{setCurrent}
        , current{0}
        , isLocked{false} {}

    Layer()              = delete;
    Layer(Layer const &) = delete;

    auto operator[](Index const index) -> Function const * {
        return raw[current][index];
    }

    void change(Index const from, Index const to) {
        current = isLocked ? from : to;
        setCurrent(current);
    }

    void toggleLock() { isLocked = !isLocked; }

  private:
    Raw *      raw;
    SetCurrent setCurrent;
    Index      current;
    bool       isLocked;
};

}  // namespace Crow

#endif  // FIRMWARE_LAYER_HPP_
