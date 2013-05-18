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

#include <SFML/Window/Event.h>

#include "sf_caml_incs_c.h"
#include "SFEvent_cstub.h"

#include "SFKey_cstub.h"
#include "SFMouse_cstub.h"
#include "SFJoystick_cstub.h"


#define Val_sfEvtClosed         Val_int(0)
#define Val_sfEvtMouseEntered   Val_int(1)
#define Val_sfEvtMouseLeft      Val_int(2)
#define Val_sfEvtLostFocus      Val_int(3)
#define Val_sfEvtGainedFocus    Val_int(4)

#define Tag_sfEvtMouseMoved               0
#define Tag_sfEvtResized                  1
#define Tag_sfEvtMouseButtonPressed       2
#define Tag_sfEvtMouseButtonReleased      3
#define Tag_sfEvtMouseWheelMoved          4
#define Tag_sfEvtKeyPressed               5
#define Tag_sfEvtKeyReleased              6
#define Tag_sfEvtTextEntered              7
#define Tag_sfEvtJoystickMoved            8
#define Tag_sfEvtJoystickButtonPressed    9
#define Tag_sfEvtJoystickButtonReleased  10
#define Tag_sfEvtJoystickConnected       11
#define Tag_sfEvtJoystickDisconnected    12


static value
Val_sfEvtMouseMoved(int x, int y) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, Tag_sfEvtMouseMoved);
    Store_field(var, 0, Val_long(x));
    Store_field(var, 1, Val_long(y));
    CAMLreturn(var);
}

static value
Val_sfEvtResized(unsigned int width, unsigned int height) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, Tag_sfEvtResized);
    Store_field(var, 0, Val_long(width));
    Store_field(var, 1, Val_long(height));
    CAMLreturn(var);
}

static value
Val_sfEvtMouseButton(int tag, sfMouseButton button, int x, int y) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(3, tag);
    Store_field(var, 0, Val_sfMouseButton(button));
    Store_field(var, 1, Val_long(x));
    Store_field(var, 2, Val_long(y));
    CAMLreturn(var);
}

#define Val_sfEvtMouseButtonPressed(button, x, y) \
    Val_sfEvtMouseButton(Tag_sfEvtMouseButtonPressed, button, x, y)

#define Val_sfEvtMouseButtonReleased(button, x, y) \
    Val_sfEvtMouseButton(Tag_sfEvtMouseButtonReleased, button, x, y)

static value
Val_sfEvtMouseWheelMoved(int delta, int x, int y) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(3, Tag_sfEvtMouseWheelMoved);
    Store_field(var, 0, Val_long(delta));
    Store_field(var, 1, Val_long(x));
    Store_field(var, 2, Val_long(y));
    CAMLreturn(var);
}

static value
Val_sfEvtKey(int tag,
        sfKeyCode code,
        sfBool alt,
        sfBool control,
        sfBool shift,
        sfBool system)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(5, tag);
    Store_field(var, 0, Val_sfKeyCode(code));
    Store_field(var, 1, Val_bool(alt));
    Store_field(var, 2, Val_bool(control));
    Store_field(var, 3, Val_bool(shift));
    Store_field(var, 4, Val_bool(system));
    CAMLreturn(var);
}

#define Val_sfEvtKeyPressed(code, alt, control, shift, system) \
    Val_sfEvtKey(Tag_sfEvtKeyPressed, code, alt, control, shift, system)

#define Val_sfEvtKeyReleased(code, alt, control, shift, system) \
    Val_sfEvtKey(Tag_sfEvtKeyReleased, code, alt, control, shift, system)

#define Val_sfUint32(ui32) caml_copy_int32(ui32)

static value
Val_sfEvtTextEntered(sfUint32 unicode)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(1, Tag_sfEvtTextEntered);
    Store_field(var, 0, Val_sfUint32(unicode));
    CAMLreturn(var);
}

static value
Val_sfEvtJoystickMoved(
    unsigned int joystickId,
    sfJoystickAxis axis,
    float position)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(3, Tag_sfEvtJoystickMoved);
    Store_field(var, 0, Val_long(joystickId));
    Store_field(var, 1, Val_sfJoystickAxis(axis));
    Store_field(var, 2, caml_copy_double(position));
    CAMLreturn(var);
}

