// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_KEYMAP_BEGIN_HPP_
#define CROW_KEYMAP_BEGIN_HPP_

#include "config.hpp"
#include "layer.hpp"
#include "report.hpp"

#include "keymap/keys.hpp"

#define K(in_key)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.key(Crow::Keymap::Key_##in_key, wasPressed);                        \
  }

#define M(in_key)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.modifier(Crow::Keymap::Modifier_##in_key, wasPressed);              \
  }

#define MT(in_key)                                                             \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    if (wasPressed) {                                                          \
      report.toggleModifierLock(Crow::Keymap::Modifier_##in_key);              \
    }                                                                          \
  }

#define L(number)                                                              \
  [](Crow::Report &, Crow::Layer &layer, bool const wasPressed) {              \
    layer.set(wasPressed ? number : Crow::Layer::Base);                        \
  }

#define LT()                                                                   \
  [](Crow::Report &, Crow::Layer &layer, bool const wasPressed) {              \
    if (wasPressed) {                                                          \
      layer.toggleLock();                                                      \
    }                                                                          \
  }

#define Nop() [](Crow::Report &, Crow::Layer &, bool const) {}

#endif  // CROW_KEYMAP_BEGIN_HPP_
