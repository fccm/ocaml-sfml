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

#include <SFML/Window/Cursor.hpp>

#include "sf_caml_incs.hpp"
#include "sf_conv_vectors.hpp"

#include "SFCursor_stub.hpp"

void
caml_sfCursor_destroy(value cursor)
{
	delete SfCursor_val(cursor);
}

CAMLextern_C value
caml_sfCursor_loadFromPixels(value data, value size, value hotspot)
{
	CAMLparam3(data, size, hotspot);
	sf::Cursor* cursor = new sf::Cursor;

	if (!cursor->loadFromPixels((const sf::Uint8*)String_val(data), SfVector2u_val(size), SfVector2u_val(hotspot)))
	{
		delete cursor;
		caml_failwith("SFCursor.loadFromPixels");
	}
	CAMLlocal1(ml_cursor);
	ml_cursor = caml_alloc_final(2, caml_sfCursor_destroy, 0, 1);
	SfCursor_val(ml_cursor) = cursor;
	CAMLreturn(ml_cursor);
}

CAMLextern_C value
caml_sfCursor_loadFromSystem(value type)
{
	CAMLparam1(type);
	sf::Cursor* cursor = new sf::Cursor;

	if (!cursor->loadFromSystem((sf::Cursor::Type)Long_val(type)))
	{
		delete cursor;
		caml_failwith("SFCursor.loadFromSystem");
	}
	CAMLlocal1(ml_cursor);
	ml_cursor = caml_alloc_final(2, caml_sfCursor_destroy, 0, 1);
	SfCursor_val(ml_cursor) = cursor;
	CAMLreturn(ml_cursor);
}
