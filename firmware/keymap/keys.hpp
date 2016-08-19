// Copyright 2016, Dawid Kurek, <dawikur@gmail.com>

#ifndef CROW_KEYMAP__KEYS_HPP_
#define CROW_KEYMAP__KEYS_HPP_

#include "config.hpp"

namespace Crow {
namespace Keymap {

// Letters
constexpr Index Key_A            = 0x04;
constexpr Index Key_B            = 0x05;
constexpr Index Key_C            = 0x06;
constexpr Index Key_D            = 0x07;
constexpr Index Key_E            = 0x08;
constexpr Index Key_F            = 0x09;
constexpr Index Key_G            = 0x0A;
constexpr Index Key_H            = 0x0B;
constexpr Index Key_I            = 0x0C;
constexpr Index Key_J            = 0x0D;
constexpr Index Key_K            = 0x0E;
constexpr Index Key_L            = 0x0F;
constexpr Index Key_M            = 0x10;
constexpr Index Key_N            = 0x11;
constexpr Index Key_O            = 0x12;
constexpr Index Key_P            = 0x13;
constexpr Index Key_Q            = 0x14;
constexpr Index Key_R            = 0x15;
constexpr Index Key_S            = 0x16;
constexpr Index Key_T            = 0x17;
constexpr Index Key_U            = 0x18;
constexpr Index Key_V            = 0x19;
constexpr Index Key_W            = 0x1A;
constexpr Index Key_X            = 0x1B;
constexpr Index Key_Y            = 0x1C;
constexpr Index Key_Z            = 0x1D;

// Numbers
constexpr Index Key_1            = 0x1E;
constexpr Index Key_2            = 0x1F;
constexpr Index Key_3            = 0x20;
constexpr Index Key_4            = 0x21;
constexpr Index Key_5            = 0x22;
constexpr Index Key_6            = 0x23;
constexpr Index Key_7            = 0x24;
constexpr Index Key_8            = 0x25;
constexpr Index Key_9            = 0x26;
constexpr Index Key_0            = 0x27;

// Additional
constexpr Index Key_Enter        = 0x28;
constexpr Index Key_Esc          = 0x29;
constexpr Index Key_BackSpace    = 0x2A;
constexpr Index Key_Tab          = 0x2B;
constexpr Index Key_Del          = 0x2C;
constexpr Index Key_Minus        = 0x2D; // - _
constexpr Index Key_Equal        = 0x2E; // = +
constexpr Index Key_OpenBracket  = 0x2F; // [ {
constexpr Index Key_CloseBracket = 0x30; // ] }
constexpr Index Key_Pipe         = 0x31; // \ |
constexpr Index Key_Semicolon    = 0x33; // ; :
constexpr Index Key_Apostrophe   = 0x34; // ' "
constexpr Index Key_Aqute        = 0x35; // ` ~
constexpr Index Key_Comma        = 0x36; // , <
constexpr Index Key_Dot          = 0x37; // . >
constexpr Index Key_ForwardSlash = 0x38; // / ?
constexpr Index Key_PrtSc        = 0x46;
constexpr Index Key_Pause        = 0x48;


// Functional
constexpr Index Key_F1           = 0x3A;
constexpr Index Key_F2           = 0x3B;
constexpr Index Key_F3           = 0x3C;
constexpr Index Key_F4           = 0x3D;
constexpr Index Key_F5           = 0x3E;
constexpr Index Key_F6           = 0x3F;
constexpr Index Key_F7           = 0x40;
constexpr Index Key_F8           = 0x41;
constexpr Index Key_F9           = 0x42;
constexpr Index Key_F10          = 0x43;
constexpr Index Key_F11          = 0x44;
constexpr Index Key_F12          = 0x45;
constexpr Index Key_F13          = 0x68;
constexpr Index Key_F14          = 0x69;
constexpr Index Key_F15          = 0x6A;
constexpr Index Key_F16          = 0x6B;
constexpr Index Key_F17          = 0x6C;
constexpr Index Key_F18          = 0x6D;
constexpr Index Key_F19          = 0x6E;
constexpr Index Key_F20          = 0x6F;
constexpr Index Key_F21          = 0x70;
constexpr Index Key_F22          = 0x71;
constexpr Index Key_F23          = 0x72;
constexpr Index Key_F24          = 0x73;

// Locks
constexpr Index Key_CapsLock     = 0x39;;
constexpr Index Key_ScrollLock   = 0x47;
constexpr Index Key_NumLock      = 0x53;

// Controlpad
constexpr Index Key_Ins_CP       = 0x49;
constexpr Index Key_Home_CP      = 0x4A;
constexpr Index Key_PgUp_CP      = 0x4B;
constexpr Index Key_Del_CP       = 0x4C;
constexpr Index Key_End_CP       = 0x4D;
constexpr Index Key_PgDn_CP      = 0x4E;
constexpr Index Key_Right_CP     = 0x4F;
constexpr Index Key_Left_CP      = 0x50;
constexpr Index Key_Down_CP      = 0x51;
constexpr Index Key_Up_CP        = 0x52;

// Keypad
constexpr Index Key_Divide_KP    = 0x54; // /
constexpr Index Key_Multiply_KP  = 0x55; // *
constexpr Index Key_Minus_KP     = 0x56; // -
constexpr Index Key_Plus_KP      = 0x57; // +
constexpr Index Key_Enter_KP     = 0x58; // Return

constexpr Index Key_1_KP         = 0x59; // End
constexpr Index Key_2_KP         = 0x5A; // Down
constexpr Index Key_3_KP         = 0x5B; // PgDn
constexpr Index Key_4_KP         = 0x5C; // Left
constexpr Index Key_6_KP         = 0x5E; // Right
constexpr Index Key_7_KP         = 0x5F; // Home
constexpr Index Key_8_KP         = 0x60; // Up
constexpr Index Key_9_KP         = 0x61; // PgUp
constexpr Index Key_0_KP         = 0x62; // Ins
constexpr Index Key_Comma_KP     = 0x63; // Del

// Extra
constexpr Index Key_WinMenu      = 0x65;

constexpr Index Key_Help         = 0x75;
constexpr Index Key_Undo         = 0x7A;
constexpr Index Key_Cut          = 0x7B;
constexpr Index Key_Copy         = 0x7C;
constexpr Index Key_Paste        = 0x7D;

constexpr Index Key_Mute         = 0x7F;
constexpr Index Key_VolumeUp     = 0x80;
constexpr Index Key_VolumeDown   = 0x81;

}  // namespace Keymap
}  // namespace Crow

#endif  // CROW_KEYMAP__KEYS_HPP_
