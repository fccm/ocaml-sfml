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

#include <SFML/Network/Packet.h>

#include <string.h>

#define CAML_NAME_SPACE

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>

#include "sfPacket_stubs.h"

CAMLprim value
caml_sfPacket_Create(value unit)
{
    sfPacket *p = sfPacket_Create();
    return Val_sfPacket(p);
}

CAMLprim value
caml_sfPacket_Destroy(value packet)
{
    sfPacket_Destroy(SfPacket_val(packet));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_Append(value packet, value data)
{
    sfPacket_Append(SfPacket_val(packet), String_val(data), caml_string_length(data));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_Clear(value packet)
{
    sfPacket_Clear(SfPacket_val(packet));
    return Val_unit;
}

CAMLprim value
caml_sfPacket_GetData(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    size_t size = sfPacket_GetDataSize(SfPacket_val(packet));
    const char *ptr = sfPacket_GetData(SfPacket_val(packet));
    str = caml_alloc_string(size);
    memcpy(String_val(str), ptr, size);
    CAMLreturn(str);
}

CAMLprim value
caml_sfPacket_EndOfPacket(value packet)
{
    sfBool b = sfPacket_EndOfPacket(SfPacket_val(packet));
    return Val_bool(b);
}

CAMLprim value
caml_sfPacket_CanRead(value packet)
{
    sfBool b = sfPacket_CanRead(SfPacket_val(packet));
    return Val_bool(b);
}

#define caml_sfPacket_Write(f,s,conv) \
  CAMLprim value caml_##f##s(value packet, value v) { \
    f(SfPacket_val(packet), conv(v)); \
    return Val_unit; \
  }

caml_sfPacket_Write(sfPacket_WriteBool,, Bool_val)
caml_sfPacket_Write(sfPacket_WriteFloat,, Double_val)
caml_sfPacket_Write(sfPacket_WriteDouble,, Double_val)
caml_sfPacket_Write(sfPacket_WriteInt8,, Long_val)
caml_sfPacket_Write(sfPacket_WriteUint8,, Long_val)
caml_sfPacket_Write(sfPacket_WriteInt16,, Long_val)
caml_sfPacket_Write(sfPacket_WriteUint16,, Long_val)
caml_sfPacket_Write(sfPacket_WriteInt32,, Long_val)
caml_sfPacket_Write(sfPacket_WriteInt32,_l, Int32_val)

#define caml_sfPacket_Read(f,s,t,conv) \
  CAMLprim value caml_##f##s(value packet) { \
    t v = f(SfPacket_val(packet)); \
    return conv(v); \
  }

caml_sfPacket_Read(sfPacket_ReadBool,, sfBool, Val_bool)
caml_sfPacket_Read(sfPacket_ReadFloat,, float, caml_copy_double)
caml_sfPacket_Read(sfPacket_ReadDouble,, double, caml_copy_double)
caml_sfPacket_Read(sfPacket_ReadInt8,, sfInt8, Val_long)
caml_sfPacket_Read(sfPacket_ReadUint8,, sfUint8, Val_long)
caml_sfPacket_Read(sfPacket_ReadInt16,, sfInt16, Val_long)
caml_sfPacket_Read(sfPacket_ReadUint16,, sfUint16, Val_long)
caml_sfPacket_Read(sfPacket_ReadInt32,_l, sfInt32, caml_copy_int32)

#define CAML_INT31_MIN (-1073741824)
#define CAML_INT31_MAX (1073741823)

CAMLprim value
caml_sfPacket_ReadInt31(value packet)
{
    sfInt32 v = sfPacket_ReadInt32(SfPacket_val(packet));
    if (v < CAML_INT31_MIN || v > CAML_INT31_MAX)
        caml_failwith("SFPacket.readInt31:"
            " Integer literal exceeds the range of"
            " representable integers of type int");
    return Val_long(v);
}

CAMLprim value
caml_sfPacket_ReadString(value packet)
{
    CAMLparam1(packet);
    CAMLlocal1(str);
    sfUint32 size = sfPacket_ReadUint32(SfPacket_val(packet));
    str = caml_alloc_string(size);
    sfPacket_ReadString(SfPacket_val(packet), String_val(str));
    CAMLreturn(str);
}

CAMLprim value
caml_sfPacket_WriteString(value packet, value s)
{
    sfPacket_WriteUint32(SfPacket_val(packet), caml_string_length(s));
    sfPacket_WriteString(SfPacket_val(packet), String_val(s));
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
