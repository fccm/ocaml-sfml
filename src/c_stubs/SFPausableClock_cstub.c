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

#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>

#include "PausableClock_c.h"

#include "sf_caml_incs_c.h"
#include "SFTime_cstub.h"

#define Val_sfPausableClock(pck) ((value)(pck))
#define SfPausableClock_val(pck) ((sfPausableClock *)(pck))


/* wrapping sfPausableClock to ocaml */

CAMLprim value
caml_sfPausableClock_create(value paused)
{
    sfPausableClock *pclock = sfPausableClock_create(Bool_val(paused));
    return Val_sfPausableClock(pclock);
}

CAMLprim value
caml_sfPausableClock_destroy(value pclock)
{
    sfPausableClock_destroy(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_pause(value pclock)
{
    sfPausableClock_pause(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_start(value pclock)
{
    sfPausableClock_start(SfPausableClock_val(pclock));
    return Val_unit;
}

CAMLprim value
caml_sfPausableClock_isPaused(value pclock)
{
    int p = sfPausableClock_isPaused(SfPausableClock_val(pclock));
    switch (p) {
        case -1: caml_failwith("SFPausableClock.isPaused");
        case 0: return Val_false;
        case 1: return Val_true;
    }
    caml_failwith("SFPausableClock.isPaused");
}

CAMLprim value
caml_sfPausableClock_getElapsedTime(value pclock)
{
    sfTime time = sfPausableClock_getElapsedTime(SfPausableClock_val(pclock));
    if (sfTime_isError(time))
        caml_failwith("SFPausableClock.getElapsedTime");
    return Val_sfTime_u(&time);
}

CAMLprim value
caml_sfPausableClock_getElapsedTime_asSeconds(value pclock)
{
    sfTime time = sfPausableClock_getElapsedTime(SfPausableClock_val(pclock));
    if (sfTime_isError(time))
        caml_failwith("SFPausableClock.getElapsedTime");
    float sec = sfTime_asSeconds(time);
    return caml_copy_double(sec);
}

CAMLprim value
caml_sfPausableClock_restart(value pclock, value paused)
{
    sfTime time = sfPausableClock_restart(SfPausableClock_val(pclock), Bool_val(paused));
    if (sfTime_isError(time))
        caml_failwith("SFPausableClock.restart");
    return Val_sfTime_u(&time);
}

/* vim: sw=4 sts=4 ts=4 et
 */
