#ifndef _CSF_TEXT_INC
#define _CSF_TEXT_INC

#include <SFML/Graphics/Text.h>


#define Val_sfText(txt) ((value)(txt))
#define SfText_val(txt) ((sfText *)(txt))


/* overloaded types */
/* (access to the "u" field of "t") */
#define SfText_val_u(txt)       SfText_val(Field(txt,0))


#endif // _CSF_TEXT_INC
