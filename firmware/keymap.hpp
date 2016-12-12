// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef FIRMWARE_KEYMAP_HPP_
#define FIRMWARE_KEYMAP_HPP_

#include "keymap_begin.hpp"

namespace Crow {

Layer::Function const Layers[][RowsCount][ColsCount] = {

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
// ;_________,____,____,____,_____,____,____,____,____,____,____,____________;
// |ShiftL   |Z   |X   |C   |V    |B   |N   |M   |<   |>   |?   |ShiftR      |
// |         |    |    |    |     |    |    |    | ,  | .  | /  |            |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |Layer|GUIL |AltL |                               |AltR |GUIR |Menu |Layer|
// | 1   |     |     |                               |     |     |     | 2   |
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  {
    { K(Aqute)       , K(1)           , K(2)           , K(3)           , K(4)           , K(5)           , K(6)           , K(7)           , K(8)           , K(9)           , K(0)           , K(Minus)       , K(Equal)         },
    { K(Tab)         , K(Q)           , K(W)           , K(E)           , K(R)           , K(T)           , K(Y)           , K(U)           , K(I)           , K(O)           , K(P)           , K(OpenBracket) , K(CloseBracket)  },
    { M(CtrlL)       , K(A)           , K(S)           , K(D)           , K(F)           , K(G)           , K(H)           , K(J)           , K(K)           , K(L)           , K(Semicolon)   , K(Apostrophe)  , K(Enter)         },
    { M(ShiftL)      , K(Z)           , K(X)           , K(C)           , K(V)           , K(B)           , K(N)           , K(M)           , K(Comma)       , K(Dot)         , K(ForwardSlash), M(ShiftR)      , K(Slash)         },
    { L(1)           , M(GUIL)        , M(AltL)        , Nop()          , Nop()          , K(SpaceBar)    , Nop()          , Nop()          , M(AltR)        , M(GUIR)        , K(Application) , L(2)           , K(BackSpace)     }
  },

//
// Layer 1
//
// ,____,____,____,____,____,____,____,____,____,____,____,____,____,________,
// |Esc |F1  |F2  |F3  |F4  |F5  |F6  |F7  |F8  |F9  |F10 |F11 |F12 |Delete  |
// |    |    |    |    |    |    |    |    |    |    |    |    |    |        |
// ;______,____,____,____,_____,____,____,____,____,____,____,____,____,_____;
// |Layer |    |Pau-|    |Ins  |    |    |    |Home|    | ^  |<-- |--> |     |
// | Lock |    | se |    | CP  |    |    |    |    |    | |  |    |    |     |
// ;_______,____,____,____,_____,____,____,____,____,____,____,____,_________;
// |CtrlL  |End |Prt-|    |PgDn |Home|<-- | |  | ^  |--> |    |    |Enter    |
// |       |    | Sc |    |     |    |    | V  | |  |    |    |    |         |
// ;_________,____,____,____,_____,____,____,____,____,____,____,____________;
// |ShiftL   |    |Del |    |     |PgUp|    | |  |    |    |    |ShiftR      |
// |         |    |    |    |     |    |    | V  |    |    |    |            |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |Layer|GUIL |AltL |                               |AltR |GUIR |Menu |     |
// |#1###|     |     |                               |     |     |     |     |
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  {
    { K(Esc)         , K(F1)          , K(F2)          , K(F3)      , K(F4)              , K(F5)          , K(F6)          , K(F7)          , K(F8)          , K(F9)          , K(F10)         , K(F11)         , K(F12)          },
    { LL()           , Nop()          , K(Pause)       , Nop()      , K(Ins)             , Nop()          , Nop()          , Nop()          , K(Home)        , Nop()          , K(Up)          , K(Left)        , K(Right)        },
    { M(CtrlL)       , K(End)         , K(PrtSc)       , Nop()      , K(PgDn)            , Nop()          , K(Left)        , K(Down)        , K(Up)          , K(Right)       , Nop()          , Nop()          , K(Enter)        },
    { M(ShiftL)      , Nop()          , K(Delete)      , Nop()      , Nop()              , K(PgUp)        , K(Down)        , Nop()          , Nop()          , Nop()          , Nop()          , ML(ShiftR)     , Nop()           },
    { L(1)           , M(GUIL)        , M(AltL)        , Nop()      , Nop()              , K(SpaceBar)    , Nop()          , Nop()          , M(AltR)        , M(GUIR)        , K(Application) , Nop()          , K(Delete)       }
  },

//
// Layer 2
//
// ,____,____,____,____,____,____,____,____,____,____,____,____,____,________,
// |Esc | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |10  |11  |12  |BackSp  |
// |    |    |    |    |    |    |    |    |    |    |    |    |    |        |
// ;______,____,____,____,_____,____,____,____,____,____,____,____,____,_____;
// |Layer |Mac |    |    |     |    |    |    |    |Play|Stop|Prev|Next|     |
// | Lock | Rec|    |    |     |    |    |    |    |    |    |    |    |     |
// ;_______,____,____,____,_____,____,____,____,____,____,____,____,_________;
// |       |    |    |    |     |    |    |    |    |Mute|Vol-|Vol+|Enter    |
// |       |    |    |    |     |    |    |    |    |    |    |    |         |
// ;_________,____,____,____,_____,____,____,____,____,____,____,____________;
// |ShiftL   |    |    |    |     |    |    |    |-Bri|+Bri|    |ShiftR      |
// | Lock    |    |    |    |     |    |    |    | gth| gth|    | Lock       |
// ;_____,_____,_____ ,______________________________,_____,_____,_____,_____,
// |     |GUIL |AltL |                               |AltR |GUIR |Menu |Layer|
// |     |     |     |                               |     |     |     |#2###|
// `-----`-----`-----`-------------------------------`-----`-----`-----`-----`

  {
    { K(Esc)         , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()          , Nop()            },
    { LL()           , Nop()          , P(Up)          , Nop()          , PC(Backward)   , PS(Up)         , Nop()          , Nop()          , Nop()          , C(Play_Pause)  , C(Stop)        , C(PrevTrack)   , C(NextTrack)     },
    { Nop()          , P(Left)        , P(Down)        , P(Right)       , PS(Left)       , PS(Down)       , PS(Right)      , Nop()          , Nop()          , C(Mute)        , C(VolumeDown)  , C(VolumeUp)    , K(Enter)         },
    { ML(ShiftL)     , PC(Left)       , PC(Middle)     , PC(Right)      , PC(Forward)    , Nop()          , Nop()          , Nop()          , C(BrightDown)  , C(BrightUp)    , Nop()          , ML(ShiftR)     , Nop()            },
    { Nop()          , M(GUIL)        , M(AltL)        , Nop()          , Nop()          , K(SpaceBar)    , Nop()          , Nop()          , M(AltR)        , M(GUIR)        , K(Application) , L(2)           , K(BackSpace)     }
  }
};

}  // namespace Crow

#include "keymap_end.hpp"

#endif  // FIRMWARE_KEYMAP_HPP_
