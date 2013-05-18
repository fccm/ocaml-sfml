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

#include <SFML/Graphics/Color.h>
#include "sf_caml_incs_c.h"
#include "SFColor_cstub.h"

void
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

value
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

value
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

value
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

value
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

/* vim: sw=4 sts=4 ts=4 et
 */
