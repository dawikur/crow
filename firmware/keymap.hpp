// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_KEYMAP_HPP_
#define CROW_KEYMAP_HPP_

#include "keymap_begin.hpp"

namespace Crow {

Function const Layers[][RowsCount][ColsCount] PROGMEM = {

//
// Layer 0
//
// ,____,____,____,____,____,____,____,____,____,____,____,____,____,________,
// |~   |!   |@   |#   |$   |%   |^   |&   |*   |(   |)   |_   |+   |BackSp  |
// | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  |        |
// ;______,____,____,____,_____,____,____,____,____,____,____,____,____,_____;
// |Tab   |Q   |W   |E   |R    |T   |Y   |U   |I   |O   |P   |{   |}   ||    |
// |      |    |    |    |     |    |    |    |    |    |    | [  | ]  | \   |
// ;_______,____,____,____,_____,____,____,____,____,____,____,____,_________;
// |CtrlL  |A   |S   |D   |F    |G   |H   |J   |K   |L   |:   |"   |Enter    |
// |       |    |    |    |     |    |    |    |    |    | ;  | '  |         |
// ;_______,____,____,____,_____,____,____,____,____,____,____,______________;
// |ShiftL   |Z   |X   |C   |V    |B   |N   |M   |<   |>   |?   |ShiftR      |
// |         |    |    |    |     |    |    |    | ,  | .  | /  |            |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |Fn1  |GUIL |AltL |                               |AltR |GUIR |Menu |Fn2  |
// |     |     |     |                               |     |     |     |     |
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  {
    { K(Aqute),  K(1),    K(2),    K(3),        K(4),    K(5),    K(6),           K(7),  K(8),     K(9),   K(0),            K(Minus),       K(Equal),        K(BackSpace) },
    { K(Tab),    K(Q),    K(W),    K(E),        K(R),    K(T),    K(Y),           K(U),  K(I),     K(O),   K(P),            K(OpenBracket), K(CloseBracket), K(Slash) },
    { M(CtrlL),  K(A),    K(S),    K(D),        K(F),    K(G),    K(H),           K(J),  K(K),     K(L),   K(Semicolon),    K(Apostrophe),  K(Enter),        Nop() },
    { M(ShiftL), K(Z),    K(X),    K(C),        K(V),    K(B),    K(N),           K(M),  K(Comma), K(Dot), K(ForwardSlash), M(ShiftR),      Nop(),           Nop() },
    { Fn(1),     M(GUIL), M(AltL), K(SpaceBar), M(AltR), M(GUIR), K(Application), Fn(2), Nop(),    Nop(),  Nop(),           Nop(),          Nop(),           Nop() }
  },

//
// Layer 1
//
// ,____,____,____,____,____,____,____,____,____,____,____,____,____,________,
// |Esc |F1  |F2  |F3  |F4  |F5  |F6  |F7  |F8  |F9  |F10 |F11 |F12 |Delete  |
// |    |    |    |    |    |    |    |    |    |    |    |    |    |        |
// ;______,____,____,____,_____,____,____,____,____,____,____,____,____,_____;
// |Fn1   |    |Pau-|    |     |    |Copy|Undo|Ins |    |Pas-|    |    |     |
// |Toggle|    | se |    |     |    |    |    | CP |    | te |    |    |     |
// ;_______,____,____,____,_____,____,____,____,____,____,____,____,_________;
// |Caps   |End |Prt-|    |PgDn |Home|<-- | |  |^   |--> |    |    |Enter    |
// | Lock  |    | Sc |    |     |    |    | V  ||   |    |    |    |         |
// ;_______,____,____,____,_____,____,____,____,____,____,____,______________;
// |Shift    |    |Del |    |     |PgUp|    |    |    |    |    |            |
// | Toggle  |    |    |    |     |    |    |    |    |    |    |            |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |#####|GUIL |AltL |                               |AltR |GUIR |Menu |     |
// |#####|     |     |                               |     |     |     |     |
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  {
    { K(Esc),           K(F1),   K(F2),     K(F3),       K(F4),   K(F5),   K(F6),          K(F7),   K(F8),  K(F9),    K(F10),       K(F11),        K(F12),          K(Delete) },
    { Fn(1_Toggle),     Nop(),   K(Pause),  Nop(),       Nop(),   Nop(),   K(Copy),        K(Undo), K(Ins), Nop(),    K(Paste),     Nop(),         Nop(),           Nop() },
    { K(CapsLock),      K(End),  K(PrtSc),  Nop(),       K(PgDn), K(Home), K(Left),        K(Down), K(Up),  K(Right), K(Semicolon), K(Apostrophe), K(Enter),        Nop() },
    { Fn(Shift_Toggle), Nop(),   K(Delete), Nop(),       Nop(),   Nop(),   Nop(),          Nop(),   Nop(),  Nop(),    Nop(),        Nop(),         Nop(),           Nop() },
    { Nop(),            M(GUIL), M(AltL),   K(SpaceBar), M(AltR), M(GUIR), K(Application), Nop(),   Nop(),  Nop(),    Nop(),        Nop(),         Nop(),           Nop() }
  },

//
// Layer 2
//
// ,____,____,____,____,____,____,____,____,____,____,____,____,____,________,
// |Esc |    |    |    |    |    |    |    |    |    |    |    |    |Delete  |
// |    | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |10  |11  |12  |        |
// ;______,____,____,____,_____,____,____,____,____,____,____,____,____,_____;
// |Fn2   |Mac |    |    |     |    |    |    |    |Play|Stop|Prev|Next|     |
// |Toggle| Rec|    |    |     |    |    |    |    |    |    |    |    |     |
// ;_______,____,____,____,_____,____,____,____,____,____,____,____,_________;
// |       |    |    |    |     |    |    |    |    |Mute|Vol-|Vol+|Enter    |
// |       |    |    |    |     |    |    |    |    |    |    |    |         |
// ;_______,____,____,____,_____,____,____,____,____,____,____,______________;
// |         |    |    |    |     |    |    |    |-Bri|+Bri|    |            |
// |         |    |    |    |     |    |    |    | gth| gth|    |            |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |     |GUIL |AltL |                               |AltR |GUIR |Menu |#####|
// |     |     |     |                               |     |     |     |#####|
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  { // TODO: 2016-08-19
    { K(Esc),       MK(1),   MK(2),     MK(3),       MK(4),   MK(5),   MK(6),          MK(7),   MK(8),  MK(9), MK(10), MK(11), MK(12), K(Delete) },
    { Fn(2_Toggle), MR(),    Nop(),     Nop(),       Nop(),   Nop(),   Nop(),          Nop(),   Nop(),  Nop(), Nop(),  Nop(),  Nop(),  Nop() },
    { Nop(),        Nop(),   Nop(),     Nop(),       Nop(),   Nop(),   Nop(),          Nop(),   Nop(),  Nop(), Nop(),  Nop(),  Nop(),  Nop() },
    { Nop(),        Nop(),   K(Delete), Nop(),       Nop(),   Nop(),   Nop(),          Nop(),   Nop(),  Nop(), Nop(),  Nop(),  Nop(),  Nop() },
    { Nop(),        M(GUIL), M(AltL),   K(SpaceBar), M(AltR), M(GUIR), K(Application), Nop(),   Nop(),  Nop(), Nop(),  Nop(),  Nop(),  Nop() }
  }

};

}  // namespace Crow

#include "keymap_end.hpp"

#endif  // CROW_KEYMAP_HPP_
