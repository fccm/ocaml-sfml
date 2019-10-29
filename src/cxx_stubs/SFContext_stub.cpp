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

#include <SFML/Window/Context.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "sf_context_settings.hpp"

#define Val_sfContext(ctx) ((value)(ctx))
#define SfContext_val(ctx) ((sf::Context *)(ctx))


/* sf::Context */

CAMLextern_C value
caml_sfContext_create(value unit)
{
    sf::Context *context = new sf::Context;
    return Val_sfContext(context);
}

CAMLextern_C value
caml_sfContext_destroy(value context)
{
    delete SfContext_val(context);
    return Val_unit;
}

CAMLextern_C value
caml_sfContext_getSettings(value context)
{
    CAMLparam1(context);
    CAMLreturn(Val_sfContextSettings(&SfContext_val(context)->getSettings()));
}

CAMLextern_C value
caml_sfContext_setActive(value context, value active)
{
    SfContext_val(context)->setActive(Bool_val(active));
    return Val_unit;
}

CAMLextern_C value
caml_sfContext_getActiveContext(value unit)
{
    const sf::Context* context = sf::Context::getActiveContext();
    return context == NULL ? Val_none : Some_val(context);
}

CAMLextern_C value
caml_sfContext_getActiveContextId(value unit)
{
    return caml_copy_int64(sf::Context::getActiveContextId());
}

// vim: sw=4 sts=4 ts=4 et
