#include "raster.h"

void plot_bitmap_32(UINT32 *base, int x, int y, UINT32 *bitmap, unsigned int height) {
	int screenWidth = 20;
	int longs_per_screen = 8000;
	int offset = (y * screenWidth) + (x >> 5);

	UINT32 *offsetPtr = base + offset;
	int i;
	for (i = 0; i < height; i++) {
		if (offset < longs_per_screen) {
			*offsetPtr |= bitmap[i];
		}
		offsetPtr += screenWidth;
		offset += screenWidth;
	}
}

void plot_bitmap_8(UINT32 *base, int x, int y, UINT8 *bitmap, unsigned int height) {
	UINT8 *base8 = (UINT8 *)base;
	int screenWidth = 80;
	int bytes_per_screen = 32000;
	int offset = (y * screenWidth) + (x >> 3);

	int i;
	for (i = 0; i < height; i++) {
		if (offset < bytes_per_screen) {
			*(base8 + offset) |= bitmap[i];
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
	int i,j;
	int converted_x1 = x1 >> 5;
	int converted_x2 = x2 >> 5;
	UINT32 *start;
	UINT32 colorValue;
	if (color == 0) {
		colorValue = 0x00000000;
	}
	else {
		colorValue = 0xFFFFFFFF;
	}

	for(i = y1; i < y2 && i < 400; i++) {
		start = base + (i * screenWidth) + converted_x1;
        for(j = converted_x1; j < converted_x2 && j < 20; j++) {
            *start = colorValue;
			start++;
        }
    }
}

void plot_full_screen(UINT32 *base, UINT32 *screen) {
    int longs_per_screen = 8000;
  	UINT32 *offset = base;
  	int x = 0;

  	while (x++ < longs_per_screen) {
    	*(offset++) = screen[x];
  	}
}

UINT16 *get_video_base() {
	UINT32 base, temp_high, temp_low;
	UINT8 *high_byte = 0x00FF8201;
    UINT8 *mid_byte = 0x00FF8203;
	
	long old_ssp = Super(0);
	temp_high = *high_byte;
	temp_low = *mid_byte;
	Super(old_ssp);

	base = (temp_high << 16);
	base |= (temp_low << 8);

    return (UINT16 *) base;
}

