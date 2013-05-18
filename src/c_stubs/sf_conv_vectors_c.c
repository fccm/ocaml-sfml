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

#include "sf_caml_incs_c.h"

#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

value Val_sfVector2i(sfVector2i *vec)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_long(vec->x));
    Store_field(ret, 1, Val_long(vec->y));
    CAMLreturn(ret);
}

value Val_sfVector2u(sfVector2u *vec)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_long(vec->x));
    Store_field(ret, 1, Val_long(vec->y));
    CAMLreturn(ret);
}

value Val_sfVector2f(sfVector2f *vec)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(vec->x));
    Store_field(ret, 1, caml_copy_double(vec->y));
    CAMLreturn(ret);
}

value Val_sfVector3f(sfVector3f *vec)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, caml_copy_double(vec->x));
    Store_field(ret, 1, caml_copy_double(vec->y));
    Store_field(ret, 2, caml_copy_double(vec->z));
    CAMLreturn(ret);
}

sfVector2i
SfVector2i_val(value ml_vec)
{
    sfVector2i vec;
    vec.x = Long_val(Field(ml_vec,0));
    vec.y = Long_val(Field(ml_vec,1));
    return vec;
}

sfVector2i
SfVector2i_val2(value x, value y)
{
    sfVector2i vec;
    vec.x = Long_val(x);
    vec.y = Long_val(y);
    return vec;
}

sfVector2u
SfVector2u_val2(value x, value y)
{
    sfVector2u vec;
    vec.x = Long_val(x);
    vec.y = Long_val(y);
    return vec;
}

sfVector2u
SfVector2u_val(value ml_vec)
{
    sfVector2u vec;
    vec.x = Long_val(Field(ml_vec,0));
    vec.y = Long_val(Field(ml_vec,1));
    return vec;
}

sfVector2f
SfVector2f_val2(value x, value y)
{
    sfVector2f vec;
    vec.x = Double_val(x);
    vec.y = Double_val(y);
    return vec;
}

sfVector2f
SfVector2f_val(value ml_vec)
{
    sfVector2f vec;
    vec.x = Double_val(Field(ml_vec,0));
    vec.y = Double_val(Field(ml_vec,1));
    return vec;
}

sfVector3f
SfVector3f_val(value ml_vec)
{
    sfVector3f vec;
    vec.x = Double_val(Field(ml_vec,0));
    vec.y = Double_val(Field(ml_vec,1));
    vec.z = Double_val(Field(ml_vec,2));
    return vec;
}

sfVector3f
SfVector3f_val3(value x, value y, value z)
{
    sfVector3f vec;
    vec.x = Double_val(x);
    vec.y = Double_val(y);
    vec.z = Double_val(z);
    return vec;
}

/* vim: sw=4 sts=4 ts=4 et
 */
