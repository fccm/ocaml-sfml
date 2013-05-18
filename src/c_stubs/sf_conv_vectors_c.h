#ifndef _CSF_CONV_VECTORS_INC
#define _CSF_CONV_VECTORS_INC

#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

value Val_sfVector2i(sfVector2i *vec);
value Val_sfVector2u(sfVector2u *vec);
value Val_sfVector2f(sfVector2f *vec);
value Val_sfVector3f(sfVector3f *vec);

sfVector2i SfVector2i_val(value vec);
sfVector2i SfVector2i_val2(value x, value y);
sfVector2u SfVector2u_val2(value x, value y);
sfVector2u SfVector2u_val(value ml_vec);
sfVector2f SfVector2f_val2(value x, value y);
sfVector2f SfVector2f_val(value ml_vec);
sfVector3f SfVector3f_val(value ml_vec);
sfVector3f SfVector3f_val3(value x, value y, value z);

#endif // _CSF_CONV_VECTORS_INC
