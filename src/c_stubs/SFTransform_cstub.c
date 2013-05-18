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

#include <SFML/Graphics/Transform.h>

#include "sf_caml_incs_c.h"
#include "SFTransform_cstub.h"

#include <string.h>

#include <stdio.h>
void finalize_sfTransform(value v)
{
    fprintf(stdout, "## finalising SFTransform.t\n");  /* DEBUG */
    fflush(stdout);
}

/* sfTransform */

static struct custom_operations sfTransform_custom_ops = {
    identifier:  "sfTransform struct",
    /*
    finalize:    custom_finalize_default,
    */
    finalize:    finalize_sfTransform,

    compare:     custom_compare_default,
    hash:        custom_hash_default,
    serialize:   custom_serialize_default,
    deserialize: custom_deserialize_default
};

value Val_sfTransform(const sfTransform *trans)
{
    CAMLparam0();
    CAMLlocal1(ml_trans);

    ml_trans = caml_alloc_custom(
            &sfTransform_custom_ops, sizeof(sfTransform), 0, 1);

    memcpy(Data_custom_val(ml_trans), trans, sizeof(sfTransform));

    CAMLreturn(ml_trans);
}

CAMLprim value
caml_sfTransform_Identity(value unit)
{
    return Val_sfTransform(&sfTransform_Identity);
}

CAMLprim value
caml_sfTransform_fromMatrix(value matrix)
{
    int length = Wosize_val(matrix) / Double_wosize;
    if (length != 9)
        caml_invalid_argument("SFTransform.fromMatrix");

    sfTransform trans = sfTransform_fromMatrix(
        Double_field(matrix, 0),
        Double_field(matrix, 1),
        Double_field(matrix, 2),
        Double_field(matrix, 3),
        Double_field(matrix, 4),
        Double_field(matrix, 5),
        Double_field(matrix, 6),
        Double_field(matrix, 7),
        Double_field(matrix, 8));

    return Val_sfTransform(&trans);
}

CAMLprim value
caml_sfTransform_getMatrix(value transform)
{
    CAMLparam1(transform);
    CAMLlocal1(m);
    unsigned int i;
    float matrix[16];
    sfTransform_getMatrix(SfTransform_val(transform), matrix);
    m = caml_alloc(16 * Double_wosize, Double_array_tag);
    for (i = 0; i < 16; i++)
        Store_double_field(m, i, matrix[i]);
    CAMLreturn(m);
}

CAMLprim value
caml_sfTransform_getInverse(value transform)
{
    sfTransform inv = sfTransform_getInverse(SfTransform_val(transform));
    return Val_sfTransform(&inv);
}

/* TODO:
sfVector2f sfTransform_transformPoint(
        const sfTransform* transform, sfVector2f point);

sfFloatRect sfTransform_transformRect(
        const sfTransform* transform, sfFloatRect rectangle);
*/

CAMLprim value
caml_sfTransform_combine(value transform, value other)
{
    sfTransform_combine(SfTransform_val(transform), SfTransform_val(other));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_translate(value transform, value x, value y)
{
    sfTransform_translate(
            SfTransform_val(transform), Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_translate2(value transform, value vec)
{
    sfTransform_translate(SfTransform_val(transform),
            Double_val(Field(vec,0)),
            Double_val(Field(vec,1)));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_rotate(value transform, value angle)
{
    sfTransform_rotate(SfTransform_val(transform), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_rotateWithCenter(
        value transform, value angle, value centerX, value centerY)
{
    sfTransform_rotateWithCenter(
            SfTransform_val(transform),
            Double_val(angle), Double_val(centerX), Double_val(centerY));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_rotateWithCenter2(value transform, value angle, value center)
{
    sfTransform_rotateWithCenter(
            SfTransform_val(transform), Double_val(angle),
            Double_val(Field(center,0)),
            Double_val(Field(center,1)));
    return Val_unit;
}

CAMLprim value
caml_sfTransform_scale(value transform, value scaleX, value scaleY)
{
    sfTransform_scale(
            SfTransform_val(transform), Double_val(scaleX), Double_val(scaleY));
    return Val_unit;
}

/* TODO:
void sfTransform_scaleWithCenter(sfTransform* transform, float scaleX,
        float scaleY, float centerX, float centerY);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
