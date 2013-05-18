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

#include <SFML/Window/VideoMode.hpp>

#include "sf_caml_incs.hpp"

/* sf::VideoMode */

static inline value
copy_sfVideoMode_contents(const sf::VideoMode& mode)
{
    CAMLparam0();
    CAMLlocal1(v);
    v = caml_alloc(3, 0);
    Store_field(v, 0, Val_long(mode.width));
    Store_field(v, 1, Val_long(mode.height));
    Store_field(v, 2, Val_long(mode.bitsPerPixel));
    CAMLreturn(v);
}

#define c2ml_sfVideoMode_contents(v) \
    unsigned int width = Long_val(Field(v, 0)); \
    unsigned int height = Long_val(Field(v, 1)); \
    unsigned int bitsPerPixel = Long_val(Field(v, 2));

CAMLextern_C value
caml_sfVideoMode_getDesktopMode(value unit)
{
    CAMLparam0();
    CAMLlocal1(ml_mode);

    sf::VideoMode mode = sf::VideoMode::getDesktopMode();

    ml_mode = copy_sfVideoMode_contents(mode);

    CAMLreturn(ml_mode);
}

CAMLextern_C value
caml_sfVideoMode_getFullscreenModes(value unit)
{
    CAMLparam0();
    CAMLlocal2(ml_modes, v);

    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    ml_modes = caml_alloc(modes.size(), 0);

    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        v = copy_sfVideoMode_contents(mode);
        Store_field(ml_modes, i, v);
    }

    CAMLreturn(ml_modes);
}

/* TODO
CAMLextern_C value
caml_sfVideoMode_isValid(value ml_mode)
{
    sfVideoMode_isValid(mode);
}
*/

// vim: sw=4 sts=4 ts=4 et
