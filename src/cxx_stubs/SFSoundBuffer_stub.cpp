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

#include <SFML/Audio/SoundBuffer.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFSoundBuffer_stub.hpp"
#include "SFTime_stub.hpp"


/* sf::SoundBuffer */

CAMLextern_C value
caml_sfSoundBuffer_loadFromFile(value filename)
{
    sf::SoundBuffer *sbf = new sf::SoundBuffer;
    bool r = sbf->loadFromFile(String_val(filename));
    if (!r) caml_failwith("SFSoundBuffer.loadFromFile");
    return Val_sfSoundBuffer(sbf);
}

CAMLextern_C value
caml_sfSoundBuffer_loadFromMemory(value data)
{
    sf::SoundBuffer *sbf = new sf::SoundBuffer;
    bool r = sbf->loadFromMemory(String_val(data), caml_string_length(data));
    if (!r) caml_failwith("SFSoundBuffer.loadFromMemory");
    return Val_sfSoundBuffer(sbf);
}

CAMLextern_C value
caml_sfSoundBuffer_loadFromSamples(
        value samples, value channelCount, value sampleRate)
{
    sf::Int16* _samples = static_cast<sf::Int16*>Caml_ba_data_val(samples);
    std::size_t sampleCount = caml_ba_byte_size(Caml_ba_array_val(samples)) / 2;
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# SFSoundBuffer.loadFromSamples: "
              << sampleCount
              << std::endl << std::flush;  // DEBUG
#endif
    sf::SoundBuffer *sbf = new sf::SoundBuffer;
    bool r = sbf->loadFromSamples(
            _samples, sampleCount,
            UInt_val(channelCount), UInt_val(sampleRate));
    if (!r) caml_failwith("SFSoundBuffer.loadFromSamples");
    return Val_sfSoundBuffer(sbf);
}

CAMLextern_C value
caml_sfSoundBuffer_destroy(value soundBuffer)
{
    delete SfSoundBuffer_val(soundBuffer);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# soundBuffer deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfSoundBuffer_getSampleCount(value soundBuffer)
{
    std::size_t samplesCount = SfSoundBuffer_val(soundBuffer)->getSampleCount();
    return Val_long(samplesCount);
}

CAMLextern_C value
caml_sfSoundBuffer_getSampleRate(value soundBuffer)
{
    unsigned int sampleRate = SfSoundBuffer_val(soundBuffer)->getSampleRate();
    return Val_long(sampleRate);
}

CAMLextern_C value
caml_sfSoundBuffer_getChannelCount(value soundBuffer)
{
    unsigned int channelsCount =
        SfSoundBuffer_val(soundBuffer)->getChannelCount();
    return Val_long(channelsCount);
}

CAMLextern_C value
caml_sfSoundBuffer_getDuration(value soundBuffer)
{
    sf::Time duration = SfSoundBuffer_val(soundBuffer)->getDuration();
    return Val_sfTime(duration);
}

CAMLextern_C value
caml_sfSoundBuffer_saveToFile(value soundBuffer, value filename)
{
    bool saved = SfSoundBuffer_val(soundBuffer)->saveToFile(String_val(filename));
    if (!saved) caml_failwith("SFSoundBuffer.saveToFile");
    return Val_unit;
}

/* TODO
sfSoundBuffer* sfSoundBuffer_createFromStream(sfInputStream* stream);
sfSoundBuffer* sfSoundBuffer_copy(sfSoundBuffer* soundBuffer);
const sfInt16* sfSoundBuffer_getSamples(const sfSoundBuffer* soundBuffer);
*/

// vim: sw=4 sts=4 ts=4 et
