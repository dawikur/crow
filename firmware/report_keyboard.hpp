// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_KEYBOARD_HPP_
#define FIRMWARE_REPORT_KEYBOARD_HPP_

#include "config.hpp"

namespace Crow {
namespace Reports {

class Keyboard {
 public:
  Keyboard() : raw{0, 0, 0}, lockedModifiers{0}, changed{false} {}

  explicit operator bool () const {
    return changed;
  }

  void commit() {
    changed = false;
  }

  void key(Index const key, bool const wasPressed) {
    wasPressed ? process_key_press(key) : process_key_release(key);
    changed = true;
  }

  void modifier(Index const key, bool const wasPressed) {
    wasPressed ? process_modifier_press(key) : process_modifier_release(key);
    changed = true;
  }

  void toggleModifierLock(Index const key) {
    if (lockedModifiers & key) {
      lockedModifiers &= ~key;
      process_modifier_release(key);
    } else {
      lockedModifiers |= key;
      process_modifier_press(key);
    }
    changed = true;
  }

  static Index constexpr id() { return 2; }
  void const *data() const { return &raw; }
  Index size() const { return sizeof (raw); }

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
  bool changed;
};


static uint8_t const KeyboardDescriptor[] PROGMEM = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, Keyboard::id(),          //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)

    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)

    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0xE7,                    //   LOGICAL_MAXIMUM (231)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0xE7,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

}  // namespace Report
}  // namespace Crow

#endif  // FIRMWARE_REPORT_KEYBOARD_HPP_
