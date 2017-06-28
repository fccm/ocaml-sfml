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

#include <SFML/Window/Joystick.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFJoystick_stub.hpp"

/* sf::Joystick */

value
Val_sfJoystickAxis(sf::Joystick::Axis axis)
{
    switch (axis)
    {
        case sf::Joystick::X:    return Val_int(0);
        case sf::Joystick::Y:    return Val_int(1);
        case sf::Joystick::Z:    return Val_int(2);
        case sf::Joystick::R:    return Val_int(3);
        case sf::Joystick::U:    return Val_int(4);
        case sf::Joystick::V:    return Val_int(5);
        case sf::Joystick::PovX: return Val_int(6);
        case sf::Joystick::PovY: return Val_int(7);
        default: caml_failwith("SFJoystick.axis");
    }
    caml_failwith("SFJoystick.axis");
}

sf::Joystick::Axis
SfJoystickAxis_val(value axis)
{
    switch (Int_val(axis))
    {
        case 0: return sf::Joystick::X;
        case 1: return sf::Joystick::Y;
        case 2: return sf::Joystick::Z;
        case 3: return sf::Joystick::R;
        case 4: return sf::Joystick::U;
        case 5: return sf::Joystick::V;
        case 6: return sf::Joystick::PovX;
        case 7: return sf::Joystick::PovY;
        default: caml_failwith("SFJoystick.axis");
    }
    caml_failwith("SFJoystick.axis");
}

CAMLextern_C value
caml_sfJoystickCount(value unit)
{
    return Val_int(sf::Joystick::Count);
}

CAMLextern_C value
caml_sfJoystickButtonCount(value unit)
{
    return Val_int(sf::Joystick::ButtonCount);
}

CAMLextern_C value
caml_sfJoystickAxisCount(value unit)
{
    return Val_int(sf::Joystick::AxisCount);
}

CAMLextern_C value
caml_sfJoystick_isConnected(value joystick)
{
    return Val_bool(
        sf::Joystick::isConnected(Int_val(joystick)));
}

CAMLextern_C value
caml_sfJoystick_getButtonCount(value joystick)
{
    unsigned int n = sf::Joystick::getButtonCount(Int_val(joystick));
    return Val_int(n);
}

CAMLextern_C value
caml_sfJoystick_update(value unit)
{
    sf::Joystick::update();
    return Val_unit;
}

CAMLextern_C value
caml_sfJoystick_isButtonPressed(value ml_joystick, value ml_button)
{
    int joystick = Int_val(ml_joystick);
    int button = Int_val(ml_button);
    if (joystick < 0 || button < 0)
        caml_invalid_argument("SFJoystick.isButtonPressed");
    return Val_bool(
        sf::Joystick::isButtonPressed(joystick, button));
}

CAMLextern_C value
caml_sfJoystick_hasAxis(value ml_joystick, value axis)
{
    int joystick = Int_val(ml_joystick);
    if (joystick < 0)
        caml_invalid_argument("SFJoystick.hasAxis");
    return Val_bool(
        sf::Joystick::hasAxis(joystick, SfJoystickAxis_val(axis)));
}

CAMLextern_C value
caml_sfJoystick_getAxisPosition(value ml_joystick, value axis)
{
    int joystick = Int_val(ml_joystick);
    if (joystick < 0)
        caml_invalid_argument("SFJoystick.getAxisPosition");
    float pos = sf::Joystick::getAxisPosition(joystick, SfJoystickAxis_val(axis));
    return caml_copy_double(pos);
}

CAMLextern_C value
caml_sfJoystick_getIdentification(value ml_joystick)
{
    CAMLparam0();

    sf::Joystick::Identification sf_ident = sf::Joystick::getIdentification(Unsigned_int_val(ml_joystick));
    CAMLlocal1(ident);
    ident = caml_alloc_tuple(3);
    Store_field(ident, 0, caml_copy_string(sf_ident.name.toAnsiString().c_str()));
    Store_field(ident, 1, caml_copy_nativeint(sf_ident.vendorId));
    Store_field(ident, 2, caml_copy_nativeint(sf_ident.productId));

    CAMLreturn(ident);
}

#include <cmath>

sf::Vector2f
sfJoystick_normaliseDirectionProportional(float x, float y)
{
#define VECTOR_LENGTH(x, y) \
  sqrtf(((x) * (x)) + ((y) * (y)))
    float in_len, ratio;
    sf::Vector2f res;
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

CAMLextern_C value
caml_sfJoystick_normaliseDirectionProportional(value x, value y)
{
    sf::Vector2f vec = 
        sfJoystick_normaliseDirectionProportional(
                Double_val(x), Double_val(y));

    return Val_sfVector2f(vec);
}

// vim: sw=4 sts=4 ts=4 et
