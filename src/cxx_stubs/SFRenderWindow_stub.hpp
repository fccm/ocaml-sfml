#ifndef _SF_RENDERWINDOW_INC
#define _SF_RENDERWINDOW_INC

#include <SFML/Graphics/RenderWindow.hpp>

static value Val_sfRenderWindow(sf::RenderWindow * p)
{
    return caml_copy_nativeint((intnat) p);
}

static sf::RenderWindow * SfRenderWindow_val(value v)
{
    return (sf::RenderWindow *) Nativeint_val(v);
}

#endif // _SF_RENDERWINDOW_INC
