#include "psg.h"

typedef struct
{
    int channel;
    int tune;
    int volume;

} Sound;


void play_bird_effect();
void play_pipe_effect();
void play_collision_effect();