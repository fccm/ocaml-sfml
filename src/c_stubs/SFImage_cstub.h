#ifndef _CSF_IMAGE_INC
#define _CSF_IMAGE_INC

#include <SFML/Graphics/Image.h>


#define Val_sfImage(img) ((value)(img))
#define SfImage_val(img) ((sfImage *)(img))


/* overloaded types */
/* (access to the "u" field of "t") */
#define SfImage_val_u(img) \
            SfImage_val(Field(img,0))


value caml_copy_sfImage(sfImage *img);


#endif // _CSF_IMAGE_INC
