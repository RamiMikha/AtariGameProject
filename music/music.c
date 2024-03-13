#include "music.h"

extern Music song[]= {
    {0, 248, 11},
    {0, 249, 10},
    {0, 250, 11}
};

UINT32 NOTE_DURATION = 1000;

/*No function is tested yet*/

void start_music(Music *music){
    music->current_note = 0;
    music->channel = song[music->current_note].channel;
    music->tune = song[music->current_note].tune;
    music->volume = song[music->current_note].volume;

    set_tone(music->channel, music->tune);
    set_volume(music->channel, music->volume);
    enable_channel(music->channel, 1, 0);
}


void update_music(UINT32 time_elapsed, Music *music){
    int time_since_last_note = 0;
    
    time_since_last_note += time_elapsed;
    if (time_since_last_note > NOTE_DURATION){
        if (music->current_note < sizeof(song)/sizeof(song[0])){
            music->current_note++;
            music->channel = song[music->current_note].channel;
            music->tune = song[music->current_note].tune;
            music->volume = song[music->current_note].volume;
            set_tone(music->channel, music->tune);
            set_volume(music->channel, music->volume);
            enable_channel(music->channel, 1, 0);
        } else {
            start_music(music);
        }




        time_since_last_note = 0;
    }
}
