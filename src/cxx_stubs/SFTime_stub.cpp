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
#include <SFML/System/Sleep.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"

#include "SFTime_stub.hpp"

#define SfTime_val_p(t) (*SfTime_val(t))

value Val_sfTime(const sf::Time& t)
{
    sf::Time *time = new sf::Time();
    *time = t;
    return (value) time;
}

void finalize_sf_time(value t)
{
#if defined(_OCAML_SFML_DEBUG)
    // XXX: DEBUG
    std::cout << "# finalising time..." << std::endl << std::flush;
    std::cout << "# " << String_val(Field(t,1)) << std::endl << std::flush;
#endif

    delete SfTime_val_u(t);

#if defined(_OCAML_SFML_DEBUG)
    // XXX: DEBUG
    std::cout << "# time finalize done!" << std::endl << std::flush;
#endif
}

value Val_sfTime_u(sf::Time t)
{
    CAMLparam0();
    CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    //ret = caml_alloc_final(2, &finalize_sf_time, 0, 1);
    Store_field(ret, 0, Val_sfTime(t));
    Store_field(ret, 1, caml_copy_string("sf::Time from C++ stub"));
    CAMLreturn(ret);
}

CAMLextern_C value
caml_sfTime_destroy(value time)
{
    delete SfTime_val(time);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# time deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfSeconds(value amount)
{
    sf::Time t = sf::seconds(Double_val(amount));
    return Val_sfTime(t);
}

CAMLextern_C value
caml_sfMilliseconds(value amount)
{
    sf::Time t = sf::milliseconds(Int32_val(amount));
    return Val_sfTime(t);
}

CAMLextern_C value
caml_sfMicroseconds(value amount)
{
    sf::Time t = sf::microseconds(Int64_val(amount));
    return Val_sfTime(t);
}

CAMLextern_C value
caml_sfTime_asSeconds(value time)
{
    float sec = SfTime_val(time)->asSeconds();
    return caml_copy_double(sec);
}

CAMLextern_C value
caml_sfTime_asMilliseconds(value time)
{
    sf::Int32 millisec = SfTime_val(time)->asMilliseconds();
    return caml_copy_int32(millisec);
}

CAMLextern_C value
caml_sfTime_asMicroseconds(value time)
{
    sf::Int64 micro = SfTime_val(time)->asMicroseconds();
    return caml_copy_int64(micro);
}

CAMLextern_C value
caml_sfTime_add(value a, value b)
{
    sf::Time res = SfTime_val_p(a) + SfTime_val_p(b);
    return Val_sfTime(res);
}

CAMLextern_C value
caml_sfTime_sub(value a, value b)
{
    sf::Time res = SfTime_val_p(a) - SfTime_val_p(b);
    return Val_sfTime(res);
}

CAMLextern_C value
caml_sfTime_mul(value a, value b)
{
    sf::Time res = Float_val(a) * SfTime_val_p(b);
    return Val_sfTime(res);
}

CAMLextern_C value
caml_sfTime_mult(value a, value b)
{
    sf::Time res = SfTime_val_p(a) * Float_val(b);
    return Val_sfTime(res);
}

CAMLextern_C value
caml_sfTime_div(value a, value b)
{
    sf::Time res = SfTime_val_p(a) / Float_val(b);
    return Val_sfTime(res);
}

CAMLextern_C value
caml_sfTime_eq(value a, value b)
{
    bool res = SfTime_val_p(a) == SfTime_val_p(b);
    return Val_bool(res);
}

CAMLextern_C value
caml_sfTime_gt(value a, value b)
{
    bool res = SfTime_val_p(a) > SfTime_val_p(b);
    return Val_bool(res);
}

CAMLextern_C value
caml_sfTime_lt(value a, value b)
{
    bool res = SfTime_val_p(a) < SfTime_val_p(b);
    return Val_bool(res);
}

CAMLextern_C value
caml_sfSleep(value duration)
{
    caml_enter_blocking_section();
    sf::sleep(*SfTime_val(duration));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLextern_C value
caml_sfSleep_sec(value sec)
{
    caml_enter_blocking_section();
    sf::Time t = sf::seconds(Double_val(sec));
    sf::sleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLextern_C value
caml_sfSleep_msec(value msec)
{
    caml_enter_blocking_section();
    sf::Time t = sf::milliseconds(Int32_val(msec));
    sf::sleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLextern_C value
caml_sfSleep_musec(value musec)
{
    caml_enter_blocking_section();
    sf::Time t = sf::microseconds(Int64_val(musec));
    sf::sleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

// vim: sw=4 sts=4 ts=4 et
