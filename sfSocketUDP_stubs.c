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

#include <SFML/Network/SocketUDP.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <string.h>

#include "sfSocket_stubs.h"
#include "sfPacket_stubs.h"

CAMLprim value
caml_sfSocketUDP_Create(value unit)
{
    sfSocketUDP *sock;
    sock = sfSocketUDP_Create();
    if (!sock) caml_failwith("SFSocketUDP.create");
    return Val_sfSocketUDP(sock);
}

CAMLprim value
caml_sfSocketUDP_Destroy(value sock)
{
    sfSocketUDP_Destroy(SfSocketUDP_val(sock));
    return Val_unit;
}

CAMLprim value
caml_sfSocketUDP_SetBlocking(value sock, value blocking)
{
    sfSocketUDP_SetBlocking(SfSocketUDP_val(sock), Bool_val(blocking));
    return Val_unit;
}

CAMLprim value
caml_sfSocketUDP_Bind(value sock, value port)
{
    sfBool ok = sfSocketUDP_Bind(SfSocketUDP_val(sock), Long_val(port));
    if (!ok) caml_failwith("SFSocketUDP.bind");
    return Val_unit;
}

CAMLprim value
caml_sfSocketUDP_Unbind(value sock)
{
    sfBool ok = sfSocketUDP_Unbind(SfSocketUDP_val(sock));
    if (!ok) caml_failwith("SFSocketUDP.unbind");
    return Val_unit;
}

#define check_sfSocketStatus(st) \
    switch (st) { \
    case sfSocketDone: break; \
    case sfSocketNotReady: \
        caml_raise_constant(*caml_named_value("SFSocketUDP.Socket_Not_Ready")); break; \
    case sfSocketDisconnected: \
        caml_raise_constant(*caml_named_value("SFSocketUDP.Socket_Disconnected")); break; \
    case sfSocketError: \
        caml_raise_constant(*caml_named_value("SFSocketUDP.Socket_Error")); break; \
    }

CAMLprim value
caml_sfSocketUDP_Send(value sock, value data, value addr, value port)
{
    sfSocketStatus st;
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFSocketUDP.send: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    st = sfSocketUDP_Send(SfSocketUDP_val(sock),
            String_val(data), caml_string_length(data),
            address, Long_val(port));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketUDP_Receive(value sock, value data)
{
    CAMLparam2(sock, data);
    CAMLlocal2(ret, mladdr);
    sfSocketStatus st;
    size_t maxSize = caml_string_length(data);
    size_t sizeReceived;
    unsigned short port;
    sfIPAddress address;
    st = sfSocketUDP_Receive(SfSocketUDP_val(sock),
            String_val(data), maxSize, &sizeReceived, &address, &port);
    check_sfSocketStatus(st)
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), address.Address, 16);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_long(sizeReceived));
    Store_field(ret, 1, mladdr);
    Store_field(ret, 2, Val_long(port));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfSocketUDP_SendPacket(value sock, value packet, value addr, value port)
{
    sfSocketStatus st;
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFSocketUDP.sendPacket: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    st = sfSocketUDP_SendPacket(SfSocketUDP_val(sock), SfPacket_val_u(packet), address, Long_val(port));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketUDP_ReceivePacket(value sock, value packet)
{
    CAMLparam2(sock, packet);
    CAMLlocal2(ret, mladdr);
    sfSocketStatus st;
    unsigned short port;
    sfIPAddress address;
    st = sfSocketUDP_ReceivePacket(SfSocketUDP_val(sock),
            SfPacket_val_u(packet), &address, &port);
    check_sfSocketStatus(st)
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), address.Address, 16);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, mladdr);
    Store_field(ret, 1, Val_long(port));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfSocketUDP_IsValid(value sock)
{
    sfBool valid = sfSocketUDP_IsValid(SfSocketUDP_val(sock));
    return Val_bool(valid);
}

/* vim: sw=4 sts=4 ts=4 et
 */
