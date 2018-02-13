// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_KEYMAP_BEGIN_HPP_
#define FIRMWARE_KEYMAP_BEGIN_HPP_

#include "config.hpp"
#include "layer.hpp"
#include "report.hpp"

namespace Crow {

#define Nop() [](Report &, Layer &, bool const) {}

// Key
#define K(in_key)                                                              \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.key(Keymap::Key_##in_key, wasPressed);                              \
  }

// Modifier
#define M(in_key)                                                              \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.modifier(Keymap::Modifier_##in_key, wasPressed);                    \
  }

// Modifier Lock
#define ML(in_key)                                                             \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    if (wasPressed) {                                                          \
      report.toggleModifierLock(Keymap::Modifier_##in_key);                    \
    }                                                                          \
  }

// Layer
#define L(in_from, in_to)                                                      \
  [](Report &report, Layer &layer, bool const wasPressed) {                    \
    report.clear();                                                            \
    if (wasPressed) {                                                          \
      layer.change(in_from, in_to);                                            \
    } else {                                                                   \
      layer.change(in_to, in_from);                                            \
    }                                                                          \
  }

// Layer Lock
#define LL()                                                                   \
  [](Report &, Layer &layer, bool const wasPressed) {                          \
    if (wasPressed) {                                                          \
      layer.toggleLock();                                                      \
    }                                                                          \
  }

// Customer Media
#define C(in_key)                                                              \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.media(Keymap::Media_##in_key, wasPressed);                          \
  }

// Pointer
#define P(in_id)                                                               \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.move(Keymap::Pointer_Move##in_id, wasPressed);                      \
  }

#define PS(in_id)                                                              \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.scroll(Keymap::Pointer_Scroll##in_id, wasPressed);                  \
  }

#define PC(in_button)                                                          \
  [](Report &report, Layer &, bool const wasPressed) {                         \
    report.click(Keymap::Pointer_Button##in_button, wasPressed);               \
  }

}  // namespace Crow

#endif  // FIRMWARE_KEYMAP_BEGIN_HPP_
