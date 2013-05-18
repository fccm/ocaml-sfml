#ifndef _SF_SOCKET_INC
#define _SF_SOCKET_INC

#include <SFML/Network/Socket.hpp>


#define check_sfSocketStatus(st, mod_name) \
  switch (st) { \
  case sf::Socket::Done: break; \
  case sf::Socket::NotReady: \
    caml_raise_constant(*caml_named_value(mod_name ".Socket_Not_Ready")); break; \
  case sf::Socket::Disconnected: \
    caml_raise_constant(*caml_named_value(mod_name ".Socket_Disconnected")); break; \
  case sf::Socket::Error: \
    caml_raise_constant(*caml_named_value(mod_name ".Socket_Error")); break; \
  default: caml_failwith(mod_name ": Error"); \
  }

#endif // _SF_SOCKET_INC
