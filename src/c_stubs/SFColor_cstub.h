#ifndef _CSF_CONV_COLOR_INC
#define _CSF_CONV_COLOR_INC

#include <SFML/Graphics/Color.h>

void SfColor_val(sfColor *color, value ml_color);
value Val_sfColor4(sfColor *color);
value Val_sfColor3(sfColor *color);
value Val_RGB(sfColor *color);
value Val_RGBA(sfColor *color);

#endif // _CSF_CONV_COLOR_INC
