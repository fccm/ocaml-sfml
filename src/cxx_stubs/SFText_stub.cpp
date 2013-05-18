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

#include <SFML/Graphics/Text.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFText_stub.hpp"
#include "SFColor_stub.hpp"
#include "SFRect_stub.hpp"
#include "SFFont_stub.hpp"


/* sf::Text */

CAMLextern_C value
caml_sfText_create(value unit)
{
    sf::Text *text = new sf::Text;
    return Val_sfText(text);
}

CAMLextern_C value
caml_sfText_destroy(value text)
{
    delete SfText_val(text);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# text deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setString(value text, value str)
{
    SfText_val(text)->setString(String_val(str));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setFont(value text, value font)
{
    SfText_val(text)->setFont(*SfFont_val_u(font));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setCharacterSize(value text, value size)
{
    SfText_val(text)->setCharacterSize(Long_val(size));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setOrigin(value text, value origin)
{
    SfText_val(text)->setOrigin(SfVector2f_val(origin));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setPosition(value text, value position)
{
    SfText_val(text)->setPosition(SfVector2f_val(position));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setPosition2(value text, value left, value top)
{
    SfText_val(text)->setPosition(SfVector2f_val2(left, top));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setColor(value text, value color)
{
    SfText_val(text)->setColor(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setRotation(value text, value rotation)
{
    SfText_val(text)->setRotation(Double_val(rotation));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setScale(value text, value scale)
{
    SfText_val(text)->setScale(SfVector2f_val(scale));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_setScale2(value text, value scaleX, value scaleY)
{
    SfText_val(text)->setScale(SfVector2f_val2(scaleX, scaleY));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_move(value text, value offset)
{
    SfText_val(text)->move(SfVector2f_val(offset));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_move2(value text, value offsetX, value offsetY)
{
    SfText_val(text)->move(SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_rotate(value text, value angle)
{
    SfText_val(text)->rotate(Double_val(angle));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_scale(value text, value factors)
{
    SfText_val(text)->scale(SfVector2f_val(factors));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_scale2(value text, value factorX, value factorY)
{
    SfText_val(text)->scale(SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLextern_C value
caml_sfText_getLocalBounds(value text)
{
    sf::FloatRect rect = SfText_val(text)->getLocalBounds();
    return caml_copy_sfFloatRect(rect);
}

CAMLextern_C value
caml_sfText_getGlobalBounds(value text)
{
    sf::FloatRect rect = SfText_val(text)->getGlobalBounds();
    return caml_copy_sfFloatRect(rect);
}

/* TODO
typedef enum
{   sfTextRegular,
    sfTextBold,
    sfTextItalic,
    sfTextUnderlined
} sfTextStyle;

sfText* sfText_copy(sfText* text);
sfVector2f sfText_getPosition(const sfText* text);
float sfText_getRotation(const sfText* text);
sfVector2f sfText_getScale(const sfText* text);
sfVector2f sfText_getOrigin(const sfText* text);
sfTransform sfText_getTransform(const sfText* text);
sfTransform sfText_getInverseTransform(const sfText* text);
void sfText_setUnicodeString(sfText* text, const sfUint32* string);
void sfText_setStyle(sfText* text, sfUint32 style);
const char* sfText_getString(const sfText* text);
const sfUint32* sfText_getUnicodeString(const sfText* text);
const sfFont* sfText_getFont(const sfText* text);
unsigned int sfText_getCharacterSize(const sfText* text);
sfUint32 sfText_getStyle(const sfText* text);
sfColor sfText_getColor(const sfText* text);
sfVector2f sfText_findCharacterPos(const sfText* text, size_t index);
*/

// vim: sw=4 sts=4 ts=4 et
