#ifndef _CSF_FONT_INC
#define _CSF_FONT_INC

#include <SFML/Graphics/Font.h>


#define Val_sfFont(fnt) ((value)(fnt))
#define SfFont_val(fnt) ((sfFont *)(fnt))

/* overloaded type */
/* (access to the "u" field of "t") */
#define SfFont_val_u(font) \
            SfFont_val(Field(font,0))

#endif // _CSF_FONT_INC
