#ifndef _SF_PACKET_INC
#define _SF_PACKET_INC

#include <SFML/Network/Packet.hpp>
#include "sf_caml_incs.hpp"

value Val_sfPacket(sf::Packet * p);
sf::Packet * SfPacket_val(value v);

#define SfPacket_val_u(pkt) \
            SfPacket_val(Field(pkt,0))

#endif // _SF_PACKET_INC
