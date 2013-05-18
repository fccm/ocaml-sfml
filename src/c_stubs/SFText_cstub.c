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

#include <SFML/Graphics/Text.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFText_cstub.h"
#include "SFRect_cstub.h"
#include "SFColor_cstub.h"
#include "SFFont_cstub.h"


/* sfText */

CAMLprim value
caml_sfText_create(value unit)
{
    sfText* text;
    text = sfText_create();
    if (!text) caml_failwith("SFText.create");
    return Val_sfText(text);
}

CAMLprim value
caml_sfText_destroy(value text)
{
    sfText_destroy(SfText_val(text));
    return Val_unit;
}

CAMLprim value
caml_sfText_setString(value text, value str)
{
    sfText_setString(SfText_val(text), String_val(str));
    return Val_unit;
}

CAMLprim value
caml_sfText_setFont(value text, value font)
{
    sfText_setFont(SfText_val(text), SfFont_val_u(font));
    return Val_unit;
}

CAMLprim value
caml_sfText_setCharacterSize(value text, value size)
{
    sfText_setCharacterSize(SfText_val(text), Long_val(size));
    return Val_unit;
}

CAMLprim value
caml_sfText_setOrigin(value text, value origin)
{
    sfText_setOrigin(SfText_val(text), SfVector2f_val(origin));
    return Val_unit;
}

CAMLprim value
caml_sfText_setPosition(value text, value position)
{
    sfText_setPosition(SfText_val(text), SfVector2f_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfText_setPosition2(value text, value left, value top)
{
    sfText_setPosition(SfText_val(text), SfVector2f_val2(left, top));
    return Val_unit;
}

CAMLprim value
caml_sfText_setColor(value text, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfText_setColor(SfText_val(text), color);
    return Val_unit;
}

CAMLprim value
caml_sfText_setRotation(value text, value rotation)
{
    sfText_setRotation(SfText_val(text), Double_val(rotation));
    return Val_unit;
}

CAMLprim value
caml_sfText_setScale(value text, value scale)
{
    sfText_setScale(SfText_val(text), SfVector2f_val(scale));
    return Val_unit;
}

CAMLprim value
caml_sfText_setScale2(value text, value scaleX, value scaleY)
{
    sfText_setScale(SfText_val(text), SfVector2f_val2(scaleX, scaleY));
    return Val_unit;
}

CAMLprim value
caml_sfText_move(value text, value offset)
{
    sfText_move(SfText_val(text), SfVector2f_val(offset));
    return Val_unit;
}

CAMLprim value
caml_sfText_move2(value text, value offsetX, value offsetY)
{
    sfText_move(SfText_val(text), SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfText_rotate(value text, value angle)
{
    sfText_rotate(SfText_val(text), Double_val(angle));
    return Val_unit;
}

CAMLprim value
caml_sfText_scale(value text, value factors)
{
    sfText_scale(SfText_val(text), SfVector2f_val(factors));
    return Val_unit;
}

CAMLprim value
caml_sfText_scale2(value text, value factorX, value factorY)
{
    sfText_scale(SfText_val(text), SfVector2f_val2(factorX, factorY));
    return Val_unit;
}

CAMLprim value
caml_sfText_getLocalBounds(value text)
{
    if (SfText_val(text) == NULL)
        caml_failwith("SFText.getLocalBounds");
    sfFloatRect rect = sfText_getLocalBounds(SfText_val(text));
    return caml_copy_sfFloatRect(&rect);
}

CAMLprim value
caml_sfText_getGlobalBounds(value text)
{
    if (SfText_val(text) == NULL)
        caml_failwith("SFText.getGlobalBounds");
    sfFloatRect rect = sfText_getGlobalBounds(SfText_val(text));
    return caml_copy_sfFloatRect(&rect);
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

/* vim: sw=4 sts=4 ts=4 et
 */
