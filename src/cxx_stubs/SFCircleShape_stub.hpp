#ifndef _SF_CIRCLESHAPE_INC
#define _SF_CIRCLESHAPE_INC

#include <SFML/Graphics/CircleShape.hpp>

#define Val_sfCircleShape(cs) ((value)(cs))
#define SfCircleShape_val(cs) ((sf::CircleShape *)(cs))

#define SfCircleShape_val_u(shape) \
            SfCircleShape_val(Field(shape,0))

#endif // _SF_CIRCLESHAPE_INC
