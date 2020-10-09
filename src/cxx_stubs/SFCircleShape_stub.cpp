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

#include <SFML/Graphics/CircleShape.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "sf_conv_vectors.hpp"
#include "SFCircleShape_stub.hpp"
#include "SFColor_stub.hpp"

value Val_sfCircleShape(sf::CircleShape * cs)
{
    return caml_copy_nativeint((intnat) cs);
}

sf::CircleShape * SfCircleShape_val(value cs)
{
    return (sf::CircleShape *) Nativeint_val(cs);
}

CAMLextern_C value
caml_sfCircleShape_create(value radius, value pointCount, value unit)
{
    unsigned int pr = 0;
    sf::CircleShape *cs;

    if (radius     != Val_none) pr |= 0b0001;
    if (pointCount != Val_none) pr |= 0b0010;

    switch (pr) {
        case 0b0000:
            cs = new sf::CircleShape();
            break;
        case 0b0001:
            cs = new sf::CircleShape(
                    Double_val(Some_val(radius)));
            break;
        case 0b0011:
            cs = new sf::CircleShape(
                    Double_val(Some_val(radius)),
                    Long_val(Some_val(pointCount)));
            break;
        case 0b0010:
            cs = new sf::CircleShape(0.f,
                    Long_val(Some_val(pointCount)));
            break;
        default:
            caml_failwith("SFCircleShape.create");
    }

    return Val_sfCircleShape(cs);
}

CAMLextern_C value
caml_sfCircleShape_destroy(value circle)
{
    delete SfCircleShape_val(circle);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# circle deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_setPointCount(value circle, value count)
{
    SfCircleShape_val(circle)->setPointCount(Long_val(count));
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_getPointCount(value circle)
{
    unsigned int count = SfCircleShape_val(circle)->getPointCount();
    return Val_long(count);
}

CAMLextern_C value
caml_sfCircleShape_setPosition(value shape, value position)
{
    SfCircleShape_val(shape)->setPosition(SfVector2f_val(position));
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_setFillColor(value shape, value color)
{
    SfCircleShape_val(shape)->setFillColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_setRadius(value shape, value radius)
{
    SfCircleShape_val(shape)->setRadius(Double_val(radius));
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_getRadius(value shape)
{
    float r = SfCircleShape_val(shape)->getRadius();
    return caml_copy_double(r);
}

CAMLextern_C value
caml_sfCircleShape_setOutlineColor(value shape, value color)
{
    SfCircleShape_val(shape)->setOutlineColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfCircleShape_setOutlineThickness(value shape, value thickness)
{
    SfCircleShape_val(shape)->setOutlineThickness(Float_val(thickness));
    return Val_unit;
}

/* TODO
  virtual Vector2f getPoint(unsigned int index) const;
*/

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
unsigned int sfCircleShape_getPointCount(const sfCircleShape* shape);
sfVector2f sfCircleShape_getPoint(const sfCircleShape* shape, unsigned int index);
void sfCircleShape_setPointCount(sfCircleShape* shape, unsigned int count);
sfFloatRect sfCircleShape_getLocalBounds(const sfCircleShape* shape);
sfFloatRect sfCircleShape_getGlobalBounds(const sfCircleShape* shape);
*/

// vim: sw=4 sts=4 ts=4 et
