#include "music.h"
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>

Note song[]= {
    {0, 60, 100},
    {0, 60, 100},
    {0, 67, 100},
    {0, 67, 100},
    {0, 69, 100},
    {0, 69, 100},
    {0, 67, 100},
    {0, 65, 100},
    {0, 64, 100},
    {0, 62, 100},
    {0, 60, 100}
};

UINT32 NOTE_DURATION = 10;
Music* music;

void start_music(){
    int channel, tune, volume;
    music = (Music*)malloc(sizeof(Music));
    music->current_note = 0;
    music->song = song;
    channel = music->song[music->current_note].channel;
    tune = music->song[music->current_note].tune;
    volume = music->song[music->current_note].volume;

    set_tone(channel, tune);
    set_volume(channel, volume);
    enable_channel(channel, 1, 1);
}


void update_music(UINT32 time_elapsed){

    music->time_since_last_note += time_elapsed;
    if (music->time_since_last_note > NOTE_DURATION){
        if (music->current_note < sizeof(song)/sizeof(song[0])){
            int channel, tune, volume;
            music->current_note++;
            channel = music->song[music->current_note].channel;
            tune = music->song[music->current_note].tune;
            volume = music->song[music->current_note].volume;

            set_tone(channel, tune);
            set_volume(channel, volume);
            enable_channel(channel, 1, 1);

        } else {
            start_music();
        }
        music->time_since_last_note = 0;
    }   
}
