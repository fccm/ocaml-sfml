#ifndef _SF_FONT_INC
#define _SF_FONT_INC

#include <SFML/Graphics/Font.hpp>


#define Val_sfFont(fnt) ((value)(fnt))
#define SfFont_val(fnt) ((sf::Font *)(fnt))

#define SfFont_val_u(font) \
            SfFont_val(Field(font,0))


#endif // _SF_FONT_INC
