/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2010 Florent Monnier <monnier.florent(_)gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
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

#include <SFML/Graphics.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/bigarray.h>
#include <caml/signals.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* types conversions */

#define Val_none Val_int(0)
#define Some_val(v) Field(v,0)

static inline value
Val_some(value v) {
    CAMLparam1(v);
    CAMLlocal1(some);
    some = caml_alloc(1, 0);
    Store_field(some, 0, v);
    CAMLreturn(some);
}

#define Val_sfWindow(win) ((value)(win))
#define SfWindow_val(win) ((sfWindow *)(win))

#define Val_sfRenderWindow(win) ((value)(win))
#define SfRenderWindow_val(win) ((sfRenderWindow *)(win))

#define Val_sfInput(inp) ((value)(inp))
#define SfInput_val(inp) ((sfInput *)(inp))

#define Val_sfImage(img) ((value)(img))
#define SfImage_val(img) ((sfImage *)(img))

#define Val_sfSprite(spr) ((value)(spr))
#define SfSprite_val(spr) ((sfSprite *)(spr))

#define Val_sfView(view) ((value)(view))
#define SfView_val(view) ((sfView *)(view))

#define Val_sfClock(clk) ((value)(clk))
#define SfClock_val(clk) ((sfClock *)(clk))

#define Val_sfPausableClock(pck) ((value)(pck))
#define SfPausableClock_val(pck) ((sfPausableClock *)(pck))

#define Val_sfString(str) ((value)(str))
#define SfString_val(str) ((sfString *)(str))

#define Val_sfFont(fnt) ((value)(fnt))
#define SfFont_val(fnt) ((sfFont *)(fnt))

#define Val_sfShape(shp) ((value)(shp))
#define SfShape_val(shp) ((sfShape *)(shp))

#define Val_sfMusic(msc) ((value)(msc))
#define SfMusic_val(msc) ((sfMusic *)(msc))

#define Val_sfSound(snd) ((value)(snd))
#define SfSound_val(snd) ((sfSound *)(snd))

#define Val_sfSoundBuffer(sbf) ((value)(sbf))
#define SfSoundBuffer_val(sbf) ((sfSoundBuffer *)(sbf))


/* overloaded types */
/* (access to the "u" field of "t") */
#define SfString_val_u(text)     SfString_val(Field(text,0))
#define SfFont_val_u(font)       SfFont_val(Field(font,0))
#define SfSprite_val_u(spr)      SfSprite_val(Field(spr,0)) 
#define SfImage_val_u(img)       SfImage_val(Field(img,0))
#define SfSoundBuffer_val_u(sbf) SfSoundBuffer_val(Field(sbf,0))


#define SF_WIN_STYLE_TITLEBAR   (-857527493)
#define SF_WIN_STYLE_RESIZE     ( 142301684)
#define SF_WIN_STYLE_CLOSE      (-933029960)
#define SF_WIN_STYLE_FULLSCREEN (-105629125)

#define Val_sfEvtClosed         Val_int(0)
#define Val_sfEvtMouseEntered   Val_int(1)
#define Val_sfEvtMouseLeft      Val_int(2)
#define Val_sfEvtLostFocus      Val_int(3)
#define Val_sfEvtGainedFocus    Val_int(4)

#define Tag_sfEvtMouseMoved           0
#define Tag_sfEvtResized              1
#define Tag_sfEvtMouseButtonPressed   2
#define Tag_sfEvtMouseButtonReleased  3
#define Tag_sfEvtMouseWheelMoved      4
#define Tag_sfEvtKeyPressed           5
#define Tag_sfEvtKeyReleased          6
#define Tag_sfEvtTextEntered          7
#define Tag_sfEvtJoyMoved             8
#define Tag_sfEvtJoyButtonPressed     9
#define Tag_sfEvtJoyButtonReleased   10

static inline value
Val_sfEvtMouseMoved(int x, int y) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, Tag_sfEvtMouseMoved);
    Store_field(var, 0, Val_long(x));
    Store_field(var, 1, Val_long(y));
    CAMLreturn(var);
}

static inline value
Val_sfEvtResized(unsigned int width, unsigned int height) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, Tag_sfEvtResized);
    Store_field(var, 0, Val_long(width));
    Store_field(var, 1, Val_long(height));
    CAMLreturn(var);
}

static inline sfMouseButton
SfMouseButton_val(value button) {
    switch (Int_val(button))
    {
        case 0: return sfButtonLeft;
        case 1: return sfButtonRight;
        case 2: return sfButtonMiddle;
        case 3: return sfButtonX1;
        case 4: return sfButtonX2;
        default: caml_failwith("SFEvent.mouse_button");
    }
    caml_failwith("SFEvent.mouse_button");
}

static inline value
Val_sfMouseButton(sfMouseButton button) {
    switch (button) {
        case sfButtonLeft:   return Val_long(0);
        case sfButtonRight:  return Val_long(1);
        case sfButtonMiddle: return Val_long(2);
        case sfButtonX1:     return Val_long(3);
        case sfButtonX2:     return Val_long(4);
        default: caml_failwith("SFEvent.mouse_button");
    }
    caml_failwith("SFEvent.mouse_button");
}

static inline value
Val_sfEvtMouseButton(int tag, sfMouseButton button, int x, int y) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(3, tag);
    Store_field(var, 0, Val_sfMouseButton(button));
    Store_field(var, 1, Val_long(x));
    Store_field(var, 2, Val_long(y));
    CAMLreturn(var);
}

#define Val_sfEvtMouseButtonPressed(button, x, y) \
    Val_sfEvtMouseButton(Tag_sfEvtMouseButtonPressed, button, x, y)

#define Val_sfEvtMouseButtonReleased(button, x, y) \
    Val_sfEvtMouseButton(Tag_sfEvtMouseButtonReleased, button, x, y)

static inline value
Val_sfEvtMouseWheelMoved(int delta) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(1, Tag_sfEvtMouseWheelMoved);
    Store_field(var, 0, Val_long(delta));
    CAMLreturn(var);
}


static inline value
Val_sfKeyCode(sfKeyCode code)
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
        default: return Val_int(101);
    }
    return Val_int(101);
}

static inline sfKeyCode
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
        default: caml_failwith("SFKey.t");
    }
    caml_failwith("SFKey.t");
    return sfKeyEscape;
}

static inline value
Val_sfEvtKey(int tag, sfKeyCode code, sfBool alt, sfBool control, sfBool shift)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(4, tag);
    Store_field(var, 0, Val_sfKeyCode(code));
    Store_field(var, 1, Val_bool(alt));
    Store_field(var, 2, Val_bool(control));
    Store_field(var, 3, Val_bool(shift));
    CAMLreturn(var);
}

#define Val_sfEvtKeyPressed(code, alt, control, shift) \
    Val_sfEvtKey(Tag_sfEvtKeyPressed, code, alt, control, shift)

#define Val_sfEvtKeyReleased(code, alt, control, shift) \
    Val_sfEvtKey(Tag_sfEvtKeyReleased, code, alt, control, shift)

#define Val_sfUint32(ui32) caml_copy_int32(ui32)

static inline value
Val_sfEvtTextEntered(sfUint32 unicode)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(1, Tag_sfEvtTextEntered);
    Store_field(var, 0, Val_sfUint32(unicode));
    CAMLreturn(var);
}

static inline sfJoyAxis
SfJoyAxis_val(value axis)
{
    switch (Int_val(axis))
    {
        case 0: return sfJoyAxisX;
        case 1: return sfJoyAxisY;
        case 2: return sfJoyAxisZ;
        case 3: return sfJoyAxisR;
        case 4: return sfJoyAxisU;
        case 5: return sfJoyAxisV;
        case 6: return sfJoyAxisPOV;
    }
    caml_failwith("joy_axis");
    return 0;
}

static inline value
Val_sfJoyAxis(sfJoyAxis axis)
{
    switch (axis)
    {
        case sfJoyAxisX: return Val_int(0);
        case sfJoyAxisY: return Val_int(1);
        case sfJoyAxisZ: return Val_int(2);
        case sfJoyAxisR: return Val_int(3);
        case sfJoyAxisU: return Val_int(4);
        case sfJoyAxisV: return Val_int(5);
        case sfJoyAxisPOV: return Val_int(6);
    }
    caml_failwith("joy_axis");
    return Val_unit;
}

static inline value
Val_sfEvtJoyMoved(
    unsigned int joystickId,
    sfJoyAxis axis,
    float position)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(3, Tag_sfEvtJoyMoved);
    Store_field(var, 0, Val_long(joystickId));
    Store_field(var, 1, Val_sfJoyAxis(axis));
    Store_field(var, 2, caml_copy_double(position));
    CAMLreturn(var);
}

static inline value
Val_sfEvtJoyButton(int tag,
    unsigned int joystickId,
    unsigned int button)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, tag);
    Store_field(var, 0, Val_long(joystickId));
    Store_field(var, 1, Val_long(button));
    CAMLreturn(var);
}

#define Val_sfEvtJoyButtonPressed(joystickId, button) \
    Val_sfEvtJoyButton(Tag_sfEvtJoyButtonPressed, joystickId, button)

#define Val_sfEvtJoyButtonReleased(joystickId, button) \
    Val_sfEvtJoyButton(Tag_sfEvtJoyButtonReleased, joystickId, button)


