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

#include <SFML/Network/SocketTCP.h>

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
caml_sfSocketTCP_Create(value unit)
{
    sfSocketTCP *sock;
    sock = sfSocketTCP_Create();
    if (!sock) caml_failwith("SFSocketTCP.create");
    return Val_sfSocketTCP(sock);
}

CAMLprim value
caml_sfSocketTCP_Destroy(value socket)
{
    sfSocketTCP_Destroy(SfSocketTCP_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_SetBlocking(value socket, value blocking)
{
    sfSocketTCP_SetBlocking(SfSocketTCP_val(socket), Bool_val(blocking));
    return Val_unit;
}

#define check_sfSocketStatus(st) \
    switch (st) { \
    case sfSocketDone: break; \
    case sfSocketNotReady: \
        caml_raise_constant(*caml_named_value("SFSocketTCP.Socket_Not_Ready")); break; \
    case sfSocketDisconnected: \
        caml_raise_constant(*caml_named_value("SFSocketTCP.Socket_Disconnected")); break; \
    case sfSocketError: \
        caml_raise_constant(*caml_named_value("SFSocketTCP.Socket_Error")); break; \
    }

CAMLprim value
caml_sfSocketTCP_Connect(value socket, value port, value addr, value timeout)
{
    sfSocketStatus st;
    sfIPAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFSocketTCP.connect: address length <> 16");
    memcpy(address.Address, String_val(addr), 16);
    st = sfSocketTCP_Connect(SfSocketTCP_val(socket), Int_val(port), address, Double_val(timeout));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_Listen(value socket, value port)
{
    sfBool successful = sfSocketTCP_Listen(SfSocketTCP_val(socket), Int_val(port));
    if (!successful) caml_failwith("SFSocketTCP.listen");
    return Val_bool(successful);
}

CAMLprim value
caml_sfSocketTCP_Accept(value socket)
{
    CAMLparam1(socket);
    CAMLlocal2(ret, mladdr);
    sfSocketStatus st;
    sfSocketTCP *connected;
    sfIPAddress address;
    st = sfSocketTCP_Accept(SfSocketTCP_val(socket), &connected, &address);
    check_sfSocketStatus(st)
    mladdr = caml_alloc_string(16);
    memcpy(String_val(mladdr), address.Address, 16);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_sfSocketTCP(connected));
    Store_field(ret, 1, mladdr);
    CAMLreturn(ret);
}

CAMLprim value
caml_sfSocketTCP_Send(value socket, value data)
{
    sfSocketStatus st;
    st = sfSocketTCP_Send(SfSocketTCP_val(socket),
            String_val(data), caml_string_length(data));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_Send_sub(value socket, value data, value ofs, value len)
{
    sfSocketStatus st;
    st = sfSocketTCP_Send(SfSocketTCP_val(socket),
            String_val(data) + Int_val(ofs), Int_val(len));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_Receive(value socket, value data)
{
    sfSocketStatus st;
    size_t sizeReceived;
    st = sfSocketTCP_Receive(SfSocketTCP_val(socket),
            String_val(data), caml_string_length(data), &sizeReceived);
    check_sfSocketStatus(st)
    return Val_long(sizeReceived);
}

CAMLprim value
caml_sfSocketTCP_SendPacket(value socket, value packet)
{
    sfSocketStatus st;
    st = sfSocketTCP_SendPacket(SfSocketTCP_val(socket), SfPacket_val_u(packet));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_ReceivePacket(value socket, value packet)
{
    sfSocketStatus st;
    st = sfSocketTCP_ReceivePacket(SfSocketTCP_val(socket), SfPacket_val_u(packet));
    check_sfSocketStatus(st)
    return Val_unit;
}

CAMLprim value
caml_sfSocketTCP_IsValid(value socket)
{
    sfBool valid = sfSocketTCP_IsValid(SfSocketTCP_val(socket));
    return Val_bool(valid);
}

/* vim: sw=4 sts=4 ts=4 et
 */
