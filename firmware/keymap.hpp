// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_KEYMAP_HPP_
#define FIRMWARE_KEYMAP_HPP_

#include "keymap_begin.hpp"
#include "keymap_keys.hpp"

namespace Crow {

#define CROW_KEYMAP_

Layer::Function const Layers[][RowsCount][ColsCount] =
    #include "config.hpp"
;

#undef CROW_KEYMAP_

}  // namespace Crow

#include "keymap_end.hpp"

#endif  // FIRMWARE_KEYMAP_HPP_
