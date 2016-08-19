// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_LAYER_HPP_
#define CROW_LAYER_HPP_

namespace Crow {

using Function = void (*)(bool const);
using Layer = Function **;

}  // namespace Crow

#endif  // CROW_LAYER_HPP_
