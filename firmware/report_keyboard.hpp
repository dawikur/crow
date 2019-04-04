// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_KEYBOARD_HPP_
#define FIRMWARE_REPORT_KEYBOARD_HPP_

#include "report_base.hpp"

namespace Crow {
namespace Reports {

struct KeyboardRaw {
    static constexpr int KeysCount = 6;

    KeyboardRaw() : modifiers{0}, reserved{0}, keys{0} {}

    uint8_t modifiers;
    uint8_t reserved;
    uint8_t keys[KeysCount];
};

class Keyboard : public Base<3, KeyboardRaw> {
    using Base = Base<3, KeyboardRaw>;

  public:
    Keyboard() : Base{}, lockedModifiers{0} {}

    void key(Index const key, bool const wasPressed) {
        wasPressed ? process_key_press(key) : process_key_release(key);
        markChanged();
    }

    void keysClear() {
        for (int i = 0; i < KeyboardRaw::KeysCount; ++i) {
            if (raw.keys[i] != 0) {
                raw.keys[i] = 0;
                markChanged();
            }
        }
    }

    void modifier(Index const key, bool const wasPressed) {
        wasPressed ? process_modifier_press(key) : process_modifier_release(key);
        markChanged();
    }

    void toggleModifierLock(Index const key) {
        if (lockedModifiers & key) {
            lockedModifiers &= ~key;
            process_modifier_release(key);
        } else {
            lockedModifiers |= key;
            process_modifier_press(key);
        }
        markChanged();
    }

  private:
    void process_key_press(Index const key) {
        for (int i = 0; i < KeyboardRaw::KeysCount; ++i) {
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
        for (int i = 0; i < KeyboardRaw::KeysCount; ++i) {
            if (raw.keys[i] == key) {
                raw.keys[i] = 0x00;
                return;
            }
        }
    }

    void process_modifier_press(Index const key) { raw.modifiers |= key; }
    void process_modifier_release(Index const key) { raw.modifiers &= ~key; }

    uint8_t lockedModifiers;
};

static uint8_t const KeyboardDescriptor[] PROGMEM = {
    0X05, 0X01,            // USAGE_PAGE (GENERIC DESKTOP)
    0X09, 0X06,            // USAGE (KEYBOARD)
    0XA1, 0X01,            // COLLECTION (APPLICATION)
    0X85, Keyboard::id(),  //   REPORT_ID (3)
    0X05, 0X07,            //   USAGE_PAGE (KEYBOARD)

    0X19, 0XE0,            //   USAGE_MINIMUM (KEYBOARD LEFTCONTROL)
    0X29, 0XE7,            //   USAGE_MAXIMUM (KEYBOARD RIGHT GUI)
    0X15, 0X00,            //   LOGICAL_MINIMUM (0)
    0X25, 0X01,            //   LOGICAL_MAXIMUM (1)
    0X75, 0X01,            //   REPORT_SIZE (1)
    0X95, 0X08,            //   REPORT_COUNT (8)
    0X81, 0X02,            //   INPUT (DATA,VAR,ABS)

    0X95, 0X01,            //   REPORT_COUNT (1)
    0X75, 0X08,            //   REPORT_SIZE (8)
    0X81, 0X03,            //   INPUT (CNST,VAR,ABS)

    0X95, 0X06,            //   REPORT_COUNT (6)
    0X75, 0X08,            //   REPORT_SIZE (8)
    0X15, 0X00,            //   LOGICAL_MINIMUM (0)
    0X25, 0XE7,            //   LOGICAL_MAXIMUM (231)
    0X05, 0X07,            //   USAGE_PAGE (KEYBOARD)
    0X19, 0X00,            //   USAGE_MINIMUM (RESERVED (NO EVENT INDICATED))
    0X29, 0XE7,            //   USAGE_MAXIMUM (KEYBOARD APPLICATION)
    0X81, 0X00,            //   INPUT (DATA, ARY, ABS)

    0XC0,                  // END_COLLECTION
};

}  // namespace Reports
}  // namespace Crow

#endif  // FIRMWARE_REPORT_KEYBOARD_HPP_
