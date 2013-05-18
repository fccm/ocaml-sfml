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

#include <SFML/Network/TcpListener.hpp>

#include "sf_caml_incs.hpp"
#include "SFTcpListener_stub.hpp"
#include "SFTcpSocket_stub.hpp"
#include "SFSocket_stub.hpp"


CAMLextern_C value
caml_sfTcpListener_create(value unit)
{
    sf::TcpListener *list = new sf::TcpListener;
	return Val_sfTcpListener(list);
}

CAMLextern_C value
caml_sfTcpListener_destroy(value listener)
{
    delete SfTcpListener_val(listener);
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpListener_setBlocking(value listener, value blocking)
{
    SfTcpListener_val(listener)->setBlocking(Bool_val(blocking));
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpListener_isBlocking(value listener)
{
    return Val_bool(
        SfTcpListener_val(listener)->isBlocking());
}

CAMLextern_C value
caml_sfTcpListener_getLocalPort(value listener)
{
    unsigned short port = SfTcpListener_val(listener)->getLocalPort();
    return Val_long(port);
}

CAMLextern_C value
caml_sfTcpListener_listen(value listener, value port)
{
    sf::Socket::Status st = SfTcpListener_val(listener)->listen(Int_val(port));
    check_sfSocketStatus(st, "SFTcpListener")
    return Val_unit;
}

CAMLextern_C value
caml_sfTcpListener_accept(value listener)
{
    sf::TcpSocket *connected = new sf::TcpSocket;
    sf::Socket::Status st = SfTcpListener_val(listener)->accept(*connected);
    if (st != sf::Socket::Done) delete connected;
    check_sfSocketStatus(st, "SFTcpListener")
    if (connected == NULL) caml_failwith("SFTcpListener.accept");
    return Val_sfTcpSocket(connected);
}

// vim: sw=4 sts=4 ts=4 et
