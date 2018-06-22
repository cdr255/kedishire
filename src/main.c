#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tiles.h"
#include "audio.h"
#include "map.h"

int main(int argc, char ** argv)
{
  // Declare
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_AUDIO_STREAM *stream = NULL;
  ALLEGRO_SAMPLE *sample = NULL;
  struct tileset *tileset;
  struct tile *tiles;
  struct map *background;

  int mapping[5][8] = {
		       {0, 1, 2, 3, 4, 5, 6, 7},
		       {8, 9, 10, 11, 12, 13, 14, 15},
		       {16, 17, 18, 19, 20, 21, 22, 23},
		       {24, 25, 26, 27, 28, 29, 30, 31},
		       {32, 33, 34, 35, 36, 37, 38, 39}
  };

  int mapping0[5][8] = {
			{27, 27, 27, 27, 27, 27, 27, 27},
			{27, 27, 27, 27, 27, 27, 27, 27},
			{27, 27, 27, 27, 27, 27, 27, 27},
			{27, 27, 27, 27, 27, 27, 27, 27},
			{27, 27, 27, 27, 27, 27, 27, 27}
  };
  
  // Initialize
  /// VIDEO
  al_init();
  al_init_image_addon();
  display = al_create_display(8*tilesize, 5*tilesize);
  tileset_load(&tileset, &tiles, "castle.png");
  map_load(&map, &tiles, 8, 5, mapping);
  map_load(&background, &tiles, 8, 5, mapping0);
  /// AUDIO
  al_install_audio();
  al_init_acodec_addon();
  al_reserve_samples(5);
  playmod(&stream, "test.xm");

  // Clear
  al_clear_to_color(al_map_rgba(255,0,0,200));

  //assert(test);

  printf("1, 1 is: %d", map->tilemap[1][1]);
  // Draw
  //  al_draw_bitmap(map->tiles[1].image, 1*tilesize, 1*tilesize, 0);
  for(int h = 0;h < map->height;h++)
    {
      for(int w = 0;w < map->width;w++)
  	{
  	  al_draw_bitmap(background->tiles[background->tilemap[h][w]].image, w*tilesize, h*tilesize, 0);
	  al_draw_bitmap(map->tiles[map->tilemap[h][w]].image, w*tilesize, h*tilesize, 0);
  	    }
    }
  // Display
  al_flip_display();
  al_rest(10);

  // Clean up
  /// AUDIO
  al_destroy_audio_stream(stream);
  al_uninstall_audio();
  /// VIDEO
  map_free(&map);
  tileset_free(&tileset, &tiles);
  al_shutdown_image_addon();
  al_destroy_display(display);
  
  return 0;
}
