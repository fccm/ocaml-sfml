/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2010 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Network/TcpListener.h>

#include "sf_caml_incs_c.h"
#include "SFTcpListener_cstub.h"
#include "SFTcpSocket_cstub.h"
#include "SFSocket_cstub.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


CAMLprim value
caml_sfTcpListener_create(value unit)
{
	sfTcpListener *list = sfTcpListener_create();
	return Val_sfTcpListener(list);
}

CAMLprim value
caml_sfTcpListener_destroy(value listener)
{
    sfTcpListener_destroy(SfTcpListener_val(listener));
    return Val_unit;
}

CAMLprim value
caml_sfTcpListener_setBlocking(value listener, value blocking)
{
    sfTcpListener_setBlocking(SfTcpListener_val(listener), Bool_val(blocking));
    return Val_unit;
}

CAMLprim value
caml_sfTcpListener_isBlocking(value listener)
{
    return Val_bool(
        sfTcpListener_isBlocking(SfTcpListener_val(listener)));
}

CAMLprim value
caml_sfTcpListener_getLocalPort(value listener)
{
    unsigned short port = sfTcpListener_getLocalPort(SfTcpListener_val(listener));
    return Val_long(port);
}

CAMLprim value
caml_sfTcpListener_listen(value listener, value port)
{
    sfSocketStatus st = sfTcpListener_listen(SfTcpListener_val(listener), Int_val(port));
    check_sfSocketStatus(st, "SFTcpListener")
    return Val_unit;
}

CAMLprim value
caml_sfTcpListener_accept(value listener)
{
    sfTcpSocket *connected = NULL;
    sfSocketStatus st = sfTcpListener_accept(SfTcpListener_val(listener), &connected);
    check_sfSocketStatus(st, "SFTcpListener")
    if (connected == NULL) caml_failwith("SFTcpListener.accept");
    return Val_sfTcpSocket(connected);
}

/* vim: sw=4 sts=4 ts=4 et
 */
