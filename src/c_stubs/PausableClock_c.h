/*
 * PausableClock, this class is like a stopwatch: you can pause the clock and
 * restart it. And in a easy way.
 * Copyright (C) 2009 Marco Antognini <hiura(_)romandie.com>
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
 
#ifndef _CSF_PAUSABLECLOCK_H
#define _CSF_PAUSABLECLOCK_H

#include "SFTime_cstub.h"

/* sfPausableClock */
 
/*
 * sfPausableClock is not part of SFML,
 * it was provided on the SFML's wiki:
 * http://www.sfml-dev.org/wiki/en/sources/pausableclock
 * and was written by Marco Antognini and Laurent Gomila in C++
 * here it was rewritten in C by Florent Monnier
 */

typedef struct _sfPausableClock
{
    /* Is the PausableClock paused? */
    int am_i_paused;
 
    /* Time buffer. */
    sfTime my_time;
 
    /* The sfClock used. */
    sfClock *my_clock;
} sfPausableClock;

 
sfPausableClock *
sfPausableClock_create(int paused)
{
    sfPausableClock *pclock;
    pclock = malloc(sizeof(sfPausableClock));
    pclock->am_i_paused = paused;  /* does the clock start paused? */
    pclock->my_time = sfTime_Zero;
    pclock->my_clock = sfClock_create();
    return pclock;
}

void sfPausableClock_destroy(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        sfClock_destroy(pclock->my_clock);
        free(pclock);
        pclock = NULL;
    }
}

/* Set the clock in 'pause' mode. */
void sfPausableClock_pause(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not yet paused... */
        if (!pclock->am_i_paused)
        {
            pclock->am_i_paused = 1;
            pclock->my_time =
                sfTime_add(
                    pclock->my_time,
                    sfClock_getElapsedTime(pclock->my_clock));
        }
    }
}
 
int sfPausableClock_isPaused(sfPausableClock *pclock)
{
    if (pclock == NULL) return (-1);
    return (pclock->am_i_paused != 0);
}

/* Start the clock (again). */
void sfPausableClock_start(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not yet started... */
        if (pclock->am_i_paused)
        {
            (void) sfClock_restart(pclock->my_clock);
            pclock->am_i_paused = 0;
        }
    }
}
 
/* Get the time elapsed since last Reset. */
sfTime sfPausableClock_getElapsedTime(sfPausableClock *pclock)
{
    if (pclock != NULL) {
        /* If not paused... */
        if (pclock->am_i_paused)
            return pclock->my_time;
        else
            return sfTime_add(
                        pclock->my_time,
                        sfClock_getElapsedTime(pclock->my_clock));
    }
    return (sfTime_error_f());
}
 
/* Reset the clock. */
sfTime sfPausableClock_restart(sfPausableClock *pclock, int paused)
{
    if (pclock != NULL) {
        pclock->am_i_paused = paused;  /* does the clock start paused? */
        pclock->my_time = sfTime_Zero;
        return sfClock_restart(pclock->my_clock);
    }
    return (sfTime_error_f());
}

#endif /* _CSF_PAUSABLECLOCK_H */
