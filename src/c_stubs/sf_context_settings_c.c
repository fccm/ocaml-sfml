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

#include <SFML/Window/Window.h>

#include "sf_caml_incs_c.h"
#include "sf_context_settings_c.h"

void
SfContextSettings_val(sfContextSettings *settings, value ml_settings)
{
    settings->depthBits         = Long_val(Field(ml_settings, 0));
    settings->stencilBits       = Long_val(Field(ml_settings, 1));
    settings->antialiasingLevel = Long_val(Field(ml_settings, 2));
    settings->majorVersion      = Long_val(Field(ml_settings, 3));
    settings->minorVersion      = Long_val(Field(ml_settings, 4));
}

value
Val_sfContextSettings(sfContextSettings *settings)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(5, 0);
    Store_field(ret, 0, Val_long(settings->depthBits));
    Store_field(ret, 1, Val_long(settings->stencilBits));
    Store_field(ret, 2, Val_long(settings->antialiasingLevel));
    Store_field(ret, 3, Val_long(settings->majorVersion));
    Store_field(ret, 4, Val_long(settings->minorVersion));
    CAMLreturn(ret);
}

/* vim: sw=4 sts=4 ts=4 et
 */
