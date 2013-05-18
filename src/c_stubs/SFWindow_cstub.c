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

#include <SFML/Window.h>

#include "sf_caml_incs_c.h"

#include "sf_caml_conv_c.h"
#include "sf_conv_vectors_c.h"
#include "sf_context_settings_c.h"

#include "SFWindow_cstub.h"
#include "SFEvent_cstub.h"

#define Val_sfWindow(win) ((value)(win))
#define SfWindow_val(win) ((sfWindow *)(win))


/* sfWindow */

CAMLprim value
caml_sfWindow_create(
    value ml_mode, value title, value ml_style, value ml_settings)
{
    sfVideoMode mode;
    sfContextSettings settings;
    unsigned long style;
    sfWindow *win;

    mode.width        = Long_val(Field(ml_mode, 0));
    mode.height       = Long_val(Field(ml_mode, 1));
    mode.bitsPerPixel = Long_val(Field(ml_mode, 2));

    SfContextSettings_val(&settings, ml_settings);

    style = 0;
    while (ml_style != Val_emptylist)
    {
        switch (Long_val(Field(ml_style, 0)))
        {
            case SF_WIN_STYLE_TITLEBAR:   style |= sfTitlebar;     break;
            case SF_WIN_STYLE_RESIZE:     style |= sfResize;       break;
            case SF_WIN_STYLE_CLOSE:      style |= sfClose;        break;
            case SF_WIN_STYLE_FULLSCREEN: style |= sfFullscreen;   break;
            case SF_WIN_STYLE_DEFAULT:    style |= sfDefaultStyle; break;
            default: caml_failwith("SFWindow.create");
        }
        ml_style = Field(ml_style, 1);
    }

    if (style & sfFullscreen && !sfVideoMode_isValid(mode))
        caml_invalid_argument("SFWindow.create: video_mode");

    win = sfWindow_create(mode, String_val(title), style, &settings);
    if (!win) caml_failwith("SFWindow.create");

    return Val_sfWindow(win);
}

CAMLprim value
caml_sfWindow_createFromHandle(value ml_handle, value ml_settings)
{
    sfContextSettings settings;
    sfWindow* win;

    SfContextSettings_val(&settings, ml_settings);

    win = sfWindow_createFromHandle(Nativeint_val(ml_handle), &settings);
    if (!win) caml_failwith("SFWindow.createFromHandle");

    return Val_sfWindow(win);
}

CAMLprim value
caml_sfWindow_destroy(value win)
{
    sfWindow_destroy(SfWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_isOpen(value win)
{
    return Val_bool(
        sfWindow_isOpen(SfWindow_val(win)));
}

CAMLprim value
caml_sfWindow_close(value win)
{
    sfWindow_close(SfWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_display(value win)
{
    caml_enter_blocking_section();
    sfWindow_display(SfWindow_val(win));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfWindow_pollEvent(value win)
{
    sfEvent event;
    const char fail_msg[] = "SFWindow.pollEvent";
    sfBool isev = sfWindow_pollEvent(SfWindow_val(win), &event);
    if (isev) return Val_some(Val_sfEvent(&event, fail_msg));
    else return Val_none;
}

CAMLprim value
caml_sfWindow_waitEvent(value win)
{
    sfEvent event;
    const char func_name[] = "SFWindow.waitEvent";
    sfBool err = sfWindow_waitEvent(SfWindow_val(win), &event);
    if (err) caml_failwith(func_name);
    return Val_sfEvent(&event, func_name);
}

CAMLprim value
caml_sfWindow_getSize(value win)
{
    sfVector2u size = sfWindow_getSize(SfWindow_val(win));
    return Val_sfVector2u(&size);
}

CAMLprim value
caml_sfWindow_getWidth(value win)
{
    sfVector2u size = sfWindow_getSize(SfWindow_val(win));
    return Val_long(size.x);
}

CAMLprim value
caml_sfWindow_getHeight(value win)
{
    sfVector2u size = sfWindow_getSize(SfWindow_val(win));
    return Val_long(size.y);
}

CAMLprim value
caml_sfWindow_setSize2(value win, value width, value height)
{
    sfWindow_setSize(SfWindow_val(win), SfVector2u_val2(width, height));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setSize(value win, value size)
{
    sfWindow_setSize(SfWindow_val(win), SfVector2u_val(size));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setPosition2(value win, value left, value top)
{
    sfWindow_setPosition(SfWindow_val(win), SfVector2i_val2(left, top));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setPosition(value win, value pos)
{
    sfWindow_setPosition(SfWindow_val(win), SfVector2i_val(pos));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_getPosition(value win)
{
    sfVector2i pos = sfWindow_getPosition(SfWindow_val(win));
    return Val_sfVector2i(&pos);
}

CAMLprim value
caml_sfWindow_setTitle(value win, value title)
{
    sfWindow_setTitle(SfWindow_val(win), String_val(title));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setActive(value win, value active)
{
    sfBool a = sfWindow_setActive(SfWindow_val(win), Bool_val(active));
    return Val_bool(a);
}

CAMLprim value
caml_sfWindow_setVisible(value win, value visible)
{
    sfWindow_setVisible(SfWindow_val(win), Bool_val(visible));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setMouseCursorVisible(value win, value visible)
{
    sfWindow_setMouseCursorVisible(SfWindow_val(win), Bool_val(visible));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setKeyRepeatEnabled(value win, value enabled)
{
    sfWindow_setKeyRepeatEnabled(SfWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setJoystickThreshold(value win, value threshold)
{
    sfWindow_setJoystickThreshold(SfWindow_val(win), Double_val(threshold));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setFramerateLimit(value win, value limit)
{
    sfWindow_setFramerateLimit(SfWindow_val(win), Long_val(limit));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_setVerticalSyncEnabled(value win, value enabled)
{
    sfWindow_setVerticalSyncEnabled(SfWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfWindow_getSettings(value win)
{
    sfContextSettings settings = sfWindow_getSettings(SfWindow_val(win));
    return Val_sfContextSettings(&settings);
}

CAMLprim value
caml_sfWindow_getMousePosition(value relativeTo)
{
    sfVector2i pos = sfMouse_getPosition(SfWindow_val(relativeTo));
    return Val_sfVector2i(&pos);
}

CAMLprim value
caml_sfWindow_setMousePosition(value relativeTo, value position)
{
    sfMouse_setPosition(SfVector2i_val(position), SfWindow_val(relativeTo));
    return Val_unit;
}

/* TODO
void sfWindow_setSize(sfWindow* window, sfVector2u size);

void sfWindow_setIcon(sfWindow* window,
        unsigned int width, unsigned int height, const sfUint8* pixels);

sfWindowHandle sfWindow_getSystemHandle(const sfWindow* window);
*/

/* vim: sw=4 sts=4 ts=4 et
 */
