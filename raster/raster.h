#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_bitmap_32(ULONG32 *base, int x, int y, ULONG32 *bitmap, unsigned int height);
void clear_screen(ULONG32 *base);
void fill_region(ULONG32 *base, int x1, int x2, int y1, int y2);


#endif
