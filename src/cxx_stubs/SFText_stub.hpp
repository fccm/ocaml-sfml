#ifndef _SF_TEXT_INC
#define _SF_TEXT_INC

#include <SFML/Graphics/Text.hpp>


#define Val_sfText(txt) ((value)(txt))
#define SfText_val(txt) ((sf::Text *)(txt))

#define SfText_val_u(text) \
            SfText_val(Field(text,0))


#endif // _SF_TEXT_INC
