#ifndef _SF_RECT_INC
#define _SF_RECT_INC

#include <SFML/Graphics/Rect.hpp>

value caml_copy_sfIntRect(const sf::IntRect& rect);
value caml_copy_sfFloatRect(const sf::FloatRect& rect);

sf::IntRect SfIntRect_val(value int_rect);
sf::FloatRect SfFloatRect_val(value float_rect);

#endif // _SF_RECT_INC
