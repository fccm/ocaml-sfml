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

#include <SFML/Graphics/Color.hpp>

#include "sf_caml_incs.hpp"

/* sf::Color */

sf::Color
SfColor_val(value color)
{
    value _color = Field(color,0);
    switch (Tag_val(color))
    {
        case 0:
            return sf::Color(
                    Int_val(Field(_color,0)),
                    Int_val(Field(_color,1)),
                    Int_val(Field(_color,2)));
        case 1:
            return sf::Color(
                    Int_val(Field(_color,0)),
                    Int_val(Field(_color,1)),
                    Int_val(Field(_color,2)),
                    Int_val(Field(_color,3)));
        default: caml_failwith("SFColor.t");
    }
}

value
Val_sfColor4(const sf::Color& color)
{
    CAMLparam0();
    CAMLlocal2(col, rgba);
    rgba = caml_alloc(4, 0);
    Store_field(rgba, 0, Val_long(color.r));
    Store_field(rgba, 1, Val_long(color.g));
    Store_field(rgba, 2, Val_long(color.b));
    Store_field(rgba, 3, Val_long(color.a));
    col = caml_alloc(1, 1);
    Store_field(col, 0, rgba);
    CAMLreturn(col);
}

value
Val_sfColor3(const sf::Color& color)
{
    CAMLparam0();
    CAMLlocal2(col, rgb);
    rgb = caml_alloc(3, 0);
    Store_field(rgb, 0, Val_long(color.r));
    Store_field(rgb, 1, Val_long(color.g));
    Store_field(rgb, 2, Val_long(color.b));
    col = caml_alloc(1, 0);
    Store_field(col, 0, rgb);
    CAMLreturn(col);
}

value
Val_RGB(const sf::Color& color)
{
    CAMLparam0();
    CAMLlocal1(rgb);
    rgb = caml_alloc(3, 0);
    Store_field(rgb, 0, Val_long(color.r));
    Store_field(rgb, 1, Val_long(color.g));
    Store_field(rgb, 2, Val_long(color.b));
    CAMLreturn(rgb);
}

value
Val_RGBA(const sf::Color& color)
{
    CAMLparam0();
    CAMLlocal1(rgba);
    rgba = caml_alloc(4, 0);
    Store_field(rgba, 0, Val_long(color.r));
    Store_field(rgba, 1, Val_long(color.g));
    Store_field(rgba, 2, Val_long(color.b));
    Store_field(rgba, 3, Val_long(color.a));
    CAMLreturn(rgba);
}

// vim: sw=4 sts=4 ts=4 et
