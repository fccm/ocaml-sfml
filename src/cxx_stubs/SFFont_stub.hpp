#ifndef _SF_FONT_INC
#define _SF_FONT_INC

#include <SFML/Graphics/Font.hpp>


value Val_sfFont(sf::Font * p);
sf::Font * SfFont_val(value v);

#define SfFont_val_u(font) \
            SfFont_val(Field(font,0))


#endif // _SF_FONT_INC
