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

#define SfClock_val(clk) (*(sf::Clock **)Data_custom_val(clk))


static void
caml_sfClock_destroy(value clock)
{
    delete SfClock_val(clock);
}

/* sf::Clock */

CAMLextern_C value
caml_sfClock_create(value unit)
{
    value clock = caml_alloc_final(2, caml_sfClock_destroy, 0, 1);
    SfClock_val(clock) = new sf::Clock;
    return clock;
}

CAMLextern_C value
caml_sfClock_restart(value clock)
{
    return Val_sfTime(SfClock_val(clock)->restart());
}

CAMLextern_C value
caml_sfClock_getElapsedTime(value clock)
{
    return Val_sfTime(SfClock_val(clock)->getElapsedTime());
}

// vim: sw=4 sts=4 ts=4 et
