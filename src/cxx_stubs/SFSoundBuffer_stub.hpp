#ifndef _SF_SOUNDBUFFER_INC
#define _SF_SOUNDBUFFER_INC

#include <SFML/Audio/SoundBuffer.hpp>

#define Val_sfSoundBuffer(sdb) ((value)(sdb))
#define SfSoundBuffer_val(sdb) ((sf::SoundBuffer *)(sdb))

#define SfSoundBuffer_val_u(sdb) SfSoundBuffer_val(Field(sdb,0))

#endif // _SF_SOUNDBUFFER_INC

