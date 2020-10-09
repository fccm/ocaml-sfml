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

#include <SFML/Graphics/Shape.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFShape_stub.hpp"
#include "SFColor_stub.hpp"


value Val_sfShape(sf::Shape * p)
{
    return caml_copy_nativeint((intnat) p);
}

sf::Shape * SfShape_val(value v)
{
    return (sf::Shape *) Nativeint_val(v);
}


class sfShapeImpl : public sf::Shape
{
public:
    sfShapeImpl(value userPoints) :
    points (userPoints)
    {
    }

    virtual std::size_t getPointCount() const
    {
        unsigned int len = Wosize_val(points);
        return (len);
    }

    virtual sf::Vector2f getPoint(std::size_t index) const
    {
        value point = Field(points, index);
        return sf::Vector2f(
                Double_val(Field(point,0)),
                Double_val(Field(point,1)));
    }

    using sf::Shape::update;

private:
    value points;
};


/* sf::Shape */

CAMLextern_C value
caml_sfShape_create(value points)
{
    sf::Shape *shape = new sfShapeImpl(points);
    return Val_sfShape(shape);
}

CAMLextern_C value
caml_sfShape_destroy(value shape)
{
    delete SfShape_val(shape);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# shape deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_move(value shape, value offsetX, value offsetY)
{
    SfShape_val(shape)->move(SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_move2(value shape, value offset)
{
    SfShape_val(shape)->move(SfVector2f_val(offset));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_rotate(value shape, value angle)
{
    SfShape_val(shape)->rotate(Double_val(angle));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_scale(value shape, value factorX, value factorY)
{
    SfShape_val(shape)->scale(SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_scale2(value shape, value factors)
{
    SfShape_val(shape)->scale(SfVector2f_val(factors));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setPosition(value shape, value x, value y)
{
    SfShape_val(shape)->setPosition(SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setPosition2(value shape, value pos)
{
    SfShape_val(shape)->setPosition(SfVector2f_val(pos));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setRotation(value shape, value angle)
{
    SfShape_val(shape)->setRotation(Double_val(angle));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setScale(value shape, value x, value y)
{
    SfShape_val(shape)->setScale(SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setScale2(value shape, value scale)
{
    SfShape_val(shape)->setScale(SfVector2f_val(scale));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setOrigin(value shape, value originX, value originY)
{
    SfShape_val(shape)->setOrigin(SfVector2f_val2(originX, originY));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setOrigin2(value shape, value origin)
{
    SfShape_val(shape)->setOrigin(SfVector2f_val(origin));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setFillColor(value shape, value color)
{
    SfShape_val(shape)->setFillColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setOutlineColor(value shape, value color)
{
    SfShape_val(shape)->setOutlineColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_setOutlineThickness(value shape, value thickness)
{
    SfShape_val(shape)->setOutlineThickness(Double_val(thickness));
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_update(value shape)
{
    ((sfShapeImpl *)(shape))->update();
    return Val_unit;
}

CAMLextern_C value
caml_sfShape_getPointCount(value shape)
{
    unsigned int count = SfShape_val(shape)->getPointCount();
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

// vim: sw=4 sts=4 ts=4 et
