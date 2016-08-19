// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_FUNCTIONS_HPP_
#define CROW_FUNCTIONS_HPP_

namespace Crow {

inline void Send_Key(Index const key, bool const wasPressed) {}
inline void Send_Modifier(Index const key, bool const wasPressed) {}

inline void Function_1(bool const wasPressed) {}
inline void Function_1_Toggle(bool const wasPressed) {}
inline void Function_2(bool const wasPressed) {}
inline void Function_2_Toggle(bool const wasPressed) {}

inline void Function_Shift_Toggle(bool const wasPressed) {}

inline void Macro_Rec(bool const wasPressed) {}
inline void Macro_Key(Index const key, bool const wasPressed) {}

}  // namespace Crow

#endif  // CROW_FUNCTIONS_HPP_
