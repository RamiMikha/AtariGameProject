#include <osbind.h>
#include "raster\raster.h"

/*For testing Purposes*/
const UINT32 flappy_bitmap[32] = {
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x000fff00, 
  0x000fff00, 
  0x00f060c0, 
  0x00f060c0, 
  0x03018030, 
  0x03018030, 
  0x7fc180cc, 
  0x7fc180cc, 
  0x806180cc, 
  0x806180cc, 
  0x8018600c, 
  0x8018600c, 
  0x80181ffe, 
  0x80181ffe, 
  0x60606001, 
  0x60606001, 
  0x1f819ffe, 
  0x1f819ffe, 
  0x18006006, 
  0x18006006, 
  0x07801ff8, 
  0x07801ff8, 
  0x007fe000, 
  0x007fe000, 
  0x00000000, 
  0x00000000, 
  0x00000000,
  0x00000000, 
  0x00000000,
};

const UINT8 random_bitmap[5] = {
	0x7f, 
  	0x7c, 
  	0x80, 
  	0x86, 
  	0x97, 
};

int main()
{
	UINT32 *base = Physbase();
	UINT8 *base8 = Physbase();

	clear_screen(base);

	fill_region(base, 0, 639, 300, 399,1);

	clear_screen(base);

	plot_bitmap_32(base, 20, 50, flappy_bitmap, 32);

	clear_screen(base);

	plot_bitmap_8(base8, 60, 70, random_bitmap, 5);

	

	return 0;
}
