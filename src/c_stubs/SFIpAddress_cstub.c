/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2011 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Network/IpAddress.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <string.h>

#include "SFTime_cstub.h"
#include "SFIpAddress_cstub.h"


value
Val_sfIpAddress(sfIpAddress address)
{
    CAMLparam0();
    CAMLlocal1(addr);
    addr = caml_alloc_string(16);
    memcpy(String_val(addr), address.address, 16);
    CAMLreturn(addr);
}

CAMLprim value
caml_sfIpAddress_fromString(value str)
{
    sfIpAddress addr = sfIpAddress_fromString(String_val(str));
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_fromBytes(value b0, value b1, value b2, value b3)
{
    sfIpAddress addr = sfIpAddress_fromBytes(
            Long_val(b0), Long_val(b1), Long_val(b2), Long_val(b3));
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_fromInteger(value int_addr)
{
    sfUint32 address = Int32_val(int_addr);
    sfIpAddress addr = sfIpAddress_fromInteger(address);
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_toString(value addr)
{
    CAMLparam1(addr);
    CAMLlocal1(ml_str);
    char str[120];
    size_t len;
    const char *f_name = "SFIpAddress.toString";
    sfIpAddress_toString(SfIpAddress_val(addr, f_name), str);
    len = strlen(str);
    ml_str = caml_alloc_string(len);
    memcpy(String_val(ml_str), str, len);
    CAMLreturn(ml_str);
}

CAMLprim value
caml_sfIpAddress_toInteger(value addr)
{
    const char *f_name = "SFIpAddress.toInteger";
    sfUint32 int_addr = sfIpAddress_toInteger(SfIpAddress_val(addr, f_name));
    return caml_copy_int32(int_addr);
}

CAMLprim value
caml_sfIpAddress_getLocalAddress(value unit)
{
    sfIpAddress addr = sfIpAddress_getLocalAddress();
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_getPublicAddress(value timeout)
{
    sfIpAddress addr = sfIpAddress_getPublicAddress(SfTime_val(timeout));
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_localHost(value unit)
{
    sfIpAddress addr = sfIpAddress_LocalHost;
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_None(value unit)
{
    sfIpAddress addr = sfIpAddress_None;
    return Val_sfIpAddress(addr);
}

CAMLprim value
caml_sfIpAddress_Broadcast(value unit)
{
    sfIpAddress addr = sfIpAddress_Broadcast;
    return Val_sfIpAddress(addr);
}

/* vim: sw=4 sts=4 ts=4 et
 */
