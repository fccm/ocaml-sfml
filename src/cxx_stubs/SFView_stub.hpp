#ifndef _SF_VIEW_INC
#define _SF_VIEW_INC

#include <SFML/Graphics/View.hpp>


value Val_sfView(sf::View *view, value origin = Val_unit);

#define SfView_val(view) (*(sf::View **)(Data_custom_val(view)))


#endif // _SF_VIEW_INC
