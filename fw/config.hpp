// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_CONFIG_HPP_
#define CROW_CONFIG_HPP_

#include <cstdint>

namespace Crow {

using Data   = uint16_t;
using Index  = uint8_t;
using RawRow = int16_t;

namespace Config {

constexpr Index Rows = 5;
constexpr Index Cols = 15;

}  // namespace Config

namespace Keymap {

}  // namespace Keymap

}  // namespace Crow

#endif  // CROW_CONFIG_HPP_
