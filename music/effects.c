#include "effects.h"

Sound flap_noise[] = {
    {2, 0x281, 10},
    {2, 0x1C5, 10},
    {2, 0x2A7, 10},
    {2, 0x281, 10},
    {2, 0x1C5, 10},
    {2, 0x2A7, 10},
    {2, 0x281, 10},
    {2, 0x1C5, 10},
    {2, 0x2A7, 10},
    {2, 0x281, 10},
    {2, 0x1C5, 10},
    {2, 0x2A7, 10}    
};

Sound ping_sound[] = {
    {2, 0x024, 20},
    {2, 0x02A, 20},
    {2, 0x028, 20},
    {2, 0x035, 20}
};

Sound hit_sound[] = {
    {2, 300, 10},
    {2, 300, 10},
    {2, 300, 10},
    {2, 300, 10},
    {2, 300, 10},
    {2, 300, 10},
    {2, 300, 10}
};

void delay(int milliseconds) {
    int i, j;
    for(i = 0; i < milliseconds; i++){} 
}

void play_bird_effect(){
    int i;
    for (i = 0; i < sizeof(flap_noise)/sizeof(flap_noise[0]); i++){
        set_tone(flap_noise[i].channel, flap_noise[i].tone);
        set_volume(flap_noise[i].channel, flap_noise[i].volume);
        set_noise(flap_noise[i].tone);
        set_envelope(0, 3500);
        enable_channel(flap_noise[i].channel, 1, 0);
        enable_channel(flap_noise[i].channel, 0, 0);        
    }
    

}
void play_pipe_effect(){
    int i;
    for (i = 0; i < sizeof(ping_sound)/sizeof(ping_sound[0]); i++){
        set_tone(ping_sound[i].channel, ping_sound[i].tone);
        set_volume(ping_sound[i].channel, ping_sound[i].volume);
        set_envelope(0, 3500);
        enable_channel(ping_sound[i].channel, 1, 0);
        delay(500);
        enable_channel(ping_sound[i].channel, 0, 0);
    }
}
void play_collision_effect(){
    int i;
    for (i = 0; i < sizeof(hit_sound)/sizeof(hit_sound[0]); i++){
        set_tone(hit_sound[i].channel, hit_sound[i].tone);
        set_volume(hit_sound[i].channel, hit_sound[i].volume);
        set_envelope(0, 3500);
        enable_channel(hit_sound[i].channel, 1, 0);
        delay(500);
        enable_channel(hit_sound[i].channel, 0, 0);
    }
}