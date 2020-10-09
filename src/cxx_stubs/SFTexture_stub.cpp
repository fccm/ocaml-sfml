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

#include <SFML/Graphics/Texture.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "sf_conv_vectors.hpp"
#include "SFTexture_stub.hpp"
#include "SFRect_stub.hpp"
#include "SFImage_stub.hpp"

value Val_sfTexture(sf::Texture * p)
{
    return caml_copy_nativeint((intnat) p);
}

sf::Texture * SfTexture_val(value v)
{
    return (sf::Texture *) Nativeint_val(v);
}

/* sf::Texture */

CAMLextern_C value
caml_sfTexture_create(value width, value height)
{
    sf::Texture *tex = new sf::Texture;
    bool created = tex->create(Long_val(width), Long_val(height));
    if (!created) {
        delete tex;
        caml_failwith("SFTexture.create");
    }
    return Val_sfTexture(tex);
}

CAMLextern_C value
caml_sfTexture_destroy(value texture)
{
    delete SfTexture_val(texture);
    return Val_unit;
}

CAMLextern_C value
caml_sfTexture_createFromFile(value filename, value area, value unit)
{
    bool loaded;
    sf::Texture *tex = new sf::Texture;
    if (area == Val_none) {
        loaded = tex->loadFromFile(String_val(filename));
    } else {
        loaded = tex->loadFromFile(String_val(filename),
                SfIntRect_val(Some_val(area)));
    }
    if (!loaded) {
        delete tex;
        caml_failwith("SFTexture.createFromFile");
    }
    return Val_sfTexture(tex);
}

CAMLextern_C value
caml_sfTexture_createFromMemory(value data, value area, value unit)
{
    bool loaded;
    sf::Texture *tex = new sf::Texture;
    if (area == Val_none) {
        loaded = tex->loadFromMemory(String_val(data), caml_string_length(data));
    } else {
        loaded = tex->loadFromMemory(String_val(data), caml_string_length(data),
                SfIntRect_val(Some_val(area)));
    }
    if (!loaded) {
        delete tex;
        caml_failwith("SFTexture.createFromMemory");
    }
    return Val_sfTexture(tex);
}

/* TODO?
sfTexture* sfTexture_createFromStream(
        sfInputStream* stream, const sfIntRect* area);
*/

CAMLextern_C value
caml_sfTexture_createFromImage(value image, value area, value unit)
{
    bool loaded;
    sf::Texture *tex = new sf::Texture;
    if (area == Val_none) {
        loaded = tex->loadFromImage(*SfImage_val_u(image));
    } else {
        loaded = tex->loadFromImage(*SfImage_val_u(image),
                SfIntRect_val(Some_val(area)));
    }
    if (!loaded) {
        delete tex;
        caml_failwith("SFTexture.createFromImage");
    }
    return Val_sfTexture(tex);
}

CAMLextern_C value
caml_sfTexture_copy(value texture)
{
    sf::Texture *tex = new sf::Texture(*SfTexture_val(texture));
    if (tex == NULL) caml_failwith("SFTexture.copy");  // TODO ???
    return Val_sfTexture(tex);
}

CAMLextern_C value
caml_sfTexture_getSize(value texture)
{
    sf::Vector2u size = SfTexture_val(texture)->getSize();
    return Val_sfVector2u(size);
}

CAMLextern_C value
caml_sfTexture_copyToImage(value texture)
{
    /*
    sf::Image img = SfTexture_val(texture)->copyToImage();
    */
    caml_failwith("SFTexture.copyToImage");  // TODO
    return Val_int(-1);  // TODO
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

CAMLextern_C value
caml_sfTexture_bind(value texture)
{
    sf::Texture::bind(
            SfTexture_val(texture)/*, TODO
            CoordinateType coordinateType = Normalized*/);
    return Val_unit;
}

CAMLextern_C value
caml_sfTexture_generateMipmap(value texture)
{
    return Val_bool(SfTexture_val(texture)->generateMipmap());
}

CAMLextern_C value
caml_sfTexture_setSmooth(value texture, value smooth)
{
    SfTexture_val(texture)->setSmooth(Bool_val(smooth));
    return Val_unit;
}

CAMLextern_C value
caml_sfTexture_isSmooth(value texture)
{
    return Val_bool(SfTexture_val(texture)->isSmooth());
}

CAMLextern_C value
caml_sfTexture_setRepeated(value texture, value repeated)
{
    SfTexture_val(texture)->setRepeated(Bool_val(repeated));
    return Val_unit;
}

CAMLextern_C value
caml_sfTexture_isRepeated(value texture)
{
    return Val_bool(SfTexture_val(texture)->isRepeated());
}

CAMLextern_C value
caml_sfTexture_getMaximumSize(value unit)
{
    unsigned int size = sf::Texture::getMaximumSize();
    return Val_long(size);
}


/* TODO:
enum CoordinateType
{
Normalized, ///< Texture coordinates in range [0 .. 1]
Pixels      ///< Texture coordinates in range [0 .. size]
};

Texture();
Texture(const Texture& copy);
bool create(unsigned int width, unsigned int height);
bool loadFromFile(const std::string& filename, const IntRect& area = IntRect());
bool loadFromMemory(const void* data, std::size_t size, const IntRect& area = IntRect());
bool loadFromStream(sf::InputStream& stream, const IntRect& area = IntRect());
bool loadFromImage(const Image& image, const IntRect& area = IntRect());

Vector2u getSize() const;
Image copyToImage() const;
void update(const Uint8* pixels);
void update(const Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
void update(const Image& image);
void update(const Image& image, unsigned int x, unsigned int y);
void update(const Window& window);
void update(const Window& window, unsigned int x, unsigned int y);
void setSmooth(bool smooth);
bool isSmooth() const;
void setRepeated(bool repeated);
bool isRepeated() const;
Texture& operator =(const Texture& right);
static void bind(const Texture* texture, CoordinateType coordinateType = Normalized);
static unsigned int getMaximumSize();
static unsigned int getValidSize(unsigned int size);
*/

// vim: sw=4 sts=4 ts=4 et
