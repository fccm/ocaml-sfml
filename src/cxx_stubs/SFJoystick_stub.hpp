#ifndef _SF_JOYSTICK_INC
#define _SF_JOYSTICK_INC

#include <SFML/Window/Joystick.hpp>

value Val_sfJoystickAxis(sf::Joystick::Axis axis);
sf::Joystick::Axis SfJoystickAxis_val(value axis);

#endif // _SF_JOYSTICK_INC
