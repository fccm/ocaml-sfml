/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2012 Florent Monnier <monnier.florent(_)gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    If you use this software in a product, an acknowledgment
 *    in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include <SFML/Window/Keyboard.hpp>

#include "sf_caml_incs.hpp"

value Val_sfKeyCode(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::A: return Val_int(0);
        case sf::Keyboard::B: return Val_int(1);
        case sf::Keyboard::C: return Val_int(2);
        case sf::Keyboard::D: return Val_int(3);
        case sf::Keyboard::E: return Val_int(4);
        case sf::Keyboard::F: return Val_int(5);
        case sf::Keyboard::G: return Val_int(6);
        case sf::Keyboard::H: return Val_int(7);
        case sf::Keyboard::I: return Val_int(8);
        case sf::Keyboard::J: return Val_int(9);
        case sf::Keyboard::K: return Val_int(10);
        case sf::Keyboard::L: return Val_int(11);
        case sf::Keyboard::M: return Val_int(12);
        case sf::Keyboard::N: return Val_int(13);
        case sf::Keyboard::O: return Val_int(14);
        case sf::Keyboard::P: return Val_int(15);
        case sf::Keyboard::Q: return Val_int(16);
        case sf::Keyboard::R: return Val_int(17);
        case sf::Keyboard::S: return Val_int(18);
        case sf::Keyboard::T: return Val_int(19);
        case sf::Keyboard::U: return Val_int(20);
        case sf::Keyboard::V: return Val_int(21);
        case sf::Keyboard::W: return Val_int(22);
        case sf::Keyboard::X: return Val_int(23);
        case sf::Keyboard::Y: return Val_int(24);
        case sf::Keyboard::Z: return Val_int(25);
        case sf::Keyboard::Num0: return Val_int(26);
        case sf::Keyboard::Num1: return Val_int(27);
        case sf::Keyboard::Num2: return Val_int(28);
        case sf::Keyboard::Num3: return Val_int(29);
        case sf::Keyboard::Num4: return Val_int(30);
        case sf::Keyboard::Num5: return Val_int(31);
        case sf::Keyboard::Num6: return Val_int(32);
        case sf::Keyboard::Num7: return Val_int(33);
        case sf::Keyboard::Num8: return Val_int(34);
        case sf::Keyboard::Num9: return Val_int(35);
        case sf::Keyboard::Escape:    return Val_int(36);
        case sf::Keyboard::LControl:  return Val_int(37);
        case sf::Keyboard::LShift:    return Val_int(38);
        case sf::Keyboard::LAlt:      return Val_int(39);
        case sf::Keyboard::LSystem:   return Val_int(40);
        case sf::Keyboard::RControl:  return Val_int(41);
        case sf::Keyboard::RShift:    return Val_int(42);
        case sf::Keyboard::RAlt:      return Val_int(43);
        case sf::Keyboard::RSystem:   return Val_int(44);
        case sf::Keyboard::Menu:      return Val_int(45);
        case sf::Keyboard::LBracket:  return Val_int(46);
        case sf::Keyboard::RBracket:  return Val_int(47);
        case sf::Keyboard::SemiColon: return Val_int(48);
        case sf::Keyboard::Comma:     return Val_int(49);
        case sf::Keyboard::Period:    return Val_int(50);
        case sf::Keyboard::Quote:     return Val_int(51);
        case sf::Keyboard::Slash:     return Val_int(52);
        case sf::Keyboard::BackSlash: return Val_int(53);
        case sf::Keyboard::Tilde:     return Val_int(54);
        case sf::Keyboard::Equal:     return Val_int(55);
        case sf::Keyboard::Dash:      return Val_int(56);
        case sf::Keyboard::Space:     return Val_int(57);
        case sf::Keyboard::Return:    return Val_int(58);
        case sf::Keyboard::BackSpace: return Val_int(59);
        case sf::Keyboard::Tab:       return Val_int(60);
        case sf::Keyboard::PageUp:    return Val_int(61);
        case sf::Keyboard::PageDown:  return Val_int(62);
        case sf::Keyboard::End:       return Val_int(63);
        case sf::Keyboard::Home:      return Val_int(64);
        case sf::Keyboard::Insert:    return Val_int(65);
        case sf::Keyboard::Delete:    return Val_int(66);
        case sf::Keyboard::Add:       return Val_int(67);
        case sf::Keyboard::Subtract:  return Val_int(68);
        case sf::Keyboard::Multiply:  return Val_int(69);
        case sf::Keyboard::Divide:    return Val_int(70);
        case sf::Keyboard::Left:      return Val_int(71);
        case sf::Keyboard::Right:     return Val_int(72);
        case sf::Keyboard::Up:        return Val_int(73);
        case sf::Keyboard::Down:      return Val_int(74);
        case sf::Keyboard::Numpad0:   return Val_int(75);
        case sf::Keyboard::Numpad1:   return Val_int(76);
        case sf::Keyboard::Numpad2:   return Val_int(77);
        case sf::Keyboard::Numpad3:   return Val_int(78);
        case sf::Keyboard::Numpad4:   return Val_int(79);
        case sf::Keyboard::Numpad5:   return Val_int(80);
        case sf::Keyboard::Numpad6:   return Val_int(81);
        case sf::Keyboard::Numpad7:   return Val_int(82);
        case sf::Keyboard::Numpad8:   return Val_int(83);
        case sf::Keyboard::Numpad9:   return Val_int(84);
        case sf::Keyboard::F1:    return Val_int(85);
        case sf::Keyboard::F2:    return Val_int(86);
        case sf::Keyboard::F3:    return Val_int(87);
        case sf::Keyboard::F4:    return Val_int(88);
        case sf::Keyboard::F5:    return Val_int(89);
        case sf::Keyboard::F6:    return Val_int(90);
        case sf::Keyboard::F7:    return Val_int(91);
        case sf::Keyboard::F8:    return Val_int(92);
        case sf::Keyboard::F9:    return Val_int(93);
        case sf::Keyboard::F10:   return Val_int(94);
        case sf::Keyboard::F11:   return Val_int(95);
        case sf::Keyboard::F12:   return Val_int(96);
        case sf::Keyboard::F13:   return Val_int(97);
        case sf::Keyboard::F14:   return Val_int(98);
        case sf::Keyboard::F15:   return Val_int(99);
        case sf::Keyboard::Pause: return Val_int(100);
        case sf::Keyboard::Unknown: return Val_int(101);
        default: return Val_int(101);
    }
    return Val_int(101);
}

