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

#include <SFML/Graphics/Texture.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "sf_conv_vectors_c.h"
#include "SFTexture_cstub.h"
#include "SFRect_cstub.h"
#include "SFImage_cstub.h"


/* sfTexture */

CAMLprim value
caml_sfTexture_create(value width, value height)
{
    sfTexture *tex = sfTexture_create(Long_val(width), Long_val(height));
    if (tex == NULL) caml_failwith("SFTexture.create");
    return Val_sfTexture(tex);
}

CAMLprim value
caml_sfTexture_destroy(value texture)
{
    sfTexture_destroy(SfTexture_val(texture));
    return Val_unit;
}

CAMLprim value
caml_sfTexture_createFromFile(value filename, value ml_area, value unit)
{
    sfIntRect area;
    sfIntRect *area_ptr;
    if (ml_area != Val_none) {
        SfIntRect_val(&area, Some_val(ml_area));
        area_ptr = &area;
    } else {
        area_ptr = NULL;
    }
    sfTexture *tex = sfTexture_createFromFile(String_val(filename), area_ptr);
    if (tex == NULL) caml_failwith("SFTexture.createFromFile");
    return Val_sfTexture(tex);
}

CAMLprim value
caml_sfTexture_createFromMemory(value data, value ml_area, value unit)
{
    sfIntRect area;
    sfIntRect *area_ptr;
    if (ml_area != Val_none) {
        SfIntRect_val(&area, Some_val(ml_area));
        area_ptr = &area;
    } else {
        area_ptr = NULL;
    }
    sfTexture *tex = sfTexture_createFromMemory(
            String_val(data), caml_string_length(data), area_ptr);
    if (tex == NULL) caml_failwith("SFTexture.createFromMemory");
    return Val_sfTexture(tex);
}

/* TODO?
sfTexture* sfTexture_createFromStream(
        sfInputStream* stream, const sfIntRect* area);
*/

CAMLprim value
caml_sfTexture_createFromImage(value image, value ml_area, value unit)
{
    sfIntRect area;
    sfIntRect *area_ptr;
    if (ml_area != Val_none) {
        SfIntRect_val(&area, Some_val(ml_area));
        area_ptr = &area;
    } else {
        area_ptr = NULL;
    }
    sfTexture *tex = sfTexture_createFromImage(SfImage_val_u(image), area_ptr);
    if (tex == NULL) caml_failwith("SFTexture.createFromImage");
    return Val_sfTexture(tex);
}

CAMLprim value
caml_sfTexture_copy(value texture)
{
    sfTexture *tex = sfTexture_copy(SfTexture_val(texture));
    if (tex == NULL) caml_failwith("SFTexture.copy");
    return Val_sfTexture(tex);
}

CAMLprim value
caml_sfTexture_getSize(value texture)
{
    sfVector2u size = sfTexture_getSize(SfTexture_val(texture));
    return Val_sfVector2u(&size);
}

CAMLprim value
caml_sfTexture_copyToImage(value texture)
{
    sfImage *img = sfTexture_copyToImage(SfTexture_val(texture));
    if (!img) caml_failwith("SFTexture.copyToImage");
    return caml_copy_sfImage(img);  // XXX TODO: test and debug me!
}

/* TODO
void sfTexture_updateFromPixels(sfTexture* texture, const sfUint8* pixels,
        unsigned int width, unsigned int height, unsigned int x, unsigned int y);

void sfTexture_updateFromImage(sfTexture* texture, const sfImage* image,
        unsigned int x, unsigned int y);

void sfTexture_updateFromWindow(sfTexture* texture, const sfWindow* window,
        unsigned int x, unsigned int y);

void sfTexture_updateFromRenderWindow(sfTexture* texture,
        const sfRenderWindow* renderWindow, unsigned int x, unsigned int y);
*/

CAMLprim value
caml_sfTexture_bind(value texture)
{
    sfTexture_bind(SfTexture_val(texture));
    return Val_unit;
}

CAMLprim value
caml_sfTexture_setSmooth(value texture, value smooth)
{
    sfTexture_setSmooth(SfTexture_val(texture), Bool_val(smooth));
    return Val_unit;
}

CAMLprim value
caml_sfTexture_isSmooth(value texture)
{
    return Val_bool(sfTexture_isSmooth(SfTexture_val(texture)));
}

CAMLprim value
caml_sfTexture_setRepeated(value texture, value repeated)
{
    sfTexture_setRepeated(SfTexture_val(texture), Bool_val(repeated));
    return Val_unit;
}

CAMLprim value
caml_sfTexture_isRepeated(value texture)
{
    return Val_bool(sfTexture_isRepeated(SfTexture_val(texture)));
}

CAMLprim value
caml_sfTexture_getMaximumSize(value unit)
{
    unsigned int size = sfTexture_getMaximumSize();
    return Val_long(size);
}

/* vim: sw=4 sts=4 ts=4 et
 */
