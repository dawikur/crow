// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_HPP_
#define FIRMWARE_REPORT_HPP_

#include "config.hpp"
#include "report_customer.hpp"
#include "report_keyboard.hpp"
#include "report_pointer.hpp"

namespace Crow {

class Report {
 public:
  using SendImpl
    = void (*)(Index const id, void const *const data, Index const size);

  Report() : sendImpl{nullptr}, keyboard{} {}

  void setup(SendImpl const newSendImpl) { sendImpl = newSendImpl; }

  void send() {
    send(customer);
    send(keyboard);
    send(pointer);
  }

  void clear() {
    keyboard.keysClear();
    pointer.clear();
  }

  void key(Index const key, bool const wasPressed) {
    keyboard.key(key, wasPressed);
  }

  void modifier(Index const key, bool const wasPressed) {
    keyboard.modifier(key, wasPressed);
  }

  void toggleModifierLock(Index const key) { keyboard.toggleModifierLock(key); }

  void media(Index const key, bool const wasPressed) {
    customer.media(key, wasPressed);
  }

  void pointer_action(Index const id, bool const wasPressed) {
    pointer.action(id, wasPressed);
  }

 private:
  template <class Type>
  void send(Type &report) {
    if (report) {
      (*sendImpl)(report.id(), report.data(), report.size());
      report.commit();
    }
  }

  SendImpl sendImpl;

  Reports::Customer customer;
  Reports::Keyboard keyboard;
  Reports::Pointer  pointer;
};

}  // namespace Crow

#endif  // FIRMWARE_REPORT_HPP_
