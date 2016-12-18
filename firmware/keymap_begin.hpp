// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_KEYMAP_BEGIN_HPP_
#define FIRMWARE_KEYMAP_BEGIN_HPP_

#include "config.hpp"
#include "layer.hpp"
#include "report.hpp"

#include "keymap_keys.hpp"

namespace Crow {

#define Nop()                                                                   \
  [](Crow::Report &, Crow::Layer &, bool const) {}

// Key
#define K(in_key)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.key(Crow::Keymap::Key_##in_key, wasPressed);                        \
  }

// Modifier
#define M(in_key)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.modifier(Crow::Keymap::Modifier_##in_key, wasPressed);              \
  }

// Modifier Lock
#define ML(in_key)                                                             \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    if (wasPressed) {                                                          \
      report.toggleModifierLock(Crow::Keymap::Modifier_##in_key);              \
    }                                                                          \
  }

// Layer
#define L(in_from, in_to)                                                      \
  [](Crow::Report &report, Crow::Layer &layer, bool const wasPressed) {        \
    report.clear();                                                            \
    layer.set(wasPressed ? in_to : in_from);                                   \
  }

// Layer Lock
#define LL()                                                                   \
  [](Crow::Report &, Crow::Layer &layer, bool const wasPressed) {              \
    if (wasPressed) {                                                          \
      layer.toggleLock();                                                      \
    }                                                                          \
  }

// Customer Media
#define C(in_key)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.media(Crow::Keymap::Media_##in_key, wasPressed);                    \
  }

// Pointer
#define P(in_id)                                                               \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.move(Crow::Keymap::Pointer_Move##in_id, wasPressed);                \
  }

#define PS(in_id)                                                              \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.scroll(Crow::Keymap::Pointer_Scroll##in_id, wasPressed);            \
  }

#define PC(in_button)                                                          \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.click(Crow::Keymap::Pointer_Button##in_button, wasPressed);         \
  }

}  // namespace Crow

#endif  // FIRMWARE_KEYMAP_BEGIN_HPP_
