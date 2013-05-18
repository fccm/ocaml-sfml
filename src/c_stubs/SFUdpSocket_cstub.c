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

#include <SFML/Network/UdpSocket.h>

#include "sf_caml_incs_c.h"
#include "SFSocket_cstub.h"
#include "SFUdpSocket_cstub.h"
#include "SFPacket_cstub.h"
#include "SFIpAddress_cstub.h"

#include <string.h>

CAMLprim value
caml_sfUdpSocket_create(value unit)
{
    sfUdpSocket *sock = sfUdpSocket_create();
    if (!sock) caml_failwith("SFUdpSocket.create");
    return Val_sfUdpSocket(sock);
}

CAMLprim value
caml_sfUdpSocket_destroy(value sock)
{
    sfUdpSocket_destroy(SfUdpSocket_val(sock));
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_setBlocking(value sock, value blocking)
{
    sfUdpSocket_setBlocking(SfUdpSocket_val(sock), Bool_val(blocking));
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_bind(value sock, value port)
{
    sfSocketStatus st = sfUdpSocket_bind(SfUdpSocket_val(sock), Long_val(port));
    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_unbind(value sock)
{
    sfUdpSocket_unbind(SfUdpSocket_val(sock));
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_send(value sock, value data, value address, value port)
{
    sfSocketStatus st;
    char f_name[] = "SFUdpSocket.send";

    st = sfUdpSocket_send(SfUdpSocket_val(sock),
            String_val(data), caml_string_length(data),
            SfIpAddress_val(address, f_name), Long_val(port));

    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_receive(value sock, value data)
{
    CAMLparam2(sock, data);
    CAMLlocal1(ret);

    sfSocketStatus st;
    size_t maxSize = caml_string_length(data);
    size_t sizeReceived;
    unsigned short port;
    sfIpAddress address;

    st = sfUdpSocket_receive(SfUdpSocket_val(sock),
            String_val(data), maxSize, &sizeReceived, &address, &port);

    check_sfSocketStatus(st, "SFUdpSocket")

    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_long(sizeReceived));
    Store_field(ret, 1, Val_sfIpAddress(address));
    Store_field(ret, 2, Val_long(port));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfUdpSocket_sendPacket(value sock, value packet, value address, value port)
{
    sfSocketStatus st;
    char f_name[] = "SFUdpSocket.sendPacket";
    st = sfUdpSocket_sendPacket(
            SfUdpSocket_val(sock), SfPacket_val_u(packet),
            SfIpAddress_val(address, f_name), Long_val(port));
    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfUdpSocket_receivePacket(value sock, value packet)
{
    CAMLparam2(sock, packet);
    CAMLlocal1(ret);
    sfSocketStatus st;
    unsigned short port;
    sfIpAddress address;

    st = sfUdpSocket_receivePacket(SfUdpSocket_val(sock),
            SfPacket_val_u(packet), &address, &port);

    check_sfSocketStatus(st, "SFUdpSocket")

    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_sfIpAddress(address));
    Store_field(ret, 1, Val_long(port));
    CAMLreturn(ret);
}

CAMLprim value
caml_sfUdpSocket_isBlocking(value sock)
{
    return Val_bool(
        sfUdpSocket_isBlocking(SfUdpSocket_val(sock)));
}

CAMLprim value
caml_sfUdpSocket_getLocalPort(value sock)
{
    unsigned short port = sfUdpSocket_getLocalPort(SfUdpSocket_val(sock));
    return Val_long(port);
}

CAMLprim value
caml_sfUdpSocket_maxDatagramSize(value unit)
{
    unsigned int size = sfUdpSocket_maxDatagramSize();
    return Val_long(size);
}

/* vim: sw=4 sts=4 ts=4 et
 */
