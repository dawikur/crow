// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_HPP_
#define FIRMWARE_REPORT_HPP_

#include "config.hpp"
#include "report_keyboard.hpp"

namespace Crow {

class Report {
 public:
  using SendImpl = void (*)(Index const id,
                            void const *const data,
                            Index const size);

  Report() : sendImpl{nullptr}, keyboard{} {}

  void setup(SendImpl const newSendImpl) {
    sendImpl = newSendImpl;
  }

  void send() {
    if (keyboard) {
      (*sendImpl)(keyboard.id(), keyboard.data(), keyboard.size());
      keyboard.commit();
    }
  }

  void key(Index const key, bool const wasPressed) {
    keyboard.key(key, wasPressed);
  }

  void modifier(Index const key, bool const wasPressed) {
    keyboard.modifier(key, wasPressed);
  }

  void toggleModifierLock(Index const key) {
    keyboard.toggleModifierLock(key);
  }

 private:
  SendImpl sendImpl;

  Reports::Keyboard keyboard;
};

}  // namespace Crow

#endif  // FIRMWARE_REPORT_HPP_
