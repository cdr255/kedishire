#ifndef _AUDIO_H_
#define _AUDIO_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

extern const int stream_buffers;
extern const int stream_samples;
bool playmod(ALLEGRO_AUDIO_STREAM **stream, const char * filename);


#endif
