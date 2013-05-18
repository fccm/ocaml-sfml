#ifndef _SF_VIEW_INC
#define _SF_VIEW_INC

#include <SFML/Graphics/View.hpp>


value Val_sfView(sf::View *view, value deletable);

#define SfView_val(view) ((sf::View *)(Field(view,0)))

#define sfView_deletable(view) \
    Bool_val(Field(view,1))


#endif // _SF_VIEW_INC
