#ifndef _SF_SPRITE_INC
#define _SF_SPRITE_INC

#include <SFML/Graphics/Sprite.hpp>


#define Val_sfSprite(spr) ((value)(spr))
#define SfSprite_val(spr) ((sf::Sprite *)(spr))

#define SfSprite_val_u(sprite) \
            SfSprite_val(Field(sprite,0))


#endif // _SF_SPRITE_INC
