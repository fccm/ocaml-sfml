#ifndef _SF_SOUNDBUFFER_INC
#define _SF_SOUNDBUFFER_INC

#include <SFML/Audio/SoundBuffer.hpp>

value Val_sfSoundBuffer(sf::SoundBuffer * p);
sf::SoundBuffer * SfSoundBuffer_val(value v);

#define SfSoundBuffer_val_u(sdb) SfSoundBuffer_val(Field(sdb,0))

#endif // _SF_SOUNDBUFFER_INC

