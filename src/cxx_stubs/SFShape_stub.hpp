#ifndef _SF_SHAPE_INC
#define _SF_SHAPE_INC

#include <SFML/Graphics/Shape.hpp>

value Val_sfShape(sf::Shape * p);
sf::Shape * SfShape_val(value v);

#define SfShape_val_u(shape) \
            SfShape_val(Field(shape,0))


#endif // _SF_SHAPE_INC
