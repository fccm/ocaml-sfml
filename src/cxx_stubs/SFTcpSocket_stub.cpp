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

#include <SFML/Network/TcpSocket.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFTcpSocket_stub.hpp"
#include "SFIpAddress_stub.hpp"
#include "SFSocket_stub.hpp"
#include "SFPacket_stub.hpp"
#include "SFTime_stub.hpp"

/* sf::TcpSocket */

CAMLextern_C value
caml_sfTcpSocket_create(value unit)
{
    sf::TcpSocket *sock = new sf::TcpSocket;
    return Val_sfTcpSocket(sock);
}

CAMLextern_C value
caml_sfTcpSocket_destroy(value socket)
{
    delete SfTcpSocket_val(socket);
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_connect(
        value socket, value port, value address, value timeout, value unit)
{
    sf::Socket::Status st;
    if (timeout != Val_none) {
        st = SfTcpSocket_val(socket)->connect(
                SfIpAddress_val(address), Int_val(port),
                SfTime_val(Some_val(timeout)));
    } else {
        st = SfTcpSocket_val(socket)->connect(
                SfIpAddress_val(address), Int_val(port));
    }
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_disconnect(value socket)
{
    SfTcpSocket_val(socket)->disconnect();
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_setBlocking(value socket, value blocking)
{
    SfTcpSocket_val(socket)->setBlocking(Bool_val(blocking));
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_isBlocking(value socket)
{
    bool b = SfTcpSocket_val(socket)->isBlocking();
    return Val_bool(b);
}

CAMLextern_C value
caml_sfTcpSocket_send(value socket, value data)
{
    sf::Socket::Status st =
        SfTcpSocket_val(socket)->send(
            String_val(data), caml_string_length(data));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_send_sub(value socket, value data, value ofs, value len)
{
    sf::Socket::Status st =
        SfTcpSocket_val(socket)->send(
            String_val(data) + Int_val(ofs), Int_val(len));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_receive(value socket, value data)
{
    std::size_t sizeReceived;
    sf::Socket::Status st =
        SfTcpSocket_val(socket)->receive(
            String_val(data),
            caml_string_length(data),
            sizeReceived);
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_long(sizeReceived);
}

CAMLextern_C value
caml_sfTcpSocket_sendPacket(value socket, value packet)
{
    sf::Socket::Status st =
        SfTcpSocket_val(socket)->send(*SfPacket_val_u(packet));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_receivePacket(value socket, value packet)
{
    sf::Socket::Status st =
        SfTcpSocket_val(socket)->receive(*SfPacket_val_u(packet));
    check_sfSocketStatus(st, "SFTcpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpSocket_getLocalPort(value socket)
{
    unsigned short pt = SfTcpSocket_val(socket)->getLocalPort();
    return Val_int(pt);
}

CAMLextern_C value
caml_sfTcpSocket_getRemotePort(value socket)
{
    unsigned short pt = SfTcpSocket_val(socket)->getRemotePort();
    return Val_int(pt);
}

/* TODO
sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket);
*/

// vim: sw=4 sts=4 ts=4 et
