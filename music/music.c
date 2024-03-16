#include "music.h"
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>

Note song[]= {
    {0, 0x1AC, 10},
    {0, 0x17D, 10},
    {0, 0x1AC, 10},
    {0, 0x140, 10},
    {0, 0x153, 10},
    {0, 0x1AC, 10},
    {0, 0x17D, 10},
    {0, 0x1AC, 10},
    {0, 0x11D, 10},
    {0, 0x140, 10},
    {0, 0x1AC, 10},
    {0, 0x1AC, 10},
    {0, 0x0FE, 10},
    {0, 0x140, 10},
    {0, 0x153, 10},
    {0, 0x17D, 10},
    {0, 0x0E2, 10},
    {0, 0x0FE, 10},
    {0, 0x140, 10},
    {0, 0x11D, 10},
    {0, 0x140, 10}
};

UINT32 NOTE_DURATION = 20;
Music* music;

void start_music(){
    int channel, tone, volume;
    music = (Music*)malloc(sizeof(Music));
    music->current_note = 0;
    music->song = song;
    channel = music->song[music->current_note].channel;
    tone = music->song[music->current_note].tone;
    volume = music->song[music->current_note].volume;

    set_tone(channel, tone);
    set_volume(channel, volume);
    enable_channel(channel, 1, 0);
}


void update_music(UINT32 time_elapsed){

    music->time_since_last_note += time_elapsed;
    if (music->time_since_last_note > NOTE_DURATION){
        if (music->current_note < sizeof(song)/sizeof(song[0])){
            int channel, tone, volume;
            music->current_note++;
            channel = music->song[music->current_note].channel;
            tone = music->song[music->current_note].tone;
            volume = music->song[music->current_note].volume;

            set_tone(channel, tone);
            set_volume(channel, volume);
            enable_channel(channel, 1, 0);

        } else {
            start_music();
        }
        music->time_since_last_note = 0;
    }   
}
