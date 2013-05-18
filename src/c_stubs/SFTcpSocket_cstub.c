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

#include <SFML/Network/TcpSocket.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFTcpSocket_cstub.h"
#include "SFSocket_cstub.h"
#include "SFPacket_cstub.h"
#include "SFTime_cstub.h"

#include <string.h>

/* sfTcpSocket */

CAMLprim value
caml_sfTcpSocket_create(value unit)
{
    sfTcpSocket *sock;
    sock = sfTcpSocket_create();
    if (!sock) caml_failwith("SFTcpSocket.create");
    return Val_sfTcpSocket(sock);
}

CAMLprim value
caml_sfTcpSocket_destroy(value socket)
{
    sfTcpSocket_destroy(SfTcpSocket_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_connect(
        value socket, value port, value addr, value timeout, value unit)
{
    sfSocketStatus st;
    sfIpAddress address;
    if (caml_string_length(addr) != 16)
        caml_invalid_argument("SFTcpSocket.connect: address length <> 16");
    memcpy(address.address, String_val(addr), 16);
    if (timeout != Val_none) {
        st = sfTcpSocket_connect(
                SfTcpSocket_val(socket), address, Int_val(port),
                SfTime_val(Some_val(timeout)));
    } else {
        st = sfTcpSocket_connect(
                SfTcpSocket_val(socket), address, Int_val(port),
                sfTime_Zero);
    }
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_disconnect(value socket)
{
    sfTcpSocket_disconnect(SfTcpSocket_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_setBlocking(value socket, value blocking)
{
    sfTcpSocket_setBlocking(SfTcpSocket_val(socket), Bool_val(blocking));
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_isBlocking(value socket)
{
    sfBool b = sfTcpSocket_isBlocking(SfTcpSocket_val(socket));
    return Val_bool(b);
}

CAMLprim value
caml_sfTcpSocket_send(value socket, value data)
{
    sfSocketStatus st;
    st = sfTcpSocket_send(SfTcpSocket_val(socket),
            String_val(data), caml_string_length(data));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_send_sub(value socket, value data, value ofs, value len)
{
    sfSocketStatus st;
    st = sfTcpSocket_send(SfTcpSocket_val(socket),
            String_val(data) + Int_val(ofs), Int_val(len));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_receive(value socket, value data)
{
    sfSocketStatus st;
    size_t sizeReceived;
    st = sfTcpSocket_receive(SfTcpSocket_val(socket),
            String_val(data), caml_string_length(data), &sizeReceived);
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_long(sizeReceived);
}

CAMLprim value
caml_sfTcpSocket_sendPacket(value socket, value packet)
{
    sfSocketStatus st;
    st = sfTcpSocket_sendPacket(SfTcpSocket_val(socket), SfPacket_val_u(packet));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_receivePacket(value socket, value packet)
{
    sfSocketStatus st;
    st = sfTcpSocket_receivePacket(SfTcpSocket_val(socket), SfPacket_val_u(packet));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLprim value
caml_sfTcpSocket_getLocalPort(value socket)
{
    unsigned short pt = sfTcpSocket_getLocalPort(SfTcpSocket_val(socket));
    return Val_int(pt);
}

CAMLprim value
caml_sfTcpSocket_getRemotePort(value socket)
{
    unsigned short pt = sfTcpSocket_getRemotePort(SfTcpSocket_val(socket));
    return Val_int(pt);
}

/* TODO
sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
