#ifndef _CSF_SPRITE_INC
#define _CSF_SPRITE_INC

#include <SFML/Graphics/Sprite.h>


#define Val_sfSprite(spr) ((value)(spr))
#define SfSprite_val(spr) ((sfSprite *)(spr))


/* overloaded types */
/* (access to the "u" field of "t") */
#define SfSprite_val_u(spr) \
            SfSprite_val(Field(spr,0)) 

#endif // _CSF_SPRITE_INC
