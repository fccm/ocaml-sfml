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

#include <SFML/Window/Mouse.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFMouse_stub.hpp"

sf::Mouse::Button
SfMouseButton_val(value button)
{
    switch (Int_val(button))
    {
        case 0: return sf::Mouse::Left;
        case 1: return sf::Mouse::Right;
        case 2: return sf::Mouse::Middle;
        case 3: return sf::Mouse::XButton1;
        case 4: return sf::Mouse::XButton2;
        default: caml_failwith("SFMouse.mouse_button");
    }
    caml_failwith("SFMouse.mouse_button");
}

value
Val_sfMouseButton(sf::Mouse::Button button)
{
    switch (button) {
        case sf::Mouse::Left:        return Val_long(0);
        case sf::Mouse::Right:       return Val_long(1);
        case sf::Mouse::Middle:      return Val_long(2);
        case sf::Mouse::XButton1:    return Val_long(3);
        case sf::Mouse::XButton2:    return Val_long(4);
        default: caml_failwith("SFMouse.mouse_button");
    }
    caml_failwith("SFMouse.mouse_button");
}

CAMLextern_C value
caml_sfMouseButtonCount(value unit)
{
    return Val_int(sf::Mouse::ButtonCount);
}

CAMLextern_C value
caml_sfMouse_isButtonPressed(value button)
{
    return Val_bool(
        sf::Mouse::isButtonPressed(SfMouseButton_val(button)));
}

CAMLextern_C value
caml_sfMouse_getPosition(value unit)
{
    sf::Vector2i pos = sf::Mouse::getPosition();
    return Val_sfVector2i(pos);
}

CAMLextern_C value
caml_sfMouse_setPosition(value position)
{
    sf::Mouse::setPosition(SfVector2i_val(position));
    return Val_unit;
}

// vim: sw=4 sts=4 ts=4 et
