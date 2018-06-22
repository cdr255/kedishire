#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tiles.h"

int main(int argc, char ** argv)
{
  // Declare
  ALLEGRO_DISPLAY *display = NULL;
  struct tileset *tileset;
  struct tile *tiles;

  // Initialize
  al_init();
  al_init_image_addon();
  display = al_create_display(8*tilesize, 5*tilesize);
  tileset_load(&tileset, &tiles, "castle.png");


  // Clear
  al_clear_to_color(al_map_rgba(255,0,0,200));

  // Draw
  al_draw_bitmap(tiles[11].image, 1*tilesize, 1*tilesize, 0);

  // Display
  al_flip_display();
  al_rest(1);

  // Clean up
  tileset_free(&tileset, &tiles);
  al_destroy_display(display);
  al_shutdown_image_addon();
  return 0;
}
