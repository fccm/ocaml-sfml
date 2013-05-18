#ifndef _SF_SHAPE_INC
#define _SF_SHAPE_INC

#include <SFML/Graphics/Shape.hpp>


#define Val_sfShape(shp) ((value)(shp))
#define SfShape_val(shp) ((sf::Shape *)(shp))

#define SfShape_val_u(shape) \
            SfShape_val(Field(shape,0))


#endif // _SF_SHAPE_INC
