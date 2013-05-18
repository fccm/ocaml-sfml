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

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

#include "PausableClock.hpp"

#include "sf_caml_incs.hpp"
#include "SFTime_stub.hpp"

#define Val_sfPausableClock(pck) ((value)(pck))
#define SfPausableClock_val(pck) ((sftools::PausableClock *)(pck))

CAMLextern_C value
caml_sfPausableClock_create(value paused)
{
    sftools::PausableClock *pclock = new sftools::PausableClock(Bool_val(paused));
    return Val_sfPausableClock(pclock);
}

CAMLextern_C value
caml_sfPausableClock_destroy(value pclock)
{
    delete SfPausableClock_val(pclock);
    return Val_unit;
}

CAMLextern_C value
caml_sfPausableClock_pause(value pclock)
{
    SfPausableClock_val(pclock)->pause();
    return Val_unit;
}

CAMLextern_C value
caml_sfPausableClock_start(value pclock)
{
    SfPausableClock_val(pclock)->start();
    return Val_unit;
}

CAMLextern_C value
caml_sfPausableClock_isPaused(value pclock)
{
    return Val_bool(
        SfPausableClock_val(pclock)->isPaused());
}

CAMLextern_C value
caml_sfPausableClock_getElapsedTime(value pclock)
{
    sf::Time time = SfPausableClock_val(pclock)->getElapsedTime();
    return Val_sfTime_u(time);
}

CAMLextern_C value
caml_sfPausableClock_getElapsedTime_asSeconds(value pclock)
{
    float sec = SfPausableClock_val(pclock)->getElapsedTime().asSeconds();
    return caml_copy_double(sec);
}

CAMLextern_C value
caml_sfPausableClock_restart(value pclock, value paused)
{
    sf::Time time = SfPausableClock_val(pclock)->restart(Bool_val(paused));
    return Val_sfTime_u(time);
}

// vim: sw=4 sts=4 ts=4 et
