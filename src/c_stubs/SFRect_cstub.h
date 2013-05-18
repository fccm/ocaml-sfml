#ifndef _CSF_RECT_INC
#define _CSF_RECT_INC

#include <SFML/Graphics/Rect.h>

value caml_copy_sfIntRect(sfIntRect *rect);
value caml_copy_sfFloatRect(sfFloatRect *rect);

void SfFloatRect_val(sfFloatRect *rect, value float_rect);
void SfIntRect_val(sfIntRect *rect, value int_rect);

#endif // _CSF_RECT_INC
