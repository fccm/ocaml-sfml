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

#include <SFML/Audio/SoundBufferRecorder.hpp>

#include "sf_caml_incs.hpp"

static value Val_sfSoundBufferRecorder(sf::SoundBufferRecorder * p)
{
    return caml_copy_nativeint((intnat) p);
}
static sf::SoundBufferRecorder * SfSoundBufferRecorder_val(value v)
{
    return (sf::SoundBufferRecorder *) Nativeint_val(v);
}

CAMLextern_C value
caml_sfSoundBufferRecorder_create()
{
    sf::SoundBufferRecorder *sbr = new sf::SoundBufferRecorder;
    return Val_sfSoundBufferRecorder(sbr);
}

CAMLextern_C value
caml_sfSoundBufferRecorder_destroy(value sbr)
{
    delete SfSoundBufferRecorder_val(sbr);
    return Val_unit;
}

CAMLextern_C value
caml_sfSoundBufferRecorder_start(value sbr, value sampleRate)
{
    SfSoundBufferRecorder_val(sbr)->start(
            Int_val(sampleRate));
    return Val_unit;
}

CAMLextern_C value
caml_sfSoundBufferRecorder_stop(value sbr)
{
    SfSoundBufferRecorder_val(sbr)->stop();
    return Val_unit;
}

CAMLextern_C value
caml_sfSoundBufferRecorder_getSampleRate(value sbr)
{
    unsigned int sr = SfSoundBufferRecorder_val(sbr)->getSampleRate();
    return Val_int(sr);
}

/* TODO
const sfSoundBuffer* sfSoundBufferRecorder_getBuffer(
        const sfSoundBufferRecorder* soundBufferRecorder);
*/

// vim: sw=4 sts=4 ts=4 et
