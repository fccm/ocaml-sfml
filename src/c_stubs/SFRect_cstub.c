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

#include <SFML/Graphics/Rect.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFRect_cstub.h"

/* sfRect */

value caml_copy_sfIntRect(sfIntRect *rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    int left   = rect->left;
    int top    = rect->top;
    int width  = rect->width;
    int height = rect->height;
    r = caml_alloc(4, 0);
    Store_field(r, 0, Val_long(left));
    Store_field(r, 1, Val_long(top));
    Store_field(r, 2, Val_long(width));
    Store_field(r, 3, Val_long(height));
    CAMLreturn(r);
}

value caml_copy_sfFloatRect(sfFloatRect *rect)
{
    CAMLparam0();
    CAMLlocal1(r);
    float left   = rect->left;
    float top    = rect->top;
    float width  = rect->width;
    float height = rect->height;
    r = caml_alloc(4, 0);
    Store_field(r, 0, caml_copy_double(left));
    Store_field(r, 1, caml_copy_double(top));
    Store_field(r, 2, caml_copy_double(width));
    Store_field(r, 3, caml_copy_double(height));
    CAMLreturn(r);
}

void SfIntRect_val(sfIntRect *rect, value int_rect)
{
    rect->left   = Int_val(Field(int_rect,0));
    rect->top    = Int_val(Field(int_rect,1));
    rect->width  = Int_val(Field(int_rect,2));
    rect->height = Int_val(Field(int_rect,3));
}

void SfFloatRect_val(sfFloatRect *rect, value float_rect)
{
    /*
    if (Tag_val(float_rect) == Double_array_tag) {
    */
    rect->left   = Double_field(float_rect,0);
    rect->top    = Double_field(float_rect,1);
    rect->width  = Double_field(float_rect,2);
    rect->height = Double_field(float_rect,3);
    /*
    rect->left   = Double_val(Field(float_rect,0));
    rect->top    = Double_val(Field(float_rect,1));
    rect->width  = Double_val(Field(float_rect,2));
    rect->height = Double_val(Field(float_rect,3));
    */
}

CAMLprim value
caml_sfIntRect_contains(value rect, value x, value y)
{
    sfIntRect _rect;
    SfIntRect_val(&_rect, rect);
    return Val_bool(
        sfIntRect_contains(&_rect, Int_val(x), Int_val(y)));
}

CAMLprim value
caml_sfFloatRect_contains(value rect, value x, value y)
{
    sfFloatRect _rect;
    SfFloatRect_val(&_rect, rect);
    return Val_bool(
        sfFloatRect_contains(&_rect, Double_val(x), Double_val(y)));
}

CAMLprim value
caml_sfFloatRect_intersects(value rect1, value rect2)
{
    sfFloatRect _rect1;
    sfFloatRect _rect2;
    SfFloatRect_val(&_rect1, rect1);
    SfFloatRect_val(&_rect2, rect2);
    sfBool inter = sfFloatRect_intersects(&_rect1, &_rect2, NULL);
    return Val_bool(inter);
}

CAMLprim value
caml_sfFloatRect_intersection(value rect1, value rect2)
{
    sfFloatRect _rect1;
    sfFloatRect _rect2;
    sfFloatRect intersection;
    SfFloatRect_val(&_rect1, rect1);
    SfFloatRect_val(&_rect2, rect2);
    sfBool inter = sfFloatRect_intersects(&_rect1, &_rect2, &intersection);
    if (inter) {
        return Val_some(caml_copy_sfFloatRect(&intersection));
    } else {
        return Val_none;
    }
}

CAMLprim value
caml_sfIntRect_intersects(value rect1, value rect2)
{
    sfIntRect _rect1;
    sfIntRect _rect2;
    SfIntRect_val(&_rect1, rect1);
    SfIntRect_val(&_rect2, rect2);
    sfBool inter = sfIntRect_intersects(&_rect1, &_rect2, NULL);
    return Val_bool(inter);
}

CAMLprim value
caml_sfIntRect_intersection(value rect1, value rect2)
{
    sfIntRect _rect1;
    sfIntRect _rect2;
    sfIntRect intersection;
    SfIntRect_val(&_rect1, rect1);
    SfIntRect_val(&_rect2, rect2);
    sfBool inter = sfIntRect_intersects(&_rect1, &_rect2, &intersection);
    if (inter) {
        return Val_some(caml_copy_sfIntRect(&intersection));
    } else {
        return Val_none;
    }
}

/* vim: sw=4 sts=4 ts=4 et
 */
