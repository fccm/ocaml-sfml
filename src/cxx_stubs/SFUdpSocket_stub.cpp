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

#include <SFML/Network/UdpSocket.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFUdpSocket_stub.hpp"
#include "SFSocket_stub.hpp"
#include "SFIpAddress_stub.hpp"
#include "SFPacket_stub.hpp"


CAMLextern_C value
caml_sfUdpSocket_create(value unit)
{
    sf::UdpSocket *sock = new sf::UdpSocket;
    return Val_sfUdpSocket(sock);
}

CAMLextern_C value
caml_sfUdpSocket_destroy(value sock)
{
    delete SfUdpSocket_val(sock);
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_setBlocking(value sock, value blocking)
{
    SfUdpSocket_val(sock)->setBlocking(Bool_val(blocking));
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_bind(value sock, value address, value port)
{
    sf::Socket::Status st =
        SfUdpSocket_val(sock)->bind(Long_val(port), Option_val(address, SfIpAddress_val, sf::IpAddress::Any));
    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_unbind(value sock)
{
    SfUdpSocket_val(sock)->unbind();
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_send(value sock, value data, value address, value port)
{
    sf::Socket::Status st;
    st = SfUdpSocket_val(sock)->send(
            String_val(data),
            caml_string_length(data),
            SfIpAddress_val(address),
            Long_val(port));
    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_receive(value sock, value data)
{
    CAMLparam2(sock, data);
    CAMLlocal1(ret);
    std::size_t maxSize = caml_string_length(data);
    std::size_t sizeReceived;
    unsigned short port;
    sf::IpAddress address;
    sf::Socket::Status st;

    st = SfUdpSocket_val(sock)->receive(
            String_val(data), maxSize, sizeReceived, address, port);
    check_sfSocketStatus(st, "SFUdpSocket")

    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_long(sizeReceived));
    Store_field(ret, 1, Val_sfIpAddress(address));
    Store_field(ret, 2, Val_long(port));
    CAMLreturn(ret);
}

CAMLextern_C value
caml_sfUdpSocket_sendPacket(value sock, value packet, value address, value port)
{
    sf::Socket::Status st;
    st = SfUdpSocket_val(sock)->send(
            *SfPacket_val_u(packet),
            SfIpAddress_val(address),
            Long_val(port));
    check_sfSocketStatus(st, "SFUdpSocket")
    return Val_unit;
}

CAMLextern_C value
caml_sfUdpSocket_receivePacket(value sock, value packet)
{
    CAMLparam2(sock, packet);
    CAMLlocal1(ret);
    unsigned short port;
    sf::IpAddress address;
    sf::Socket::Status st;

    st = SfUdpSocket_val(sock)->receive(
            *SfPacket_val_u(packet), address, port);
    check_sfSocketStatus(st, "SFUdpSocket")

    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_sfIpAddress(address));
    Store_field(ret, 1, Val_long(port));
    CAMLreturn(ret);
}

CAMLextern_C value
caml_sfUdpSocket_isBlocking(value sock)
{
    return Val_bool(
        SfUdpSocket_val(sock)->isBlocking());
}

CAMLextern_C value
caml_sfUdpSocket_getLocalPort(value sock)
{
    unsigned short port = SfUdpSocket_val(sock)->getLocalPort();
    return Val_long(port);
}

CAMLextern_C value
caml_sfUdpSocket_maxDatagramSize(value unit)
{
    return Val_long(sf::UdpSocket::MaxDatagramSize);
}

// vim: sw=4 sts=4 ts=4 et
