#ifndef _SF_TEXT_INC
#define _SF_TEXT_INC

#include <SFML/Graphics/Text.hpp>


value Val_sfText(sf::Text * p);
sf::Text * SfText_val(value v);

#define SfText_val_u(text) \
            SfText_val(Field(text,0))


#endif // _SF_TEXT_INC
