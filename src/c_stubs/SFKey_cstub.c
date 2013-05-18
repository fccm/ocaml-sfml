/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2010 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Window/Keyboard.h>

#include "sf_caml_incs_c.h"
#include "SFKey_cstub.h"

value Val_sfKeyCode(sfKeyCode code)
{
    switch (code)
    {
        case sfKeyA: return Val_int(0);
        case sfKeyB: return Val_int(1);
        case sfKeyC: return Val_int(2);
        case sfKeyD: return Val_int(3);
        case sfKeyE: return Val_int(4);
        case sfKeyF: return Val_int(5);
        case sfKeyG: return Val_int(6);
        case sfKeyH: return Val_int(7);
        case sfKeyI: return Val_int(8);
        case sfKeyJ: return Val_int(9);
        case sfKeyK: return Val_int(10);
        case sfKeyL: return Val_int(11);
        case sfKeyM: return Val_int(12);
        case sfKeyN: return Val_int(13);
        case sfKeyO: return Val_int(14);
        case sfKeyP: return Val_int(15);
        case sfKeyQ: return Val_int(16);
        case sfKeyR: return Val_int(17);
        case sfKeyS: return Val_int(18);
        case sfKeyT: return Val_int(19);
        case sfKeyU: return Val_int(20);
        case sfKeyV: return Val_int(21);
        case sfKeyW: return Val_int(22);
        case sfKeyX: return Val_int(23);
        case sfKeyY: return Val_int(24);
        case sfKeyZ: return Val_int(25);
        case sfKeyNum0: return Val_int(26);
        case sfKeyNum1: return Val_int(27);
        case sfKeyNum2: return Val_int(28);
        case sfKeyNum3: return Val_int(29);
        case sfKeyNum4: return Val_int(30);
        case sfKeyNum5: return Val_int(31);
        case sfKeyNum6: return Val_int(32);
        case sfKeyNum7: return Val_int(33);
        case sfKeyNum8: return Val_int(34);
        case sfKeyNum9: return Val_int(35);
        case sfKeyEscape:    return Val_int(36);
        case sfKeyLControl:  return Val_int(37);
        case sfKeyLShift:    return Val_int(38);
        case sfKeyLAlt:      return Val_int(39);
        case sfKeyLSystem:   return Val_int(40);
        case sfKeyRControl:  return Val_int(41);
        case sfKeyRShift:    return Val_int(42);
        case sfKeyRAlt:      return Val_int(43);
        case sfKeyRSystem:   return Val_int(44);
        case sfKeyMenu:      return Val_int(45);
        case sfKeyLBracket:  return Val_int(46);
        case sfKeyRBracket:  return Val_int(47);
        case sfKeySemiColon: return Val_int(48);
        case sfKeyComma:     return Val_int(49);
        case sfKeyPeriod:    return Val_int(50);
        case sfKeyQuote:     return Val_int(51);
        case sfKeySlash:     return Val_int(52);
        case sfKeyBackSlash: return Val_int(53);
        case sfKeyTilde:     return Val_int(54);
        case sfKeyEqual:     return Val_int(55);
        case sfKeyDash:      return Val_int(56);
        case sfKeySpace:     return Val_int(57);
        case sfKeyReturn:    return Val_int(58);
        case sfKeyBack:      return Val_int(59);
        case sfKeyTab:       return Val_int(60);
        case sfKeyPageUp:    return Val_int(61);
        case sfKeyPageDown:  return Val_int(62);
        case sfKeyEnd:       return Val_int(63);
        case sfKeyHome:      return Val_int(64);
        case sfKeyInsert:    return Val_int(65);
        case sfKeyDelete:    return Val_int(66);
        case sfKeyAdd:       return Val_int(67);
        case sfKeySubtract:  return Val_int(68);
        case sfKeyMultiply:  return Val_int(69);
        case sfKeyDivide:    return Val_int(70);
        case sfKeyLeft:      return Val_int(71);
        case sfKeyRight:     return Val_int(72);
        case sfKeyUp:        return Val_int(73);
        case sfKeyDown:      return Val_int(74);
        case sfKeyNumpad0:   return Val_int(75);
        case sfKeyNumpad1:   return Val_int(76);
        case sfKeyNumpad2:   return Val_int(77);
        case sfKeyNumpad3:   return Val_int(78);
        case sfKeyNumpad4:   return Val_int(79);
        case sfKeyNumpad5:   return Val_int(80);
        case sfKeyNumpad6:   return Val_int(81);
        case sfKeyNumpad7:   return Val_int(82);
        case sfKeyNumpad8:   return Val_int(83);
        case sfKeyNumpad9:   return Val_int(84);
        case sfKeyF1:    return Val_int(85);
        case sfKeyF2:    return Val_int(86);
        case sfKeyF3:    return Val_int(87);
        case sfKeyF4:    return Val_int(88);
        case sfKeyF5:    return Val_int(89);
        case sfKeyF6:    return Val_int(90);
        case sfKeyF7:    return Val_int(91);
        case sfKeyF8:    return Val_int(92);
        case sfKeyF9:    return Val_int(93);
        case sfKeyF10:   return Val_int(94);
        case sfKeyF11:   return Val_int(95);
        case sfKeyF12:   return Val_int(96);
        case sfKeyF13:   return Val_int(97);
        case sfKeyF14:   return Val_int(98);
        case sfKeyF15:   return Val_int(99);
        case sfKeyPause: return Val_int(100);
        case sfKeyUnknown: return Val_int(101);
        default: return Val_int(101);
    }
    return Val_int(101);
}

