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

#include <SFML/Audio/Sound.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFTime_stub.hpp"
#include "SFSoundBuffer_stub.hpp"

#define Val_sfSound(snd) ((value)(snd))
#define SfSound_val(snd) ((sf::Sound *)(snd))

static value
Val_sfSoundStatus(sf::Sound::Status sndst)
{
    switch (sndst)
    {
        case sf::Sound::Stopped: return Val_int(0);
        case sf::Sound::Paused:  return Val_int(1);
        case sf::Sound::Playing: return Val_int(2);
        default: caml_failwith("SFSound.sound_status");
    }
    caml_failwith("SFSound.sound_status");
}

/* sf::Sound */

CAMLextern_C value
caml_sfSound_create(value unit)
{
    sf::Sound *sound = new sf::Sound;
    return Val_sfSound(sound);
}

CAMLextern_C value
caml_sfSound_destroy(value sound)
{
    delete SfSound_val(sound);
#if defined(_OCAML_SFML_DEBUG)
    std::cout << "# sound deleted" << std::endl << std::flush;  // DEBUG
#endif
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_copy(value orig)
{
    sf::Sound *copy = new sf::Sound(*SfSound_val(orig));
    return Val_sfSound(copy);
}

CAMLextern_C value
caml_sfSound_play(value sound)
{
    SfSound_val(sound)->play();
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_pause(value sound)
{
    SfSound_val(sound)->pause();
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_stop(value sound)
{
    SfSound_val(sound)->stop();
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setBuffer(value sound, value buffer)
{
    SfSound_val(sound)->setBuffer(*SfSoundBuffer_val_u(buffer));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setLoop(value sound, value loop)
{
    SfSound_val(sound)->setLoop(Bool_val(loop));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_getLoop(value sound)
{
    bool loop = SfSound_val(sound)->getLoop();
    return Val_bool(loop);
}

CAMLextern_C value
caml_sfSound_getStatus(value sound)
{
    sf::Sound::Status sndst = SfSound_val(sound)->getStatus();
    return Val_sfSoundStatus(sndst);
}

CAMLextern_C value
caml_sfSound_setPitch(value sound, value pitch)
{
    SfSound_val(sound)->setPitch(Double_val(pitch));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setVolume(value sound, value volume)
{
    SfSound_val(sound)->setVolume(Double_val(volume));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setPosition(value sound, value x, value y, value z)
{
    SfSound_val(sound)->setPosition(SfVector3f_val3(x, y, z));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setPosition3(value sound, value position)
{
    SfSound_val(sound)->setPosition(SfVector3f_val(position));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setRelativeToListener(value sound, value relative)
{
    SfSound_val(sound)->setRelativeToListener(Bool_val(relative));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setMinDistance(value sound, value minDistance)
{
    SfSound_val(sound)->setMinDistance(Double_val(minDistance));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setAttenuation(value sound, value attenuation)
{
    SfSound_val(sound)->setAttenuation(Double_val(attenuation));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_setPlayingOffset(value sound, value timeOffset)
{
    SfSound_val(sound)->setPlayingOffset(SfTime_val(timeOffset));
    return Val_unit;
}

CAMLextern_C value
caml_sfSound_getPlayingOffset(value sound)
{
    sf::Time playingOffset = SfSound_val(sound)->getPlayingOffset();
    return Val_sfTime(playingOffset);
}

CAMLextern_C value
caml_sfSound_getPitch(value sound)
{
    float pitch = SfSound_val(sound)->getPitch();
    return caml_copy_double(pitch);
}

CAMLextern_C value
caml_sfSound_getVolume(value sound)
{
    float volume = SfSound_val(sound)->getVolume();
    return caml_copy_double(volume);
}

CAMLextern_C value
caml_sfSound_isRelativeToListener(value sound)
{
    bool relativeToListener = SfSound_val(sound)->isRelativeToListener();
    return Val_bool(relativeToListener);
}

CAMLextern_C value
caml_sfSound_getPosition(value sound)
{
    sf::Vector3f pos = SfSound_val(sound)->getPosition();
    return Val_sfVector3f(pos);
}

CAMLextern_C value
caml_sfSound_getMinDistance(value sound)
{
    float minDistance = SfSound_val(sound)->getMinDistance();
    return caml_copy_double(minDistance);
}

CAMLextern_C value
caml_sfSound_getAttenuation(value sound)
{
    float attenuation = SfSound_val(sound)->getAttenuation();
    return caml_copy_double(attenuation);
}

/* TODO
const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound);
*/

// vim: sw=4 sts=4 ts=4 et
