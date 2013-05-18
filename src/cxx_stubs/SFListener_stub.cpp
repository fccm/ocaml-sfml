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

#include <SFML/Audio/Listener.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"

/* sf::Listener */

CAMLextern_C value
caml_sfListener_setGlobalVolume(value volume)
{
    sf::Listener::setGlobalVolume(Double_val(volume));
    return Val_unit;
}

CAMLextern_C value
caml_sfListener_getGlobalVolume(value unit)
{
    float v = sf::Listener::getGlobalVolume();
    return caml_copy_double(v);
}

CAMLextern_C value
caml_sfListener_setPosition3(value posX, value posY, value posZ)
{
    sf::Listener::setPosition(SfVector3f_val3(posX, posY, posZ));
    return Val_unit;
}

CAMLextern_C value
caml_sfListener_setPosition(value pos)
{
    sf::Listener::setPosition(SfVector3f_val(pos));
    return Val_unit;
}

CAMLextern_C value
caml_sfListener_getPosition(value unit)
{
    sf::Vector3f pos = sf::Listener::getPosition();
    return Val_sfVector3f(pos);
}

CAMLextern_C value
caml_sfListener_setDirection(value orientation)
{
    sf::Listener::setDirection(SfVector3f_val(orientation));
    return Val_unit;
}

CAMLextern_C value
caml_sfListener_getDirection(value unit)
{
    sf::Vector3f dir = sf::Listener::getDirection();
    return Val_sfVector3f(dir);
}

// vim: sw=4 sts=4 ts=4 et
