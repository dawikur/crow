// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_REPORT_HPP_
#define FIRMWARE_REPORT_HPP_

#include "types.hpp"
#include "report_customer.hpp"
#include "report_keyboard.hpp"
#include "report_pointer.hpp"

namespace Crow {

class Report {
  public:
    using Send
        = void (*)(Index const id, void const *const data, Index const size);

    Report(Send const sendImpl) : sendImpl{sendImpl}, keyboard{} {}

    Report() = delete;

    void send() {
        send(customer);
        send(keyboard);
        send(pointer);
    }

    void clear() {
        customer.clear();
        keyboard.clear();
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

    void move(Index const id, bool const wasPressed) {
        pointer.move(id, wasPressed);
    }

    void scroll(Index const id, bool const wasPreseed) {
        pointer.scroll(id, wasPreseed);
    }

    void click(Index const button, bool const wasPressed) {
        pointer.click(button, wasPressed);
    }

  private:
    template <class Type>
    void send(Type &report) {
        if (report) {
            (*sendImpl)(report.id(), report.data(), report.size());
            report.commit();
        }
    }

    Send sendImpl;

    Reports::Customer customer;
    Reports::Keyboard keyboard;
    Reports::Pointer  pointer;
};

}  // namespace Crow

#endif  // FIRMWARE_REPORT_HPP_
