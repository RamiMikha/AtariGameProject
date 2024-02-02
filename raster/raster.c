#include "raster.h"

void plot_bitmap_32(ULONG32 *base, int x, int y, ULONG32 *bitmap, unsigned int height)
{
    int screenWidth = 20;

	int offset = (y * screenWidth) + (x/32);

	int i;
	for (i = 0; i < height; i++) {
		*(base + offset) |= bitmap[i]; 
		offset += screenWidth;
	}

}

