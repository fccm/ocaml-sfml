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

#include <SFML/Graphics/Sprite.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFSprite_cstub.h"
#include "SFColor_cstub.h"
#include "SFTexture_cstub.h"


/* sfSprite */

CAMLprim value
caml_sfSprite_create(value unit)
{
    sfSprite *sprite = sfSprite_create();
    if (!sprite) caml_failwith("SFSprite.create");
    return Val_sfSprite(sprite);
}

CAMLprim value
caml_sfSprite_destroy(value sprite)
{
    sfSprite_destroy(SfSprite_val(sprite));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_copy(value sprite)
{
    sfSprite *copy = sfSprite_copy(SfSprite_val(sprite));
    return Val_sfSprite(copy);
}

CAMLprim value
caml_sfSprite_move(value sprite, value offset)
{
    sfSprite_move(SfSprite_val(sprite), SfVector2f_val(offset));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_move2(value sprite, value offsetX, value offsetY)
{
    sfSprite_move(SfSprite_val(sprite), SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_scale(value sprite, value factors)
{
    sfSprite_scale(SfSprite_val(sprite), SfVector2f_val(factors));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_scale2(value sprite, value factorX, value factorY)
{
    sfSprite_scale(SfSprite_val(sprite), SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_rotate(value sprite, value angle)
{
    sfSprite_rotate(SfSprite_val(sprite), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setPosition(value sprite, value pos)
{
    sfSprite_setPosition(SfSprite_val(sprite), SfVector2f_val(pos));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setPosition2(value sprite, value x, value y)
{
    sfSprite_setPosition(SfSprite_val(sprite), SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setScale(value sprite, value scale)
{
    sfSprite_setScale(SfSprite_val(sprite), SfVector2f_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setScale2(value sprite, value scaleX, value scaleY)
{
    sfSprite_setScale(SfSprite_val(sprite), SfVector2f_val2(scaleX, scaleY));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setRotation(value sprite, value rotation)
{
    sfSprite_setRotation(SfSprite_val(sprite), Double_val(rotation));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setOrigin(value sprite, value origin)
{
    sfSprite_setOrigin(SfSprite_val(sprite), SfVector2f_val(origin));
    return Val_unit;
}

CAMLprim value
caml_sfSprite_setColor(value sprite, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfSprite_setColor(SfSprite_val(sprite), color);
    return Val_unit;
}

CAMLprim value
caml_sfSprite_getScaleX(value sprite)
{
    sfVector2f scale = sfSprite_getScale(SfSprite_val(sprite));
    return caml_copy_double(scale.x);
}

CAMLprim value
caml_sfSprite_getScaleY(value sprite)
{
    sfVector2f scale = sfSprite_getScale(SfSprite_val(sprite));
    return caml_copy_double(scale.y);
}

CAMLprim value
caml_sfSprite_getScale(value sprite)
{
    CAMLparam1(sprite);
    CAMLlocal1(xy);
    sfVector2f scale = sfSprite_getScale(SfSprite_val(sprite));
    xy = caml_alloc(2, 0);
    Store_field(xy, 0, caml_copy_double(scale.x));
    Store_field(xy, 1, caml_copy_double(scale.y));
    CAMLreturn(xy);
}

CAMLprim value
caml_sfSprite_getRotation(value sprite)
{
    return caml_copy_double(
            sfSprite_getRotation(SfSprite_val(sprite)));
}

CAMLprim value
caml_sfSprite_setTexture(value sprite, value texture, value resetRect)
{
    sfSprite_setTexture(
            SfSprite_val(sprite), SfTexture_val(texture), Bool_val(resetRect));
    return Val_unit;
}

/* TODO
sfVector2f sfSprite_getPosition(const sfSprite* sprite);
sfVector2f sfSprite_getOrigin(const sfSprite* sprite);
sfTransform sfSprite_getTransform(const sfSprite* sprite);
sfTransform sfSprite_getInverseTransform(const sfSprite* sprite);
void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle);
const sfTexture* sfSprite_getTexture(const sfSprite* sprite);
sfIntRect sfSprite_getTextureRect(const sfSprite* sprite);
sfColor sfSprite_getColor(const sfSprite* sprite);
sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite);
sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
