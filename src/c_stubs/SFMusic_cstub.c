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

#include <SFML/Audio/Music.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "sf_sound_status.h"
#include "SFTime_cstub.h"

#define Val_sfMusic(msc) ((value)(msc))
#define SfMusic_val(msc) ((sfMusic *)(msc))


/* sfMusic */

CAMLprim value
caml_sfMusic_openFromFile(value filename)
{
    sfMusic* music;
    music = sfMusic_createFromFile(String_val(filename));
    if (!music) caml_failwith("SFMusic.createFromFile");
    return Val_sfMusic(music);
}

CAMLprim value
caml_sfMusic_openFromMemory(value data)
{
    sfMusic *music =
        sfMusic_createFromMemory(
            String_val(data), caml_string_length(data));
    if (!music) caml_failwith("SFMusic.createFromMemory");
    return Val_sfMusic(music);
}

CAMLprim value
caml_sfMusic_destroy(value music)
{
    sfMusic_destroy(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getDuration(value music)
{
    sfTime duration = sfMusic_getDuration(SfMusic_val(music));
    return Val_sfTime_u(&duration);
}

CAMLprim value
caml_sfMusic_play(value music)
{
    sfMusic_play(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_pause(value music)
{
    sfMusic_pause(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_stop(value music)
{
    sfMusic_stop(SfMusic_val(music));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getChannelCount(value music)
{
    unsigned int channelsCount = sfMusic_getChannelCount(SfMusic_val(music));
    return Val_long(channelsCount);
}

CAMLprim value
caml_sfMusic_getSampleRate(value music)
{
    unsigned int sampleRate = sfMusic_getSampleRate(SfMusic_val(music));
    return Val_long(sampleRate);
}

CAMLprim value
caml_sfMusic_getStatus(value music)
{
    sfSoundStatus sndst = sfMusic_getStatus(SfMusic_val(music));
    return Val_sfSoundStatus(sndst, "SFMusic.getStatus");
}

CAMLprim value
caml_sfMusic_setPlayingOffset(value music, value timeOffset)
{
    sfMusic_setPlayingOffset(SfMusic_val(music), SfTime_val_u(timeOffset));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getPlayingOffset(value music)
{
    sfTime playingOffset = sfMusic_getPlayingOffset(SfMusic_val(music));
    return Val_sfTime_u(&playingOffset);
}

CAMLprim value
caml_sfMusic_setLoop(value music, value loop)
{
    sfMusic_setLoop(SfMusic_val(music), Bool_val(loop));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getLoop(value music)
{
    sfBool loop = sfMusic_getLoop(SfMusic_val(music));
    return Val_bool(loop);
}

/******************************************/

CAMLprim value
caml_sfMusic_setVolume(value music, value volume)
{
    sfMusic_setVolume(SfMusic_val(music), Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getVolume(value music)
{
    float volume = sfMusic_getVolume(SfMusic_val(music));
    return caml_copy_double(volume);
}

CAMLprim value
caml_sfMusic_setPitch(value music, value pitch)
{
    sfMusic_setPitch(SfMusic_val(music), Double_val(pitch));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getPitch(value music)
{
    float pitch = sfMusic_getPitch(SfMusic_val(music));
    return caml_copy_double(pitch);
}

CAMLprim value
caml_sfMusic_setRelativeToListener(value music, value relative)
{
    sfMusic_setRelativeToListener(SfMusic_val(music), Bool_val(relative));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_isRelativeToListener(value music)
{
    return Val_bool(
        sfMusic_isRelativeToListener(SfMusic_val(music)));
}

CAMLprim value
caml_sfMusic_setMinDistance(value music, value minDistance)
{
    sfMusic_setMinDistance(SfMusic_val(music), Double_val(minDistance));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getMinDistance(value music)
{
    float minDistance = sfMusic_getMinDistance(SfMusic_val(music));
    return caml_copy_double(minDistance);
}

CAMLprim value
caml_sfMusic_setAttenuation(value music, value attenuation)
{
    sfMusic_setAttenuation(SfMusic_val(music), Double_val(attenuation));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getAttenuation(value music)
{
    float attenuation = sfMusic_getAttenuation(SfMusic_val(music));
    return caml_copy_double(attenuation);
}

CAMLprim value
caml_sfMusic_setPosition(value music, value x, value y, value z)
{
    sfMusic_setPosition(SfMusic_val(music), SfVector3f_val3(x, y, z));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_setPosition3(value music, value position)
{
    sfMusic_setPosition(SfMusic_val(music), SfVector3f_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfMusic_getPosition(value music)
{
    sfVector3f pos = sfMusic_getPosition(SfMusic_val(music));
    return Val_sfVector3f(&pos);
}

/* TODO
sfMusic* sfMusic_createFromStream(sfInputStream* stream);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
