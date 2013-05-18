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

#include <SFML/Graphics/RenderStates.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFRenderStates_cstub.h"
#include "SFBlendMode_cstub.h"
#include "SFTransform_cstub.h"
#include "SFTexture_cstub.h"
#include "SFShader_cstub.h"

/* sfRenderStates */

static struct custom_operations sfRenderStates_custom_ops = {
    identifier:  "sfRenderStates struct",
    finalize:    custom_finalize_default,
    compare:     custom_compare_default,
    hash:        custom_hash_default,
    serialize:   custom_serialize_default,
    deserialize: custom_deserialize_default
};

#define SfTransform_p_val(tr) \
    (SfTransform_val_struct(tr))

CAMLprim value
caml_create_sfRenderStates(
        value ml_blendMode,
        value ml_transform,
        value ml_texture,
        value ml_shader,
        value unit)
{
    CAMLparam5(ml_blendMode, ml_transform, ml_texture, ml_shader, unit);
    CAMLlocal1(ml_states);

    sfRenderStates *states;

    ml_states = caml_alloc_custom(
            &sfRenderStates_custom_ops, sizeof(sfRenderStates), 0, 1);

    states = (sfRenderStates *) Data_custom_val(ml_states);

    states->blendMode = Option_val(ml_blendMode, SfBlendMode_val, sfBlendAlpha);
    states->transform = Option_val(ml_transform, SfTransform_p_val, sfTransform_Identity);
    states->texture   = Option_val(ml_texture,   SfTexture_val, NULL);
    states->shader    = Option_val(ml_shader,    SfShader_val, NULL);

    CAMLreturn(ml_states);
}

CAMLprim value
caml_sfRenderStates_destroy(value states)
{
    /* garbage collected (for compatibility with the C++ stubs) */
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
