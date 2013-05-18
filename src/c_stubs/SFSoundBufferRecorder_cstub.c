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

#include <SFML/Audio/SoundBufferRecorder.h>

#include "sf_caml_incs_c.h"

#define Val_sfSoundBufferRecorder(sbr) ((value)(sbr))
#define SfSoundBufferRecorder_val(sbr) ((sfSoundBufferRecorder *)(sbr))

CAMLprim value
caml_sfSoundBufferRecorder_create()
{
    sfSoundBufferRecorder *sbr = sfSoundBufferRecorder_create();
    return Val_sfSoundBufferRecorder(sbr);
}

CAMLprim value
caml_sfSoundBufferRecorder_destroy(value sbr)
{
    sfSoundBufferRecorder_destroy(SfSoundBufferRecorder_val(sbr));
    return Val_unit;
}

CAMLprim value
caml_sfSoundBufferRecorder_start(value sbr, value sampleRate)
{
    sfSoundBufferRecorder_start(
            SfSoundBufferRecorder_val(sbr), Int_val(sampleRate));
    return Val_unit;
}

CAMLprim value
caml_sfSoundBufferRecorder_stop(value sbr)
{
    sfSoundBufferRecorder_stop(SfSoundBufferRecorder_val(sbr));
    return Val_unit;
}

CAMLprim value
caml_sfSoundBufferRecorder_getSampleRate(value sbr)
{
    unsigned int sr = sfSoundBufferRecorder_getSampleRate(
            SfSoundBufferRecorder_val(sbr));
    return Val_int(sr);
}

/* TODO
const sfSoundBuffer* sfSoundBufferRecorder_getBuffer(
        const sfSoundBufferRecorder* soundBufferRecorder);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
