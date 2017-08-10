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

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "sf_conv_vectors.hpp"
#include "sf_conv_style.hpp"
#include "sf_context_settings.hpp"

#include "SFRenderWindow_stub.hpp"
#include "SFRenderStates_stub.hpp"
#include "SFVideoMode_stub.hpp"
#include "SFView_stub.hpp"
#include "SFEvent_stub.hpp"
#include "SFColor_stub.hpp"
#include "SFImage_stub.hpp"
#include "SFText_stub.hpp"
#include "SFSprite_stub.hpp"
#include "SFShape_stub.hpp"
#include "SFCircleShape_stub.hpp"


/* sf::RenderWindow */

CAMLextern_C value
caml_sfRenderWindow_create(
    value ml_mode, value title, value ml_style, value ml_settings)
{
    sf::ContextSettings settings;

    settings.depthBits         = Long_val(Field(ml_settings, 0));
    settings.stencilBits       = Long_val(Field(ml_settings, 1));
    settings.antialiasingLevel = Long_val(Field(ml_settings, 2));
    settings.majorVersion      = Long_val(Field(ml_settings, 3));
    settings.minorVersion      = Long_val(Field(ml_settings, 4));

    sf::VideoMode mode;
    SfVideoMode_val(&mode, ml_mode);

    sf::Uint32 style = SfStyle_val(ml_style);

    sf::RenderWindow *window;
    window = new sf::RenderWindow;
    window->create(mode, String_val(title), style, settings);

    return Val_sfRenderWindow(window);
}

CAMLextern_C value
caml_sfRenderWindow_createFromHandle(value ml_handle, value ml_settings)
{
    sf::ContextSettings settings;

    settings.depthBits         = Long_val(Field(ml_settings, 0));
    settings.stencilBits       = Long_val(Field(ml_settings, 1));
    settings.antialiasingLevel = Long_val(Field(ml_settings, 2));
    settings.majorVersion      = Long_val(Field(ml_settings, 3));
    settings.minorVersion      = Long_val(Field(ml_settings, 4));

    sf::RenderWindow *window;
    window = new sf::RenderWindow;
    window->create(
            (sf::WindowHandle) Nativeint_val(ml_handle), settings);

    return Val_sfRenderWindow(window);
}

CAMLextern_C value
caml_sfRenderWindow_isOpen(value win)
{
    return Val_bool(
        SfRenderWindow_val(win)->isOpen());
}

