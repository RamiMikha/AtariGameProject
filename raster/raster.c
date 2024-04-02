#include "raster.h"

void plot_bitmap_32(UINT32 *base, int x, int y, UINT32 *bitmap, unsigned int height) {
	int offset = (y * SCREEN_WIDTH_32) + (x >> 5);

	UINT32 *offsetPtr = base + offset;
	int i;
	for (i = 0; i < height; i++) {
		if (offset < LONGS_PER_SCREEN) {
			*offsetPtr |= bitmap[i];
		}
		offsetPtr += SCREEN_WIDTH_32;
		offset += SCREEN_WIDTH_32;
	}
}

void plot_bitmap_8(UINT32 *base, int x, int y, UINT8 *bitmap, unsigned int height) {
	UINT8 *base8 = (UINT8 *)base;
	int offset = (y * SCREEN_WIDTH_8) + (x >> 3);

	int i;
	for (i = 0; i < height; i++) {
		if (offset < BYTES_PER_SCREEN) {
			*(base8 + offset) |= bitmap[i];
		}
		offset += SCREEN_WIDTH_8;
	}
}

void clear_screen(UINT32 *base) {
  	UINT32 *offset = base;
  	int x = 0;

  	while (x++ < LONGS_PER_SCREEN) {
    	*(offset++) = 0;
  	}	
}

void fill_region(UINT32 *base, int x1, int x2, int y1, int y2, int color)
{
	int i,j;
	int converted_x1 = x1 >> 5;
	int converted_x2 = x2 >> 5;
	UINT32 *start;
	UINT32 colorValue;
	if (color == 0) {
		colorValue = BLACK;
	}
	else {
		colorValue = WHITE;
	}

	for(i = y1; i < y2 && i < 400; i++) {
		start = base + (i * SCREEN_WIDTH_32) + converted_x1;
        for(j = converted_x1; j < converted_x2 && j < 20; j++) {
            *start = colorValue;
			start++;
        }
    }
}

void plot_full_screen(UINT32 *base, UINT32 *screen) {
  	UINT32 *offset = base;
  	int x = 0;

  	while (x++ < LONGS_PER_SCREEN) {
    	*(offset++) = screen[x];
  	}
}

UINT16 *get_video_base() {
	UINT32 base, temp_high, temp_mid;
	UINT8 *high_byte = HIGH_VIDEO_BASE_REGISTER;
    UINT8 *mid_byte = MID_VIDEO_BASE_REGISTER;
	
	long old_ssp = Super(0);
	temp_high = *high_byte;
	temp_mid = *mid_byte;
	Super(old_ssp);

	base = (temp_high << 16);
	base |= (temp_mid << 8);

    return (UINT16 *) base;
}

void set_video_base(UINT16 *base_address) {
	UINT32 base = (UINT32) base_address;
	UINT8 high_byte = (base >> 16);
	UINT8 mid_byte = (base >> 8);

	UINT8 *high_byte_ptr = HIGH_VIDEO_BASE_REGISTER;
	UINT8 *mid_byte_ptr = MID_VIDEO_BASE_REGISTER;

	long old_ssp = Super(0);
	*high_byte_ptr = high_byte;
	*mid_byte_ptr = mid_byte;
	Super(old_ssp);
}

