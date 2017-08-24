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

#include <SFML/Network/SocketSelector.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFTcpListener_stub.hpp"
#include "SFTcpSocket_stub.hpp"
#include "SFUdpSocket_stub.hpp"
#include "SFTime_stub.hpp"

#define SfSocketSelector_val(s) ((sf::SocketSelector *)(s))
#define Val_sfSocketSelector(s) ((value)(s))

CAMLextern_C value
caml_sfSocketSelector_create(value unit)
{
    sf::SocketSelector *selector = new sf::SocketSelector();
    return Val_sfSocketSelector(selector);
}

CAMLextern_C value
caml_sfSocketSelector_copy(value selector)
{
    sf::SocketSelector *sel =
        new sf::SocketSelector(*SfSocketSelector_val(selector));
    return Val_sfSocketSelector(sel);
}

CAMLextern_C value
caml_sfSocketSelector_destroy(value selector)
{
    delete SfSocketSelector_val(selector);
    return Val_unit;
}

CAMLextern_C value
caml_sfSocketSelector_addTcpListener(value selector, value socket)
{
    SfSocketSelector_val(selector)->add(*SfTcpListener_val(socket));
    return Val_unit;
}

CAMLextern_C value
caml_sfSocketSelector_addTcpSocket(value selector, value socket)
{
    SfSocketSelector_val(selector)->add(*SfTcpSocket_val(socket));
    return Val_unit;
}

CAMLextern_C value
caml_sfSocketSelector_addUdpSocket(value selector, value socket)
{
    SfSocketSelector_val(selector)->add(*SfUdpSocket_val(socket));
    return Val_unit;
}

CAMLextern_C value
caml_sfSocketSelector_clear(value selector)
{
    SfSocketSelector_val(selector)->clear();
    return Val_unit;
}

CAMLextern_C value
caml_sfSocketSelector_wait(value selector, value timeout, value unit)
{
    if (timeout == Val_none)
        return Val_bool(
            SfSocketSelector_val(selector)->wait());
    else
        return Val_bool(
            SfSocketSelector_val(selector)->wait(
                SfTime_val(Some_val(timeout))));
}

CAMLextern_C value
caml_sfSocketSelector_isTcpListenerReady(value selector, value socket)
{
    return Val_bool(
        SfSocketSelector_val(selector)->isReady(
            *SfTcpListener_val(socket)));
}

CAMLextern_C value
caml_sfSocketSelector_isTcpSocketReady(value selector, value socket)
{
    return Val_bool(
        SfSocketSelector_val(selector)->isReady(
            *SfTcpSocket_val(socket)));
}

CAMLextern_C value
caml_sfSocketSelector_isUdpSocketReady(value selector, value socket)
{
    return Val_bool(
        SfSocketSelector_val(selector)->isReady(
            *SfUdpSocket_val(socket)));
}

CAMLextern_C value
caml_sfSocketSelector_removeTcpSocket(value selector, value socket)
{
    SfSocketSelector_val(selector)->remove(
            *SfTcpSocket_val(socket));
    return Val_unit;
}

/* TODO
void sfSocketSelector_removeTcpListener(
        sfSocketSelector* selector, sfTcpListener* socket);

void sfSocketSelector_removeUdpSocket(
        sfSocketSelector* selector, sfUdpSocket* socket);
*/

// vim: sw=4 sts=4 ts=4 et