CAMLextern_C value
caml_sfRenderWindow_close(value win)
{
    SfRenderWindow_val(win)->close();
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_display(value win)
{
    caml_enter_blocking_section();
    SfRenderWindow_val(win)->display();
    caml_leave_blocking_section();
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_destroy(value win)
{
    delete SfRenderWindow_val(win);
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_pollEvent(value win)
{
    sf::Event event;
    const char func_msg[] = "SFRenderWindow.pollEvent";
    bool isev = SfRenderWindow_val(win)->pollEvent(event);
    if (isev) return Val_some(Val_sfEvent(event, func_msg));
    else return Val_none;
}

CAMLextern_C value
caml_sfRenderWindow_waitEvent(value win)
{
    sf::Event event;
    const char func_name[] = "SFRenderWindow.waitEvent";
    bool err = SfRenderWindow_val(win)->waitEvent(event);
    if (err) caml_failwith(func_name);
    return Val_sfEvent(event, func_name);
}

CAMLextern_C value
caml_sfRenderWindow_clear(value win, value color)
{
    SfRenderWindow_val(win)->clear(SfColor_val(color));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_blank(value win)
{
    SfRenderWindow_val(win)->clear(sf::Color::Black);
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_getSize(value win)
{
    sf::Vector2u size = SfRenderWindow_val(win)->getSize();
    return Val_sfVector2u(size);
}

CAMLextern_C value
caml_sfRenderWindow_getWidth(value win)
{
    sf::Vector2u size = SfRenderWindow_val(win)->getSize();
    return Val_long(size.x);
}

CAMLextern_C value
caml_sfRenderWindow_getHeight(value win)
{
    sf::Vector2u size = SfRenderWindow_val(win)->getSize();
    return Val_long(size.y);
}

CAMLextern_C value
caml_sfRenderWindow_setSize(value win, value width, value height)
{
    SfRenderWindow_val(win)->setSize(SfVector2u_val2(width, height));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setSize2(value win, value size)
{
    SfRenderWindow_val(win)->setSize(SfVector2u_val(size));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_drawSprite(
        value win, value sprite, value ml_states, value unit)
{
    if (ml_states == Val_none) {
        SfRenderWindow_val(win)->draw(*SfSprite_val_u(sprite));
    } else {
        sf::RenderStates states = *SfRenderStates_val(Some_val(ml_states));
        SfRenderWindow_val(win)->draw(*SfSprite_val_u(sprite), states);
    }
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_drawText(value win, value text, value ml_states, value unit)
{
    if (ml_states == Val_none) {
        SfRenderWindow_val(win)->draw(*SfText_val_u(text));
    } else {
        sf::RenderStates states = *SfRenderStates_val(Some_val(ml_states));
        SfRenderWindow_val(win)->draw(*SfText_val_u(text), states);
    }
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_drawShape(
        value win, value shape, value ml_states, value unit)
{
    if (ml_states == Val_none) {
        SfRenderWindow_val(win)->draw(*SfShape_val_u(shape));
    } else {
        sf::RenderStates states = *SfRenderStates_val(Some_val(ml_states));
        SfRenderWindow_val(win)->draw(*SfShape_val_u(shape), states);
    }
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_drawCircleShape(
        value win, value shape, value ml_states, value unit)
{
    if (ml_states == Val_none) {
        SfRenderWindow_val(win)->draw(*SfCircleShape_val_u(shape));
    } else {
        sf::RenderStates states = *SfRenderStates_val(Some_val(ml_states));
        SfRenderWindow_val(win)->draw(*SfCircleShape_val_u(shape), states);
    }
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setPosition(value win, value left, value top)
{
    SfRenderWindow_val(win)->setPosition(SfVector2i_val2(left, top));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setPosition2(value win, value position)
{
    SfRenderWindow_val(win)->setPosition(SfVector2i_val(position));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setMouseCursorVisible(value win, value show)
{
    SfRenderWindow_val(win)->setMouseCursorVisible(Bool_val(show));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setMouseCursorGrabbed(value win, value grabbed)
{
    SfRenderWindow_val(win)->setMouseCursorGrabbed(Bool_val(grabbed));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setVisible(value win, value visible)
{
    SfRenderWindow_val(win)->setVisible(Bool_val(visible));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setKeyRepeatEnabled(value win, value enabled)
{
    SfRenderWindow_val(win)->setKeyRepeatEnabled(Bool_val(enabled));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setActive(value win, value active)
{
    bool status = SfRenderWindow_val(win)->setActive(Bool_val(active));
    if (!status) caml_failwith("SFRenderWindow.setActive");
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setFramerateLimit(value win, value limit)
{
    SfRenderWindow_val(win)->setFramerateLimit(Long_val(limit));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setView(value win, value view)
{
    SfRenderWindow_val(win)->setView(*SfView_val(view));
    return Val_unit;
}

/* TODO
CAMLextern_C value
caml_sfRenderWindow_convertCoords(value win, value point, value targetView)
{
    sf::Vector2f res =
        SfRenderWindow_val(win)->convertCoords(
                SfVector2i_val(point), *SfView_val(targetView));
    return Val_sfVector2f(res);
}
*/

CAMLextern_C value
caml_sfRenderWindow_setVerticalSyncEnabled(value win, value enabled)
{
    SfRenderWindow_val(win)->setVerticalSyncEnabled(Bool_val(enabled));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_setJoystickThreshold(value win, value threshold)
{
    SfRenderWindow_val(win)->setJoystickThreshold(Double_val(threshold));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_getMousePosition(value relativeTo)
{
    sf::Vector2i pos = sf::Mouse::getPosition(*SfRenderWindow_val(relativeTo));
    return Val_sfVector2i(pos);
}

CAMLextern_C value
caml_sfRenderWindow_setMousePosition(value relativeTo, value position)
{
    sf::Mouse::setPosition(
            SfVector2i_val(position), *SfRenderWindow_val(relativeTo));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_pushGLStates(value win)
{
    SfRenderWindow_val(win)->pushGLStates();
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_popGLStates(value win)
{
    SfRenderWindow_val(win)->popGLStates();
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_resetGLStates(value win)
{
    SfRenderWindow_val(win)->resetGLStates();
    return Val_unit;
}


// XXX: TODO: put it in SFImage_stub.hpp
CAMLextern_C value caml_sfImage_destroy(value img);


void finalize_captured(value img)
{
#if defined(_OCAML_SFML_DEBUG)
    // XXX: DEBUG
    std::cout << "# capture finalize..." << std::endl << std::flush;
    std::cout << "# " << String_val(Field(img,1)) << std::endl << std::flush;
#endif

    caml_sfImage_destroy((value) SfImage_val_u(img));

#if defined(_OCAML_SFML_DEBUG)
    // XXX: DEBUG
    std::cout << "# capture finalize done!" << std::endl << std::flush;
#endif
}

static value
caml_copy_sfImage(const sf::Image& img)
{
    CAMLparam0();
    CAMLlocal1(ret);
    sf::Image *copy = new sf::Image;
    *copy = img;
    ret = caml_alloc_final(2, &finalize_captured, 0, 1);
    Store_field(ret, 0, Val_sfImage(copy));
    Store_field(ret, 1, caml_copy_string("captured image"));
    CAMLreturn(ret);
}

CAMLextern_C value
caml_sfRenderWindow_capture(value win)
{
    sf::Image cap = SfRenderWindow_val(win)->capture();
    return caml_copy_sfImage(cap);  // XXX TODO: test and debug me!
}

CAMLextern_C value
caml_sfRenderWindow_getSettings(value win)
{
    sf::ContextSettings settings = SfRenderWindow_val(win)->getSettings();
    return Val_sfContextSettings(&settings);
}

CAMLextern_C value
caml_sfRenderWindow_setTitle(value win, value title)
{
    SfRenderWindow_val(win)->setTitle(String_val(title));
    return Val_unit;
}

CAMLextern_C value
caml_sfRenderWindow_getView(value win)
{
    CAMLparam1(win);
    CAMLreturn(Val_sfView(&SfRenderWindow_val(win)->getView(), win));
}

/* TODO
sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow);

void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, unsigned int width,
        unsigned int height, const sfUint8* pixels);

sfWindowHandle sfRenderWindow_getSystemHandle(
        const sfRenderWindow* renderWindow);

const sfView* sfRenderWindow_getDefaultView(
        const sfRenderWindow* renderWindow);

sfIntRect sfRenderWindow_getViewport(
        const sfRenderWindow* renderWindow, const sfView* view);

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

/* TODO
RenderWindow();
RenderWindow(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
explicit RenderWindow(WindowHandle handle, const ContextSettings& settings = ContextSettings());
virtual ~RenderWindow();
virtual Vector2u getSize() const;
Image capture() const;
protected:
virtual void onCreate();
virtual void onResize();
*/

// vim: sw=4 sts=4 ts=4 et
