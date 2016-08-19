// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_FUNCTIONS_HPP_
#define CROW_FUNCTIONS_HPP_

namespace Crow {

void Send_Key(Index const key, bool const wasPressed) {}
void Send_Modifier(Index const key, bool const wasPressed) {}

void Function_1(bool const wasPressed) {}
void Function_1_Toggle(bool const wasPressed) {}
void Function_2(bool const wasPressed) {}
void Function_2_Toggle(bool const wasPressed) {}

void Function_Shift_Toggle(bool const wasPressed) {}

void Macro_Rec(bool const wasPressed) {}
void Macro_Key(Index const key, bool const wasPressed) {}

}  // namespace Crow

#endif  // CROW_FUNCTIONS_HPP_
