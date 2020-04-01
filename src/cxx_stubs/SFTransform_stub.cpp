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

#include <SFML/Graphics/Transform.hpp>

#include "sf_caml_incs.hpp"
#include "SFTransform_stub.hpp"

#include <cstring>

#if defined(_OCAML_SFML_DEBUG)
#include <cstdio>
#endif

void finalize_sfTransform_oo(value v)
{
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "### finalising SFTransform.t"
              << std::endl << std::flush;  // XXX: DEBUG
#endif
}

/* sf::Transform */

char id_sf_trans[] = "sf::Transform class";
static struct custom_operations sfTransform_custom_ops = {
    .identifier =  id_sf_trans,
    /*
    finalize:    custom_finalize_default,
    */
    .finalize =    finalize_sfTransform_oo,

    .compare =     custom_compare_default,
    .hash =        custom_hash_default,
    .serialize =   custom_serialize_default,
    .deserialize = custom_deserialize_default
};

value Val_sfTransform(sf::Transform *trans)
{
    CAMLparam0();
    CAMLlocal1(ml_trans);

    std::size_t size_of_transfrom;
    //size_of_transfrom = sizeof(sf::Transform);
    size_of_transfrom = 16 * sizeof(float);

    ml_trans = caml_alloc_custom(
            &sfTransform_custom_ops, size_of_transfrom, 0, 1);

    std::memcpy(Data_custom_val(ml_trans), trans, size_of_transfrom);

#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# alloc sf::Transform, sizeof:"
              << sizeof(sf::Transform)
              << ", "
              << size_of_transfrom
              << std::endl << std::flush;  // XXX: DEBUG
#endif

    CAMLreturn(ml_trans);
}


/* sf::Transform */

CAMLextern_C value
caml_sfTransform_Identity(value unit)
{
    sf::Transform identity = sf::Transform();
    return Val_sfTransform(&identity);
}

CAMLextern_C value
caml_sfTransform_fromMatrix(value matrix)
{
    int length = Wosize_val(matrix) / Double_wosize;
    if (length != 9)
        caml_invalid_argument("SFTransform.fromMatrix");

    sf::Transform trans = sf::Transform(
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

CAMLextern_C value
caml_sfTransform_getMatrix(value transform)
{
    CAMLparam1(transform);
    CAMLlocal1(m);
    unsigned int i;
    const float *matrix;
    matrix = SfTransform_val(transform)->getMatrix();
    m = caml_alloc(16 * Double_wosize, Double_array_tag);
    for (i = 0; i < 16; i++)
        Store_double_field(m, i, matrix[i]);
    CAMLreturn(m);
}

CAMLextern_C value
caml_sfTransform_getInverse(value transform)
{
    sf::Transform inv = SfTransform_val(transform)->getInverse();
    return Val_sfTransform(&inv);
}

/* TODO:
sfVector2f sfTransform_transformPoint(
        const sfTransform* transform, sfVector2f point);

sfFloatRect sfTransform_transformRect(
        const sfTransform* transform, sfFloatRect rectangle);
*/

CAMLextern_C value
caml_sfTransform_combine(value transform, value other)
{
    SfTransform_val(transform)->combine(*SfTransform_val(other));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_translate(value transform, value x, value y)
{
    SfTransform_val(transform)->translate(Double_val(x), Double_val(y));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_translate2(value transform, value vec)
{
    SfTransform_val(transform)->translate(
            Double_val(Field(vec,0)),
            Double_val(Field(vec,1)));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_rotate(value transform, value angle)
{
    SfTransform_val(transform)->rotate(Double_val(angle));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_rotateWithCenter(
        value transform, value angle, value centerX, value centerY)
{
    SfTransform_val(transform)->rotate(
            Double_val(angle), Double_val(centerX), Double_val(centerY));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_rotateWithCenter2(value transform, value angle, value center)
{
    SfTransform_val(transform)->rotate(
            Double_val(angle),
            Double_val(Field(center,0)),
            Double_val(Field(center,1)));
    return Val_unit;
}

CAMLextern_C value
caml_sfTransform_scale(value transform, value scaleX, value scaleY)
{
    SfTransform_val(transform)->scale(Double_val(scaleX), Double_val(scaleY));
    return Val_unit;
}

/* TODO:
void sfTransform_scaleWithCenter(sfTransform* transform,
        float scaleX, float scaleY, float centerX, float centerY);
*/

// vim: sw=4 sts=4 ts=4 et
