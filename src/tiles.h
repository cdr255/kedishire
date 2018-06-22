#ifndef _TILES_H_
#define _TILES_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <assert.h>


extern const int tilesize;

struct tile {
  ALLEGRO_BITMAP *image;
  int collision;
};

struct tileset {
  ALLEGRO_BITMAP *image;
  int width, height, number_of_tiles;
};


bool tileset_load(struct tileset **tileset, struct tile **tiles, const char *tileset_image);
bool tileset_free(struct tileset **tileset, struct tile **tiles);
 

#endif
