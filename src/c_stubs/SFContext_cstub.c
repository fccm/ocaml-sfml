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

#include <SFML/Window/Context.h>

#include "sf_caml_incs_c.h"

#define Val_sfContext(ctx) ((value)(ctx))
#define SfContext_val(ctx) ((sfContext *)(ctx))


/* sfContext */

CAMLprim value
caml_sfContext_create(value unit)
{
    sfContext *context = sfContext_create();
    return Val_sfContext(context);
}

CAMLprim value
caml_sfContext_destroy(value context)
{
    sfContext_destroy(SfContext_val(context));
    return Val_unit;
}

CAMLprim value
caml_sfContext_setActive(value context, value active)
{
    sfContext_setActive(SfContext_val(context), Bool_val(active));
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