sfKeyCode
SfKeyCode_val(value code)
{
    switch (Int_val(code))
    {
        case  0: return sfKeyA;
        case  1: return sfKeyB;
        case  2: return sfKeyC;
        case  3: return sfKeyD;
        case  4: return sfKeyE;
        case  5: return sfKeyF;
        case  6: return sfKeyG;
        case  7: return sfKeyH;
        case  8: return sfKeyI;
        case  9: return sfKeyJ;
        case 10: return sfKeyK;
        case 11: return sfKeyL;
        case 12: return sfKeyM;
        case 13: return sfKeyN;
        case 14: return sfKeyO;
        case 15: return sfKeyP;
        case 16: return sfKeyQ;
        case 17: return sfKeyR;
        case 18: return sfKeyS;
        case 19: return sfKeyT;
        case 20: return sfKeyU;
        case 21: return sfKeyV;
        case 22: return sfKeyW;
        case 23: return sfKeyX;
        case 24: return sfKeyY;
        case 25: return sfKeyZ;
        case 26: return sfKeyNum0;
        case 27: return sfKeyNum1;
        case 28: return sfKeyNum2;
        case 29: return sfKeyNum3;
        case 30: return sfKeyNum4;
        case 31: return sfKeyNum5;
        case 32: return sfKeyNum6;
        case 33: return sfKeyNum7;
        case 34: return sfKeyNum8;
        case 35: return sfKeyNum9;
        case 36: return sfKeyEscape;
        case 37: return sfKeyLControl;
        case 38: return sfKeyLShift;
        case 39: return sfKeyLAlt;
        case 40: return sfKeyLSystem;
        case 41: return sfKeyRControl;
        case 42: return sfKeyRShift;
        case 43: return sfKeyRAlt;
        case 44: return sfKeyRSystem;
        case 45: return sfKeyMenu;
        case 46: return sfKeyLBracket;
        case 47: return sfKeyRBracket;
        case 48: return sfKeySemiColon;
        case 49: return sfKeyComma;
        case 50: return sfKeyPeriod;
        case 51: return sfKeyQuote;
        case 52: return sfKeySlash;
        case 53: return sfKeyBackSlash;
        case 54: return sfKeyTilde;
        case 55: return sfKeyEqual;
        case 56: return sfKeyDash;
        case 57: return sfKeySpace;
        case 58: return sfKeyReturn;
        case 59: return sfKeyBack;
        case 60: return sfKeyTab;
        case 61: return sfKeyPageUp;
        case 62: return sfKeyPageDown;
        case 63: return sfKeyEnd;
        case 64: return sfKeyHome;
        case 65: return sfKeyInsert;
        case 66: return sfKeyDelete;
        case 67: return sfKeyAdd;
        case 68: return sfKeySubtract;
        case 69: return sfKeyMultiply;
        case 70: return sfKeyDivide;
        case 71: return sfKeyLeft;
        case 72: return sfKeyRight;
        case 73: return sfKeyUp;
        case 74: return sfKeyDown;
        case 75: return sfKeyNumpad0;
        case 76: return sfKeyNumpad1;
        case 77: return sfKeyNumpad2;
        case 78: return sfKeyNumpad3;
        case 79: return sfKeyNumpad4;
        case 80: return sfKeyNumpad5;
        case 81: return sfKeyNumpad6;
        case 82: return sfKeyNumpad7;
        case 83: return sfKeyNumpad8;
        case 84: return sfKeyNumpad9;
        case 85: return sfKeyF1;
        case 86: return sfKeyF2;
        case 87: return sfKeyF3;
        case 88: return sfKeyF4;
        case 89: return sfKeyF5;
        case 90: return sfKeyF6;
        case 91: return sfKeyF7;
        case 92: return sfKeyF8;
        case 93: return sfKeyF9;
        case 94: return sfKeyF10;
        case 95: return sfKeyF11;
        case 96: return sfKeyF12;
        case 97: return sfKeyF13;
        case 98: return sfKeyF14;
        case 99: return sfKeyF15;
        case 100: return sfKeyPause;
        case 101: return sfKeyUnknown;
        default: caml_failwith("SFKey.t");
    }
    caml_failwith("SFKey.t");
    return sfKeyUnknown;
}

/* vim: sw=4 sts=4 ts=4 et
 */
