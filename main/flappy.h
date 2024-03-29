#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include "..\music\music.h"
#include "..\music\effects.h"
#include <osbind.h>
#include "..\raster\raster.h"

#ifndef FLAPPY_H
#define FLAPPY_H

UINT32 get_time();

int align_back_buffer(UINT8 back_buffer[]);

void run_game(UINT32 *base, UINT32 *back_base, UINT32 timeThen, UINT32 timeNow, UINT32 timeElapsed, Model model);

void load_splash_screen(UINT32 *base);

#endif
