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

#include <SFML/Network/SocketSelector.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFUdpSocket_cstub.h"
#include "SFTcpListener_cstub.h"
#include "SFTcpSocket_cstub.h"
#include "SFSocket_cstub.h"
#include "SFTime_cstub.h"

#include <string.h>

#define SfSocketSelector_val(s) ((sfSocketSelector *)(s))
#define Val_sfSocketSelector(s) ((value)(s))

CAMLprim value
caml_sfSocketSelector_create(value unit)
{
    sfSocketSelector *selector = sfSocketSelector_create();
    return Val_sfSocketSelector(selector);
}

CAMLprim value
caml_sfSocketSelector_copy(value selector)
{
    sfSocketSelector *sel =
        sfSocketSelector_copy(SfSocketSelector_val(selector));
    return Val_sfSocketSelector(sel);
}

CAMLprim value
caml_sfSocketSelector_destroy(value selector)
{
    sfSocketSelector_destroy(SfSocketSelector_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSocketSelector_addTcpListener(value selector, value socket)
{
    sfSocketSelector_addTcpListener(
            SfSocketSelector_val(selector), SfTcpListener_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSocketSelector_addTcpSocket(value selector, value socket)
{
    sfSocketSelector_addTcpSocket(
            SfSocketSelector_val(selector), SfTcpSocket_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSocketSelector_addUdpSocket(value selector, value socket)
{
    sfSocketSelector_addUdpSocket(
            SfSocketSelector_val(selector), SfUdpSocket_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSocketSelector_clear(value selector)
{
    sfSocketSelector_clear(SfSocketSelector_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSocketSelector_wait(value selector, value timeout)
{
    if (timeout == Val_none)
        return Val_bool(
            sfSocketSelector_wait(
                SfSocketSelector_val(selector), sfTime_Zero));

    return Val_bool(
        sfSocketSelector_wait(
            SfSocketSelector_val(selector), SfTime_val(Some_val(timeout))));
}

CAMLprim value
caml_sfSocketSelector_isTcpListenerReady(value selector, value socket)
{
    return Val_bool(
        sfSocketSelector_isTcpListenerReady(
            SfSocketSelector_val(selector), SfTcpListener_val(socket)));
}

CAMLprim value
caml_sfSocketSelector_isTcpSocketReady(value selector, value socket)
{
    return Val_bool(
        sfSocketSelector_isTcpSocketReady(
            SfSocketSelector_val(selector), SfTcpSocket_val(socket)));
}

CAMLprim value
caml_sfSocketSelector_isUdpSocketReady(value selector, value socket)
{
    return Val_bool(
        sfSocketSelector_isUdpSocketReady(
            SfSocketSelector_val(selector), SfUdpSocket_val(socket)));
}

CAMLprim value
caml_sfSocketSelector_removeTcpSocket(value selector, value socket)
{
    sfSocketSelector_removeTcpSocket(
            SfSocketSelector_val(selector), SfTcpSocket_val(socket));
    return Val_unit;
}

/* TODO
void sfSocketSelector_removeTcpListener(
        sfSocketSelector* selector, sfTcpListener* socket);

void sfSocketSelector_removeUdpSocket(
        sfSocketSelector* selector, sfUdpSocket* socket);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
