#include "psg.h" 
#include "../model.h"

#ifndef MUSIC_H
#define MUSIC_H

UINT32 NOTE_DURATION = 1000;

void start_music(Model *model);

void update_music(UINT32 time_elapsed, Model *model);



#endif