static value
Val_sfEvtJoyButton(int tag,
    unsigned int joystickId,
    unsigned int button)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, tag);
    Store_field(var, 0, Val_long(joystickId));
    Store_field(var, 1, Val_long(button));
    CAMLreturn(var);
}

#define Val_sfEvtJoystickButtonPressed(joystickId, button) \
    Val_sfEvtJoyButton(Tag_sfEvtJoystickButtonPressed, joystickId, button)

#define Val_sfEvtJoystickButtonReleased(joystickId, button) \
    Val_sfEvtJoyButton(Tag_sfEvtJoystickButtonReleased, joystickId, button)


static value
Val_sfJoystickConnectEvent(int tag,
    unsigned int joystickId)
{
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(1, tag);
    Store_field(var, 0, Val_long(joystickId));
    CAMLreturn(var);
}

#define Val_sfEvtJoystickConnected(joystickId) \
    Val_sfJoystickConnectEvent(Tag_sfEvtJoystickConnected, joystickId)

#define Val_sfEvtJoystickDisconnected(joystickId) \
    Val_sfJoystickConnectEvent(Tag_sfEvtJoystickDisconnected, joystickId)


value Val_sfEvent(sfEvent* event, char const *fail_msg)
{
    switch (event->type)
    {
        case sfEvtMouseMoved:
            return Val_sfEvtMouseMoved(
                            event->mouseMove.x,
                            event->mouseMove.y);

        case sfEvtMouseButtonPressed:
            return Val_sfEvtMouseButtonPressed(
                            event->mouseButton.button,
                            event->mouseButton.x,
                            event->mouseButton.y);

        case sfEvtMouseButtonReleased:
            return Val_sfEvtMouseButtonReleased(
                            event->mouseButton.button,
                            event->mouseButton.x,
                            event->mouseButton.y);

        case sfEvtMouseWheelMoved:
            return Val_sfEvtMouseWheelMoved(
                            event->mouseWheel.x,
                            event->mouseWheel.y,
                            event->mouseWheel.delta);

        case sfEvtKeyPressed:
            return Val_sfEvtKeyPressed(
                            event->key.code,
                            event->key.alt,
                            event->key.control,
                            event->key.shift,
                            event->key.system);
        case sfEvtKeyReleased:
            return Val_sfEvtKeyReleased(
                            event->key.code,
                            event->key.alt,
                            event->key.control,
                            event->key.shift,
                            event->key.system);

        case sfEvtTextEntered:
            return Val_sfEvtTextEntered(
                            event->text.unicode);

        case sfEvtJoystickMoved:
            return Val_sfEvtJoystickMoved(
                            event->joystickMove.joystickId,
                            event->joystickMove.axis,
                            event->joystickMove.position);

        case sfEvtJoystickButtonPressed:
            return Val_sfEvtJoystickButtonPressed(
                            event->joystickButton.joystickId,
                            event->joystickButton.button);

        case sfEvtJoystickButtonReleased:
            return Val_sfEvtJoystickButtonReleased(
                            event->joystickButton.joystickId,
                            event->joystickButton.button);

        case sfEvtJoystickConnected:
            return Val_sfEvtJoystickConnected(
                            event->joystickConnect.joystickId);

        case sfEvtJoystickDisconnected:
            return Val_sfEvtJoystickDisconnected(
                            event->joystickConnect.joystickId);

        case sfEvtResized:
            return Val_sfEvtResized(
                            event->size.width,
                            event->size.height);

        case sfEvtMouseEntered:
            return Val_sfEvtMouseEntered;

        case sfEvtMouseLeft:
            return Val_sfEvtMouseLeft;

        case sfEvtLostFocus:
            return Val_sfEvtLostFocus;

        case sfEvtGainedFocus:
            return Val_sfEvtGainedFocus;

        case sfEvtClosed:
            return Val_sfEvtClosed;

        default: caml_failwith(fail_msg);
    }
}

/* vim: sw=4 sts=4 ts=4 et
 */
