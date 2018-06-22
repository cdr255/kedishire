#include "tiles.h"

const int tilesize = 16;

bool tileset_load(struct tileset **tileset, struct tile **tiles, const char *tileset_image)
{
  *tileset = calloc(1, sizeof(struct tileset));
  int counter = 0;
  (*tileset)->image = al_load_bitmap(tileset_image);
  assert((*tileset)->image);
  (*tileset)->width = al_get_bitmap_width((*tileset)->image) / tilesize;
  (*tileset)->height = al_get_bitmap_height((*tileset)->image) / tilesize;
  (*tileset)->number_of_tiles = (*tileset)->width * (*tileset)->height;

  *tiles = calloc((*tileset)->number_of_tiles, sizeof(struct tile));

  for(int h=0;h < (*tileset)->height;h++)
    {
      for(int w=0;w < (*tileset)->width;w++)
  	{
  	  (*tiles)[counter].image = al_create_sub_bitmap((*tileset)->image, w*tilesize, h*tilesize, tilesize, tilesize);
  	  assert((*tiles)[counter].image);
  	  counter++;
  	}
    }
  return true;
  
}

bool tileset_free(struct tileset **tileset, struct tile **tiles)
{
  free(*tileset);
  free(*tiles);
}
