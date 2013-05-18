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
#include <SFML/System/Sleep.h>

#include "sf_caml_incs_c.h"
#include "SFTime_cstub.h"

#include <string.h>

/* sfTime */

sfTime sfTime_error = { -1 };
sfTime sfTime_error_f()
{
    return sfTime_error;
}

sfBool sfTime_isError(sfTime t)
{
    if (t.microseconds == -1)
        return sfTrue;
    else
        return sfFalse;
}

sfTime
sfTime_add(sfTime a, sfTime b)
{
    sfTime res;
    res.microseconds = a.microseconds + b.microseconds;
    return res;
}

static sfTime
sfTime_sub(sfTime a, sfTime b)
{
    sfTime res;
    res.microseconds = a.microseconds - b.microseconds;
    return res;
}

static sfTime
sfTime_mul(double a, sfTime b)
{
    sfTime res;
    res.microseconds = (sfInt64) (a * ((double) b.microseconds));
    return res;
}

static sfTime
sfTime_mult(sfTime a, double b)
{
    sfTime res;
    res.microseconds = (sfInt64) (((double) a.microseconds) * b);
    return res;
}

static sfTime
sfTime_div(sfTime a, double b)
{
    sfTime res;
    res.microseconds = (sfInt64) (((double) a.microseconds) / b);
    return res;
}

static struct custom_operations sfTime_custom_ops = {
    identifier:  "sfTime struct",
    finalize:    custom_finalize_default,
    compare:     custom_compare_default,
    hash:        custom_hash_default,
    serialize:   custom_serialize_default,
    deserialize: custom_deserialize_default
};

value Val_sfTime(sfTime *time)
{
    CAMLparam0();
    CAMLlocal1(ml_time);

    /* TODO: FIX ME! */
    ml_time = caml_alloc_custom(&sfTime_custom_ops, sizeof(sfTime), 0, 1);
    memcpy(Data_custom_val(ml_time), time, sizeof(sfTime));

    CAMLreturn(ml_time);
}

value Val_sfTime_u(sfTime *time)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, 0);
    Store_field(var, 0, Val_sfTime(time));
    Store_field(var, 1, caml_copy_string("DEBUG: c stub"));
    CAMLreturn(var);
}

CAMLprim value
caml_sfTime_destroy(value time)
{
    return Val_unit;
}

CAMLprim value
caml_sfTime_add(value a, value b)
{
    sfTime res = sfTime_add(SfTime_val(a), SfTime_val(b));
    return Val_sfTime(&res);
}

CAMLprim value
caml_sfTime_sub(value a, value b)
{
    sfTime res = sfTime_sub(SfTime_val(a), SfTime_val(b));
    return Val_sfTime(&res);
}

CAMLprim value
caml_sfTime_mul(value a, value b)
{
    sfTime res = sfTime_mul(Double_val(a), SfTime_val(b));
    return Val_sfTime(&res);
}

CAMLprim value
caml_sfTime_mult(value a, value b)
{
    sfTime res = sfTime_mult(SfTime_val(a), Double_val(b));
    return Val_sfTime(&res);
}

CAMLprim value
caml_sfTime_div(value a, value b)
{
    sfTime res = sfTime_div(SfTime_val(a), Double_val(b));
    return Val_sfTime(&res);
}

CAMLprim value
caml_sfTime_asSeconds(value time)
{
    float sec = sfTime_asSeconds(SfTime_val(time));
    return caml_copy_double(sec);
}

CAMLprim value
caml_sfTime_asMilliseconds(value time)
{
    sfInt32 millisec = sfTime_asMilliseconds(SfTime_val(time));
    return caml_copy_int32(millisec);
}

CAMLprim value
caml_sfTime_asMicroseconds(value time)
{
    sfInt64 micro = sfTime_asMicroseconds(SfTime_val(time));
    return caml_copy_int64(micro);
}

CAMLprim value
caml_sfSeconds(value amount)
{
    sfTime time = sfSeconds(Double_val(amount));
    return Val_sfTime(&time);
}

CAMLprim value
caml_sfMilliseconds(value amount)
{
    sfTime time = sfMilliseconds(Int32_val(amount));
    return Val_sfTime(&time);
}

CAMLprim value
caml_sfMicroseconds(value amount)
{
    sfTime time = sfMicroseconds(Int64_val(amount));
    return Val_sfTime(&time);
}

CAMLprim value
caml_sfSleep(value duration)
{
    caml_enter_blocking_section();
    sfSleep(SfTime_val(duration));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfSleep_sec(value sec)
{
    caml_enter_blocking_section();
    sfTime t = sfSeconds(Double_val(sec));
    sfSleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfSleep_msec(value msec)
{
    caml_enter_blocking_section();
    sfTime t = sfMilliseconds(Int32_val(msec));
    sfSleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfSleep_musec(value musec)
{
    caml_enter_blocking_section();
    sfTime t = sfMicroseconds(Int64_val(musec));
    sfSleep(t);
    caml_leave_blocking_section();
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
