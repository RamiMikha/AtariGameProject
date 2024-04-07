#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include "..\music\music.h"
#include "..\music\effects.h"
#include <osbind.h>
#include "..\raster\raster.h"
#include "..\ISR\ISR_he~1.h"


#ifndef FLAPPY_H
#define FLAPPY_H

#define BACK_BUFFER 32256
#define TIMER_MEMORY_ADDRESS 0x462
#define BACK_BUFFER_ALIGNER 256
#define SPACEASCII 0x39
#define LEFT_BUTTON_PRESS 0xFA

UINT32 get_time();

int align_back_buffer(UINT8 back_buffer[]);

void run_game(UINT32 *base, UINT32 *back_base, UINT32 timeThen, UINT32 timeNow, UINT32 timeElapsed, Model model);

void load_splash_screen(UINT32 *base);

#endif
