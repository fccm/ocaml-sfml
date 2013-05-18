#ifndef _CSF_TIME_INC
#define _CSF_TIME_INC

#include <SFML/System/Time.h>

#include "sf_caml_incs_c.h"

value Val_sfTime(sfTime *time);
value Val_sfTime_u(sfTime *time);

#define SfTime_val(time) \
    (*((sfTime *) Data_custom_val(time)))

#define SfTime_val_u(t) \
            SfTime_val(Field(t,0))


/* Missing functions in CSFML */

sfTime sfTime_add(sfTime a, sfTime b);

sfTime sfTime_error_f();
sfBool sfTime_isError(sfTime t);

#endif /* _CSF_TIME_INC */
