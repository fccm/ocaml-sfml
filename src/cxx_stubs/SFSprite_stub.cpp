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

#include <SFML/Graphics/Sprite.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFSprite_stub.hpp"
#include "SFTexture_stub.hpp"
#include "SFColor_stub.hpp"

/* sf::Sprite */

CAMLextern_C value
caml_sfSprite_create(value unit)
{
    sf::Sprite *sprite = new sf::Sprite;
    return Val_sfSprite(sprite);
}

CAMLextern_C value
caml_sfSprite_destroy(value sprite)
{
    delete SfSprite_val(sprite);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# sprite deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_copy(value sprite)
{
    sf::Sprite *copy = new sf::Sprite;
    *copy = *SfSprite_val(sprite);
    return Val_sfSprite(copy);
}

CAMLextern_C value
caml_sfSprite_move(value sprite, value offset)
{
    SfSprite_val(sprite)->move(SfVector2f_val(offset));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_move2(value sprite, value offsetX, value offsetY)
{
    SfSprite_val(sprite)->move(SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_scale(value sprite, value factors)
{
    SfSprite_val(sprite)->scale(SfVector2f_val(factors));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_scale2(value sprite, value factorX, value factorY)
{
    SfSprite_val(sprite)->scale(SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_rotate(value sprite, value angle)
{
    SfSprite_val(sprite)->rotate(Double_val(angle));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setPosition(value sprite, value pos)
{
    SfSprite_val(sprite)->setPosition(SfVector2f_val(pos));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setPosition2(value sprite, value x, value y)
{
    SfSprite_val(sprite)->setPosition(SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setScale(value sprite, value scale)
{
    SfSprite_val(sprite)->setScale(SfVector2f_val(scale));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setScale2(value sprite, value scaleX, value scaleY)
{
    SfSprite_val(sprite)->setScale(SfVector2f_val2(scaleX, scaleY));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setRotation(value sprite, value rotation)
{
    SfSprite_val(sprite)->setRotation(Double_val(rotation));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setOrigin(value sprite, value origin)
{
    SfSprite_val(sprite)->setOrigin(SfVector2f_val(origin));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_setColor(value sprite, value color)
{
    SfSprite_val(sprite)->setColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfSprite_getScaleX(value sprite)
{
    sf::Vector2f scale = SfSprite_val(sprite)->getScale();
    return caml_copy_double(scale.x);
}

CAMLextern_C value
caml_sfSprite_getScaleY(value sprite)
{
    sf::Vector2f scale = SfSprite_val(sprite)->getScale();
    return caml_copy_double(scale.y);
}

CAMLextern_C value
caml_sfSprite_getScale(value sprite)
{
    sf::Vector2f scale = SfSprite_val(sprite)->getScale();
    return Val_sfVector2f(scale);
}

CAMLextern_C value
caml_sfSprite_getRotation(value sprite)
{
    return caml_copy_double(
            SfSprite_val(sprite)->getRotation());
}

CAMLextern_C value
caml_sfSprite_setTexture(value sprite, value texture, value resetRect)
{
    SfSprite_val(sprite)->setTexture(*SfTexture_val(texture), Bool_val(resetRect));
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

// vim: sw=4 sts=4 ts=4 et
