#ifndef _CSF_SOUNDBUFFER_INC
#define _CSF_SOUNDBUFFER_INC

#include <SFML/Audio/SoundBuffer.h>

#define Val_sfSoundBuffer(sbf) ((value)(sbf))
#define SfSoundBuffer_val(sbf) ((sfSoundBuffer *)(sbf))

#define SfSoundBuffer_val_u(sbf) SfSoundBuffer_val(Field(sbf,0))

#endif // _CSF_SOUNDBUFFER_INC
