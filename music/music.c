#include "music.h"
#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>

int channels[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int tones[] = {0x1AC, 0x17D, 0x1AC, 0x140, 0x153, 0x1AC, 0x17D, 0x1AC, 0x11D, 0x140, 0x1AC, 0x1AC, 0x0FE, 0x140, 0x153, 0x17D, 0x0E2, 0x0FE, 0x140, 0x11D, 0x140};
int volumes[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};


UINT32 NOTE_DURATION = 20;
Music music;

void start_music(){
    int channel, tone, volume;
    music.current_note = 0;
    music.channel = channels;
    music.tone = tones;
    music.volume = volumes;
    channel = music.channel[music.current_note];
    tone = music.tone[music.current_note];
    volume = music.volume[music.current_note];

    set_tone(channel, tone);
    set_volume(channel, volume);
    enable_channel(channel, 1, 0);
}


void update_music(UINT32 time_elapsed){

    music.time_since_last_note += time_elapsed;
    if (music.time_since_last_note > NOTE_DURATION){
        if (music.current_note < sizeof(channels)/sizeof(channels[0])){
            int channel, tone, volume;
            music.current_note++;
            channel = music.channel[music.current_note];
            tone = music.tone[music.current_note];
            volume = music.volume[music.current_note];

            set_tone(channel, tone);
            set_volume(channel, volume);
            enable_channel(channel, 1, 0);

        } else {
            start_music();
        }
        music.time_since_last_note = 0;
    }   
}
