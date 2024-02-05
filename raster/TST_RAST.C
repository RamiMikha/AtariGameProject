#include <osbind.h>
#include "raster.h"

int main()
{
	UINT32 *base = Physbase();

	clear_screen(base);
	fill_region(base, 0, 639, 300, 399);
	

	return 0;
}
