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

#include <SFML/Graphics/Image.h>

#include <string.h>

#include "sf_caml_incs_c.h"
#include "SFImage_cstub.h"
#include "SFColor_cstub.h"

CAMLprim value caml_sfImage_destroy(value img);

void finalize_captured(value v)
{
    fprintf(stdout, "capture finalize...\n");  // XXX: DEBUG
    fprintf(stdout, "%s\n", String_val(Field(Data_custom_val(v),1)));//XXX:DEBUG
    caml_sfImage_destroy(Field(Data_custom_val(v),0));
    fprintf(stdout, "capture finalize done!\n");  // XXX: DEBUG
    fflush(stdout);
}

value
caml_copy_sfImage(sfImage *img)
{
    CAMLparam0();
    CAMLlocal1(ret);
    //ret = caml_alloc_custom(&capture_custom_ops, 2, 0, 1);
    ret = caml_alloc_final(2, &finalize_captured, 0, 1);
    Store_field(ret, 0, Val_sfImage(img));
    Store_field(ret, 1, caml_copy_string("captured image"));
    CAMLreturn(ret);
}


/* sfImage */

CAMLprim value
caml_sfImage_createFromFile(value filename)
{
    sfImage *img;
    img = sfImage_createFromFile(String_val(filename));
    if (!img) caml_failwith("SFImage.createFromFile");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_createFromColor(value width, value height, value ml_color)
{
    sfImage *img;
    sfColor color;
    SfColor_val(&color, ml_color);
    img = sfImage_createFromColor(Long_val(width), Long_val(height), color);
    if (!img) caml_failwith("SFImage.createFromColor");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_createFromMemory(value data)
{
    sfImage *img;
    img = sfImage_createFromMemory(String_val(data), caml_string_length(data));
    if (!img) caml_failwith("SFImage.createFromMemory");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_createFromPixels(value width, value height, value data)
{
    sfImage *img;
    unsigned int Width = Int_val(width);
    unsigned int Height = Int_val(height);
    if (caml_string_length(data) != (Width * Height * 4))
        caml_invalid_argument("SFImage.createFromPixels");
    img = sfImage_createFromPixels(Width, Height, (sfUint8 *) String_val(data));
    if (!img) caml_failwith("SFImage.createFromPixels");
    return Val_sfImage(img);
}

CAMLprim value
caml_sfImage_destroy(value img)
{
    sfImage_destroy(SfImage_val(img));
#if defined(_OCAML_CSFML_DEBUG)
    fprintf(stdout, "sfImage_destroy() called\n");  // XXX: DEBUG
    fflush(stdout);
#endif
    return Val_unit;
}

CAMLprim value
caml_sfImage_getWidth(value image)
{
    sfVector2u size = sfImage_getSize(SfImage_val(image));
    return Val_long(size.x);
}

CAMLprim value
caml_sfImage_getHeight(value image)
{
    sfVector2u size = sfImage_getSize(SfImage_val(image));
    return Val_long(size.y);
}

CAMLprim value
caml_sfImage_getSize(value image)
{
    CAMLparam1(image);
    CAMLlocal1(dims);
    dims = caml_alloc(2, 0);
    sfVector2u size = sfImage_getSize(SfImage_val(image));
    Store_field(dims, 0, Val_long(size.x));
    Store_field(dims, 1, Val_long(size.y));
    CAMLreturn(dims);
}

CAMLprim value
caml_sfImage_getPixelsBA(value sf_image)
{
    CAMLparam1(sf_image);
    CAMLlocal1(img_ba);
    size_t img_data_size;
    sfVector2u size = sfImage_getSize(SfImage_val(sf_image));
    unsigned int width = size.x;
    unsigned int height = size.y;
    const sfUint8 *img_data = sfImage_getPixelsPtr(SfImage_val(sf_image));
    if (img_data == NULL) caml_failwith("SFImage.getPixelsBA");
    long dims[3];
    dims[0] = width;
    dims[1] = height;
    dims[2] = 4;
    img_ba = caml_ba_alloc(CAML_BA_UINT8 | CAML_BA_C_LAYOUT, 3, NULL, dims);
    img_data_size = width * height * 4 * sizeof(char);
    memcpy(Caml_ba_data_val(img_ba), img_data, img_data_size);
    CAMLreturn(img_ba);
}

CAMLprim value
caml_sfImage_getPixelsStr(value sf_image)
{
    CAMLparam1(sf_image);
    CAMLlocal1(img_str);
    sfVector2u size = sfImage_getSize(SfImage_val(sf_image));
    unsigned int width = size.x;
    unsigned int height = size.y;
    unsigned int len = width * height * 4;
    const sfUint8 *img_data = sfImage_getPixelsPtr(SfImage_val(sf_image));
    if (img_data == NULL) caml_failwith("SFImage.getPixelsStr");
    img_str = caml_alloc_string(len);
    memcpy(String_val(img_str), img_data, len);
    CAMLreturn(img_str);
}

CAMLprim value
caml_sfImage_saveToFile(value image, value filename)
{
    sfBool saved = sfImage_saveToFile(SfImage_val(image), String_val(filename));
    if (!saved) caml_failwith("SFImage.saveToFile");
    return Val_unit;
}

CAMLprim value
caml_sfImage_setPixel(value image, value x, value y, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfImage_setPixel(SfImage_val(image), Long_val(x), Long_val(y), color);
    return Val_unit;
}

CAMLprim value
caml_sfImage_getPixel4(value image, value x, value y)
{
    sfColor color =
        sfImage_getPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_sfColor4(&color);
}

CAMLprim value
caml_sfImage_getPixel3(value image, value x, value y)
{
    sfColor color =
        sfImage_getPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_sfColor3(&color);
}

CAMLprim value
caml_sfImage_getPixelRGB(value image, value x, value y)
{
    sfColor color =
        sfImage_getPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_RGB(&color);
}

CAMLprim value
caml_sfImage_getPixelRGBA(value image, value x, value y)
{
    sfColor color =
        sfImage_getPixel(SfImage_val(image), Int_val(x), Int_val(y));
    return Val_RGBA(&color);
}

sfUint8
SfUint8_val(value _d)
{
    int d = Long_val(_d);
    if (d < 0 || d > 255)
        caml_invalid_argument("sfUint8");
    return (sfUint8) d;
}

CAMLprim value
caml_sfImage_createMaskFromColor(value image, value ml_color, value alpha)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfImage_createMaskFromColor(SfImage_val(image), color, SfUint8_val(alpha));
    return Val_unit;
}

CAMLprim value
caml_sfImage_flipHorizontally(value image)
{
    sfImage_flipHorizontally(SfImage_val(image));
    return Val_unit;
}

CAMLprim value
caml_sfImage_flipVertically(value image)
{
    sfImage_flipVertically(SfImage_val(image));
    return Val_unit;
}

/* TODO
sfImage* sfImage_create(unsigned int width, unsigned int height);
sfImage* sfImage_createFromStream(sfInputStream* stream);
sfImage* sfImage_copy(sfImage* image);
void sfImage_copyImage(sfImage* image, const sfImage* source,
        unsigned int destX, unsigned int destY, sfIntRect sourceRect,
        sfBool applyAlpha);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
