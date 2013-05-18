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

#include <SFML/Graphics/RenderWindow.h>

#include "sf_caml_incs_c.h"
#include "sf_context_settings_c.h"

#define Val_sfRenderWindow(win) ((value)(win))
#define SfRenderWindow_val(win) ((sfRenderWindow *)(win))


#define SF_WIN_STYLE_TITLEBAR   (-857527493)
#define SF_WIN_STYLE_RESIZE     ( 142301684)
#define SF_WIN_STYLE_CLOSE      (-933029960)
#define SF_WIN_STYLE_FULLSCREEN (-105629125)
#define SF_WIN_STYLE_DEFAULT    (-974566413)



/* sfRenderWindow */

CAMLprim value
caml_sfRenderWindow_create(
    value ml_mode, value title, value ml_style, value ml_settings)
{
    sfVideoMode mode;
    sfContextSettings settings;
    unsigned long style;
    sfRenderWindow* win;

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
            default: caml_failwith("SFRenderWindow.create");
        }
        ml_style = Field(ml_style, 1);
    }

    win = sfRenderWindow_create(mode, String_val(title), style, &settings);
    if (!win) caml_failwith("SFRenderWindow.create");

    return Val_sfRenderWindow(win);
}

CAMLprim value
caml_sfRenderWindow_createFromHandle(value ml_handle, value ml_settings)
{
    sfContextSettings settings;
    sfRenderWindow* win;

    SfContextSettings_val(&settings, ml_settings);

    win = sfRenderWindow_createFromHandle(
            (sfWindowHandle)Nativeint_val(ml_handle), &settings);
    if (!win) caml_failwith("SFRenderWindow.createFromHandle");

    return Val_sfRenderWindow(win);
}

CAMLprim value
caml_sfRenderWindow_isOpen(value win)
{
    return Val_bool(
        sfRenderWindow_isOpen(SfRenderWindow_val(win)));
}

