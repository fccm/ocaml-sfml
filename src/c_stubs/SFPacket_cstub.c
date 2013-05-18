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

#include <SFML/Network/Packet.h>

#include <string.h>

#include "sf_caml_incs_c.h"
#include "SFPacket_cstub.h"

CAMLprim value
caml_sfPacket_create(value unit)
{
    sfPacket *p = sfPacket_create();
    return Val_sfPacket(p);
}

CAMLprim value
caml_sfPacket_destroy(value packet)
{
    sfPacket_clear(SfPacket_val(packet));
    sfPacket_destroy(SfPacket_val(packet));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_copy(value packet)
{
    sfPacket *p = sfPacket_copy(SfPacket_val(packet));
    return Val_sfPacket(p);
}

CAMLprim value
caml_sfPacket_append(value packet, value data)
{
    sfPacket_append(SfPacket_val(packet),
            String_val(data), caml_string_length(data));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_clear(value packet)
{
    sfPacket_clear(SfPacket_val(packet));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_getData(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    size_t size = sfPacket_getDataSize(SfPacket_val(packet));
    const char *ptr = sfPacket_getData(SfPacket_val(packet));
    str = caml_alloc_string(size);
    memcpy(String_val(str), ptr, size);
    CAMLreturn(str);
}

CAMLprim value
caml_sfPacket_endOfPacket(value packet)
{
    sfBool b = sfPacket_endOfPacket(SfPacket_val(packet));
    return Val_bool(b);
}

CAMLprim value
caml_sfPacket_canRead(value packet)
{
    sfBool b = sfPacket_canRead(SfPacket_val(packet));
    return Val_bool(b);
}

#define caml_sfPacket_write(f,s,conv) \
  CAMLprim value caml_##f##s(value packet, value v) { \
    f(SfPacket_val(packet), conv(v)); \
    return Val_unit; \
  }

caml_sfPacket_write(sfPacket_writeBool,, Bool_val)
caml_sfPacket_write(sfPacket_writeFloat,, Double_val)
caml_sfPacket_write(sfPacket_writeDouble,, Double_val)
caml_sfPacket_write(sfPacket_writeInt8,, Long_val)
caml_sfPacket_write(sfPacket_writeUint8,, Long_val)
caml_sfPacket_write(sfPacket_writeInt16,, Long_val)
caml_sfPacket_write(sfPacket_writeUint16,, Long_val)
caml_sfPacket_write(sfPacket_writeInt32,, Long_val)
caml_sfPacket_write(sfPacket_writeInt32,_l, Int32_val)

#define caml_sfPacket_read(f,s,t,conv) \
  CAMLprim value caml_##f##s(value packet) { \
    t v = f(SfPacket_val(packet)); \
    return conv(v); \
  }

caml_sfPacket_read(sfPacket_readBool,, sfBool, Val_bool)
caml_sfPacket_read(sfPacket_readFloat,, float, caml_copy_double)
caml_sfPacket_read(sfPacket_readDouble,, double, caml_copy_double)
caml_sfPacket_read(sfPacket_readInt8,, sfInt8, Val_long)
caml_sfPacket_read(sfPacket_readUint8,, sfUint8, Val_long)
caml_sfPacket_read(sfPacket_readInt16,, sfInt16, Val_long)
caml_sfPacket_read(sfPacket_readUint16,, sfUint16, Val_long)
caml_sfPacket_read(sfPacket_readInt32,_l, sfInt32, caml_copy_int32)

#define CAML_INT31_MIN (-1073741824)
#define CAML_INT31_MAX (1073741823)

CAMLprim value
caml_sfPacket_readInt31(value packet)
{
    sfInt32 v = sfPacket_readInt32(SfPacket_val(packet));
    if (v < CAML_INT31_MIN || v > CAML_INT31_MAX)
        caml_failwith("SFPacket.readInt31:"
            " Integer literal exceeds the range of"
            " representable integers of type int");
    return Val_long(v);
}

CAMLprim value
caml_sfPacket_readString(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    sfUint32 size = sfPacket_readUint32(SfPacket_val(packet));
    str = caml_alloc_string(size);
    sfPacket_readString(SfPacket_val(packet), String_val(str));
    CAMLreturn(str);
}

CAMLprim value
caml_sfPacket_writeString(value packet, value s)
{
    sfPacket_writeUint32(SfPacket_val(packet), caml_string_length(s));
    sfPacket_writeString(SfPacket_val(packet), String_val(s));
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

/* vim: sw=4 sts=4 ts=4 et
 */
