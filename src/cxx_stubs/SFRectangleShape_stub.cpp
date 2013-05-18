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

#include <SFML/Graphics/RectangleShape.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "sf_conv_vectors.hpp"

#define Val_sfRectangleShape(rect) ((value)(rect))
#define SfRectangleShape_val(rect) ((sf::RectangleShape *)(rect))

CAMLextern_C value
caml_sfRectangleShape_create(value size, value unit)
{
    sf::RectangleShape *rs;
    if (size != Val_none)
        rs = new sf::RectangleShape(SfVector2f_val(Some_val(size)));
    else
        rs = new sf::RectangleShape();
    return Val_sfRectangleShape(rs);
}

CAMLextern_C value
caml_sfRectangleShape_destroy(value rectangle)
{
    delete SfRectangleShape_val(rectangle);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# rectangle deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

/* TODO
    void setSize(const Vector2f& size);
    const Vector2f& getSize() const;
    virtual unsigned int getPointCount() const;
    virtual Vector2f getPoint(unsigned int index) const;
*/

// vim: sw=4 sts=4 ts=4 et
