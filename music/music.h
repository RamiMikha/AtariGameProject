#include "psg.h" 
#include "../model.h"

#ifndef MUSIC_H
#define MUSIC_H
 typedef struct {
    int channel;
    int tune;
    int volume;
 } Note;
 
typedef struct {
    int current_note;
    int lenght;
    UINT32 time_since_last_note;
    Note* song;
} Music;

void start_music();

void update_music(UINT32 time_elapsed);



#endif