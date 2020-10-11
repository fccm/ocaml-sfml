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

#include <SFML/Graphics/View.h>

#include "sf_caml_incs_c.h"
#include "sf_conv_vectors_c.h"
#include "SFView_cstub.h"
#include "SFRect_cstub.h"

value Val_sfView(sfView *view, value deletable) {
    CAMLparam0();
    CAMLlocal1(var);
    var = caml_alloc(2, 0);
    Store_field(var, 0, ((value) (view)));
    Store_field(var, 1, deletable);
    CAMLreturn(var);
}

/* sfView */

CAMLprim value
caml_sfView_create(value unit)
{
    sfView *view = sfView_create();
    if (!view) caml_failwith("SFView.create");
    return Val_sfView(view, Val_true);
}

CAMLprim value
caml_sfView_createFromRect(value float_rect)
{
    sfFloatRect rect;
    SfFloatRect_val(&rect, float_rect);
    sfView *view = sfView_createFromRect(rect);
    if (!view) caml_failwith("SFView.createFromRect");
    return Val_sfView(view, Val_true);
}

CAMLprim value
caml_sfView_destroy(value view)
{
    if (sfView_deletable(view)) {
        sfView_destroy(SfView_val(view));
    }
    return Val_unit;
}

CAMLprim value
caml_sfView_setCenter2(value view, value x, value y)
{
    sfView_setCenter(SfView_val(view), SfVector2f_val2(x, y));
    return Val_unit;
}

CAMLprim value
caml_sfView_setCenter(value view, value center)
{
    sfView_setCenter(SfView_val(view), SfVector2f_val(center));
    return Val_unit;
}

CAMLprim value
caml_sfView_setSize2(value view, value width, value height)
{
	sfView_setSize(SfView_val(view), SfVector2f_val2(width, height));
	return Val_unit;
}

CAMLprim value
caml_sfView_setSize(value view, value size)
{
	sfView_setSize(SfView_val(view), SfVector2f_val(size));
	return Val_unit;
}

CAMLprim value
caml_sfView_move2(value view, value offsetX, value offsetY)
{
    sfView_move(SfView_val(view), SfVector2f_val2(offsetX, offsetY));
    return Val_unit;
}

CAMLprim value
caml_sfView_move(value view, value offset)
{
    sfView_move(SfView_val(view), SfVector2f_val(offset));
    return Val_unit;
}

CAMLprim value
caml_sfView_zoom(value view, value factor)
{
    sfView_zoom(SfView_val(view), Double_val(factor));
    return Val_unit;
}

CAMLprim value
caml_sfView_getCenter(value view)
{
    sfVector2f center = sfView_getCenter(SfView_val(view));
    return Val_sfVector2f(&center);
}

CAMLprim value
caml_sfView_getSize(value view)
{
    sfVector2f size = sfView_getSize(SfView_val(view));
    return Val_sfVector2f(&size);
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

/* vim: sw=4 sts=4 ts=4 et
 */
