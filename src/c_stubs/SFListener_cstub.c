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

#include <SFML/Audio/Listener.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"

/* sfListener */

CAMLprim value
caml_sfListener_setGlobalVolume(value volume)
{
    sfListener_setGlobalVolume(Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfListener_getGlobalVolume(value unit)
{
    return caml_copy_double(sfListener_getGlobalVolume());
}

CAMLprim value
caml_sfListener_setPosition(value pos)
{
    sfListener_setPosition(SfVector3f_val(pos));
    return Val_unit;
}

CAMLprim value
caml_sfListener_setPosition3(value posX, value posY, value posZ)
{
    sfListener_setPosition(SfVector3f_val3(posX, posY, posZ));
    return Val_unit;
}

CAMLprim value
caml_sfListener_getPosition(value unit)
{
    sfVector3f pos = sfListener_getPosition();
    return Val_sfVector3f(&pos);
}

CAMLprim value
caml_sfListener_setDirection(value orientation)
{
    sfListener_setDirection(SfVector3f_val(orientation));
    return Val_unit;
}

CAMLprim value
caml_sfListener_setDirection3(value dirX, value dirY, value dirZ)
{
    sfListener_setDirection(SfVector3f_val3(dirX, dirY, dirZ));
    return Val_unit;
}

CAMLprim value
caml_sfListener_getDirection(value unit)
{
    sfVector3f dir = sfListener_getDirection();
    return Val_sfVector3f(&dir);
}

/* vim: sw=4 sts=4 ts=4 et
 */
