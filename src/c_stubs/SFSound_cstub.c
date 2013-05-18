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

#include <SFML/Audio/Sound.h>

#include "sf_caml_incs_c.h"
#include "sf_sound_status.h"
#include "sf_conv_vectors_c.h"
#include "SFTime_cstub.h"
#include "SFSoundBuffer_cstub.h"

#define Val_sfSound(snd) ((value)(snd))
#define SfSound_val(snd) ((sfSound *)(snd))


/* sfSound */

CAMLprim value
caml_sfSound_create(value unit)
{
    return Val_sfSound(sfSound_create());
}

CAMLprim value
caml_sfSound_destroy(value sound)
{
    sfSound_destroy(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_copy(value orig)
{
    sfSound *copy = sfSound_copy(SfSound_val(orig));
    return Val_sfSound(copy);
}

CAMLprim value
caml_sfSound_play(value sound)
{
    sfSound_play(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_pause(value sound)
{
    sfSound_pause(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_stop(value sound)
{
    sfSound_stop(SfSound_val(sound));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setBuffer(value sound, value buffer)
{
    sfSound_setBuffer(SfSound_val(sound), SfSoundBuffer_val_u(buffer));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setLoop(value sound, value loop)
{
    sfSound_setLoop(SfSound_val(sound), Bool_val(loop));
    return Val_unit;
}

CAMLprim value
caml_sfSound_getLoop(value sound)
{
    sfBool loop = sfSound_getLoop(SfSound_val(sound));
    return Val_bool(loop);
}

CAMLprim value
caml_sfSound_getStatus(value sound)
{
    sfSoundStatus sst = sfSound_getStatus(SfSound_val(sound));
    return Val_sfSoundStatus(sst, "SFSound.sound_status");
}

CAMLprim value
caml_sfSound_setPitch(value sound, value pitch)
{
    sfSound_setPitch(SfSound_val(sound), Double_val(pitch));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setVolume(value sound, value volume)
{
    sfSound_setVolume(SfSound_val(sound), Double_val(volume));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setPosition(value sound, value x, value y, value z)
{
    sfSound_setPosition(SfSound_val(sound), SfVector3f_val3(x, y, z));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setPosition3(value sound, value position)
{
    sfSound_setPosition(SfSound_val(sound), SfVector3f_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setRelativeToListener(value sound, value relative)
{
    sfSound_setRelativeToListener(SfSound_val(sound), Bool_val(relative));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setMinDistance(value sound, value minDistance)
{
    sfSound_setMinDistance(SfSound_val(sound), Double_val(minDistance));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setAttenuation(value sound, value attenuation)
{
    sfSound_setAttenuation(SfSound_val(sound), Double_val(attenuation));
    return Val_unit;
}

CAMLprim value
caml_sfSound_setPlayingOffset(value sound, value timeOffset)
{
    sfSound_setPlayingOffset(SfSound_val(sound), SfTime_val_u(timeOffset));
    return Val_unit;
}

CAMLprim value
caml_sfSound_getPlayingOffset(value sound)
{
    sfTime pOff = sfSound_getPlayingOffset(SfSound_val(sound));
    return Val_sfTime_u(&pOff);
}

CAMLprim value
caml_sfSound_getPitch(value sound)
{
    float pitch = sfSound_getPitch(SfSound_val(sound));
    return caml_copy_double(pitch);
}

CAMLprim value
caml_sfSound_getVolume(value sound)
{
    float volume = sfSound_getVolume(SfSound_val(sound));
    return caml_copy_double(volume);
}

CAMLprim value
caml_sfSound_isRelativeToListener(value sound)
{
    sfBool rel = sfSound_isRelativeToListener(SfSound_val(sound));
    return Val_bool(rel);
}

CAMLprim value
caml_sfSound_getPosition(value sound)
{
    sfVector3f pos = sfSound_getPosition(SfSound_val(sound));
    return Val_sfVector3f(&pos);
}

CAMLprim value
caml_sfSound_getMinDistance(value sound)
{
    float md = sfSound_getMinDistance(SfSound_val(sound));
    return caml_copy_double(md);
}

CAMLprim value
caml_sfSound_getAttenuation(value sound)
{
    float att = sfSound_getAttenuation(SfSound_val(sound));
    return caml_copy_double(att);
}

/* TODO
const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
