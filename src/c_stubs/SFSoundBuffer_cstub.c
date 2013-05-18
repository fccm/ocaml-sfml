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

#include <SFML/Audio/SoundBuffer.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFSoundBuffer_cstub.h"
#include "SFTime_cstub.h"


/* sfSoundBuffer */

CAMLprim value
caml_sfSoundBuffer_loadFromFile(value filename)
{
    sfSoundBuffer *sbf = sfSoundBuffer_createFromFile(String_val(filename));
    if (sbf == NULL) caml_failwith("SFSoundBuffer.loadFromFile");
    return Val_sfSoundBuffer(sbf);
}

CAMLprim value
caml_sfSoundBuffer_loadFromMemory(value data)
{
    sfSoundBuffer *sbf =
        sfSoundBuffer_createFromMemory(
            String_val(data), caml_string_length(data));
    if (sbf == NULL) caml_failwith("SFSoundBuffer.loadFromMemory");
    return Val_sfSoundBuffer(sbf);
}

CAMLprim value
caml_sfSoundBuffer_loadFromSamples(
        value samples, value channelCount, value sampleRate)
{
    sfInt16* _samples = Caml_ba_data_val(samples);
    size_t sampleCount = caml_ba_byte_size(Caml_ba_array_val(samples)) / 2;
    sfSoundBuffer *sbf =
        sfSoundBuffer_createFromSamples(
            _samples, sampleCount, UInt_val(channelCount), UInt_val(sampleRate));
    if (sbf == NULL) caml_failwith("SFSoundBuffer.loadFromSamples");
    return Val_sfSoundBuffer(sbf);
}

CAMLprim value
caml_sfSoundBuffer_destroy(value soundBuffer)
{
    sfSoundBuffer_destroy(SfSoundBuffer_val(soundBuffer));
    return Val_unit;
}

CAMLprim value
caml_sfSoundBuffer_getSampleCount(value soundBuffer)
{
    size_t samplesCount =
        sfSoundBuffer_getSampleCount(SfSoundBuffer_val(soundBuffer));
    return Val_long(samplesCount);
}

CAMLprim value
caml_sfSoundBuffer_getSampleRate(value soundBuffer)
{
    unsigned int sampleRate =
        sfSoundBuffer_getSampleRate(SfSoundBuffer_val(soundBuffer));
    return Val_long(sampleRate);
}

CAMLprim value
caml_sfSoundBuffer_getChannelCount(value soundBuffer)
{
    unsigned int channelsCount =
        sfSoundBuffer_getChannelCount(SfSoundBuffer_val(soundBuffer));
    return Val_long(channelsCount);
}

CAMLprim value
caml_sfSoundBuffer_getDuration(value soundBuffer)
{
    sfTime duration = sfSoundBuffer_getDuration(SfSoundBuffer_val(soundBuffer));
    return Val_sfTime_u(&duration);
}

CAMLprim value
caml_sfSoundBuffer_saveToFile(value soundBuffer, value filename)
{
    sfBool saved = sfSoundBuffer_saveToFile(
            SfSoundBuffer_val(soundBuffer), String_val(filename));
    if (!saved) caml_failwith("SFSoundBuffer.saveToFile");
    return Val_unit;
}

/* TODO
sfSoundBuffer* sfSoundBuffer_createFromStream(sfInputStream* stream);

sfSoundBuffer* sfSoundBuffer_copy(sfSoundBuffer* soundBuffer);
const sfInt16* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
