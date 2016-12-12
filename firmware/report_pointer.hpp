// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_POINTER_HPP_
#define FIRMWARE_REPORT_POINTER_HPP_

#include "report_base.hpp"

namespace Crow {
namespace Reports {

union PointerRaw {
  PointerRaw() : _{0} {}

  struct Button {
    static constexpr int8_t Left    = 0x1 << 0;
    static constexpr int8_t Right   = 0x1 << 1;
    static constexpr int8_t Middle  = 0x1 << 2;
    static constexpr int8_t Back    = 0x1 << 3;
    static constexpr int8_t Forward = 0x1 << 4;
  };

  struct {
    int8_t buttons;
    int8_t x;
    int8_t y;
    int8_t wheel;
  };
  int8_t _[4];
};

class Pointer : public Base<1, PointerRaw> {
  using Base = Base<1, PointerRaw>;

  static constexpr int8_t Speed = 5;

 public:
  Pointer() : Base{} {}

  explicit operator bool() const override {
    return Base::operator bool() || raw.x != 0 || raw.y != 0;
  }

#define update_move(V, P, C)                                                   \
  do {                                                                         \
    if (raw.V C 0) {                                                           \
      if (P(Speed << 1) C raw.V)                                               \
        raw.V P## = 1;                                                         \
      else if (P(Speed * 5) C raw.V)                                           \
        raw.V P## = Speed;                                                     \
    }                                                                          \
  } while (0)

  void commit() {
    update_move(x, +, >);
    update_move(x, -, <);
    update_move(y, +, >);
    update_move(y, -, <);

    Base::commit();
  }

#undef update_move

  void clear() {
    raw.buttons = 0;
    raw.x       = 0;
    raw.y       = 0;
    raw.wheel   = 0;
  }

  void action(Index const id, bool const wasPressed) {
    wasPressed ? process_action_begin(id) : process_action_end(id);
    markChanged();
  }

 private:
  void process_action_begin(Index const id) {
    switch (id) {
      case '+' ^ 'x': raw.x = Speed; break;
      case '-' ^ 'x': raw.x = -Speed; break;
      case '+' ^ 'y': raw.y = Speed; break;
      case '-' ^ 'y': raw.y = -Speed; break;

      case 'B' ^ 'L': raw.buttons |= PointerRaw::Button::Left; break;
      case 'B' ^ 'R': raw.buttons |= PointerRaw::Button::Right; break;
      case 'B' ^ 'M': raw.buttons |= PointerRaw::Button::Middle; break;
    }
  }

  void process_action_end(Index const id) {
    switch (id) {
      case '+' ^ 'x':
        if (raw.x > 0)
          raw.x = 0x00;
        break;
      case '-' ^ 'x':
        if (raw.x < 0)
          raw.x = 0x00;
        break;
      case '+' ^ 'y':
        if (raw.y > 0)
          raw.y = 0x00;
        break;
      case '-' ^ 'y':
        if (raw.y < 0)
          raw.y = 0x00;
        break;

      case 'B' ^ 'L': raw.buttons &= ~PointerRaw::Button::Left; break;
      case 'B' ^ 'R': raw.buttons &= ~PointerRaw::Button::Right; break;
      case 'B' ^ 'M': raw.buttons &= ~PointerRaw::Button::Middle; break;
    }
  }
};

static uint8_t const PointerDescriptor[] PROGMEM = {
  0x05, 0x01,                    // USAGE_PAGE (GENERIC DESKTOP)
  0x09, 0x02,                    // USAGE (MOUSE)
  0xa1, 0x01,                    // COLLECTION (APPLICATION)
  0X85, Pointer::id(),           //   REPORT_ID (1)

  0x05, 0x09,                    //   USAGE_PAGE (BUTTON)
  0x19, 0x01,                    //   USAGE_MINIMUM (BUTTON 1)
  0x29, 0x05,                    //   USAGE_MAXIMUM (BUTTON 5)
  0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
  0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
  0x95, 0x05,                    //   REPORT_COUNT (5)
  0x75, 0x01,                    //   REPORT_SIZE (1)
  0x81, 0x02,                    //   INPUT (DATA,VAR,ABS)

  0x95, 0x01,                    //   REPORT_COUNT (1)
  0x75, 0x03,                    //   REPORT_SIZE (3)
  0x81, 0x03,                    //   INPUT (CNST,VAR,ABS)

  0x05, 0x01,                    //   USAGE_PAGE (GENERIC DESKTOP)
  0x09, 0x30,                    //   USAGE (X)
  0x09, 0x31,                    //   USAGE (Y)
  0x09, 0x38,                    //   USAGE (WHEEL)
  0x15, 0x81,                    //   LOGICAL_MINIMUM (-127)
  0x25, 0x7f,                    //   LOGICAL_MAXIMUM (127)
  0x75, 0x08,                    //   REPORT_SIZE (8)
  0x95, 0x03,                    //   REPORT_COUNT (3)
  0x81, 0x06,                    //   INPUT (DATA,VAR,REL)

  0xc0,                          // END_COLLECTION
};

}  // namespace Reports
}  // namespace Crow

#endif  // FIRMWARE_REPORT_CUSTOMER_HPP_
