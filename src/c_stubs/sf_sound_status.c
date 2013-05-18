#include <SFML/Audio/SoundStatus.h>
#include "sf_caml_incs_c.h"
#include "sf_sound_status.h"

value
Val_sfSoundStatus(sfSoundStatus sndst, char *fail_msg)
{
    switch (sndst)
    {
        case sfStopped: return Val_int(0);
        case sfPaused:  return Val_int(1);
        case sfPlaying: return Val_int(2);
        default: caml_failwith(fail_msg);
    }
    caml_failwith(fail_msg);
}

/* vim: sw=4 sts=4 ts=4 et
 */
