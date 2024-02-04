#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_bitmap_32(UINT32 *base, int x, int y, UINT32 *bitmap, unsigned int height);
void plot_bitmap_8(UINT8 *base, int x, int y, UINT8 *bitmap, unsigned int height);
void clear_screen(UINT32 *base);
void fill_region(UINT32 *base, int x1, int x2, int y1, int y2);


#endif
