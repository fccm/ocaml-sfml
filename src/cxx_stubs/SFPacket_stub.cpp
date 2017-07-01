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

#include <SFML/Network/Packet.hpp>

#include <cstring>

#include "sf_caml_incs.hpp"
#include "SFPacket_stub.hpp"

CAMLextern_C value
caml_sfPacket_create(value unit)
{
    sf::Packet *p = new sf::Packet;
    return Val_sfPacket(p);
}

CAMLextern_C value
caml_sfPacket_destroy(value packet)
{
    SfPacket_val(packet)->clear();
    delete SfPacket_val(packet);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# packet deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfPacket_copy(value packet)
{
    sf::Packet *p = new sf::Packet(*SfPacket_val(packet));
    return Val_sfPacket(p);
}

CAMLextern_C value
caml_sfPacket_append(value packet, value data)
{
    SfPacket_val(packet)->append(
            String_val(data), caml_string_length(data));
    return Val_unit;
}

CAMLextern_C value
caml_sfPacket_clear(value packet)
{
    SfPacket_val(packet)->clear();
    return Val_unit;
}

CAMLextern_C value
caml_sfPacket_getData(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    const std::size_t size = SfPacket_val(packet)->getDataSize();
    const void *ptr = SfPacket_val(packet)->getData();
    str = caml_alloc_string(size);
    memcpy(String_val(str), ptr, size);
    CAMLreturn(str);
}

CAMLextern_C value
caml_sfPacket_endOfPacket(value packet)
{
    bool b = SfPacket_val(packet)->endOfPacket();
    return Val_bool(b);
}

CAMLextern_C value
caml_sfPacket_canRead(value packet)
{
    if (SfPacket_val(packet))
        return Val_true;
    else
        return Val_false;
}

#define caml_sfPacket_write(f,s,t,conv) \
  CAMLextern_C value caml_##f##s(value packet, value mlv) { \
    t v = conv(mlv); \
    *SfPacket_val(packet) << v; \
    return Val_unit; \
  }

caml_sfPacket_write(sfPacket_writeBool,, bool, Bool_val)
caml_sfPacket_write(sfPacket_writeFloat,, float, Double_val)
caml_sfPacket_write(sfPacket_writeDouble,, double, Double_val)
caml_sfPacket_write(sfPacket_writeInt8,, sf::Int8, Long_val)
caml_sfPacket_write(sfPacket_writeUint8,, sf::Uint8, Long_val)
caml_sfPacket_write(sfPacket_writeInt16,, sf::Int16, Long_val)
caml_sfPacket_write(sfPacket_writeUint16,, sf::Uint16, Long_val)
caml_sfPacket_write(sfPacket_writeInt32,, sf::Int32, Long_val)
caml_sfPacket_write(sfPacket_writeInt32,_l, sf::Int32, Int32_val)
caml_sfPacket_write(sfPacket_writeInt64,, sf::Int64, Int64_val)

#define caml_sfPacket_read(f,s,t,conv) \
  CAMLextern_C value caml_##f##s(value packet) { \
    t v; \
    *SfPacket_val(packet) >> v; \
    return conv(v); \
  }

caml_sfPacket_read(sfPacket_readBool,, bool, Val_bool)
caml_sfPacket_read(sfPacket_readFloat,, float, caml_copy_double)
caml_sfPacket_read(sfPacket_readDouble,, double, caml_copy_double)
caml_sfPacket_read(sfPacket_readInt8,, sf::Int8, Val_long)
caml_sfPacket_read(sfPacket_readUint8,, sf::Uint8, Val_long)
caml_sfPacket_read(sfPacket_readInt16,, sf::Int16, Val_long)
caml_sfPacket_read(sfPacket_readUint16,, sf::Uint16, Val_long)
caml_sfPacket_read(sfPacket_readInt32,_l, sf::Int32, caml_copy_int32)
caml_sfPacket_read(sfPacket_readInt32,, sf::Int64, caml_copy_int64)

#define CAML_INT31_MIN (-1073741824)
#define CAML_INT31_MAX (1073741823)

CAMLextern_C value
caml_sfPacket_readInt31(value packet)
{
    sf::Int32 v;
    *SfPacket_val(packet) >> v;
    if (v < CAML_INT31_MIN || v > CAML_INT31_MAX)
        caml_failwith("SFPacket.readInt31:"
            " Integer literal exceeds the range of"
            " representable integers of type int");
    return Val_long(v);
}

#include <iostream>
CAMLextern_C value
caml_sfPacket_readString(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    std::string s;
    sf::Uint32 len;
    *SfPacket_val(packet) >> len;
    *SfPacket_val(packet) >> s;
    //std::size_t size = strlen(s);
    // XXX: DEBUG
    //std::cout << "readString, got: " << size << std::endl << std::flush;
    std::size_t size = s.size();
    if (size != len) {
        caml_failwith("SFPacket.readString: length mismatch");
    }
    str = caml_alloc_string(size);
    std::cout << "## Before memcpy" << std::endl << std::flush;
    memcpy(String_val(str), s.c_str(), size);
    std::cout << "## After memcpy" << std::endl << std::flush;
    CAMLreturn(str);
}

CAMLextern_C value
caml_sfPacket_writeString(value packet, value str)
{
    char *s = String_val(str);
    sf::Uint32 len = caml_string_length(str);
    *SfPacket_val(packet) << len;
    *SfPacket_val(packet) << s;
    return Val_unit;
}

/* TODO
void sfPacket_writeUint32(sfPacket* packet, sfUint32);
sfUint32 sfPacket_readUint32(sfPacket* packet);
void sfPacket_writeString(sfPacket* packet, const char* string);
void sfPacket_readString(sfPacket* packet, char* string);
void sfPacket_writeWideString(sfPacket* packet, const wchar_t* string);
void sfPacket_readWideString(sfPacket* packet, wchar_t* string);
*/

// vim: sw=4 sts=4 ts=4 et
