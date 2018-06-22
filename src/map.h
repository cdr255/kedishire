#ifndef _MAP_H_
#define _MAP_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <assert.h>
#include "tiles.h"

struct map {
  struct tile *tiles;
  int width, height;
  int **tilemap;
};

struct map *map;

bool map_load(struct map **, struct tile **, int, int, int (*)[8]);
ALLEGRO_BITMAP * map_show_tile(struct map **, int, int);
void map_free(struct map **);
#endif
