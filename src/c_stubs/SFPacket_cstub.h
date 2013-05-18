#ifndef _CSF_PACKET_INC
#define _CSF_PACKET_INC

#include <SFML/Network/Packet.h>

#define Val_sfPacket(p) ((value)(p))
#define SfPacket_val(p) ((sfPacket*)(p))
#define SfPacket_val_u(p) ((sfPacket*)(Field(p,0)))

#endif // _CSF_PACKET_INC
