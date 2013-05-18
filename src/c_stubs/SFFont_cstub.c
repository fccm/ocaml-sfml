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

#include <SFML/Graphics/Font.h>

#include "sf_caml_incs_c.h"
#include "SFFont_cstub.h"
#include "SFRect_cstub.h"

/* sfFont */

CAMLprim value
caml_sfFont_createFromFile(value filename)
{
    sfFont* font;
    font = sfFont_createFromFile(String_val(filename));
    if (!font) caml_failwith("SFFont.createFromFile");
    return Val_sfFont(font);
}

CAMLprim value
caml_sfFont_createFromMemory(value data)
{
    sfFont* font;
    font = sfFont_createFromMemory(String_val(data), caml_string_length(data));
    if (!font) caml_failwith("SFFont.createFromMemory");
    return Val_sfFont(font);
}

CAMLprim value
caml_sfFont_destroy(value font)
{
    sfFont_destroy(SfFont_val(font));
    return Val_unit;
}

CAMLprim value
caml_sfFont_copy(value font)
{
    sfFont *copy = sfFont_copy(SfFont_val(font));
    return Val_sfFont(copy);
}

CAMLprim value
caml_sfFont_getGlyph(value font, value codePoint, value characterSize, value bold)
{
    CAMLparam4(font, codePoint, characterSize, bold);
    CAMLlocal1(ret);
    sfGlyph glyph = sfFont_getGlyph(
        SfFont_val(font), Int32_val(codePoint), Long_val(characterSize), Bool_val(bold));
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_long(glyph.advance));
    Store_field(ret, 1, caml_copy_sfIntRect(&glyph.bounds));
    Store_field(ret, 2, caml_copy_sfIntRect(&glyph.textureRect));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfFont_getKerning(value font, value first, value second, value characterSize)
{
    int k = sfFont_getKerning(
        SfFont_val(font), Int32_val(first), Int32_val(second), Long_val(characterSize));
    return Val_int(k);
}

CAMLprim value
caml_sfFont_getLineSpacing(value font, value characterSize)
{
    int s = sfFont_getLineSpacing(SfFont_val(font), Long_val(characterSize));
    return Val_int(s);
}

/* TODO
sfFont* sfFont_createFromStream(sfInputStream* stream);
const sfTexture* sfFont_getTexture(sfFont* font, unsigned int characterSize);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
