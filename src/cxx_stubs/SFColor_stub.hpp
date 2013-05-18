#ifndef _SF_CONV_COLOR_INC
#define _SF_CONV_COLOR_INC

#include <SFML/Graphics/Color.hpp>

sf::Color SfColor_val(value color);
value Val_sfColor4(const sf::Color& color);
value Val_sfColor3(const sf::Color& color);
value Val_RGB(const sf::Color& color);
value Val_RGBA(const sf::Color& color);

#endif // _SF_CONV_COLOR_INC
