#ifndef _SF_CONV_VECTORS_INC
#define _SF_CONV_VECTORS_INC

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

value Val_sfVector2i(const sf::Vector2i& vec);
value Val_sfVector2u(const sf::Vector2u& vec);
value Val_sfVector2f(const sf::Vector2f& vec);
value Val_sfVector3f(const sf::Vector3f& vec);

sf::Vector2i SfVector2i_val(value ml_vec);
sf::Vector2i SfVector2i_val2(value x, value y);
sf::Vector2u SfVector2u_val2(value x, value y);
sf::Vector2u SfVector2u_val(value ml_vec);
sf::Vector2f SfVector2f_val2(value x, value y);
sf::Vector2f SfVector2f_val(value ml_vec);
sf::Vector3f SfVector3f_val(value ml_vec);
sf::Vector3f SfVector3f_val3(value x, value y, value z);

#endif // _SF_CONV_VECTORS_INC
