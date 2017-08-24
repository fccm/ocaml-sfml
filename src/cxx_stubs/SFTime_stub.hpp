#ifndef _SF_TIME_INC
#define _SF_TIME_INC

#include "sf_caml_incs.hpp"

#define Val_sfTime(t) caml_copy_int64(t.asMicroseconds())

#define SfTime_val(v) sf::microseconds(Int64_val(v))

#endif // _SF_TIME_INC
