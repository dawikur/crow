// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_KEYMAP_BEGIN_HPP_
#define FIRMWARE_KEYMAP_BEGIN_HPP_

#include "config.hpp"
#include "layer.hpp"
#include "report.hpp"

#include "keymap_keys.hpp"

#define Nop() [](Crow::Report &, Crow::Layer &, bool const) {}

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
#define L(number)                                                              \
  [](Crow::Report &report, Crow::Layer &layer, bool const wasPressed) {        \
    report.clear();                                                            \
    layer.set(wasPressed ? number : Crow::Layer::Base);                        \
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
#define P(m_id)                                                                \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.pointer_action(Crow::Keymap::Pointer_##m_id, wasPressed);           \
  }

#define PC(in_button)                                                          \
  [](Crow::Report &report, Crow::Layer &, bool const wasPressed) {             \
    report.click(Crow::Keymap::Pointer_Button##in_button, wasPressed);         \
  }

#endif  // FIRMWARE_KEYMAP_BEGIN_HPP_
