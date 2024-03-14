#include "music.h"
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>

extern Note song[]= {
    {0, 262, 10},
    {0, 262, 10},
    {0, 392, 10},
    {0, 392, 10},
    {0, 440, 10},
    {0, 440, 10},
    {0, 392, 10},
    {0, 349, 10},
    {0, 349, 10},
    {0, 330, 10},
    {0, 330, 10},
    {0, 294, 10},
    {0, 294, 10},
    {0, 262, 10}
};

UINT32 NOTE_DURATION = 1;
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
