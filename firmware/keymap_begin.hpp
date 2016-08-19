// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_KEYMAP_BEGIN_HPP_
#define CROW_KEYMAP_BEGIN_HPP_

#define K(ey)                                                                  \
  [](bool const wasPressed) { Send_Key(Keymap::Key_##ey, wasPressed); }

#define M(od)                                                                  \
  [](bool const wasPressed) {                                                  \
    Send_Modifier(Keymap::Modifier_##od, wasPressed);                          \
  }

#define Nop() nullptr

#define Fn(Name) Function_##Name

#define MR() [](bool const wasPressed) { Macro_Rec(wasPressed); }
#define MK(Num) [](bool const wasPressed) { Macro_Key(Num, wasPressed); }

#endif  // CROW_KEYMAP_BEGIN_HPP_
