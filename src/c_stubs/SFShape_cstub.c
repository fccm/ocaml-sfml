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

#include <SFML/Graphics/Shape.h>
#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFShape_cstub.h"
#include "SFColor_cstub.h"

/* sfShape */

static unsigned int
caml_sfShapeGetPointCountCallback(void *data)
{
    value points = (value) data;
    unsigned int len = Wosize_val(points);
    return (len);
}

static sfVector2f
caml_sfShapeGetPointCallback(unsigned int i, void *data)
{
    sfVector2f vec;
    value points = (value) data;
    unsigned int len = Wosize_val(points);
    if (i >= len) caml_invalid_argument("SFShape.create: getPointCallback");
    value point = Field(points, i);
    vec.x = Double_val(Field(point,0));
    vec.y = Double_val(Field(point,1));
    return vec;
}

CAMLprim value
caml_sfShape_create(value points)
{
    sfShape *shape =
        sfShape_create(
            &caml_sfShapeGetPointCountCallback,
            &caml_sfShapeGetPointCallback,
            (void *)points);
    if (!shape) caml_failwith("SFShape.create");
    return Val_sfShape(shape);
}

CAMLprim value
caml_sfShape_destroy(value shape)
{
    sfShape_destroy(SfShape_val(shape));
    return Val_unit;
}

CAMLprim value
caml_sfShape_move(value shape, value offsetX, value offsetY)
{
    sfShape_move(SfShape_val(shape), SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfShape_move2(value shape, value offset)
{
    sfShape_move(SfShape_val(shape), SfVector2f_val(offset));
    return Val_unit;
}

CAMLprim value
caml_sfShape_rotate(value shape, value angle)
{
    sfShape_rotate(SfShape_val(shape), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfShape_scale(value shape, value factorX, value factorY)
{
    sfShape_scale(SfShape_val(shape), SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLprim value
caml_sfShape_scale2(value shape, value factors)
{
    sfShape_scale(SfShape_val(shape), SfVector2f_val(factors));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setPosition(value shape, value x, value y)
{
    sfShape_setPosition(SfShape_val(shape), SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setPosition2(value shape, value pos)
{
    sfShape_setPosition(SfShape_val(shape), SfVector2f_val(pos));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setRotation(value shape, value angle)
{
    sfShape_setRotation(SfShape_val(shape), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setScale(value shape, value x, value y)
{
    sfShape_setScale(SfShape_val(shape), SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setScale2(value shape, value scale)
{
    sfShape_setScale(SfShape_val(shape), SfVector2f_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setOrigin(value shape, value originX, value originY)
{
    sfShape_setOrigin(SfShape_val(shape), SfVector2f_val2(originX, originY));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setOrigin2(value shape, value origin)
{
    sfShape_setOrigin(SfShape_val(shape), SfVector2f_val(origin));
    return Val_unit;
}

CAMLprim value
caml_sfShape_setFillColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfShape_setFillColor(SfShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfShape_setOutlineColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfShape_setOutlineColor(SfShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfShape_setOutlineThickness(value shape, value thickness)
{
    sfShape_setOutlineThickness(SfShape_val(shape), Double_val(thickness));
    return Val_unit;
}

CAMLprim value
caml_sfShape_update(value shape)
{
    sfShape_update(SfShape_val(shape));
    return Val_unit;
}

CAMLprim value
caml_sfShape_getPointCount(value shape)
{
    unsigned int count = sfShape_getPointCount(SfShape_val(shape));
    return Val_int(count);
}

/* TODO
sfVector2f sfShape_getPosition(const sfShape* shape);
float sfShape_getRotation(const sfShape* shape);
sfVector2f sfShape_getScale(const sfShape* shape);
sfVector2f sfShape_getOrigin(const sfShape* shape);
sfTransform sfShape_getTransform(const sfShape* shape);
sfTransform sfShape_getInverseTransform(const sfShape* shape);
void sfShape_setTexture(sfShape* shape, const sfTexture* texture, sfBool resetRect);
void sfShape_setTextureRect(sfShape* shape, sfIntRect rect);
const sfTexture* sfShape_getTexture(const sfShape* shape);
sfIntRect sfShape_getTextureRect(const sfShape* shape);
sfColor sfShape_getFillColor(const sfShape* shape);
sfColor sfShape_getOutlineColor(const sfShape* shape);
float sfShape_getOutlineThickness(const sfShape* shape);
sfVector2f sfShape_getPoint(const sfShape* shape, unsigned int index);
sfFloatRect sfShape_getLocalBounds(const sfShape* shape);
sfFloatRect sfShape_getGlobalBounds(const sfShape* shape);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
