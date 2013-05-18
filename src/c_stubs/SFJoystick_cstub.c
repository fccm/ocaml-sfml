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

#include <SFML/Window/Joystick.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFJoystick_cstub.h"

/* sfJoystick */

value
Val_sfJoystickAxis(sfJoystickAxis axis)
{
    switch (axis)
    {
        case sfJoystickX:    return Val_int(0);
        case sfJoystickY:    return Val_int(1);
        case sfJoystickZ:    return Val_int(2);
        case sfJoystickR:    return Val_int(3);
        case sfJoystickU:    return Val_int(4);
        case sfJoystickV:    return Val_int(5);
        case sfJoystickPovX: return Val_int(6);
        case sfJoystickPovY: return Val_int(7);
        default: caml_failwith("SFJoystick.axis");
    }
    caml_failwith("SFJoystick.axis");
}

sfJoystickAxis
SfJoystickAxis_val(value axis)
{
    switch (Int_val(axis))
    {
        case 0: return sfJoystickX;
        case 1: return sfJoystickY;
        case 2: return sfJoystickZ;
        case 3: return sfJoystickR;
        case 4: return sfJoystickU;
        case 5: return sfJoystickV;
        case 6: return sfJoystickPovX;
        case 7: return sfJoystickPovY;
        default: caml_failwith("SFJoystick.axis");
    }
    caml_failwith("SFJoystick.axis");
}

CAMLprim value
caml_sfJoystickCount(value unit)
{
    return Val_int(sfJoystickCount);
}

CAMLprim value
caml_sfJoystickButtonCount(value unit)
{
    return Val_int(sfJoystickButtonCount);
}

CAMLprim value
caml_sfJoystickAxisCount(value unit)
{
    return Val_int(sfJoystickAxisCount);
}

CAMLprim value
caml_sfJoystick_isConnected(value joystick)
{
    return Val_bool(
        sfJoystick_isConnected(Int_val(joystick)));
}

CAMLprim value
caml_sfJoystick_getButtonCount(value joystick)
{
    unsigned int n = sfJoystick_getButtonCount(Int_val(joystick));
    return Val_int(n);
}

CAMLprim value
caml_sfJoystick_update(value unit)
{
    sfJoystick_update();
    return Val_unit;
}

CAMLprim value
caml_sfJoystick_isButtonPressed(value ml_joystick, value ml_button)
{
    int joystick = Int_val(ml_joystick);
    int button = Int_val(ml_button);
    if (joystick < 0 || button < 0)
        caml_invalid_argument("SFJoystick.isButtonPressed");
    return Val_bool(
        sfJoystick_isButtonPressed(joystick, button));
}

CAMLprim value
caml_sfJoystick_hasAxis(value ml_joystick, value axis)
{
    int joystick = Int_val(ml_joystick);
    if (joystick < 0)
        caml_invalid_argument("SFJoystick.hasAxis");
    return Val_bool(
        sfJoystick_hasAxis(joystick, SfJoystickAxis_val(axis)));
}

CAMLprim value
caml_sfJoystick_getAxisPosition(value ml_joystick, value axis)
{
    int joystick = Int_val(ml_joystick);
    if (joystick < 0)
        caml_invalid_argument("SFJoystick.getAxisPosition");
    float pos = sfJoystick_getAxisPosition(joystick, SfJoystickAxis_val(axis));
    return caml_copy_double(pos);
}


#include <math.h>

static sfVector2f
sfJoystick_normaliseDirectionProportional(float x, float y)
{
#define VECTOR_LENGTH(x, y) \
  sqrtf(((x) * (x)) + ((y) * (y)))
    float in_len, ratio;
    sfVector2f res;
    if (x == 0.f && y == 0.f) {
        res.x = 0.f;
        res.y = 0.f;
        return res;
    }
    in_len = VECTOR_LENGTH(x, y);
    if (fabsf(x) > fabsf(y))
        ratio = fabsf(x / 100.f) / in_len;
    else
        ratio = fabsf(y / 100.f) / in_len;
    res.x = x * ratio;
    res.y = y * ratio;
    return res;
#undef VECTOR_LENGTH
}

CAMLprim value
caml_sfJoystick_normaliseDirectionProportional(value x, value y)
{
    sfVector2f vec = 
        sfJoystick_normaliseDirectionProportional(
                Double_val(x), Double_val(y));

    return Val_sfVector2f(&vec);
}

/* vim: sw=4 sts=4 ts=4 et
 */
