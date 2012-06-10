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

#include <SFML/Network/Selector.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <string.h>


#define SfSelectorTCP_val(s) ((sfSelectorTCP *)(s))
#define Val_sfSelectorTCP(s) ((value)(s))

#define SfSelectorUDP_val(s) ((sfSelectorUDP *)(s))
#define Val_sfSelectorUDP(s) ((value)(s))

#include "sfSocket_stubs.h"

CAMLprim value
caml_sfSelectorTCP_Create(value unit)
{
    sfSelectorTCP *sel = sfSelectorTCP_Create();
    return Val_sfSelectorTCP(sel);
}

CAMLprim value
caml_sfSelectorUDP_Create(value unit)
{
    sfSelectorUDP *sel = sfSelectorUDP_Create();
    return Val_sfSelectorUDP(sel);
}

CAMLprim value
caml_sfSelectorTCP_Destroy(value selector)
{
    sfSelectorTCP_Destroy(SfSelectorTCP_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorUDP_Destroy(value selector)
{
    sfSelectorUDP_Destroy(SfSelectorUDP_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorTCP_Add(value selector, value socket)
{
    sfSelectorTCP_Add(SfSelectorTCP_val(selector), SfSocketTCP_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorUDP_Add(value selector, value socket)
{
    sfSelectorUDP_Add(SfSelectorUDP_val(selector), SfSocketUDP_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorTCP_Remove(value selector, value socket)
{
    sfSelectorTCP_Remove(SfSelectorTCP_val(selector), SfSocketTCP_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorUDP_Remove(value selector, value socket)
{
    sfSelectorUDP_Remove(SfSelectorUDP_val(selector), SfSocketUDP_val(socket));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorTCP_Clear(value selector)
{
    sfSelectorTCP_Clear(SfSelectorTCP_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorUDP_Clear(value selector)
{
    sfSelectorUDP_Clear(SfSelectorUDP_val(selector));
    return Val_unit;
}

CAMLprim value
caml_sfSelectorTCP_Wait(value selector, value timeout)
{
    unsigned int n = sfSelectorTCP_Wait(SfSelectorTCP_val(selector), Double_val(timeout));
    return Val_long(n);
}

CAMLprim value
caml_sfSelectorUDP_Wait(value selector, value timeout)
{
    unsigned int n = sfSelectorUDP_Wait(SfSelectorUDP_val(selector), Double_val(timeout));
    return Val_long(n);
}

CAMLprim value
caml_sfSelectorTCP_GetSocketReady(value selector, value index)
{
    sfSocketTCP *sock = sfSelectorTCP_GetSocketReady(SfSelectorTCP_val(selector), Long_val(index));
    return Val_sfSocketTCP(sock);
}

CAMLprim value
caml_sfSelectorUDP_GetSocketReady(value selector, value index)
{
    sfSocketUDP *sock = sfSelectorUDP_GetSocketReady(SfSelectorUDP_val(selector), Long_val(index));
    return Val_sfSocketUDP(sock);
}

/* vim: sw=4 sts=4 ts=4 et
 */
