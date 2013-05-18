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

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "sf_caml_incs.hpp"

#include "SFTime_stub.hpp"

#define Val_sfClock(clk) ((value)(clk))
#define SfClock_val(clk) ((sf::Clock *)(clk))

/* sf::Clock */

CAMLextern_C value
caml_sfClock_create(value unit)
{
    sf::Clock *clock = new sf::Clock;
    return Val_sfClock(clock);
}

CAMLextern_C value
caml_sfClock_destroy(value clock)
{
    delete SfClock_val(clock);
    return Val_unit;
}

CAMLextern_C value
caml_sfClock_restart(value clock)
{
    sf::Time time = SfClock_val(clock)->restart();
    return Val_sfTime_u(time);
}

CAMLextern_C value
caml_sfClock_restart_asSeconds(value clock)
{
    sf::Time time = SfClock_val(clock)->restart();
    return caml_copy_double(time.asSeconds());
}

CAMLextern_C value
caml_sfClock_restart_asMilliseconds(value clock)
{
    sf::Int32 millisec = SfClock_val(clock)->restart().asMilliseconds();
    return caml_copy_int32(millisec);
}

CAMLextern_C value
caml_sfClock_restart_asMicroseconds(value clock)
{
    sf::Int64 micro = SfClock_val(clock)->restart().asMicroseconds();
    return caml_copy_int64(micro);
}

CAMLextern_C value
caml_sfClock_getElapsedTime(value clock)
{
    sf::Time time = SfClock_val(clock)->getElapsedTime();
    return Val_sfTime_u(time);
}

CAMLextern_C value
caml_sfClock_getElapsedTime_asSeconds(value clock)
{
    float sec = SfClock_val(clock)->getElapsedTime().asSeconds();
    return caml_copy_double(sec);
}

CAMLextern_C value
caml_sfClock_getElapsedTime_asMilliseconds(value clock)
{
    sf::Int32 millisec = SfClock_val(clock)->getElapsedTime().asMilliseconds();
    return caml_copy_int32(millisec);
}

CAMLextern_C value
caml_sfClock_getElapsedTime_asMicroseconds(value clock)
{
    sf::Int64 micro = SfClock_val(clock)->getElapsedTime().asMicroseconds();
    return caml_copy_int64(micro);
}

// vim: sw=4 sts=4 ts=4 et
