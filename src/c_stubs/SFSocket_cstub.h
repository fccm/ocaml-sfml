
#define check_sfSocketStatus(st, mod_name) \
    switch (st) { \
    case sfSocketDone: break; \
    case sfSocketNotReady: \
        caml_raise_constant(*caml_named_value(mod_name ".Socket_Not_Ready")); break; \
    case sfSocketDisconnected: \
        caml_raise_constant(*caml_named_value(mod_name ".Socket_Disconnected")); break; \
    case sfSocketError: \
        caml_raise_constant(*caml_named_value(mod_name ".Socket_Error")); break; \
    }
