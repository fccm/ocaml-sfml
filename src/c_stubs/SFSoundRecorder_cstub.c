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

#include <SFML/Audio/SoundRecorder.h>

#include "sf_caml_incs_c.h"

/* TODO:
typedef sfBool (*sfSoundRecorderStartCallback)(void*);
typedef sfBool (*sfSoundRecorderProcessCallback)(const sfInt16*, size_t, void*);
typedef void   (*sfSoundRecorderStopCallback)(void*);

sfSoundRecorder* sfSoundRecorder_create(sfSoundRecorderStartCallback   onStart,
                                        sfSoundRecorderProcessCallback onProcess,
                                        sfSoundRecorderStopCallback    onStop,
                                        void*                          userData);

void sfSoundRecorder_destroy(sfSoundRecorder* soundRecorder);
void sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate);
void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder);
unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder);
*/

CAMLprim value
caml_sfSoundRecorder_isAvailable(value unit)
{
    sfBool avail = sfSoundRecorder_isAvailable();
    return Val_bool(avail);
}

/* vim: sw=4 sts=4 ts=4 et
 */
