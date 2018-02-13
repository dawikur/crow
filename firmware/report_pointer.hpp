// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_POINTER_HPP_
#define FIRMWARE_REPORT_POINTER_HPP_

#include "report_base.hpp"

namespace Crow {
namespace Reports {

union PointerRaw {
  PointerRaw() : _{0} {}

  struct {
    int8_t buttons;
    int8_t X;
    int8_t Y;
    int8_t V;
  };
  int8_t _[4];
};

class Pointer : public Base<1, PointerRaw> {
  using Base = Base<1, PointerRaw>;

  static constexpr int8_t Speed = 5;

 public:
  Pointer() : Base{} {}

  explicit operator bool() const override {
    return Base::operator bool() || raw.X != 0 || raw.Y != 0;
  }

#define do_commit(P, V, C)                                                     \
  do {                                                                         \
    if (raw.V C 0) {                                                           \
      if (P(Speed << 1) C raw.V)                                               \
        raw.V P## = 1;                                                         \
      else if (P(Speed * 5) C raw.V)                                           \
        raw.V P## = Speed;                                                     \
    }                                                                          \
  } while (0)

  void commit() {
    do_commit(+, X, >);
    do_commit(-, X, <);
    do_commit(+, Y, >);
    do_commit(-, Y, <);

    do_commit(+, V, >);
    do_commit(-, V, <);

    Base::commit();
  }

#undef do_commit

  void clear() {
    raw.buttons = 0;
    raw.X       = 0;
    raw.Y       = 0;
    raw.V       = 0;
  }

  void move(Index const id, bool const wasPressed) {
    wasPressed ? process_move_begin(id) : process_move_end(id);
    markChanged();
  }

  void scroll(Index const id, bool const wasPressed) {
    wasPressed ? process_scroll_begin(id) : process_scroll_end(id);
    markChanged();
  }

  void click(Index const button, bool const wasPreseed) {
    wasPreseed ? process_click_press(button) : process_click_release(button);
    markChanged();
  }

 private:
#define case_begin(P, V)                                                       \
  case #P[0] ^ #V[0]: raw.V = P(Speed); break

  void process_move_begin(Index const id) {
    switch (id) {
      case_begin(+, X);
      case_begin(-, X);
      case_begin(+, Y);
      case_begin(-, Y);
    }
  }

  void process_scroll_begin(Index const id) {
    switch (id) {
      case_begin(+, V);
      case_begin(-, V);
    }
  }

#undef case_begin

#define case_end(P, V, C)                                                      \
  case #P[0] ^ #V[0]:                                                          \
    if (raw.V C 0) {                                                           \
      raw.V = 0x00;                                                            \
    }                                                                          \
    break

  void process_move_end(Index const id) {
    switch (id) {
      case_end(+, X, >);
      case_end(-, X, <);
      case_end(+, Y, >);
      case_end(-, Y, <);
    }
  }

  void process_scroll_end(Index const id) {
    switch (id) {
      case_end(+, V, >);
      case_end(-, V, <);
    }
  }

#undef case_end

  void process_click_press(Index const button) {
    raw.buttons |= button;
  }

  void process_click_release(Index const button) {
    raw.buttons &= ~button;
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
