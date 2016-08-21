// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_REPORT_HPP_
#define CROW_REPORT_HPP_

#include "config.hpp"

namespace Crow {

class Report {
 public:
  Report() : raw{0}, lockedModifiers{0} {}

  void key(Index const key, bool const wasPressed) {
    wasPressed ? process_key_press(key) : process_key_release(key);
  }

  void modifier(Index const key, bool const wasPressed) {
    wasPressed ? process_modifier_press(key) : process_modifier_release(key);
  }

  void toggleModifierLock(Index const key) {
    if (lockedModifiers & key) {
      lockedModifiers &= ~key;
      process_modifier_release(key);
    } else {
      lockedModifiers |= key;
      process_modifier_press(key);
    }
  }

  void const *data() const { return &raw; }
  Index size() const { return 8; }

 private:
  void process_key_press(Index const key) {
    for (int i = 0; i < 6; ++i) {
      if (raw.keys[i] == key) {
        return;
      }
      if (raw.keys[i] == 0x00) {
        raw.keys[i] = key;
        return;
      }
    }
  }

  void process_key_release(Index const key) {
    for (int i = 0; i < 6; ++i) {
      if (raw.keys[i] == key) {
        raw.keys[i] = 0x00;
        return;
      }
    }
  }

  void process_modifier_press(Index const key) { raw.modifiers |= key; }

  void process_modifier_release(Index const key) { raw.modifiers &= ~key; }

  struct RawReport {
    uint8_t modifiers;
    uint8_t reserved;
    uint8_t keys[6];
  } raw;

  uint8_t lockedModifiers;
};

}  // namespace Crow

#endif  // CROW_REPORT_HPP_