static value caml_return_sfEvent(sfEvent* event, char const *fail_msg)
{
    switch (event->Type)
    {
        case sfEvtMouseMoved:
            return Val_some(Val_sfEvtMouseMoved(
                                    event->MouseMove.X,
                                    event->MouseMove.Y));

        case sfEvtMouseButtonPressed:
            return Val_some(Val_sfEvtMouseButtonPressed(
                                    event->MouseButton.Button,
                                    event->MouseButton.X,
                                    event->MouseButton.Y));

        case sfEvtMouseButtonReleased:
            return Val_some(Val_sfEvtMouseButtonReleased(
                                    event->MouseButton.Button,
                                    event->MouseButton.X,
                                    event->MouseButton.Y));

        case sfEvtMouseWheelMoved:
            return Val_some(Val_sfEvtMouseWheelMoved(
                                    event->MouseWheel.Delta));

        case sfEvtKeyPressed:
            return Val_some(Val_sfEvtKeyPressed(
                                    event->Key.Code,
                                    event->Key.Alt,
                                    event->Key.Control,
                                    event->Key.Shift));
        case sfEvtKeyReleased:
            return Val_some(Val_sfEvtKeyReleased(
                                    event->Key.Code,
                                    event->Key.Alt,
                                    event->Key.Control,
                                    event->Key.Shift));

        case sfEvtTextEntered:
            return Val_some(Val_sfEvtTextEntered(
                                    event->Text.Unicode));

        case sfEvtJoyMoved:
            return Val_some(Val_sfEvtJoyMoved(
                                    event->JoyMove.JoystickId,
                                    event->JoyMove.Axis,
                                    event->JoyMove.Position));

        case sfEvtJoyButtonPressed:
            return Val_some(Val_sfEvtJoyButtonPressed(
                                    event->JoyButton.JoystickId,
                                    event->JoyButton.Button));

        case sfEvtJoyButtonReleased:
            return Val_some(Val_sfEvtJoyButtonReleased(
                                    event->JoyButton.JoystickId,
                                    event->JoyButton.Button));

        case sfEvtResized:
            return Val_some(Val_sfEvtResized(
                                    event->Size.Width,
                                    event->Size.Height));

        case sfEvtMouseEntered:
            return Val_some(Val_sfEvtMouseEntered);

        case sfEvtMouseLeft:
            return Val_some(Val_sfEvtMouseLeft);

        case sfEvtLostFocus:
            return Val_some(Val_sfEvtLostFocus);

        case sfEvtGainedFocus:
            return Val_some(Val_sfEvtGainedFocus);

        case sfEvtClosed:
            return Val_some(Val_sfEvtClosed);

        default: caml_failwith(fail_msg);
    }
}


static inline sfBlendMode
SfBlendMode_val(value ml_blendMode)
{
    switch (Int_val(ml_blendMode))
    {
        case 0: return sfBlendAlpha;
        case 1: return sfBlendAdd;
        case 2: return sfBlendMultiply;
        case 3: return sfBlendNone;
    }
    caml_failwith("SFBlendMode.t");
    return sfBlendNone;
}

static inline value
Val_sfBlendMode(sfBlendMode blendMode)
{
    switch (blendMode)
    {
        case sfBlendAlpha:    return Val_int(0);
        case sfBlendAdd:      return Val_int(1);
        case sfBlendMultiply: return Val_int(2);
        case sfBlendNone:     return Val_int(3);
        default: caml_failwith("SFBlendMode.t");
    }
    caml_failwith("SFBlendMode.t");
    return Val_int(3);  /* sfBlendNone */
}

static value Val_sfSoundStatus(sfSoundStatus sndst)
{
    switch (sndst)
    {
        case sfStopped: return Val_int(0);
        case sfPaused:  return Val_int(1);
        case sfPlaying: return Val_int(2);
    }
    caml_failwith("SFSound.sound_status");
    return Val_int(0);
}

static inline void
SfColor_val(sfColor *color, value ml_color)
{
    value _color = Field(ml_color,0);
    switch (Tag_val(ml_color))
    {
        case 0:
            color->r = Int_val(Field(_color,0));
            color->g = Int_val(Field(_color,1));
            color->b = Int_val(Field(_color,2));
            color->a = 255;
            break;
        case 1:
            color->r = Int_val(Field(_color,0));
            color->g = Int_val(Field(_color,1));
            color->b = Int_val(Field(_color,2));
            color->a = Int_val(Field(_color,3));
            break;
        default: caml_failwith("SFColor.t");
    }
}

static value
Val_sfColor4(sfColor *color)
{
    CAMLparam0();
    CAMLlocal2(col, rgba);
    sfUint8 r = color->r;
    sfUint8 g = color->g;
    sfUint8 b = color->b;
    sfUint8 a = color->a;
    rgba = caml_alloc(4, 0);
    Store_field(rgba, 0, Val_long(r));
    Store_field(rgba, 1, Val_long(g));
    Store_field(rgba, 2, Val_long(b));
    Store_field(rgba, 3, Val_long(a));
    col = caml_alloc(1, 1);
    Store_field(col, 0, rgba);
    CAMLreturn(col);
}

static value
Val_sfColor3(sfColor *color)
{
    CAMLparam0();
    CAMLlocal2(col, rgb);
    sfUint8 r = color->r;
    sfUint8 g = color->g;
    sfUint8 b = color->b;
    rgb = caml_alloc(3, 0);
    Store_field(rgb, 0, Val_long(r));
    Store_field(rgb, 1, Val_long(g));
    Store_field(rgb, 2, Val_long(b));
    col = caml_alloc(1, 0);
    Store_field(col, 0, rgb);
    CAMLreturn(col);
}

static value
Val_RGB(sfColor *color)
{
    CAMLparam0();
    CAMLlocal1(rgb);
    sfUint8 r = color->r;
    sfUint8 g = color->g;
    sfUint8 b = color->b;
    rgb = caml_alloc(3, 0);
    Store_field(rgb, 0, Val_long(r));
    Store_field(rgb, 1, Val_long(g));
    Store_field(rgb, 2, Val_long(b));
    CAMLreturn(rgb);
}

static value
Val_RGBA(sfColor *color)
{
    CAMLparam0();
    CAMLlocal1(rgba);
    sfUint8 r = color->r;
    sfUint8 g = color->g;
    sfUint8 b = color->b;
    sfUint8 a = color->a;
    rgba = caml_alloc(4, 0);
    Store_field(rgba, 0, Val_long(r));
    Store_field(rgba, 1, Val_long(g));
    Store_field(rgba, 2, Val_long(b));
    Store_field(rgba, 3, Val_long(a));
    CAMLreturn(rgba);
}

static value caml_return_sfIntRect(sfIntRect *rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    int left   = rect->Left;
    int top    = rect->Top;
    int right  = rect->Right;
    int bottom = rect->Bottom;
    r = caml_alloc(4, 0);
    Store_field(r, 0, Val_long(left));
    Store_field(r, 1, Val_long(top));
    Store_field(r, 2, Val_long(right));
    Store_field(r, 3, Val_long(bottom));
    CAMLreturn(r);
}

static value caml_return_sfFloatRect(sfFloatRect *rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    float left   = rect->Left;
    float top    = rect->Top;
    float right  = rect->Right;
    float bottom = rect->Bottom;
    r = caml_alloc(4, 0);
    Store_field(r, 0, caml_copy_double(left));
    Store_field(r, 1, caml_copy_double(top));
    Store_field(r, 2, caml_copy_double(right));
    Store_field(r, 3, caml_copy_double(bottom));
    CAMLreturn(r);
}


/* sfWindow */

CAMLprim value
caml_sfWindow_Create(
    value ml_mode, value title, value ml_style, value ml_settings)
{
    sfVideoMode mode;
    sfWindowSettings settings;
    unsigned long style;
    sfWindow* win;

    mode.Width        = Long_val(Field(ml_mode, 0));
    mode.Height       = Long_val(Field(ml_mode, 1));
    mode.BitsPerPixel = Long_val(Field(ml_mode, 2));

    settings.DepthBits         = Long_val(Field(ml_settings, 0));
    settings.StencilBits       = Long_val(Field(ml_settings, 1));
    settings.AntialiasingLevel = Long_val(Field(ml_settings, 2));

    style = 0;
    while (ml_style != Val_emptylist)
    {
        switch (Long_val(Field(ml_style, 0)))
        {
            case SF_WIN_STYLE_TITLEBAR:   style |= sfTitlebar;   break;
            case SF_WIN_STYLE_RESIZE:     style |= sfResize;     break;
            case SF_WIN_STYLE_CLOSE:      style |= sfClose;      break;
            case SF_WIN_STYLE_FULLSCREEN: style |= sfFullscreen; break;
            default: caml_failwith("SFWindow.create");
        }
        ml_style = Field(ml_style, 1);
    }

    win = sfWindow_Create(mode, String_val(title), style, settings);
    if (!win) caml_failwith("SFWindow.create");

    return Val_sfWindow(win);
}

