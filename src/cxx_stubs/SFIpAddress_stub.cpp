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

#include <SFML/Network/IpAddress.hpp>

#include "sf_caml_incs.hpp"
#include "SFIpAddress_stub.hpp"
#include "SFTime_stub.hpp"

value
Val_sfIpAddress(const sf::IpAddress& address)
{
    CAMLparam0();
    CAMLlocal1(addr);
    addr = caml_copy_string(address.toString().c_str());
    CAMLreturn(addr);
}

sf::IpAddress
SfIpAddress_val(value addr)
{
    return sf::IpAddress(String_val(addr));
}

CAMLextern_C value
caml_sfIpAddress_fromString(value str)
{
    sf::IpAddress addr = sf::IpAddress(String_val(str));
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_fromBytes(value b0, value b1, value b2, value b3)
{
    sf::IpAddress addr = sf::IpAddress(
            Long_val(b0), Long_val(b1), Long_val(b2), Long_val(b3));
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_fromInteger(value int_addr)
{
    sf::IpAddress addr = sf::IpAddress(
            ((sf::Uint32) Int32_val(int_addr)));
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_toString(value addr)
{
    CAMLparam1(addr);
    CAMLlocal1(ml_str);
    ml_str = caml_copy_string(
            SfIpAddress_val(addr).toString().c_str());
    CAMLreturn(ml_str);
}

CAMLextern_C value
caml_sfIpAddress_toInteger(value addr)
{
    sf::Uint32 int_addr = SfIpAddress_val(addr).toInteger();
    return caml_copy_int32(int_addr);
}

CAMLextern_C value
caml_sfIpAddress_getLocalAddress(value unit)
{
    sf::IpAddress addr = sf::IpAddress::getLocalAddress();
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_getPublicAddress(value timeout)
{
    //sf::IpAddress addr = sf::IpAddress::getPublicAddress();  // TODO
    sf::IpAddress addr = sf::IpAddress::getPublicAddress(*SfTime_val_u(timeout));
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_localHost(value unit)
{
    sf::IpAddress addr = sf::IpAddress::LocalHost;
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_None(value unit)
{
    sf::IpAddress addr = sf::IpAddress::None;
    return Val_sfIpAddress(addr);
}

CAMLextern_C value
caml_sfIpAddress_Broadcast(value unit)
{
    sf::IpAddress addr = sf::IpAddress::Broadcast;
    return Val_sfIpAddress(addr);
}

// vim: sw=4 sts=4 ts=4 et
