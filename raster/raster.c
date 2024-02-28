#include "raster.h"

void plot_bitmap_32(UINT32 *base, int x, int y, UINT32 *bitmap, unsigned int height) {
	int screenWidth = 20;
	int longs_per_screen = 8000;
	int offset = (y * screenWidth) + (x >> 5);

	int i;
	for (i = 0; i < height; i++) {
		if (offset < longs_per_screen) {
			*(base + offset) |= bitmap[i];
		}
		offset += screenWidth;
	}
}

void plot_bitmap_8(UINT8 *base, int x, int y, UINT8 *bitmap, unsigned int height) {
	int screenWidth = 80;
	int bytes_per_screen = 32000;
	int offset = (y * screenWidth) + (x >> 3);

	int i;
	for (i = 0; i < height; i++) {
		if (offset < bytes_per_screen) {
			*(base + offset) |= bitmap[i];
		}
		offset += screenWidth;
	}
}

void clear_screen(UINT32 *base) {
	int longs_per_screen = 8000;
  	UINT32 *offset = base;
  	int x = 0;

  	while (x++ < longs_per_screen) {
    	*(offset++) = 0;
  	}	
}

void fill_region(UINT32 *base, int x1, int x2, int y1, int y2, int color)
{
	int screenWidth = 20;
	int i;
	int j;
	int colorValue;
	if (color == 0) {
		colorValue = 0x00000000;
	}
	else {
		colorValue = 0xFFFFFFFF;
	}
	

	for(i = x1; i < x2 && i < 640; i++) {
        for(j = y1; j < y2 && j < 400; j++) {
            int offset = (j * screenWidth) + (i >> 5);
            *(base + offset) = colorValue;
        }
    }
}
