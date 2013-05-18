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

#include <SFML/Graphics/Rect.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFRect_stub.hpp"

/* sf::Rect */

value caml_copy_sfIntRect(const sf::IntRect& rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    r = caml_alloc(4, 0);
    Store_field(r, 0, Val_long(rect.left));
    Store_field(r, 1, Val_long(rect.top));
    Store_field(r, 2, Val_long(rect.width));
    Store_field(r, 3, Val_long(rect.height));
    CAMLreturn(r);
}

value caml_copy_sfFloatRect(const sf::FloatRect& rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    r = caml_alloc(4, 0);
    Store_field(r, 0, caml_copy_double(rect.left));
    Store_field(r, 1, caml_copy_double(rect.top));
    Store_field(r, 2, caml_copy_double(rect.width));
    Store_field(r, 3, caml_copy_double(rect.height));
    CAMLreturn(r);
}

sf::IntRect
SfIntRect_val(value int_rect)
{
    sf::IntRect rect = sf::IntRect(
        Int_val(Field(int_rect,0)),
        Int_val(Field(int_rect,1)),
        Int_val(Field(int_rect,2)),
        Int_val(Field(int_rect,3)));
    return rect;
}

sf::FloatRect
SfFloatRect_val(value float_rect)
{
    sf::FloatRect rect;
    rect = sf::FloatRect(
        Double_field(float_rect,0),
        Double_field(float_rect,1),
        Double_field(float_rect,2),
        Double_field(float_rect,3));
    /*
    rect = sf::FloatRect(
        Double_val(Field(float_rect,0)),
        Double_val(Field(float_rect,1)),
        Double_val(Field(float_rect,2)),
        Double_val(Field(float_rect,3)));
    */
    return rect;
}

CAMLextern_C value
caml_sfIntRect_contains(value rect, value x, value y)
{
    return Val_bool(
        SfIntRect_val(rect).contains(Int_val(x), Int_val(y)));
}

CAMLextern_C value
caml_sfFloatRect_contains(value rect, value x, value y)
{
    return Val_bool(
        SfFloatRect_val(rect).contains(Double_val(x), Double_val(y)));
}

CAMLextern_C value
caml_sfFloatRect_intersects(value rect1, value rect2)
{
    bool inter = SfFloatRect_val(rect1).intersects(SfFloatRect_val(rect2));
    return Val_bool(inter);
}

CAMLextern_C value
caml_sfFloatRect_intersection(value rect1, value rect2)
{
    sf::FloatRect intersection;
    bool inter =
        SfFloatRect_val(rect1).intersects(SfFloatRect_val(rect2), intersection);
    if (inter) {
        return Val_some(caml_copy_sfFloatRect(intersection));
    } else {
        return Val_none;
    }
}

CAMLextern_C value
caml_sfIntRect_intersects(value rect1, value rect2)
{
    bool inter = SfIntRect_val(rect1).intersects(SfIntRect_val(rect2));
    return Val_bool(inter);
}

CAMLextern_C value
caml_sfIntRect_intersection(value rect1, value rect2)
{
    sf::IntRect intersection;
    bool inter =
        SfIntRect_val(rect1).intersects(SfIntRect_val(rect2), intersection);
    if (inter) {
        return Val_some(caml_copy_sfIntRect(intersection));
    } else {
        return Val_none;
    }
}

// vim: sw=4 sts=4 ts=4 et
