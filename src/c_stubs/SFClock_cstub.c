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

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

#include "sf_caml_incs_c.h"
#include "SFTime_cstub.h"

#define Val_sfClock(clk) ((value)(clk))
#define SfClock_val(clk) ((sfClock *)(clk))


/* sfClock */

CAMLprim value
caml_sfClock_create(value unit)
{
    sfClock *clock;
    clock = sfClock_create();
    if (!clock) caml_failwith("SFClock.create");
    return Val_sfClock(clock);
}

CAMLprim value
caml_sfClock_destroy(value clock)
{
    sfClock_destroy(SfClock_val(clock));
    return Val_unit;
}

CAMLprim value
caml_sfClock_copy(value clock)
{
    sfClock *copy = sfClock_copy(SfClock_val(clock));
    if (!copy) caml_failwith("SFClock.copy");
    return Val_sfClock(copy);
}

CAMLprim value
caml_sfClock_getElapsedTime(value clock)
{
    sfTime time = sfClock_getElapsedTime(SfClock_val(clock));
    return Val_sfTime_u(&time);
}

CAMLprim value
caml_sfClock_getElapsedTime_asSeconds(value clock)
{
    sfTime time = sfClock_getElapsedTime(SfClock_val(clock));
    float sec = sfTime_asSeconds(time);
    return caml_copy_double(sec);
}

CAMLprim value
caml_sfClock_getElapsedTime_asMilliseconds(value clock)
{
    sfTime time = sfClock_getElapsedTime(SfClock_val(clock));
    sfInt32 millisec = sfTime_asMilliseconds(time);
    return caml_copy_int32(millisec);
}

CAMLprim value
caml_sfClock_getElapsedTime_asMicroseconds(value clock)
{
    sfTime time = sfClock_getElapsedTime(SfClock_val(clock));
    sfInt64 micro = sfTime_asMicroseconds(time);
    return caml_copy_int64(micro);
}

CAMLprim value
caml_sfClock_restart(value clock)
{
    sfTime time = sfClock_restart(SfClock_val(clock));
    return Val_sfTime_u(&time);
}

CAMLprim value
caml_sfClock_restart_asSeconds(value clock)
{
    sfTime time = sfClock_restart(SfClock_val(clock));
    float sec = sfTime_asSeconds(time);
    return caml_copy_double(sec);
}

CAMLprim value
caml_sfClock_restart_asMilliseconds(value clock)
{
    sfTime time = sfClock_restart(SfClock_val(clock));
    sfInt32 millisec = sfTime_asMilliseconds(time);
    return caml_copy_int32(millisec);
}

CAMLprim value
caml_sfClock_restart_asMicroseconds(value clock)
{
    sfTime time = sfClock_restart(SfClock_val(clock));
    sfInt64 micro = sfTime_asMicroseconds(time);
    return caml_copy_int64(micro);
}

/* vim: sw=4 sts=4 ts=4 et
 */
