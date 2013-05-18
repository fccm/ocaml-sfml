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

#include <SFML/Window/Mouse.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFMouse_cstub.h"

/* sfMouse */

sfMouseButton SfMouseButton_val(value button)
{
    switch (Int_val(button))
    {
        case 0: return sfMouseLeft;
        case 1: return sfMouseRight;
        case 2: return sfMouseMiddle;
        case 3: return sfMouseXButton1;
        case 4: return sfMouseXButton2;
        default: caml_failwith("SFMouse.mouse_button");
    }
    caml_failwith("SFMouse.mouse_button");
}

value Val_sfMouseButton(sfMouseButton button)
{
    switch (button) {
        case sfMouseLeft:        return Val_long(0);
        case sfMouseRight:       return Val_long(1);
        case sfMouseMiddle:      return Val_long(2);
        case sfMouseXButton1:    return Val_long(3);
        case sfMouseXButton2:    return Val_long(4);
        default: caml_failwith("SFMouse.mouse_button");
    }
    caml_failwith("SFMouse.mouse_button");
}

CAMLprim value
caml_sfMouseButtonCount(value unit)
{
    return Val_int(sfMouseButtonCount);
}

CAMLprim value
caml_sfMouse_isButtonPressed(value button)
{
    return Val_bool(
        sfMouse_isButtonPressed(SfMouseButton_val(button)));
}


CAMLprim value
caml_sfMouse_getPosition(value unit)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    return Val_sfVector2i(&pos);
}

CAMLprim value
caml_sfMouse_setPosition(value position)
{
    sfMouse_setPosition(SfVector2i_val(position), NULL);
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
