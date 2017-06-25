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

#include <SFML/Graphics/BlendMode.hpp>

#include "sf_caml_incs.hpp"
#include "SFBlendMode_stub.hpp"

sf::BlendMode
SfBlendMode_val(value ml_blendMode)
{
    return sf::BlendMode(
        static_cast<sf::BlendMode::Factor>(Int_val(Field(ml_blendMode, 0))),
        static_cast<sf::BlendMode::Factor>(Int_val(Field(ml_blendMode, 1))),
        static_cast<sf::BlendMode::Equation>(Int_val(Field(ml_blendMode, 2))),
        static_cast<sf::BlendMode::Factor>(Int_val(Field(ml_blendMode, 3))),
        static_cast<sf::BlendMode::Factor>(Int_val(Field(ml_blendMode, 4))),
        static_cast<sf::BlendMode::Equation>(Int_val(Field(ml_blendMode, 5))));
}

value
Val_sfBlendMode(sf::BlendMode blendMode)
{
    CAMLparam0();

    CAMLlocal1(ml_blendMode);
    ml_blendMode = caml_alloc_tuple(6);
    Store_field(ml_blendMode, 0, Val_int(blendMode.colorSrcFactor));
    Store_field(ml_blendMode, 1, Val_int(blendMode.colorDstFactor));
    Store_field(ml_blendMode, 2, Val_int(blendMode.colorEquation));
    Store_field(ml_blendMode, 3, Val_int(blendMode.alphaSrcFactor));
    Store_field(ml_blendMode, 4, Val_int(blendMode.alphaDstFactor));
    Store_field(ml_blendMode, 5, Val_int(blendMode.alphaEquation));

    CAMLreturn(ml_blendMode);
}

// vim: sw=4 sts=4 ts=4 et
