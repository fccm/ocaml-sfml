#ifndef _SF_TIME_INC
#define _SF_TIME_INC

#include <SFML/System/Time.hpp>
#include "sf_caml_incs.hpp"

value Val_sfTime(const sf::Time& t);
value Val_sfTime_u(sf::Time t);

#define SfTime_val(t) ((sf::Time *)(t))

#define SfTime_val_u(t) \
            SfTime_val(Field(t,0))

#endif // _SF_TIME_INC
