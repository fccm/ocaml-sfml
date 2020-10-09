#ifndef _SF_SPRITE_INC
#define _SF_SPRITE_INC

#include <SFML/Graphics/Sprite.hpp>

value Val_sfSprite(sf::Sprite * p);
sf::Sprite * SfSprite_val(value v);

#define SfSprite_val_u(sprite) \
            SfSprite_val(Field(sprite,0))


#endif // _SF_SPRITE_INC
