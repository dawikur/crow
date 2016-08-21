// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_LAYER_HPP_
#define CROW_LAYER_HPP_

#include "config.hpp"
#include "report.hpp"

namespace Crow {

using Function = void (*)(Report &, Index &, bool const);
using Layer = const Function[RowsCount][ColsCount];

}  // namespace Crow

#endif  // CROW_LAYER_HPP_
