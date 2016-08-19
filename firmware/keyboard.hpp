// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_KEYBOARD_HPP_
#define CROW_KEYBOARD_HPP_

namespace Crow {

class Keyboard_ {
 public:
  void send() {}

  void key(Index const key, bool const wasPressed) {}
  void modifier(Index const key, bool const wasPressed) {}
};

inline Keyboard_& Keyboard() {
  static Keyboard_ impl;
  return impl;
}

}  // namespace Crow

#endif  // CROW_KEYBOARD_HPP_
