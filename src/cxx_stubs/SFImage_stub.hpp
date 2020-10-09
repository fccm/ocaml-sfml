#ifndef _SF_IMAGE_INC
#define _SF_IMAGE_INC

#include <SFML/Graphics/Image.hpp>

value Val_sfImage(sf::Image * p);
sf::Image * SfImage_val(value v);


#define SfImage_val_u(img) \
            SfImage_val(Field(img,0))


#endif // _SF_IMAGE_INC
