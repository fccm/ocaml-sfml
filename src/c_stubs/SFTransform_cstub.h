#ifndef _CSF_TRANSFORM_INC
#define _CSF_TRANSFORM_INC

#include <SFML/Graphics/Transform.h>


value Val_sfTransform(const sfTransform *trans);


#define SfTransform_val(tr) \
    ((sfTransform *) Data_custom_val(tr))


#define SfTransform_val_struct(tr) \
    (*SfTransform_val(tr))


#endif // _CSF_TRANSFORM_INC
