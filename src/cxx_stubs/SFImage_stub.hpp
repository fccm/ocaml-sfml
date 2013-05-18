#ifndef _SF_IMAGE_INC
#define _SF_IMAGE_INC

#include <SFML/Graphics/Image.hpp>

#define Val_sfImage(img) ((value)(img))
#define SfImage_val(img) ((sf::Image *)(img))


#define SfImage_val_u(img) \
            SfImage_val(Field(img,0))


#endif // _SF_IMAGE_INC
