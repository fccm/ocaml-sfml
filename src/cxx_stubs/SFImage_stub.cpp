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

#include <SFML/Graphics/Image.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFColor_stub.hpp"
#include "SFImage_stub.hpp"

#include <cstring>


/* sf::Image */

CAMLextern_C value
caml_sfImage_createFromFile(value filename)
{
    sf::Image *img = new sf::Image;
    img->loadFromFile(String_val(filename));
    return Val_sfImage(img);
}

CAMLextern_C value
caml_sfImage_createFromColor(value width, value height, value color)
{
    sf::Image *img = new sf::Image;
    img->create(Long_val(width), Long_val(height), SfColor_val(color));
    return Val_sfImage(img);
}

CAMLextern_C value
caml_sfImage_createFromMemory(value data)
{
    sf::Image *img = new sf::Image;
    img->loadFromMemory(String_val(data), caml_string_length(data));
    return Val_sfImage(img);
}

CAMLextern_C value
caml_sfImage_createFromPixels(value width, value height, value pixels)
{
    unsigned int Width = Int_val(width);
    unsigned int Height = Int_val(height);
    if (caml_string_length(pixels) != (Width * Height * 4))
        caml_invalid_argument("SFImage.createFromPixels");
    sf::Image *img = new sf::Image;
    img->create(Width, Height, (sf::Uint8 *) String_val(pixels));
    return Val_sfImage(img);
}

CAMLextern_C value
caml_sfImage_destroy(value img)
{
    delete SfImage_val(img);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# image deleted" << std::endl << std::flush;  // XXX: DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfImage_getWidth(value image)
{
    sf::Vector2u size = SfImage_val(image)->getSize();
    return Val_long(size.x);
}

CAMLextern_C value
caml_sfImage_getHeight(value image)
{
    sf::Vector2u size = SfImage_val(image)->getSize();
    return Val_long(size.y);
}

CAMLextern_C value
caml_sfImage_getSize(value image)
{
    sf::Vector2u size = SfImage_val(image)->getSize();
    return Val_sfVector2u(size);
}

CAMLextern_C value
caml_sfImage_getPixelsBA(value sf_image)
{
    CAMLparam1(sf_image);
    CAMLlocal1(img_ba);
    size_t img_data_size;
    sf::Vector2u size = SfImage_val(sf_image)->getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    const sf::Uint8 *img_data = SfImage_val(sf_image)->getPixelsPtr();
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

CAMLextern_C value
caml_sfImage_getPixelsStr(value sf_image)
{
    CAMLparam1(sf_image);
    CAMLlocal1(img_str);
    sf::Vector2u size = SfImage_val(sf_image)->getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    unsigned int len = width * height * 4;
    const sf::Uint8 *img_data = SfImage_val(sf_image)->getPixelsPtr();
    if (img_data == NULL) caml_failwith("SFImage.getPixelsStr");
    img_str = caml_alloc_string(len);
    memcpy(String_val(img_str), img_data, len);
    CAMLreturn(img_str);
}

CAMLextern_C value
caml_sfImage_saveToFile(value image, value filename)
{
    bool saved = SfImage_val(image)->saveToFile(String_val(filename));
    if (!saved) caml_failwith("SFImage.saveToFile");
    return Val_unit;
}

CAMLextern_C value
caml_sfImage_setPixel(value image, value x, value y, value color)
{
    SfImage_val(image)->setPixel(Long_val(x), Long_val(y), SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfImage_getPixel4(value image, value x, value y)
{
    sf::Color color = SfImage_val(image)->getPixel(Int_val(x), Int_val(y));
    return Val_sfColor4(color);
}

CAMLextern_C value
caml_sfImage_getPixel3(value image, value x, value y)
{
    sf::Color color = SfImage_val(image)->getPixel(Int_val(x), Int_val(y));
    return Val_sfColor3(color);
}

CAMLextern_C value
caml_sfImage_getPixelRGB(value image, value x, value y)
{
    sf::Color color = SfImage_val(image)->getPixel(Int_val(x), Int_val(y));
    return Val_RGB(color);
}

CAMLextern_C value
caml_sfImage_getPixelRGBA(value image, value x, value y)
{
    sf::Color color = SfImage_val(image)->getPixel(Int_val(x), Int_val(y));
    return Val_RGBA(color);
}

sf::Uint8
SfUint8_val(value _d)
{
    int d = Long_val(_d);
    if (d < 0 || d > 255)
        caml_invalid_argument("sfUint8");
    return (sf::Uint8) d;
}

CAMLextern_C value
caml_sfImage_createMaskFromColor(value image, value color, value alpha)
{
    SfImage_val(image)->createMaskFromColor(
            SfColor_val(color), SfUint8_val(alpha));
    return Val_unit;
}

CAMLextern_C value
caml_sfImage_flipHorizontally(value image)
{
    SfImage_val(image)->flipHorizontally();
    return Val_unit;
}

CAMLextern_C value
caml_sfImage_flipVertically(value image)
{
    SfImage_val(image)->flipVertically();
    return Val_unit;
}

/* TODO
sfImage* sfImage_create(unsigned int width, unsigned int height);
sfImage* sfImage_createFromStream(sfInputStream* stream);
sfImage* sfImage_copy(sfImage* image);
void sfImage_copyImage(sfImage* image, const sfImage* source,
        unsigned int destX, unsigned int destY,
        sfIntRect sourceRect, sfBool applyAlpha);
*/

// vim: sw=4 sts=4 ts=4 et
