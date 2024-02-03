#include "raster.h"

void plot_bitmap_32(UINT32 *base, int x, int y, UINT32 *bitmap, unsigned int height)
{
    int screenWidth = 20;

	int offset = (y * screenWidth) + (x/32);

	int i;
	for (i = 0; i < height; i++) {
		*(base + offset) |= bitmap[i]; 
		offset += screenWidth;
	}

}

void clear_screen(UINT32 *base){

	int longs_per_screen = 8000;
  	UINT32 *offset = base;
  	int x = 0;

  	while (x++ <longs_per_screen)
  	{
    	*(offset++) = 0;
  	}	

}


