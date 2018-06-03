#ifndef _SF_CONTEXTSETTINGS_INC
#define _SF_CONTEXTSETTINGS_INC

#include <SFML/Window/ContextSettings.hpp>

void SfContextSettings_val(sf::ContextSettings *settings, value ml_settings);
value Val_sfContextSettings(const sf::ContextSettings *settings);

#endif // _SF_CONTEXTSETTINGS_INC
