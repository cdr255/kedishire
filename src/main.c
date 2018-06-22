#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tiles.h"
#include "audio.h"

int main(int argc, char ** argv)
{
  // Declare
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_AUDIO_STREAM *stream = NULL;
  ALLEGRO_SAMPLE *sample = NULL;
  struct tileset *tileset;
  struct tile *tiles;

  // Initialize
  /// VIDEO
  al_init();
  al_init_image_addon();
  display = al_create_display(8*tilesize, 5*tilesize);
  tileset_load(&tileset, &tiles, "castle.png");
  /// AUDIO
  al_install_audio();
  al_init_acodec_addon();
  al_reserve_samples(5);
  playmod(&stream, "test.xm");

  // Clear
  al_clear_to_color(al_map_rgba(255,0,0,200));

  // Draw
  al_draw_bitmap(tiles[11].image, 1*tilesize, 1*tilesize, 0);

  // Display
  al_flip_display();
  al_rest(1);

  // Clean up
  /// AUDIO
  al_destroy_audio_stream(stream);
  al_uninstall_audio();
  /// VIDEO
  tileset_free(&tileset, &tiles);
  al_shutdown_image_addon();
  al_destroy_display(display);
  
  return 0;
}
