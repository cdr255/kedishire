#include "audio.h"

const int stream_buffers = 33;
const int stream_samples = 33;

bool playmod(ALLEGRO_AUDIO_STREAM **stream, const char *filename)
{
  *stream = al_load_audio_stream(filename, stream_buffers, stream_samples);
  al_attach_audio_stream_to_mixer(*stream, al_get_default_mixer());
  return true;
}
