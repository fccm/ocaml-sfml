#ifndef _SF_TRANSFORM_INC
#define _SF_TRANSFORM_INC

#include <SFML/Graphics/Transform.hpp>


#define SfTransform_val(tr) \
    ((sf::Transform *) Data_custom_val(tr))


#define SfTransform_val_s(tr) \
    (*SfTransform_val(tr))


#endif // _SF_TRANSFORM_INC
