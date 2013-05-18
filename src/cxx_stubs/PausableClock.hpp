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
 
#ifndef _SF_PAUSABLECLOCK_HPP
#define _SF_PAUSABLECLOCK_HPP
 
/*!
 \file pausableclock.hpp
 \brief Definition and implementation of PausableClock class.
*/
 
#include <SFML/System.hpp>
 
/*!
 \namespace sftools
 \brief namespace containing tools using SFML library.
*/
namespace sftools {
 
/*!
 \class PausableClock
 \brief sf::Clock with Pause function.
*/
class PausableClock
{
    public:
        /*!
         \brief Semi-default ctor.
         \param paused : does the clock start paused ?
        */
        PausableClock(bool paused = false)
        : am_i_paused(paused)
        , my_time(sf::Time::Zero)
        , my_clock()
        {
        }
 
        /*!
         \brief Set the clock in 'pause' mode.
        */
        void pause()
        {
            if (!am_i_paused)
            {
                am_i_paused = true;
                my_time += my_clock.getElapsedTime();
            }
        }
 
        /*!
         \brief Start the clock (again).
        */
        void start()
        {
            if (am_i_paused)
            {
                my_clock.restart();
                am_i_paused = false;
            }
        }
 
        /*!
         \brief Is the clock in 'pause' mode ?
        */
        bool isPaused()
        {
            return am_i_paused;
        }
 
        /*!
         \brief Get the time elapsed since last Reset.
        */
        sf::Time getElapsedTime(void) const
        {
            // If not paused...
            if (!am_i_paused)
                return my_time + my_clock.getElapsedTime();
            else
                return my_time;
        }
 
        /*!
         \brief Reset the clock.
         \param paused : does the clock start paused ?
        */
        sf::Time restart(bool paused = false)
        {
            am_i_paused = paused;
            my_time = sf::Time::Zero;
            return my_clock.restart();
        }
 
    private:
        /*!
         \brief Is the PausableClock paused ?
        */
        bool am_i_paused;
 
        /*!
         \brief Time buffer.
        */
        sf::Time my_time;
 
        /*!
         \brief The sf::Clock used.
        */
        sf::Clock my_clock;
};
 
} // sftools namespace
 
#endif // _SF_PAUSABLECLOCK_HPP
