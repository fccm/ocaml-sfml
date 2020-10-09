#ifndef _SF_CIRCLESHAPE_INC
#define _SF_CIRCLESHAPE_INC

#include <SFML/Graphics/CircleShape.hpp>

value Val_sfCircleShape(sf::CircleShape * cs);
sf::CircleShape * SfCircleShape_val(value cs);

#define SfCircleShape_val_u(shape) \
            SfCircleShape_val(Field(shape,0))

#endif // _SF_CIRCLESHAPE_INC