CAMLprim value
caml_sfWindow_CreateFromHandle(value ml_handle, value ml_settings)
{
    sfWindowSettings settings;
    sfWindow* win;

    settings.DepthBits         = Long_val(Field(ml_settings, 0));
    settings.StencilBits       = Long_val(Field(ml_settings, 1));
    settings.AntialiasingLevel = Long_val(Field(ml_settings, 2));

    win = sfWindow_CreateFromHandle(Nativeint_val(ml_handle), settings);
    if (!win) caml_failwith("SFWindow.createFromHandle");

    return Val_sfWindow(win);
}

CAMLprim value
caml_sfWindow_IsOpened(value win)
{
    return Val_bool(
        sfWindow_IsOpened(SfWindow_val(win)));
}

CAMLprim value
caml_sfWindow_Close(value win)
{
    sfWindow_Close(SfWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_Display(value win)
{
    caml_enter_blocking_section();
    sfWindow_Display(SfWindow_val(win));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfWindow_Destroy(value win)
{
    sfWindow_Destroy(SfWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_GetEvent(value win)
{
    const char fail_msg[] = "SFWindow.getEvent";
    sfEvent event;
    sfBool isev = sfWindow_GetEvent(SfWindow_val(win), &event);
    if (isev) return caml_return_sfEvent(&event, fail_msg);
    else return Val_none;
}

CAMLprim value
caml_sfWindow_GetWidth(value win)
{
    unsigned int width = sfWindow_GetWidth(SfWindow_val(win));
    return Val_long(width);
}

CAMLprim value
caml_sfWindow_GetHeight(value win)
{
    unsigned int height = sfWindow_GetHeight(SfWindow_val(win));
    return Val_long(height);
}

CAMLprim value
caml_sfWindow_GetSize(value win)
{
    CAMLparam1(win);
    CAMLlocal1(size);
    unsigned int width = sfWindow_GetWidth(SfWindow_val(win));
    unsigned int height = sfWindow_GetHeight(SfWindow_val(win));
    size = caml_alloc(2, 0);
    Store_field(size, 0, Val_long(width));
    Store_field(size, 1, Val_long(height));
    CAMLreturn(size);
}

CAMLprim value
caml_sfWindow_SetSize(value win, value width, value height)
{
    sfWindow_SetSize(SfWindow_val(win), Long_val(width), Long_val(height));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_ShowMouseCursor(value win, value show)
{
    sfWindow_ShowMouseCursor(SfWindow_val(win), Bool_val(show));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_SetCursorPosition(value win, value left, value top)
{
    sfWindow_SetCursorPosition(SfWindow_val(win), Long_val(left), Long_val(top));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_UseVerticalSync(value win, value enabled)
{
    sfWindow_UseVerticalSync(SfWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_SetPosition(value win, value left, value top)
{
    sfWindow_SetPosition(SfWindow_val(win), Long_val(left), Long_val(top));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_Show(value win, value state)
{
    sfWindow_Show(SfWindow_val(win), Bool_val(state));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_EnableKeyRepeat(value win, value enabled)
{
    sfWindow_EnableKeyRepeat(SfWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_SetFramerateLimit(value win, value limit)
{
    sfWindow_SetFramerateLimit(SfWindow_val(win), Long_val(limit));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_SetJoystickThreshold(value win, value threshold)
{
    sfWindow_SetJoystickThreshold(SfWindow_val(win), Double_val(threshold));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_SetActive(value win, value active)
{
    sfBool a = sfWindow_SetActive(SfWindow_val(win), Bool_val(active));
    return Val_bool(a);
}

CAMLprim value
caml_sfWindow_GetFrameTime(value win)
{
    float frameTime = sfWindow_GetFrameTime(SfWindow_val(win));
    return caml_copy_double(frameTime);
}

/* TODO
sfWindowSettings sfWindow_GetSettings(sfWindow* Window);
void sfWindow_SetIcon(sfWindow* Window, unsigned int Width, unsigned int Height, sfUint8* Pixels);
*/


/* sfRenderWindow */

CAMLprim value
caml_sfRenderWindow_Create(
    value ml_mode, value title, value ml_style, value ml_settings)
{
    sfVideoMode mode;
    sfWindowSettings settings;
    unsigned long style;
    sfRenderWindow* win;

    mode.Width        = Long_val(Field(ml_mode, 0));
    mode.Height       = Long_val(Field(ml_mode, 1));
    mode.BitsPerPixel = Long_val(Field(ml_mode, 2));

    settings.DepthBits         = Long_val(Field(ml_settings, 0));
    settings.StencilBits       = Long_val(Field(ml_settings, 1));
    settings.AntialiasingLevel = Long_val(Field(ml_settings, 2));

    style = 0;
    while (ml_style != Val_emptylist)
    {
        switch (Long_val(Field(ml_style, 0)))
        {
            case SF_WIN_STYLE_TITLEBAR:   style |= sfTitlebar;   break;
            case SF_WIN_STYLE_RESIZE:     style |= sfResize;     break;
            case SF_WIN_STYLE_CLOSE:      style |= sfClose;      break;
            case SF_WIN_STYLE_FULLSCREEN: style |= sfFullscreen; break;
            default: caml_failwith("SFRenderWindow.create");
        }
        ml_style = Field(ml_style, 1);
    }

    win = sfRenderWindow_Create(mode, String_val(title), style, settings);
    if (!win) caml_failwith("SFRenderWindow.create");

    return Val_sfRenderWindow(win);
}

CAMLprim value
caml_sfRenderWindow_CreateFromHandle(value ml_handle, value ml_settings)
{
    sfWindowSettings settings;
    sfRenderWindow* win;

    settings.DepthBits         = Long_val(Field(ml_settings, 0));
    settings.StencilBits       = Long_val(Field(ml_settings, 1));
    settings.AntialiasingLevel = Long_val(Field(ml_settings, 2));

    win = sfRenderWindow_CreateFromHandle(Nativeint_val(ml_handle), settings);
    if (!win) caml_failwith("SFRenderWindow.createFromHandle");

    return Val_sfRenderWindow(win);
}

CAMLprim value
caml_sfRenderWindow_IsOpened(value win)
{
    return Val_bool(
        sfRenderWindow_IsOpened(SfRenderWindow_val(win)));
}

CAMLprim value
caml_sfRenderWindow_Close(value win)
{
    sfRenderWindow_Close(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_Display(value win)
{
    caml_enter_blocking_section();
    sfRenderWindow_Display(SfRenderWindow_val(win));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_Destroy(value win)
{
    sfRenderWindow_Destroy(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_GetEvent(value win)
{
    const char fail_msg[] = "SFRenderWindow.getEvent";
    sfEvent event;
    sfBool isev = sfRenderWindow_GetEvent(SfRenderWindow_val(win), &event);
    if (isev) return caml_return_sfEvent(&event, fail_msg);
    else return Val_none;
}

CAMLprim value
caml_sfRenderWindow_Clear(value win, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfRenderWindow_Clear(SfRenderWindow_val(win), color);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_Blank(value win)
{
    sfRenderWindow_Clear(SfRenderWindow_val(win), sfBlack);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_GetWidth(value win)
{
    unsigned int width = sfRenderWindow_GetWidth(SfRenderWindow_val(win));
    return Val_long(width);
}

CAMLprim value
caml_sfRenderWindow_GetHeight(value win)
{
    unsigned int height = sfRenderWindow_GetHeight(SfRenderWindow_val(win));
    return Val_long(height);
}

CAMLprim value
caml_sfRenderWindow_GetSize(value win)
{
    CAMLparam1(win);
    CAMLlocal1(size);
    unsigned int width = sfRenderWindow_GetWidth(SfRenderWindow_val(win));
    unsigned int height = sfRenderWindow_GetHeight(SfRenderWindow_val(win));
    size = caml_alloc(2, 0);
    Store_field(size, 0, Val_long(width));
    Store_field(size, 1, Val_long(height));
    CAMLreturn(size);
}

CAMLprim value
caml_sfRenderWindow_SetSize(value win, value width, value height)
{
    sfRenderWindow_SetSize(SfRenderWindow_val(win), Long_val(width), Long_val(height));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_DrawSprite(value win, value sprite)
{
    sfRenderWindow_DrawSprite(SfRenderWindow_val(win), SfSprite_val_u(sprite));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_DrawString(value win, value text)
{
    sfRenderWindow_DrawString(SfRenderWindow_val(win), SfString_val_u(text));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_DrawShape(value win, value shape)
{
    sfRenderWindow_DrawShape(SfRenderWindow_val(win), SfShape_val(shape));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_PreserveOpenGLStates(value win, value preserve)
{
    sfRenderWindow_PreserveOpenGLStates(SfRenderWindow_val(win), Bool_val(preserve));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_SetCursorPosition(value win, value left, value top)
{
    sfRenderWindow_SetCursorPosition(SfRenderWindow_val(win), Long_val(left), Long_val(top));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_SetPosition(value win, value left, value top)
{
    sfRenderWindow_SetPosition(SfRenderWindow_val(win), Long_val(left), Long_val(top));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_ShowMouseCursor(value win, value show)
{
    sfRenderWindow_ShowMouseCursor(SfRenderWindow_val(win), Bool_val(show));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_Show(value win, value state)
{
    sfRenderWindow_Show(SfRenderWindow_val(win), Bool_val(state));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_EnableKeyRepeat(value win, value enabled)
{
    sfRenderWindow_EnableKeyRepeat(SfRenderWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_SetActive(value win, value active)
{
    sfBool status = sfRenderWindow_SetActive(SfRenderWindow_val(win), Bool_val(active));
    if (!status) caml_failwith("SFRenderWindow.setActive");
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_SetFramerateLimit(value win, value limit)
{
    sfRenderWindow_SetFramerateLimit(SfRenderWindow_val(win), Long_val(limit));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_GetFrameTime(value win)
{
    float ft = sfRenderWindow_GetFrameTime(SfRenderWindow_val(win));
    return caml_copy_double(ft);
}

CAMLprim value
caml_sfRenderWindow_SetView(value win, value view)
{
    sfRenderWindow_SetView(SfRenderWindow_val(win), SfView_val(view));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_ConvertCoords(value win, value winX, value winY, value targetView)
{
    CAMLparam4(win, winX, winY, targetView);
    CAMLlocal1(ret);
    float ViewX, ViewY;
    sfRenderWindow_ConvertCoords(SfRenderWindow_val(win),
            Long_val(winX), Long_val(winY),
            &ViewX, &ViewY,
            SfView_val(targetView));
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(ViewX));
    Store_field(ret, 1, caml_copy_double(ViewY));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfRenderWindow_UseVerticalSync(value win, value enabled)
{
    sfRenderWindow_UseVerticalSync(SfRenderWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_SetJoystickThreshold(value win, value threshold)
{
    sfRenderWindow_SetJoystickThreshold(SfRenderWindow_val(win), Double_val(threshold));
    return Val_unit;
}

/* TODO
sfWindowSettings sfRenderWindow_GetSettings(sfRenderWindow* RenderWindow);
void sfRenderWindow_SetIcon(sfRenderWindow* RenderWindow, unsigned int Width, unsigned int Height, sfUint8* Pixels);
void sfRenderWindow_DrawPostFX(sfRenderWindow* RenderWindow, sfPostFX* PostFX);
sfImage* sfRenderWindow_Capture(sfRenderWindow* RenderWindow);
const sfView* sfRenderWindow_GetView(sfRenderWindow* RenderWindow);
sfView* sfRenderWindow_GetDefaultView(sfRenderWindow* RenderWindow);
*/


/* sfInput */

CAMLprim value
caml_sfWindow_GetInput(value win)
{
    sfInput *input = sfWindow_GetInput(SfWindow_val(win));
    return Val_sfInput(input);
}

CAMLprim value
caml_sfRenderWindow_GetInput(value win)
{
    sfInput *input = sfRenderWindow_GetInput(SfRenderWindow_val(win));
    return Val_sfInput(input);
}

CAMLprim value
caml_sfInput_GetMousePos(value input)
{
    CAMLparam1(input);
    CAMLlocal1(pos);
    int x, y;
    x = sfInput_GetMouseX(SfInput_val(input));
    y = sfInput_GetMouseY(SfInput_val(input));
    pos = caml_alloc(2, 0);
    Store_field(pos, 0, Val_long(x));
    Store_field(pos, 1, Val_long(y));
    CAMLreturn(pos);
}

CAMLprim value
caml_sfInput_IsKeyDown(value input, value keyCode)
{
    sfBool keyDown =
        sfInput_IsKeyDown(SfInput_val(input), SfKeyCode_val(keyCode));
    return Val_bool(keyDown);
}

CAMLprim value
caml_sfInput_IsMouseButtonDown(value input, value button)
{
    sfBool isMBDown =
        sfInput_IsMouseButtonDown(SfInput_val(input), SfMouseButton_val(button));
    return Val_bool(isMBDown);
}

CAMLprim value
caml_sfInput_IsJoystickButtonDown(value input, value joyId, value button)
{
    sfBool isJBDown =
        sfInput_IsJoystickButtonDown(
                SfInput_val(input), Long_val(joyId), Long_val(button));
    return Val_bool(isJBDown);
}

CAMLprim value
caml_sfInput_GetJoystickAxis(value input, value joyId, value axis)
{
    float joystickAxis =
        sfInput_GetJoystickAxis(
                SfInput_val(input), Long_val(joyId), SfJoyAxis_val(axis));
    return caml_copy_double(joystickAxis);
}


/* sfView */

CAMLprim value
caml_sfView_Create(value unit)
{
    sfView *view = sfView_Create();
    if (!view) caml_failwith("SFView.create");
    return Val_sfView(view);
}

CAMLprim value
caml_sfView_CreateFromRect(value ml_float_rect)
{
    sfFloatRect Rect;
    Rect.Left   = Double_val(Field(ml_float_rect,0));
    Rect.Top    = Double_val(Field(ml_float_rect,1));
    Rect.Right  = Double_val(Field(ml_float_rect,2));
    Rect.Bottom = Double_val(Field(ml_float_rect,3));
    sfView *view = sfView_CreateFromRect(Rect);
    if (!view) caml_failwith("SFView.createFromRect");
    return Val_sfView(view);
}

CAMLprim value
caml_sfView_Destroy(value view)
{
    sfView_Destroy(SfView_val(view));
    return Val_unit;
}

CAMLprim value
caml_sfView_SetFromRect(value view, value ml_float_rect)
{
    sfFloatRect ViewRect;
    ViewRect.Left   = Double_val(Field(ml_float_rect,0));
    ViewRect.Top    = Double_val(Field(ml_float_rect,1));
    ViewRect.Right  = Double_val(Field(ml_float_rect,2));
    ViewRect.Bottom = Double_val(Field(ml_float_rect,3));
    sfView_SetFromRect(SfView_val(view), ViewRect);
    return Val_unit;
}

CAMLprim value
caml_sfView_SetCenter(value view, value x, value y)
{
    sfView_SetCenter(SfView_val(view), Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfView_Move(value view, value offsetX, value offsetY)
{
    sfView_Move(SfView_val(view), Double_val(offsetX), Double_val(offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfView_Move2(value view, value offset)
{
    sfView_Move(SfView_val(view),
            Double_val(Field(offset,0)), Double_val(Field(offset,1)));
    return Val_unit;
}

CAMLprim value
caml_sfView_Zoom(value view, value factor)
{
    sfView_Zoom(SfView_val(view), Double_val(factor));
    return Val_unit;
}

CAMLprim value
caml_sfView_SetHalfSize(value view, value halfWidth, value halfHeight)
{
    sfView_SetHalfSize(SfView_val(view),
            Double_val(halfWidth), Double_val(halfHeight));
    return Val_unit;
}

CAMLprim value
caml_sfView_GetRect(value view)
{
    sfFloatRect rect = sfView_GetRect(SfView_val(view));
    return caml_return_sfFloatRect(&rect);
}

CAMLprim value
caml_sfView_GetCenter(value view)
{
    CAMLparam1(view);
    CAMLlocal1(center);
    float centerX = sfView_GetCenterX(SfView_val(view));
    float centerY = sfView_GetCenterY(SfView_val(view));
    center = caml_alloc(2, 0);
    Store_field(center, 0, caml_copy_double(center.x));
    Store_field(center, 1, caml_copy_double(center.y));
    CAMLreturn(center);
}

CAMLprim value
caml_sfView_GetHalfSize(value view)
{
    CAMLparam1(view);
    CAMLlocal1(halfSize);
    float halfSizeX = sfView_GetHalfSizeX(SfView_val(view));
    float halfSizeY = sfView_GetHalfSizeY(SfView_val(view));
    halfSize = caml_alloc(2, 0);
    Store_field(halfSize, 0, caml_copy_double(halfSizeX));
    Store_field(halfSize, 1, caml_copy_double(halfSizeY));
    CAMLreturn(halfSize);
}


/* sfImage */

CAMLprim value
caml_sfImage_CreateFromFile(value filename)
{
    sfImage *img;
    img = sfImage_CreateFromFile(String_val(filename));
    if (!img) caml_failwith("SFImage.createFromFile");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_CreateFromColor(value width, value height, value ml_color)
{
    sfImage *img;
    sfColor color;
    SfColor_val(&color, ml_color);
    img = sfImage_CreateFromColor(Long_val(width), Long_val(height), color);
    if (!img) caml_failwith("SFImage.createFromColor");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_CreateFromMemory(value data)
{
    sfImage *img;
    img = sfImage_CreateFromMemory(String_val(data), caml_string_length(data));
    if (!img) caml_failwith("SFImage.createFromMemory");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_CreateFromPixels(value width, value height, value data)
{
    sfImage *img;
    unsigned int Width = Int_val(width);
    unsigned int Height = Int_val(height);
    if (caml_string_length(data) != (Width * Height * 4))
        caml_invalid_argument("SFImage.createFromPixels");
    img = sfImage_CreateFromPixels(Width, Height, (sfUint8 *) String_val(data));
    if (!img) caml_failwith("SFImage.createFromPixels");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_Destroy(value img)
{
    sfImage_Destroy(SfImage_val(img));
    return Val_unit;
}

CAMLprim value
caml_sfImage_GetWidth(value image)
{
    unsigned int width = sfImage_GetWidth(SfImage_val(image));
    return Val_long(width);
}

CAMLprim value
caml_sfImage_GetHeight(value image)
{
    unsigned int height = sfImage_GetHeight(SfImage_val(image));
    return Val_long(height);
}

CAMLprim value
caml_sfImage_GetDimensions(value image)
{
    CAMLparam1(image);
    CAMLlocal1(dims);
    unsigned int width = sfImage_GetWidth(SfImage_val(image));
    unsigned int height = sfImage_GetHeight(SfImage_val(image));
    dims = caml_alloc(2, 0);
    Store_field(dims, 0, Val_long(width));
    Store_field(dims, 1, Val_long(height));
    CAMLreturn(dims);
}

CAMLprim value
caml_sfImage_GetPixelsPtr(value sf_image)
{
    CAMLparam1(sf_image);
    CAMLlocal1(img_ba);
    unsigned int width = sfImage_GetWidth(SfImage_val(sf_image));
    unsigned int height = sfImage_GetHeight(SfImage_val(sf_image));
    const sfUint8 *img_data = sfImage_GetPixelsPtr(SfImage_val(sf_image));
    long dims[3];
    dims[0] = width;
    dims[1] = height;
    dims[2] = 4;
    img_ba = caml_ba_alloc(CAML_BA_UINT8 | CAML_BA_C_LAYOUT, 3, NULL, dims);
    memcpy(Caml_ba_data_val(img_ba), img_data, width * height * 4 * sizeof(char));
    CAMLreturn(img_ba);
}

CAMLprim value
caml_sfImage_SaveToFile(value image, value filename)
{
    sfBool saved = sfImage_SaveToFile(SfImage_val(image), String_val(filename));
    if (!saved) caml_failwith("SFImage.saveToFile");
    return Val_unit;
}

CAMLprim value
caml_sfImage_SetPixel(value image, value x, value y, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfImage_SetPixel(SfImage_val(image), Long_val(x), Long_val(y), color);
    return Val_unit;
}

CAMLprim value
caml_sfImage_SetSmooth(value image, value smooth)
{
    sfImage_SetSmooth(SfImage_val(image), Bool_val(smooth));
    return Val_unit;
}

CAMLprim value
caml_sfImage_IsSmooth(value image)
{
    sfBool is_smooth = sfImage_IsSmooth(SfImage_val(image));
    return Val_bool(is_smooth);
}

CAMLprim value
caml_sfImage_Bind(value image)
{
    sfImage_Bind(SfImage_val(image));
    return Val_unit;
}

CAMLprim value
caml_sfImage_GetPixel4(value image, value x, value y)
{
    sfColor color = sfImage_GetPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_sfColor4(&color);
}

CAMLprim value
caml_sfImage_GetPixel3(value image, value x, value y)
{
    sfColor color = sfImage_GetPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_sfColor3(&color);
}

CAMLprim value
caml_sfImage_GetPixelRGB(value image, value x, value y)
{
    sfColor color = sfImage_GetPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_RGB(&color);
}

CAMLprim value
caml_sfImage_GetPixelRGBA(value image, value x, value y)
{
    sfColor color = sfImage_GetPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_RGBA(&color);
}

/*
void sfImage_Copy(sfImage* Image, sfImage* Source, unsigned int DestX, unsigned int DestY, sfIntRect SourceRect);
*/

/*
sfImage* sfImage_Create();
void sfImage_CreateMaskFromColor(sfImage* Image, sfColor ColorKey, sfUint8 Alpha);
sfBool sfImage_CopyScreen(sfImage* Image, sfRenderWindow* Window, sfIntRect SourceRect);
*/


/* sfSprite */

CAMLprim value
caml_sfSprite_Create(value unit)
{
    sfSprite *sprite;
    sprite = sfSprite_Create();
    if (!sprite) caml_failwith("SFSprite.create");
    return Val_sfSprite(sprite);
}

CAMLprim value
caml_sfSprite_SetImage(value sprite, value image)
{
    sfSprite_SetImage(SfSprite_val(sprite), SfImage_val_u(image));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Destroy(value sprite)
{
    sfSprite_Destroy(SfSprite_val(sprite));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Resize(value sprite, value width, value height)
{
    sfSprite_Resize(SfSprite_val(sprite), Double_val(width), Double_val(height));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Move(value sprite, value offsetX, value offsetY)
{
    sfSprite_Move(SfSprite_val(sprite), Double_val(offsetX), Double_val(offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Move2(value sprite, value offset)
{
    sfSprite_Move(
            SfSprite_val(sprite),
            Double_val(Field(offset,0)),
            Double_val(Field(offset,1)));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Scale(value sprite, value factorX, value factorY)
{
    sfSprite_Scale(SfSprite_val(sprite), Double_val(factorX), Double_val(factorY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Scale2(value sprite, value factor)
{
    sfSprite_Scale(
            SfSprite_val(sprite),
            Double_val(Field(factor,0)),
            Double_val(Field(factor,1)));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_Rotate(value sprite, value angle)
{
    sfSprite_Rotate(SfSprite_val(sprite), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_FlipX(value sprite, value flipped)
{
    sfSprite_FlipX(SfSprite_val(sprite), Bool_val(flipped));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_FlipY(value sprite, value flipped)
{
    sfSprite_FlipY(SfSprite_val(sprite), Bool_val(flipped));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetX(value sprite, value x)
{
    sfSprite_SetX(SfSprite_val(sprite), Double_val(x));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetY(value sprite, value y)
{
    sfSprite_SetY(SfSprite_val(sprite), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetXY(value sprite, value x, value y)
{
    sfSprite_SetX(SfSprite_val(sprite), Double_val(x));
    sfSprite_SetY(SfSprite_val(sprite), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetPosition(value sprite, value x, value y)
{
    sfSprite_SetPosition(SfSprite_val(sprite), Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetPosition2(value sprite, value pos)
{
    sfSprite_SetPosition(SfSprite_val(sprite),
        Double_val(Field(pos,0)), Double_val(Field(pos,1)));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetScaleX(value sprite, value scale)
{
    sfSprite_SetScaleX(SfSprite_val(sprite), Double_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetScaleY(value sprite, value scale)
{
    sfSprite_SetScaleY(SfSprite_val(sprite), Double_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetScale(value sprite, value scaleX, value scaleY)
{
    sfSprite_SetScale(SfSprite_val(sprite), Double_val(scaleX), Double_val(scaleY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetScale2(value sprite, value scale)
{
    sfSprite_SetScale(
            SfSprite_val(sprite),
            Double_val(Field(scale,0)),
            Double_val(Field(scale,1)));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetRotation(value sprite, value rotation)
{
    sfSprite_SetRotation(SfSprite_val(sprite), Double_val(rotation));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetCenter(value sprite, value x, value y)
{
    sfSprite_SetCenter(SfSprite_val(sprite), Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetCenter2(value sprite, value center)
{
    sfSprite_SetCenter(
            SfSprite_val(sprite),
            Double_val(Field(center,0)),
            Double_val(Field(center,1)));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetColor(value sprite, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfSprite_SetColor(SfSprite_val(sprite), color);
    return Val_unit;
}

CAMLprim value
caml_sfSprite_SetBlendMode(value sprite, value mode)
{
    sfSprite_SetBlendMode(SfSprite_val(sprite), SfBlendMode_val(mode));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_GetX(value sprite)
{
    return caml_copy_double(
            sfSprite_GetX(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetY(value sprite)
{
    return caml_copy_double(
            sfSprite_GetY(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetXY(value sprite)
{
    CAMLparam1(sprite);
    CAMLlocal1(xy);
    float x = sfSprite_GetX(SfSprite_val(sprite));
    float y = sfSprite_GetY(SfSprite_val(sprite));
    xy = caml_alloc(2, 0);
    Store_field(xy, 0, caml_copy_double(x));
    Store_field(xy, 1, caml_copy_double(y));
    CAMLreturn(xy);
}

CAMLprim value
caml_sfSprite_GetWidth(value sprite)
{
    return caml_copy_double(
            sfSprite_GetWidth(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetHeight(value sprite)
{
    return caml_copy_double(
            sfSprite_GetHeight(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetDimensions(value sprite)
{
    CAMLparam1(sprite);
    CAMLlocal1(dims);
    float width = sfSprite_GetWidth(SfSprite_val(sprite));
    float height = sfSprite_GetHeight(SfSprite_val(sprite));
    dims = caml_alloc(2, 0);
    Store_field(dims, 0, caml_copy_double(width));
    Store_field(dims, 1, caml_copy_double(height));
    CAMLreturn(dims);
}

CAMLprim value
caml_sfSprite_GetScaleX(value sprite)
{
    return caml_copy_double(
            sfSprite_GetScaleX(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetScaleY(value sprite)
{
    return caml_copy_double(
            sfSprite_GetScaleY(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetScale(value sprite)
{
    CAMLparam1(sprite);
    CAMLlocal1(xy);
    float scale_x = sfSprite_GetScaleX(SfSprite_val(sprite));
    float scale_y = sfSprite_GetScaleY(SfSprite_val(sprite));
    xy = caml_alloc(2, 0);
    Store_field(xy, 0, caml_copy_double(scale_x));
    Store_field(xy, 1, caml_copy_double(scale_y));
    CAMLreturn(xy);
}

CAMLprim value
caml_sfSprite_GetRotation(value sprite)
{
    return caml_copy_double(
            sfSprite_GetRotation(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetCenterX(value sprite)
{
    return caml_copy_double(
            sfSprite_GetCenterX(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetCenterY(value sprite)
{
    return caml_copy_double(
            sfSprite_GetCenterY(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_GetCenter(value sprite)
{
    CAMLparam1(sprite);
    CAMLlocal1(xy);
    float x = sfSprite_GetCenterX(SfSprite_val(sprite));
    float y = sfSprite_GetCenterY(SfSprite_val(sprite));
    xy = caml_alloc(2, 0);
    Store_field(xy, 0, caml_copy_double(x));
    Store_field(xy, 1, caml_copy_double(y));
    CAMLreturn(xy);
}

/*
void sfSprite_SetSubRect(sfSprite* Sprite, sfIntRect SubRect);
*/

CAMLprim value
caml_sfSprite_GetSubRect(value sprite)
{
    sfIntRect rect = sfSprite_GetSubRect(SfSprite_val(sprite));
    return caml_return_sfIntRect(&rect);
}

CAMLprim value
caml_sfSprite_GetPixel(value sprite, value x, value y)
{
    sfColor col = sfSprite_GetPixel(SfSprite_val(sprite), Long_val(x), Long_val(y));
    return Val_sfColor4(&col);
}

/*
sfColor sfSprite_GetColor(sfSprite* sprite);
sfBlendMode sfSprite_GetBlendMode(sfSprite* sprite);
void sfSprite_TransformToLocal(sfSprite* sprite, float PointX, float PointY, float* X, float* Y);
void sfSprite_TransformToGlobal(sfSprite* sprite, float PointX, float PointY, float* X, float* Y);
void sfSprite_SetSubRect(sfSprite* sprite, sfIntRect SubRect);
sfImage* sfSprite_GetImage(sfSprite* sprite);
*/


/* sfClock */

CAMLprim value
caml_sfClock_Create(value unit)
{
    sfClock *clock;
    clock = sfClock_Create();
    if (!clock) caml_failwith("SFClock.create");
    return Val_sfClock(clock);
}

CAMLprim value
caml_sfClock_Destroy(value Clock)
{
    sfClock_Destroy(SfClock_val(Clock));
    return Val_unit;
}

CAMLprim value
caml_sfClock_GetTime(value Clock)
{
    float time;
    time = sfClock_GetTime(SfClock_val(Clock));
    return caml_copy_double(time);
}

CAMLprim value
caml_sfClock_Reset(value Clock)
{
    sfClock_Reset(SfClock_val(Clock));
    return Val_unit;
}

CAMLprim value
caml_sfSleep(value duration)
{
    sfSleep(Double_val(duration));
    return Val_unit;
}


/* sfPausableClock */
 
/*
 * sfPausableClock is not part of SFML,
 * it was provided on the SFML's wiki:
 * http://www.sfml-dev.org/wiki/en/sources/pausableclock
 * and was written by Marco Antognini and Laurent Gomila in C++
 * here it was rewritten in C by me (Florent Monnier)
 */

typedef struct _sfPausableClock
{
    /* Is the PausableClock paused? */
    int am_i_paused;
 
    /* Time buffer. */
    float my_time;
 
    /* The sfClock used. */
    sfClock *my_clock;
} sfPausableClock;

 
sfPausableClock *
sfPausableClock_Create(int paused)
{
    sfPausableClock *pclock;
    pclock = malloc(sizeof(sfPausableClock));
    pclock->am_i_paused = paused;  /* does the clock start paused? */
    pclock->my_time = 0.f;
    pclock->my_clock = sfClock_Create();
    return pclock;
}

void sfPausableClock_Destroy(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        sfClock_Destroy(pclock->my_clock);
        free(pclock);
        pclock = NULL;
    }
}

/* Set the clock in 'pause' mode. */
void sfPausableClock_Pause(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not yet paused... */
        if (!pclock->am_i_paused)
        {
            pclock->am_i_paused = 1;
            pclock->my_time += sfClock_GetTime(pclock->my_clock);
        }
    }
}
 
/* Start the clock (again). */
void sfPausableClock_Start(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not yet started... */
        if (pclock->am_i_paused)
        {
            sfClock_Reset(pclock->my_clock);
            pclock->am_i_paused = 0;
        }
    }
}
 
/* Get the time elapsed since last Reset. */
float sfPausableClock_GetElapsedTime(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not paused... */
        if (!pclock->am_i_paused)
            return pclock->my_time + sfClock_GetTime(pclock->my_clock);
        else
            return pclock->my_time;
    }
    return (-1.0f);
}
 
/* Reset the clock. */
void sfPausableClock_Reset(sfPausableClock *pclock, int paused)
{
    if (pclock != NULL) {
        pclock->am_i_paused = paused;  /* does the clock start paused? */
        pclock->my_time = 0.f;
        sfClock_Reset(pclock->my_clock);
    }
}

/* wrapping sfPausableClock to ocaml */

CAMLprim value
caml_sfPausableClock_Create(value paused)
{
    sfPausableClock *pclock = sfPausableClock_Create(Bool_val(paused));
    return Val_sfPausableClock(pclock);
}

CAMLprim value
caml_sfPausableClock_Destroy(value pclock)
{
    sfPausableClock_Destroy(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_Pause(value pclock)
{
    sfPausableClock_Pause(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_Start(value pclock)
{
    sfPausableClock_Start(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_GetTime(value pclock)
{
    float t = sfPausableClock_GetElapsedTime(SfPausableClock_val(pclock));
    return caml_copy_double(t);
}

CAMLprim value
caml_sfPausableClock_Reset(value pclock, value paused)
{
    sfPausableClock_Reset(SfPausableClock_val(pclock), Bool_val(paused));
    return Val_unit;
}



/* sfFont */

CAMLprim value
caml_sfFont_GetDefaultFont(value unit)
{
    sfFont *font;
    font = sfFont_GetDefaultFont();
    if (!font) caml_failwith("SFFont.getDefaultFont");
    return Val_sfFont(font);
}

CAMLprim value
caml_sfFont_CreateFromFile(value ml_charSize, value ml_charset, value filename)
{
    sfFont* font;
    sfUint32* charset_ptr;
    sfUint32 charset;
    unsigned int charSize = 30;  /* same default value than in <SFML/Graphics/Font.hpp> */

    if (ml_charset == Val_none) charset_ptr = NULL;
    else { charset = Int32_val(Some_val(ml_charset)); charset_ptr = &charset; }

    if (ml_charSize != Val_none) {
        charSize = Long_val(Some_val(ml_charSize));
    }

    font = sfFont_CreateFromFile(String_val(filename), charSize, charset_ptr);
    if (!font) caml_failwith("SFFont.createFromFile");

    return Val_sfFont(font);
}

CAMLprim value
caml_sfFont_CreateFromMemory(value ml_charSize, value ml_charset, value data)
{
    sfFont* font;
    sfUint32* charset_ptr;
    sfUint32 charset;
    unsigned int charSize = 30;  /* same default value than in <SFML/Graphics/Font.hpp> */

    if (ml_charset == Val_none) charset_ptr = NULL;
    else { charset = Int32_val(Some_val(ml_charset)); charset_ptr = &charset; }

    if (ml_charSize != Val_none) {
        charSize = Long_val(Some_val(ml_charSize));
    }

    font = sfFont_CreateFromMemory(String_val(data), caml_string_length(data), charSize, charset_ptr);
    if (!font) caml_failwith("SFFont.createFromMemory");

    return Val_sfFont(font);
}

CAMLprim value
caml_sfFont_Destroy(value font)
{
    sfFont_Destroy(SfFont_val(font));
    return Val_unit;
}

/*
sfFont* sfFont_Create();
unsigned int sfFont_GetCharacterSize(sfFont* Font);
*/


/* sfString */

CAMLprim value
caml_sfString_Create(value unit)
{
    sfString* text;
    text = sfString_Create();
    if (!text) caml_failwith("SFString.create");
    return Val_sfString(text);
}

CAMLprim value
caml_sfString_Destroy(value text)
{
    sfString_Destroy(SfString_val(text));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetText(value text, value str)
{
    sfString_SetText(SfString_val(text), String_val(str));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetFont(value text, value font)
{
    sfString_SetFont(SfString_val(text), SfFont_val_u(font));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetSize(value text, value size)
{
    sfString_SetSize(SfString_val(text), Double_val(size));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetPosition(value text, value left, value top)
{
    sfString_SetPosition(SfString_val(text), Double_val(left), Double_val(top));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetPosition2(value text, value pos)
{
    sfString_SetPosition(SfString_val(text), 
        Double_val(Field(pos,0)), Double_val(Field(pos,1)));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetColor(value text, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfString_SetColor(SfString_val(text), color);
    return Val_unit;
}

CAMLprim value
caml_sfString_SetRotation(value text, value rotation)
{
    sfString_SetRotation(SfString_val(text), Double_val(rotation));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetScale(value text, value scaleX, value scaleY)
{
    sfString_SetScale(SfString_val(text), Double_val(scaleX), Double_val(scaleY));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetScale2(value text, value scale)
{
    sfString_SetScale(SfString_val(text),
            Double_val(Field(scale,0)), Double_val(Field(scale,1)));
    return Val_unit;
}

CAMLprim value
caml_sfString_Move(value text, value offsetX, value offsetY)
{
    sfString_Move(SfString_val(text), Double_val(offsetX), Double_val(offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfString_Move2(value text, value offset)
{
    sfString_Move(
            SfString_val(text),
            Double_val(Field(offset,0)),
            Double_val(Field(offset,1)));
    return Val_unit;
}

CAMLprim value
caml_sfString_Rotate(value text, value angle)
{
    sfString_Rotate(SfString_val(text), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfString_Scale(value text, value factorX, value factorY)
{
    sfString_Scale(SfString_val(text), Double_val(factorX), Double_val(factorY));
    return Val_unit;
}

CAMLprim value
caml_sfString_Scale2(value text, value factor)
{
    sfString_Scale(SfString_val(text),
            Double_val(Field(factor,0)), Double_val(Field(factor,1)));
    return Val_unit;
}

CAMLprim value
caml_sfString_SetBlendMode(value text, value mode)
{
    sfString_SetBlendMode(SfString_val(text), SfBlendMode_val(mode));
    return Val_unit;
}

CAMLprim value
caml_sfString_GetX(value text)
{
    float x = sfString_GetX(SfString_val(text));
    return caml_copy_double(x);
}

CAMLprim value
caml_sfString_GetY(value text)
{
    float y = sfString_GetY(SfString_val(text));
    return caml_copy_double(y);
}

CAMLprim value
caml_sfString_GetXY(value text)
{
    CAMLparam1(text);
    CAMLlocal1(xy);
    float x = sfString_GetX(SfString_val(text));
    float y = sfString_GetY(SfString_val(text));
    xy = caml_alloc(2, 0);
    Store_field(xy, 0, caml_copy_double(x));
    Store_field(xy, 1, caml_copy_double(y));
    CAMLreturn(xy);
}

CAMLprim value
caml_sfString_GetRect(value text)
{
    if (SfString_val(text) == NULL)
        caml_failwith("SFString.getRect");
    sfFloatRect rect = sfString_GetRect(SfString_val(text));
    return caml_return_sfFloatRect(&rect);
}


/* sfShape */

CAMLprim value
caml_sfShape_Create(value unit)
{
    sfShape *shape = sfShape_Create();
    if (!shape) caml_failwith("SFShape.create");
    return Val_sfShape(shape);
}

CAMLprim value
caml_sfShape_Destroy(value shape)
{
    sfShape_Destroy(SfShape_val(shape));
    return Val_unit;
}

CAMLprim value
caml_sfShape_CreateLine(
        value p1, value p2, value thickness,
        value ml_color, value outline, value ml_outlineCol)
{
    sfColor color, outlineCol;
    SfColor_val(&color, ml_color);
    SfColor_val(&outlineCol, ml_outlineCol);

    sfShape *shape = sfShape_CreateLine(
        Double_val(Field(p1,0)), Double_val(Field(p1,1)),
        Double_val(Field(p2,0)), Double_val(Field(p2,1)),
        Double_val(thickness),
        color, Double_val(outline), outlineCol);

    if (!shape) caml_failwith("SFShape.createLine");

    return Val_sfShape(shape);
}
CAMLprim value
caml_sfShape_CreateLine_bytecode(value * argv, int argn)
{
    return caml_sfShape_CreateLine(
                argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_sfShape_CreateRectangle(
        value p1, value p2,
        value ml_color, value outline, value ml_outlineCol)
{
    sfColor color, outlineCol;
    SfColor_val(&color, ml_color);
    SfColor_val(&outlineCol, ml_outlineCol);

    sfShape *shape = sfShape_CreateRectangle(
        Double_val(Field(p1,0)), Double_val(Field(p1,1)),
        Double_val(Field(p2,0)), Double_val(Field(p2,1)),
        color, Double_val(outline), outlineCol);

    if (!shape) caml_failwith("SFShape.createRectangle");

    return Val_sfShape(shape);
}

CAMLprim value
caml_sfShape_CreateCircle(
        value center, value radius,
        value ml_color, value outline, value ml_outlineCol)
{
    sfColor color, outlineCol;
    SfColor_val(&color, ml_color);
    SfColor_val(&outlineCol, ml_outlineCol);

    sfShape *shape = sfShape_CreateCircle(
        Double_val(Field(center,0)), Double_val(Field(center,1)),
        Double_val(radius), color, Double_val(outline), outlineCol);

    if (!shape) caml_failwith("SFShape.createCircle");

    return Val_sfShape(shape);
}

CAMLprim value
caml_sfShape_Move(value shape, value offsetX, value offsetY)
{
    sfShape_Move(SfShape_val(shape), Double_val(offsetX), Double_val(offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfShape_Move2(value shape, value offset)
{
    sfShape_Move(SfShape_val(shape),
            Double_val(Field(offset,0)), Double_val(Field(offset,1)));
    return Val_unit;
}

CAMLprim value
caml_sfShape_Rotate(value shape, value angle)
{
    sfShape_Rotate(SfShape_val(shape), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfShape_Scale(value shape, value factorX, value factorY)
{
    sfShape_Scale(SfShape_val(shape), Double_val(factorX), Double_val(factorY));
    return Val_unit;
}

CAMLprim value
caml_sfShape_Scale2(value shape, value factor)
{
    sfShape_Scale(SfShape_val(shape), Double_val(Field(factor,0)), Double_val(Field(factor,1)));
    return Val_unit;
}

CAMLprim value
caml_sfShape_SetBlendMode(value shape, value mode)
{
    sfShape_SetBlendMode(SfShape_val(shape), SfBlendMode_val(mode));
    return Val_unit;
}

CAMLprim value
caml_sfShape_AddPoint(
        value shape, value pos,
        value ml_color, value ml_outlineCol)
{
    sfColor color, outlineCol;
    SfColor_val(&color, ml_color);
    SfColor_val(&outlineCol, ml_outlineCol);

    sfShape_AddPoint(
            SfShape_val(shape),
            Double_val(Field(pos,0)),
            Double_val(Field(pos,1)),
            color, outlineCol);

    return Val_unit;
}


/* sfMusic */

CAMLprim value
caml_sfMusic_CreateFromFile(value filename)
{
    sfMusic* music;
    music = sfMusic_CreateFromFile(String_val(filename));
    if (!music) caml_failwith("SFMusic.createFromFile");
    return Val_sfMusic(music);
}

CAMLprim value
caml_sfMusic_CreateFromMemory(value data)
{
    sfMusic *music =
        sfMusic_CreateFromMemory(
            String_val(data), caml_string_length(data));
    if (!music) caml_failwith("SFMusic.createFromMemory");
    return Val_sfMusic(music);
}

CAMLprim value
caml_sfMusic_Destroy(value music)
{
    sfMusic_Destroy(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_Play(value music)
{
    sfMusic_Play(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_Pause(value music)
{
    sfMusic_Pause(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_Stop(value music)
{
    sfMusic_Stop(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetLoop(value music, value loop)
{
    sfMusic_SetLoop(SfMusic_val(music), Bool_val(loop));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetVolume(value music, value volume)
{
    sfMusic_SetVolume(SfMusic_val(music), Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_GetVolume(value music)
{
    float volume = sfMusic_GetVolume(SfMusic_val(music));
    return caml_copy_double(volume);
}

CAMLprim value
caml_sfMusic_SetPitch(value music, value pitch)
{
    sfMusic_SetPitch(SfMusic_val(music), Double_val(pitch));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetMinDistance(value music, value minDistance)
{
    sfMusic_SetMinDistance(SfMusic_val(music), Double_val(minDistance));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetAttenuation(value music, value attenuation)
{
    sfMusic_SetAttenuation(SfMusic_val(music), Double_val(attenuation));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetPosition(value music, value x, value y, value z)
{
    sfMusic_SetPosition(SfMusic_val(music), Double_val(x), Double_val(y), Double_val(z));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_SetRelativeToListener(value music, value relative)
{
    sfMusic_SetRelativeToListener(SfMusic_val(music), Bool_val(relative));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_GetDuration(value music)
{
    float duration = sfMusic_GetDuration(SfMusic_val(music));
    return caml_copy_double(duration);
}

CAMLprim value
caml_sfMusic_GetSampleRate(value music)
{
    unsigned int sampleRate = sfMusic_GetSampleRate(SfMusic_val(music));
    return Val_long(sampleRate);
}

CAMLprim value
caml_sfMusic_GetChannelsCount(value music)
{
    unsigned int channelsCount = sfMusic_GetChannelsCount(SfMusic_val(music));
    return Val_long(channelsCount);
}

CAMLprim value
caml_sfMusic_GetStatus(value music)
{
    sfSoundStatus sndst = sfMusic_GetStatus(SfMusic_val(music));
    return Val_sfSoundStatus(sndst);
}

CAMLprim value
caml_sfMusic_GetPlayingOffset(value music)
{
    float playingOffset = sfMusic_GetPlayingOffset(SfMusic_val(music));
    return caml_copy_double(playingOffset);
}

CAMLprim value
caml_sfMusic_GetLoop(value music)
{
    sfBool loop = sfMusic_GetLoop(SfMusic_val(music));
    return Val_bool(loop);
}

CAMLprim value
caml_sfMusic_GetPitch(value music)
{
    float pitch = sfMusic_GetPitch(SfMusic_val(music));
    return caml_copy_double(pitch);
}

CAMLprim value
caml_sfMusic_GetPosition(value music)
{
    CAMLparam1(music);
    CAMLlocal1(xyz);
    float x, y, z;
    sfMusic_GetPosition(SfMusic_val(music), &x, &y, &z);
    xyz = caml_alloc(3, 0);
    Store_field(xyz, 0, caml_copy_double(x));
    Store_field(xyz, 1, caml_copy_double(y));
    Store_field(xyz, 2, caml_copy_double(z));
    CAMLreturn(xyz);
}

/* TODO
sfBool sfMusic_IsRelativeToListener(sfMusic* Music);
float sfMusic_GetMinDistance(sfMusic* Music);
float sfMusic_GetAttenuation(sfMusic* Music);
*/


/* sfSound */

CAMLprim value
caml_sfSound_Create(value unit)
{
    return Val_sfSound(sfSound_Create());
}

CAMLprim value
caml_sfSound_Destroy(value sound)
{
    sfSound_Destroy(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_Play(value sound)
{
    sfSound_Play(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_Pause(value sound)
{
    sfSound_Pause(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_Stop(value sound)
{
    sfSound_Stop(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetBuffer(value sound, value buffer)
{
    sfSound_SetBuffer(SfSound_val(sound), SfSoundBuffer_val_u(buffer));
    return Val_unit;
}

/* TODO
sfSoundBuffer* sfSound_GetBuffer(sfSound* Sound);
*/

CAMLprim value
caml_sfSound_SetLoop(value sound, value loop)
{
    sfSound_SetLoop(SfSound_val(sound), Bool_val(loop));
    return Val_unit;
}

CAMLprim value
caml_sfSound_GetLoop(value sound)
{
    sfBool loop = sfSound_GetLoop(SfSound_val(sound));
    return Val_bool(loop);
}

CAMLprim value
caml_sfSound_GetStatus(value sound)
{
    sfSoundStatus sndst = sfSound_GetStatus(SfSound_val(sound));
    return Val_sfSoundStatus(sndst);
}

CAMLprim value
caml_sfSound_SetPitch(value sound, value pitch)
{
    sfSound_SetPitch(SfSound_val(sound), Double_val(pitch));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetVolume(value sound, value volume)
{
    sfSound_SetVolume(SfSound_val(sound), Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetPosition(value sound, value x, value y, value z)
{
    sfSound_SetPosition(SfSound_val(sound), Double_val(x), Double_val(y), Double_val(z));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetRelativeToListener(value sound, value relative)
{
    sfSound_SetRelativeToListener(SfSound_val(sound), Bool_val(relative));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetMinDistance(value sound, value minDistance)
{
    sfSound_SetMinDistance(SfSound_val(sound), Double_val(minDistance));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetAttenuation(value sound, value attenuation)
{
    sfSound_SetAttenuation(SfSound_val(sound), Double_val(attenuation));
    return Val_unit;
}

CAMLprim value
caml_sfSound_SetPlayingOffset(value sound, value timeOffset)
{
    sfSound_SetPlayingOffset(SfSound_val(sound), Double_val(timeOffset));
    return Val_unit;
}

CAMLprim value
caml_sfSound_GetPlayingOffset(value sound)
{
    float playingOffset = sfSound_GetPlayingOffset(SfSound_val(sound));
    return caml_copy_double(playingOffset);
}

CAMLprim value
caml_sfSound_GetPitch(value sound)
{
    float pitch = sfSound_GetPitch(SfSound_val(sound));
    return caml_copy_double(pitch);
}

CAMLprim value
caml_sfSound_GetVolume(value sound)
{
    float volume = sfSound_GetVolume(SfSound_val(sound));
    return caml_copy_double(volume);
}

CAMLprim value
caml_sfSound_IsRelativeToListener(value sound)
{
    sfBool relativeToListener = sfSound_IsRelativeToListener(SfSound_val(sound));
    return Val_bool(relativeToListener);
}

CAMLprim value
caml_sfSound_GetPosition(value sound)
{
    CAMLparam1(sound);
    CAMLlocal1(xyz);
    float x;
    float y;
    float z;
    sfSound_GetPosition(SfSound_val(sound), &x, &y, &z);
    xyz = caml_alloc(3, 0);
    Store_field(xyz, 0, caml_copy_double(x));
    Store_field(xyz, 1, caml_copy_double(y));
    Store_field(xyz, 2, caml_copy_double(z));
    CAMLreturn(xyz);
}

CAMLprim value
caml_sfSound_GetMinDistance(value sound)
{
    float minDistance = sfSound_GetMinDistance(SfSound_val(sound));
    return caml_copy_double(minDistance);
}

CAMLprim value
caml_sfSound_GetAttenuation(value sound)
{
    float attenuation = sfSound_GetAttenuation(SfSound_val(sound));
    return caml_copy_double(attenuation);
}


/* sfListener */

CAMLprim value
caml_sfListener_SetGlobalVolume(value volume)
{
    sfListener_SetGlobalVolume(Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfListener_GetGlobalVolume(value unit)
{
    return caml_copy_double(sfListener_GetGlobalVolume());
}

CAMLprim value
caml_sfListener_SetPosition(value posX, value posY, value posZ)
{
    sfListener_SetPosition(Double_val(posX), Double_val(posY), Double_val(posZ));
    return Val_unit;
}

CAMLprim value
caml_sfListener_GetPosition(value unit)
{
    CAMLparam0();
    CAMLlocal1(pos);
    float posX;
    float posY;
    float posZ;
    sfListener_GetPosition(&posX, &posY, &posZ);
    pos = caml_alloc(3, 0);
    Store_field(pos, 0, caml_copy_double(posX));
    Store_field(pos, 1, caml_copy_double(posY));
    Store_field(pos, 2, caml_copy_double(posZ));
    CAMLreturn(pos);
}

CAMLprim value
caml_sfListener_SetTarget(value targetX, value targetY, value targetZ)
{
    sfListener_SetTarget(Double_val(targetX), Double_val(targetY), Double_val(targetZ));
    return Val_unit;
}

CAMLprim value
caml_sfListener_GetTarget(value unit)
{
    CAMLparam0();
    CAMLlocal1(tg);
    float targetX;
    float targetY;
    float targetZ;
    sfListener_GetTarget(&targetX, &targetY, &targetZ);
    tg = caml_alloc(3, 0);
    Store_field(tg, 0, caml_copy_double(targetX));
    Store_field(tg, 1, caml_copy_double(targetY));
    Store_field(tg, 2, caml_copy_double(targetZ));
    CAMLreturn(tg);
}


/* sfSoundBuffer */

CAMLprim value
caml_sfSoundBuffer_CreateFromFile(value filename)
{
    sfSoundBuffer *sbf = sfSoundBuffer_CreateFromFile(String_val(filename));
    if (sbf == NULL) caml_failwith("SFSoundBuffer.createFromFile");
    return Val_sfSoundBuffer(sbf);
}

CAMLprim value
caml_sfSoundBuffer_CreateFromMemory(value data)
{
    sfSoundBuffer *sbf =
        sfSoundBuffer_CreateFromMemory(
            String_val(data), caml_string_length(data));
    if (sbf == NULL) caml_failwith("SFSoundBuffer.createFromMemory");
    return Val_sfSoundBuffer(sbf);
}

CAMLprim value
caml_sfSoundBuffer_Destroy(value soundBuffer)
{
    sfSoundBuffer_Destroy(SfSoundBuffer_val(soundBuffer));
    return Val_unit;
}

CAMLprim value
caml_sfSoundBuffer_GetSamplesCount(value soundBuffer)
{
    size_t samplesCount = sfSoundBuffer_GetSamplesCount(SfSoundBuffer_val(soundBuffer));
    return Val_long(samplesCount);
}

CAMLprim value
caml_sfSoundBuffer_GetSampleRate(value soundBuffer)
{
    unsigned int sampleRate = sfSoundBuffer_GetSampleRate(SfSoundBuffer_val(soundBuffer));
    return Val_long(sampleRate);
}

CAMLprim value
caml_sfSoundBuffer_GetChannelsCount(value soundBuffer)
{
    unsigned int channelsCount = sfSoundBuffer_GetChannelsCount(SfSoundBuffer_val(soundBuffer));
    return Val_long(channelsCount);
}

CAMLprim value
caml_sfSoundBuffer_GetDuration(value soundBuffer)
{
    float duration = sfSoundBuffer_GetDuration(SfSoundBuffer_val(soundBuffer));
    return caml_copy_double(duration);
}

CAMLprim value
caml_sfSoundBuffer_SaveToFile(value soundBuffer, value filename)
{
    sfBool saved = sfSoundBuffer_SaveToFile(SfSoundBuffer_val(soundBuffer), String_val(filename));
    if (!saved) caml_failwith("SFSoundBuffer.saveToFile");
    return Val_unit;
}

/* TODO?
sfSoundBuffer* sfSoundBuffer_CreateFromSamples(const sfInt16* Samples, size_t SamplesCount, unsigned int ChannelsCount, unsigned int SampleRate);
const sfInt16* sfSoundBuffer_GetSamples(sfSoundBuffer* SoundBuffer);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
