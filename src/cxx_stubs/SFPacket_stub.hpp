#ifndef _SF_PACKET_INC
#define _SF_PACKET_INC

#include <SFML/Network/Packet.hpp>
#include "sf_caml_incs.hpp"

#define Val_sfPacket(pkt) ((value)(pkt))
#define SfPacket_val(pkt) ((sf::Packet *)(pkt))

#define SfPacket_val_u(pkt) \
            SfPacket_val(Field(pkt,0))

#endif // _SF_PACKET_INC
