#ifndef _SF_VIDEOMODE_INC
#define _SF_VIDEOMODE_INC

#include <SFML/Window/VideoMode.hpp>

value copy_sfVideoMode_contents(const sf::VideoMode& mode);

#define SfVideoMode_val(mode, ml_mode) \
  do{ \
    (mode)->width        = Long_val(Field(ml_mode, 0)); \
    (mode)->height       = Long_val(Field(ml_mode, 1)); \
    (mode)->bitsPerPixel = Long_val(Field(ml_mode, 2)); \
  }while(0)

#endif // _SF_VIDEOMODE_INC
