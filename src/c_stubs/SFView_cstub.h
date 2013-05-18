#ifndef _CSF_VIEW_INC
#define _CSF_VIEW_INC

#include <SFML/Graphics/View.h>


value Val_sfView(sfView *view, value deletable);

#define SfView_val(view) ((sfView *)(Field(view,0)))

#define sfView_deletable(view) \
    Bool_val(Field(view,1))


#endif // _CSF_VIEW_INC
