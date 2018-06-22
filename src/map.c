#include "map.h"

bool map_load(struct map **target, struct tile **tiles, int w, int h, int mapping[][8])
{
  // Allocate Memory
  *target = calloc(1, sizeof(struct map));
  (*target)->tilemap = (int **)malloc(h * sizeof(int *));
  for(int i = 0;i<h;i++)
    (*target)->tilemap[i] = (int *)malloc(w * sizeof(int));
  printf("Allocated.\n");
  
  (*target)->width = 0;
  (*target)->height = 0;
  
  printf("Width: %d\nHeight: %d\n", (*target)->width, (*target)->height);
  printf("h: %d\nw: %d\n", h, w);
  for(;(*target)->height < h;(*target)->height++)
    {
      printf("In Loop.\n");
      for((*target)->width = 0;(*target)->width < w;(*target)->width++)
  	{
	  printf("Mapping: %d\n", mapping[(*target)->height][(*target)->width]);
	  (*target)->tilemap[(*target)->height][(*target)->width] = mapping[(*target)->height][(*target)->width];
	  printf("Target: %d\n", (*target)->tilemap[(*target)->height][(*target)->width]);
	}
    }
  //(*target)->tilemap[0] = (int *)calloc(w*h, sizeof(int *));
  (*target)->tiles = (*tiles);
  printf("Tiles.\n");

  return true;
  
}

ALLEGRO_BITMAP * map_show_tile(struct map **target, int w, int h)
{
  int tilenumber = (*target)->tilemap[h][w];
  return map->tiles[tilenumber].image;
}

void map_free(struct map **target)
{
  free(*target);
}
