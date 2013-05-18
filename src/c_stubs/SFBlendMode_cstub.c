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

#include <SFML/Graphics/BlendMode.h>

#include "sf_caml_incs_c.h"
#include "SFBlendMode_cstub.h"

sfBlendMode
SfBlendMode_val(value ml_blendMode)
{
    switch (Int_val(ml_blendMode))
    {
        case 0: return sfBlendAlpha;
        case 1: return sfBlendAdd;
        case 2: return sfBlendMultiply;
        case 3: return sfBlendNone;
        default: caml_failwith("SFBlendMode.t");
    }
    caml_failwith("SFBlendMode.t");
    return sfBlendNone;
}

value
Val_sfBlendMode(sfBlendMode blendMode)
{
    switch (blendMode)
    {
        case sfBlendAlpha:    return Val_int(0);
        case sfBlendAdd:      return Val_int(1);
        case sfBlendMultiply: return Val_int(2);
        case sfBlendNone:     return Val_int(3);
        default: caml_failwith("SFBlendMode.t");
    }
    caml_failwith("SFBlendMode.t");
    return Val_int(3);  /* sfBlendNone */
}

/* vim: sw=4 sts=4 ts=4 et
 */
