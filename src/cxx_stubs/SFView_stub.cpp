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

#include <SFML/Graphics/View.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"
#include "SFView_stub.hpp"
#include "SFRect_stub.hpp"

static void
caml_sfView_destroy(value view)
{
    delete SfView_val(view);
}

value
Val_sfView(const sf::View *view, value origin)
{
    CAMLparam1(origin);
    CAMLlocal1(ret);
    if (origin == Val_unit)
        ret = caml_alloc_final(2, caml_sfView_destroy, 0, 1);
    else
    {
        /* The view is owned by an sf::RenderTarget that will free it when
           appropriate. Keep a pointer to the owning object in place of the
           function suite of custom blocks so that it doesn’t get GC'd. */
        ret = caml_alloc_tuple(2);
        Store_field(ret, 0, origin);
    }
    /* const correctness is ensured at runtime against the tag of the value
       using the sfView_owner_guard function below. */
    SfView_val(ret) = const_cast<sf::View *>(view);
    CAMLreturn(ret);
}

static void
sfView_owner_guard(const char *fname, value view)
{
    if (Tag_val(view) == 0)
    {
        char error[64];
        snprintf(error, sizeof(error),
                 "SFView.%s: view is owned by an SFML render target", fname);
        caml_invalid_argument(error);
    }
}

/* sf::View */

CAMLextern_C value
caml_sfView_create(value unit)
{
    CAMLparam0();
    sf::View *view = new sf::View;
    CAMLreturn(Val_sfView(view));
}

CAMLextern_C value
caml_sfView_createFromRect(value float_rect)
{
    CAMLparam1(float_rect);
    sf::View *view = new sf::View(SfFloatRect_val(float_rect));
    CAMLreturn(Val_sfView(view));
}

CAMLextern_C value
caml_sfView_copy(value view)
{
    CAMLparam1(view);
    sf::View *copy = new sf::View(*SfView_val(view));
    CAMLreturn(Val_sfView(copy));
}

CAMLextern_C value
caml_sfView_setCenter(value view, value x, value y)
{
    sfView_owner_guard("setCenter", view);
    SfView_val(view)->setCenter(SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLextern_C value
caml_sfView_setCenter2(value view, value center)
{
    sfView_owner_guard("setCenter2", view);
    SfView_val(view)->setCenter(SfVector2f_val(center));
    return Val_unit;
}

CAMLextern_C value
caml_sfView_move(value view, value offsetX, value offsetY)
{
    sfView_owner_guard("move", view);
    SfView_val(view)->move(SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLextern_C value
caml_sfView_move2(value view, value offset)
{
    sfView_owner_guard("move2", view);
    SfView_val(view)->move(SfVector2f_val(offset));
    return Val_unit;
}

CAMLextern_C value
caml_sfView_zoom(value view, value factor)
{
    sfView_owner_guard("zoom", view);
    SfView_val(view)->zoom(Double_val(factor));
    return Val_unit;
}

CAMLextern_C value
caml_sfView_getCenter(value view)
{
    sf::Vector2f center = SfView_val(view)->getCenter();
    return Val_sfVector2f(center);
}

CAMLextern_C value
caml_sfView_getSize(value view)
{
    sf::Vector2f size = SfView_val(view)->getSize();
    return Val_sfVector2f(size);
}

/* TODO
sfView* sfView_copy(sfView* view);
void sfView_setSize(sfView* view, sfVector2f size);
void sfView_setRotation(sfView* view, float angle);
void sfView_setViewport(sfView* view, sfFloatRect viewport);
void sfView_reset(sfView* view, sfFloatRect rectangle);
float sfView_getRotation(const sfView* view);
sfFloatRect sfView_getViewport(const sfView* view);
void sfView_rotate(sfView* view, float angle);
*/

// vim: sw=4 sts=4 ts=4 et
