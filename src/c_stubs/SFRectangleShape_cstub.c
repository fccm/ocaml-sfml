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

#include <SFML/Graphics/RectangleShape.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "sf_conv_vectors_c.h"
#include "SFTransform_cstub.h"
#include "SFColor_cstub.h"

#define Val_sfRectangleShape(rect) ((value)(rect))
#define SfRectangleShape_val(rect) ((sfRectangleShape *)(rect))


/* sfRectangleShape */

CAMLprim value
caml_sfRectangleShape_create(value size, value unit)
{
    sfRectangleShape *rs = sfRectangleShape_create();
    if (size != Val_none) {
        sfRectangleShape_setSize(rs, SfVector2f_val(Some_val(size)));
    }
    return Val_sfRectangleShape(rs);
}

CAMLprim value
caml_sfRectangleShape_copy(value orig)
{
    sfRectangleShape *rect = sfRectangleShape_copy(SfRectangleShape_val(orig));
    return Val_sfRectangleShape(rect);
}

CAMLprim value
caml_sfRectangleShape_destroy(value rectangle)
{
    sfRectangleShape_destroy(SfRectangleShape_val(rectangle));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setPosition(value shape, value position)
{
    sfRectangleShape_setPosition(
            SfRectangleShape_val(shape), SfVector2f_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setRotation(value shape, value angle)
{
    sfRectangleShape_setRotation(
            SfRectangleShape_val(shape), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setScale(value shape, value scale)
{
    sfRectangleShape_setScale(
            SfRectangleShape_val(shape), SfVector2f_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setOrigin(value shape, value origin)
{
    sfRectangleShape_setOrigin(
            SfRectangleShape_val(shape), SfVector2f_val(origin));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_getPosition(value shape)
{
    sfVector2f pos = sfRectangleShape_getPosition(SfRectangleShape_val(shape));
    return Val_sfVector2f(&pos);
}

CAMLprim value
caml_sfRectangleShape_getRotation(value shape)
{
    float rot = sfRectangleShape_getRotation(SfRectangleShape_val(shape));
    return caml_copy_double(rot);
}

CAMLprim value
caml_sfRectangleShape_getScale(value shape)
{
    sfVector2f scale = sfRectangleShape_getScale(SfRectangleShape_val(shape));
    return Val_sfVector2f(&scale);
}

CAMLprim value
caml_sfRectangleShape_getOrigin(value shape)
{
    sfVector2f origin = sfRectangleShape_getOrigin(SfRectangleShape_val(shape));
    return Val_sfVector2f(&origin);
}

CAMLprim value
caml_sfRectangleShape_move(value shape, value offset)
{
    sfRectangleShape_move(SfRectangleShape_val(shape), SfVector2f_val(offset));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_rotate(value shape, value angle)
{
    sfRectangleShape_rotate(SfRectangleShape_val(shape), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_scale(value shape, value factors)
{
    sfRectangleShape_scale(
            SfRectangleShape_val(shape), SfVector2f_val(factors));
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_getTransform(value shape)
{
    sfTransform tr = sfRectangleShape_getTransform(SfRectangleShape_val(shape));
    return Val_sfTransform(&tr);
}

/* TODO
sfTransform sfRectangleShape_getInverseTransform(const sfRectangleShape* shape);

void sfRectangleShape_setTexture(
        sfRectangleShape* shape, const sfTexture* texture, sfBool resetRect);

void sfRectangleShape_setTextureRect(sfRectangleShape* shape, sfIntRect rect);
*/

CAMLprim value
caml_sfRectangleShape_setFillColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfRectangleShape_setFillColor(
            SfRectangleShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setOutlineColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfRectangleShape_setOutlineColor(
            SfRectangleShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfRectangleShape_setOutlineThickness(value shape, value thickness)
{
    sfRectangleShape_setOutlineThickness(
            SfRectangleShape_val(shape), Double_val(thickness));
    return Val_unit;
}

/* TODO
const sfTexture* sfRectangleShape_getTexture(const sfRectangleShape* shape);
sfIntRect sfRectangleShape_getTextureRect(const sfRectangleShape* shape);
sfColor sfRectangleShape_getFillColor(const sfRectangleShape* shape);
sfColor sfRectangleShape_getOutlineColor(const sfRectangleShape* shape);
float sfRectangleShape_getOutlineThickness(const sfRectangleShape* shape);
unsigned int sfRectangleShape_getPointCount(const sfRectangleShape* shape);

sfVector2f sfRectangleShape_getPoint(
        const sfRectangleShape* shape, unsigned int index);

void sfRectangleShape_setSize(sfRectangleShape* shape, sfVector2f size);
sfVector2f sfRectangleShape_getSize(const sfRectangleShape* shape);
sfFloatRect sfRectangleShape_getLocalBounds(const sfRectangleShape* shape);
sfFloatRect sfRectangleShape_getGlobalBounds(const sfRectangleShape* shape);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
