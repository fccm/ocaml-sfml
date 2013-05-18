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

#include <SFML/Graphics/CircleShape.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "sf_conv_vectors_c.h"

#include "SFCircleShape_cstub.h"
#include "SFColor_cstub.h"


/* sfCircleShape */

CAMLprim value
caml_sfCircleShape_create(value radius, value pointCount, value unit)
{
    unsigned int pr = 0;

    if (radius     != Val_none) pr |= 0b0001;
    if (pointCount != Val_none) pr |= 0b0010;

    sfCircleShape *cs = sfCircleShape_create();

    switch (pr) {
        case 0b0000:
            break;
        case 0b0001:
            sfCircleShape_setRadius(cs,
                    Double_val(Some_val(radius)));
            break;
        case 0b0010:
            sfCircleShape_setPointCount(cs,
                    Long_val(Some_val(pointCount)));
            break;
        case 0b0011:
            sfCircleShape_setRadius(cs,
                    Double_val(Some_val(radius)));
            sfCircleShape_setPointCount(cs,
                    Long_val(Some_val(pointCount)));
            break;
        default:
            caml_failwith("SFCircleShape.create");
    }

    return Val_sfCircleShape(cs);
}

CAMLprim value
caml_sfCircleShape_destroy(value circle)
{
    sfCircleShape_destroy(SfCircleShape_val(circle));
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_setPointCount(value circle, value count)
{
    sfCircleShape_setPointCount(
            SfCircleShape_val(circle), Long_val(count));
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_getPointCount(value circle)
{
    unsigned int count = sfCircleShape_getPointCount(SfCircleShape_val(circle));
    return Val_long(count);
}

CAMLprim value
caml_sfCircleShape_setPosition(value shape, value position)
{
    sfCircleShape_setPosition(SfCircleShape_val(shape), SfVector2f_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_setRadius(value shape, value radius)
{
    sfCircleShape_setRadius(SfCircleShape_val(shape), Double_val(radius));
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_getRadius(value shape)
{
    float r = sfCircleShape_getRadius(SfCircleShape_val(shape));
    return caml_copy_double(r);
}

CAMLprim value
caml_sfCircleShape_setFillColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfCircleShape_setFillColor(SfCircleShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_setOutlineColor(value shape, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfCircleShape_setOutlineColor(SfCircleShape_val(shape), color);
    return Val_unit;
}

CAMLprim value
caml_sfCircleShape_setOutlineThickness(value shape, value thickness)
{
    sfCircleShape_setOutlineThickness(
            SfCircleShape_val(shape), Double_val(thickness));
    return Val_unit;
}

/* TODO
sfCircleShape* sfCircleShape_copy(sfCircleShape* shape);
void sfCircleShape_setRotation(sfCircleShape* shape, float angle);
void sfCircleShape_setScale(sfCircleShape* shape, sfVector2f scale);
void sfCircleShape_setOrigin(sfCircleShape* shape, sfVector2f origin);
sfVector2f sfCircleShape_getPosition(const sfCircleShape* shape);
float sfCircleShape_getRotation(const sfCircleShape* shape);
sfVector2f sfCircleShape_getScale(const sfCircleShape* shape);
sfVector2f sfCircleShape_getOrigin(const sfCircleShape* shape);
void sfCircleShape_move(sfCircleShape* shape, sfVector2f offset);
void sfCircleShape_rotate(sfCircleShape* shape, float angle);
void sfCircleShape_scale(sfCircleShape* shape, sfVector2f factors);
sfTransform sfCircleShape_getTransform(const sfCircleShape* shape);
sfTransform sfCircleShape_getInverseTransform(const sfCircleShape* shape);
void sfCircleShape_setTexture(sfCircleShape* shape, const sfTexture* texture, sfBool resetRect);
void sfCircleShape_setTextureRect(sfCircleShape* shape, sfIntRect rect);
const sfTexture* sfCircleShape_getTexture(const sfCircleShape* shape);
sfIntRect sfCircleShape_getTextureRect(const sfCircleShape* shape);
sfColor sfCircleShape_getFillColor(const sfCircleShape* shape);
sfColor sfCircleShape_getOutlineColor(const sfCircleShape* shape);
float sfCircleShape_getOutlineThickness(const sfCircleShape* shape);
sfVector2f sfCircleShape_getPoint(const sfCircleShape* shape, unsigned int index);
sfFloatRect sfCircleShape_getLocalBounds(const sfCircleShape* shape);
sfFloatRect sfCircleShape_getGlobalBounds(const sfCircleShape* shape);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