sf::Keyboard::Key
SfKeyCode_val(value code)
{
    switch (Int_val(code))
    {
        case  0: return sf::Keyboard::A;
        case  1: return sf::Keyboard::B;
        case  2: return sf::Keyboard::C;
        case  3: return sf::Keyboard::D;
        case  4: return sf::Keyboard::E;
        case  5: return sf::Keyboard::F;
        case  6: return sf::Keyboard::G;
        case  7: return sf::Keyboard::H;
        case  8: return sf::Keyboard::I;
        case  9: return sf::Keyboard::J;
        case 10: return sf::Keyboard::K;
        case 11: return sf::Keyboard::L;
        case 12: return sf::Keyboard::M;
        case 13: return sf::Keyboard::N;
        case 14: return sf::Keyboard::O;
        case 15: return sf::Keyboard::P;
        case 16: return sf::Keyboard::Q;
        case 17: return sf::Keyboard::R;
        case 18: return sf::Keyboard::S;
        case 19: return sf::Keyboard::T;
        case 20: return sf::Keyboard::U;
        case 21: return sf::Keyboard::V;
        case 22: return sf::Keyboard::W;
        case 23: return sf::Keyboard::X;
        case 24: return sf::Keyboard::Y;
        case 25: return sf::Keyboard::Z;
        case 26: return sf::Keyboard::Num0;
        case 27: return sf::Keyboard::Num1;
        case 28: return sf::Keyboard::Num2;
        case 29: return sf::Keyboard::Num3;
        case 30: return sf::Keyboard::Num4;
        case 31: return sf::Keyboard::Num5;
        case 32: return sf::Keyboard::Num6;
        case 33: return sf::Keyboard::Num7;
        case 34: return sf::Keyboard::Num8;
        case 35: return sf::Keyboard::Num9;
        case 36: return sf::Keyboard::Escape;
        case 37: return sf::Keyboard::LControl;
        case 38: return sf::Keyboard::LShift;
        case 39: return sf::Keyboard::LAlt;
        case 40: return sf::Keyboard::LSystem;
        case 41: return sf::Keyboard::RControl;
        case 42: return sf::Keyboard::RShift;
        case 43: return sf::Keyboard::RAlt;
        case 44: return sf::Keyboard::RSystem;
        case 45: return sf::Keyboard::Menu;
        case 46: return sf::Keyboard::LBracket;
        case 47: return sf::Keyboard::RBracket;
        case 48: return sf::Keyboard::SemiColon;
        case 49: return sf::Keyboard::Comma;
        case 50: return sf::Keyboard::Period;
        case 51: return sf::Keyboard::Quote;
        case 52: return sf::Keyboard::Slash;
        case 53: return sf::Keyboard::BackSlash;
        case 54: return sf::Keyboard::Tilde;
        case 55: return sf::Keyboard::Equal;
        case 56: return sf::Keyboard::Dash;
        case 57: return sf::Keyboard::Space;
        case 58: return sf::Keyboard::Return;
        case 59: return sf::Keyboard::BackSpace;
        case 60: return sf::Keyboard::Tab;
        case 61: return sf::Keyboard::PageUp;
        case 62: return sf::Keyboard::PageDown;
        case 63: return sf::Keyboard::End;
        case 64: return sf::Keyboard::Home;
        case 65: return sf::Keyboard::Insert;
        case 66: return sf::Keyboard::Delete;
        case 67: return sf::Keyboard::Add;
        case 68: return sf::Keyboard::Subtract;
        case 69: return sf::Keyboard::Multiply;
        case 70: return sf::Keyboard::Divide;
        case 71: return sf::Keyboard::Left;
        case 72: return sf::Keyboard::Right;
        case 73: return sf::Keyboard::Up;
        case 74: return sf::Keyboard::Down;
        case 75: return sf::Keyboard::Numpad0;
        case 76: return sf::Keyboard::Numpad1;
        case 77: return sf::Keyboard::Numpad2;
        case 78: return sf::Keyboard::Numpad3;
        case 79: return sf::Keyboard::Numpad4;
        case 80: return sf::Keyboard::Numpad5;
        case 81: return sf::Keyboard::Numpad6;
        case 82: return sf::Keyboard::Numpad7;
        case 83: return sf::Keyboard::Numpad8;
        case 84: return sf::Keyboard::Numpad9;
        case 85: return sf::Keyboard::F1;
        case 86: return sf::Keyboard::F2;
        case 87: return sf::Keyboard::F3;
        case 88: return sf::Keyboard::F4;
        case 89: return sf::Keyboard::F5;
        case 90: return sf::Keyboard::F6;
        case 91: return sf::Keyboard::F7;
        case 92: return sf::Keyboard::F8;
        case 93: return sf::Keyboard::F9;
        case 94: return sf::Keyboard::F10;
        case 95: return sf::Keyboard::F11;
        case 96: return sf::Keyboard::F12;
        case 97: return sf::Keyboard::F13;
        case 98: return sf::Keyboard::F14;
        case 99: return sf::Keyboard::F15;
        case 100: return sf::Keyboard::Pause;
        case 101: return sf::Keyboard::Unknown;
        default: caml_failwith("SFKey.t");
    }
    caml_failwith("SFKey.t");
    return sf::Keyboard::Unknown;
}

// vim: sw=4 sts=4 ts=4 et
