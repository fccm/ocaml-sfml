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

#include <SFML/Graphics/RenderStates.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFRenderStates_stub.hpp"
#include "SFBlendMode_stub.hpp"
#include "SFTransform_stub.hpp"
#include "SFTexture_stub.hpp"
#include "SFShader_stub.hpp"

value Val_sfRenderStates(sf::RenderStates * p)
{
    return caml_copy_nativeint((intnat) p);
}

sf::RenderStates * SfRenderStates_val(value v)
{
    return (sf::RenderStates *) Nativeint_val(v);
}

/* sf::RenderStates */

CAMLextern_C value
caml_create_sfRenderStates(
        value blendMode,
        value transform,
        value texture,
        value shader,
        value unit)
{
    unsigned int pr = 0;
    sf::RenderStates *states = NULL;

    if (blendMode != Val_none) pr |= 0b0001;
    if (transform != Val_none) pr |= 0b0010;
    if (texture   != Val_none) pr |= 0b0100;
    if (shader    != Val_none) pr |= 0b1000;

    switch (pr) {
        case 0b0001:
            states = new sf::RenderStates(
                SfBlendMode_val(Some_val(blendMode)));
            break;
        case 0b0010:
            states = new sf::RenderStates(
                SfTransform_val_s(Some_val(transform)));
            break;
        case 0b0100:
            states = new sf::RenderStates(
                SfTexture_val(Some_val(texture)));
            break;
        case 0b1000:
            states = new sf::RenderStates(
                SfShader_val(Some_val(shader)));
            break;
        default:
            states = new sf::RenderStates(
                Option_val(blendMode, SfBlendMode_val, sf::BlendAlpha),
                Option_val(transform, SfTransform_val_s, sf::Transform()),
                Option_val(texture,   SfTexture_val, NULL),
                Option_val(shader,    SfShader_val, NULL));
    }

    return Val_sfRenderStates(states);
}

CAMLextern_C value
caml_sfRenderStates_destroy(value states)
{
    delete SfRenderStates_val(states);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# renderStates deleted" << std::endl << std::flush;  // XXX: DEBUG
#endif
    return Val_unit;
}

// vim: sw=4 sts=4 ts=4 et