CAMLprim value
caml_sfRenderWindow_close(value win)
{
    sfRenderWindow_close(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_display(value win)
{
    caml_enter_blocking_section();
    sfRenderWindow_display(SfRenderWindow_val(win));
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_destroy(value win)
{
    sfRenderWindow_destroy(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_pollEvent(value win)
{
    sfEvent event;
    const char fail_msg[] = "SFRenderWindow.pollEvent";
    sfBool isev = sfRenderWindow_pollEvent(SfRenderWindow_val(win), &event);
    if (isev) return Val_some(Val_sfEvent(&event, fail_msg));
    else return Val_none;
}

CAMLprim value
caml_sfRenderWindow_waitEvent(value win)
{
    sfEvent event;
    const char func_name[] = "SFRenderWindow.waitEvent";
    sfBool err = sfRenderWindow_waitEvent(SfRenderWindow_val(win), &event);
    if (err) caml_failwith(func_name);
    return Val_sfEvent(&event, func_name);
}

CAMLprim value
caml_sfRenderWindow_clear(value win, value ml_color)
{
    sfColor color;
    SfColor_val(&color, ml_color);
    sfRenderWindow_clear(SfRenderWindow_val(win), color);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_blank(value win)
{
    sfRenderWindow_clear(SfRenderWindow_val(win), sfBlack);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_getSize(value win)
{
    sfVector2u size = sfRenderWindow_getSize(SfRenderWindow_val(win));
    return Val_sfVector2u(&size);
}

CAMLprim value
caml_sfRenderWindow_getWidth(value win)
{
    sfVector2u size = sfRenderWindow_getSize(SfRenderWindow_val(win));
    return Val_long(size.x);
}

CAMLprim value
caml_sfRenderWindow_getHeight(value win)
{
    sfVector2u size = sfRenderWindow_getSize(SfRenderWindow_val(win));
    return Val_long(size.y);
}

CAMLprim value
caml_sfRenderWindow_setSize(value win, value width, value height)
{
    sfRenderWindow_setSize(
            SfRenderWindow_val(win), SfVector2u_val2(width, height));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setSize2(value win, value size)
{
    sfRenderWindow_setSize(SfRenderWindow_val(win), SfVector2u_val(size));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_drawSprite(
        value win, value sprite, value ml_states, value unit)
{

    sfRenderStates *states = Option_val(ml_states, SfRenderStates_val, NULL);
    sfRenderWindow_drawSprite(
            SfRenderWindow_val(win), SfSprite_val_u(sprite), states);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_drawText(
        value win, value text, value ml_states, value unit)
{
    sfRenderStates *states = Option_val(ml_states, SfRenderStates_val, NULL);
    sfRenderWindow_drawText(
            SfRenderWindow_val(win), SfText_val_u(text), states);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_drawShape(
        value win, value shape, value ml_states, value unit)
{
    sfRenderStates *states = Option_val(ml_states, SfRenderStates_val, NULL);
    sfRenderWindow_drawShape(
            SfRenderWindow_val(win), SfShape_val(shape), states);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_drawCircleShape(
        value win, value circle, value ml_states, value unit)
{
    sfRenderStates *states = Option_val(ml_states, SfRenderStates_val, NULL);
    sfRenderWindow_drawCircleShape(
            SfRenderWindow_val(win), SfCircleShape_val(circle), states);
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setPosition(value win, value left, value top)
{
    sfRenderWindow_setPosition(
            SfRenderWindow_val(win), SfVector2i_val2(left, top));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setPosition2(value win, value position)
{
    sfRenderWindow_setPosition(
            SfRenderWindow_val(win), SfVector2i_val(position));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setMouseCursorVisible(value win, value show)
{
    sfRenderWindow_setMouseCursorVisible(
            SfRenderWindow_val(win), Bool_val(show));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setVisible(value win, value visible)
{
    sfRenderWindow_setVisible(SfRenderWindow_val(win), Bool_val(visible));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setKeyRepeatEnabled(value win, value enabled)
{
    sfRenderWindow_setKeyRepeatEnabled(
            SfRenderWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setActive(value win, value active)
{
    sfBool status = sfRenderWindow_setActive(
            SfRenderWindow_val(win), Bool_val(active));
    if (!status) caml_failwith("SFRenderWindow.setActive");
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setFramerateLimit(value win, value limit)
{
    sfRenderWindow_setFramerateLimit(SfRenderWindow_val(win), Long_val(limit));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setView(value win, value view)
{
    sfRenderWindow_setView(SfRenderWindow_val(win), SfView_val(view));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_convertCoords(value win, value point, value targetView)
{
    sfVector2f res =
        sfRenderWindow_convertCoords(
                SfRenderWindow_val(win),
                SfVector2i_val(point), SfView_val(targetView));
    return Val_sfVector2f(&res);
}

CAMLprim value
caml_sfRenderWindow_setVerticalSyncEnabled(value win, value enabled)
{
    sfRenderWindow_setVerticalSyncEnabled(
            SfRenderWindow_val(win), Bool_val(enabled));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_setJoystickThreshold(value win, value threshold)
{
    sfRenderWindow_setJoystickThreshold(
            SfRenderWindow_val(win), Double_val(threshold));
    return Val_unit;
}


CAMLprim value
caml_sfRenderWindow_pushGLStates(value win)
{
    sfRenderWindow_pushGLStates(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_popGLStates(value win)
{
    sfRenderWindow_popGLStates(SfRenderWindow_val(win));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_resetGLStates(value win)
{
    sfRenderWindow_resetGLStates(SfRenderWindow_val(win));
    return Val_unit;
}


CAMLprim value
caml_sfRenderWindow_capture(value win)
{
    sfImage *img;
    img = sfRenderWindow_capture(SfRenderWindow_val(win));
    if (!img) caml_failwith("SFRenderWindow.capture");
    return caml_copy_sfImage(img);  // XXX TODO: test and debug me!
}

CAMLprim value
caml_sfRenderWindow_getSettings(value win)
{
    sfContextSettings settings =
        sfRenderWindow_getSettings(SfRenderWindow_val(win));
    return Val_sfContextSettings(&settings);
}

CAMLprim value
caml_sfRenderWindow_setTitle(value win, value title)
{
    sfRenderWindow_setTitle(SfRenderWindow_val(win), String_val(title));
    return Val_unit;
}

CAMLprim value
caml_sfRenderWindow_getView(value win)
{
    const sfView *view = sfRenderWindow_getView(SfRenderWindow_val(win));
    return Val_sfView((sfView *)view, Val_false);
}

/* TODO
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow);

void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, unsigned int width,
        unsigned int height, const sfUint8* pixels);

sfWindowHandle sfRenderWindow_getSystemHandle(
        const sfRenderWindow* renderWindow);

const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow);

sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow,
        const sfView* view);

void sfRenderWindow_drawCircleShape(sfRenderWindow* renderWindow,
        const sfCircleShape* object, const sfRenderStates* states);

void sfRenderWindow_drawConvexShape(sfRenderWindow* renderWindow,
        const sfConvexShape* object, const sfRenderStates* states);

void sfRenderWindow_drawRectangleShape(sfRenderWindow* renderWindow,
        const sfRectangleShape* object, const sfRenderStates* states);

void sfRenderWindow_drawVertexArray(sfRenderWindow* renderWindow,
        const sfVertexArray* object, const sfRenderStates* states);

void sfRenderWindow_drawPrimitives(sfRenderWindow* renderWindow,
        const sfVertex* vertices, unsigned int vertexCount,
        sfPrimitiveType type, const sfRenderStates* states);
*/

CAMLprim value
caml_sfRenderWindow_getMousePosition(value relativeTo)
{
    sfVector2i pos =
        sfMouse_getPosition((sfWindow *) SfRenderWindow_val(relativeTo));
    return Val_sfVector2i(&pos);
}

CAMLprim value
caml_sfRenderWindow_setMousePosition(value relativeTo, value position)
{
    sfMouse_setPosition(SfVector2i_val(position),
            (sfWindow *) SfRenderWindow_val(relativeTo));
    return Val_unit;
}

/* vim: sw=4 sts=4 ts=4 et
 */
