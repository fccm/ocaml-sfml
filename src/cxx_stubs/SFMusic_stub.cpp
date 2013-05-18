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

#include <SFML/Audio/Music.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFTime_stub.hpp"

#define Val_sfMusic(music) ((value)(music))
#define SfMusic_val(music) ((sf::Music *)(music))

static value
Val_sfMusicStatus(sf::Music::Status sndst)
{
    switch (sndst)
    {
        case sf::Music::Stopped: return Val_int(0);
        case sf::Music::Paused:  return Val_int(1);
        case sf::Music::Playing: return Val_int(2);
        default: caml_failwith("SFSound.sound_status");
    }
    caml_failwith("SFSound.sound_status");
}

/* sf::Music */

CAMLextern_C value
caml_sfMusic_openFromFile(value filename)
{
    sf::Music *music = new sf::Music;
    if (!music->openFromFile(String_val(filename))) {
        delete music;
        caml_failwith("SFMusic.createFromFile");
    }
    return Val_sfMusic(music);
}

CAMLextern_C value
caml_sfMusic_openFromMemory(value data)
{
    sf::Music *music = new sf::Music;
    if (!music->openFromMemory(String_val(data), caml_string_length(data))) {
        delete music;
        caml_failwith("SFMusic.createFromMemory");
    }
    return Val_sfMusic(music);
}

CAMLextern_C value
caml_sfMusic_destroy(value music)
{
    delete SfMusic_val(music);
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getDuration(value music)
{
    sf::Time duration = SfMusic_val(music)->getDuration();
    return Val_sfTime_u(duration);
}

CAMLextern_C value
caml_sfMusic_play(value music)
{
    SfMusic_val(music)->play();
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_pause(value music)
{
    SfMusic_val(music)->pause();
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_stop(value music)
{
    SfMusic_val(music)->stop();
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getChannelCount(value music)
{
    unsigned int channelsCount = SfMusic_val(music)->getChannelCount();
    return Val_long(channelsCount);
}

CAMLextern_C value
caml_sfMusic_getSampleRate(value music)
{
    unsigned int sampleRate = SfMusic_val(music)->getSampleRate();
    return Val_long(sampleRate);
}

CAMLextern_C value
caml_sfMusic_getStatus(value music)
{
    sf::Music::Status sndst = SfMusic_val(music)->getStatus();
    return Val_sfMusicStatus(sndst);
}

CAMLextern_C value
caml_sfMusic_setPlayingOffset(value music, value timeOffset)
{
    SfMusic_val(music)->setPlayingOffset(*SfTime_val_u(timeOffset));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getPlayingOffset(value music)
{
    sf::Time playingOffset = SfMusic_val(music)->getPlayingOffset();
    return Val_sfTime_u(playingOffset);
}

CAMLextern_C value
caml_sfMusic_setLoop(value music, value loop)
{
    SfMusic_val(music)->setLoop(Bool_val(loop));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getLoop(value music)
{
    bool loop = SfMusic_val(music)->getLoop();
    return Val_bool(loop);
}

///////////////////////////////////////////

CAMLextern_C value
caml_sfMusic_setVolume(value music, value volume)
{
    SfMusic_val(music)->setVolume(Double_val(volume));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getVolume(value music)
{
    float volume = SfMusic_val(music)->getVolume();
    return caml_copy_double(volume);
}

CAMLextern_C value
caml_sfMusic_setPitch(value music, value pitch)
{
    SfMusic_val(music)->setPitch(Double_val(pitch));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getPitch(value music)
{
    float pitch = SfMusic_val(music)->getPitch();
    return caml_copy_double(pitch);
}

CAMLextern_C value
caml_sfMusic_setRelativeToListener(value music, value relative)
{
    SfMusic_val(music)->setRelativeToListener(Bool_val(relative));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_isRelativeToListener(value music)
{
    return Val_bool(
        SfMusic_val(music)->isRelativeToListener());
}

CAMLextern_C value
caml_sfMusic_setMinDistance(value music, value minDistance)
{
    SfMusic_val(music)->setMinDistance(Double_val(minDistance));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getMinDistance(value music)
{
    float minDistance = SfMusic_val(music)->getMinDistance();
    return caml_copy_double(minDistance);
}

CAMLextern_C value
caml_sfMusic_setAttenuation(value music, value attenuation)
{
    SfMusic_val(music)->setAttenuation(Double_val(attenuation));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getAttenuation(value music)
{
    float attenuation = SfMusic_val(music)->getAttenuation();
    return caml_copy_double(attenuation);
}

CAMLextern_C value
caml_sfMusic_setPosition(value music, value x, value y, value z)
{
    SfMusic_val(music)->setPosition(SfVector3f_val3(x, y, z));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_setPosition3(value music, value position)
{
    SfMusic_val(music)->setPosition(SfVector3f_val(position));
    return Val_unit;
}

CAMLextern_C value
caml_sfMusic_getPosition(value music)
{
    sf::Vector3f pos = SfMusic_val(music)->getPosition();
    return Val_sfVector3f(pos);
}

/* TODO
sfMusic* sfMusic_createFromStream(sfInputStream* stream);
*/

// vim: sw=4 sts=4 ts=4 et
