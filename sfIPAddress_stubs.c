/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2011 Florent Monnier <monnier.florent(_)gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
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

#include <SFML/Network/IPAddress.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <string.h>


CAMLprim value
caml_sfIPAddress_FromString(value str)
{
    CAMLparam1(str);
    CAMLlocal1(mladdr);
    sfIPAddress addr = sfIPAddress_FromString(String_val(str));
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

CAMLprim value
caml_sfIPAddress_FromBytes(value b0, value b1, value b2, value b3)
{
    CAMLparam4(b0, b1, b2, b3);
    CAMLlocal1(mladdr);
    sfIPAddress addr;
    addr = sfIPAddress_FromBytes(Long_val(b0), Long_val(b1), Long_val(b2), Long_val(b3));
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

CAMLprim value
caml_sfIPAddress_FromInteger(value int_addr)
{
    CAMLparam1(int_addr);
    CAMLlocal1(mladdr);
    sfIPAddress addr;
    sfUint32 address = Int32_val(int_addr);
    addr = sfIPAddress_FromInteger(address);
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

CAMLprim value
caml_sfIPAddress_IsValid(value addr)
{
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFIPAddress.isValid: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    sfBool v = sfIPAddress_IsValid(address);
    return Val_bool(v);
}

CAMLprim value
caml_sfIPAddress_ToString(value addr)
{
    char str[16];
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFIPAddress.toString: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    sfIPAddress_ToString(address, str);
    return caml_copy_string(str);
}

CAMLprim value
caml_sfIPAddress_ToInteger(value addr)
{
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFIPAddress.toInteger: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    sfUint32 int_addr = sfIPAddress_ToInteger(address);
    return caml_copy_int32(int_addr);
}


CAMLprim value
caml_sfIPAddress_GetLocalAddress(value unit)
{
    CAMLparam0();
    CAMLlocal1(mladdr);
    sfIPAddress addr = sfIPAddress_GetLocalAddress();
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

CAMLprim value
caml_sfIPAddress_GetPublicAddress(value timeout)
{
    CAMLparam1(timeout);
    CAMLlocal1(mladdr);
    sfIPAddress addr = sfIPAddress_GetPublicAddress(Double_val(timeout));
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

CAMLprim value
caml_sfIPAddress_LocalHost(value unit)
{
    CAMLparam0();
    CAMLlocal1(mladdr);
    sfIPAddress addr = sfIPAddress_LocalHost();
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), addr.Address, 16);
    CAMLreturn(mladdr);
}

/* vim: sw=4 sts=4 ts=4 et
 */
