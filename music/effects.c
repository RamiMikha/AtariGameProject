#include "effects.h"

Sound flap_noise[] = {

};

Sound ping_sound[] = {

};

Sound hit_sound[] = {

};

void play_bird_effect(){
    int i;
    for (i = 0; i < sizeof(flap_noise)/sizeof(flap_noise[0]); i++){
        set_tone(flap_noise[i].channel, flap_noise[i].tune);
        set_volume(flap_noise[i].channel, flap_noise[i].volume);
        enable_channel(flap_noise[i].channel, 1, 1);
    }

}
void play_pipe_effect(){
    int i;
    for (i = 0; i < sizeof(ping_sound)/sizeof(ping_sound[0]); i++){
        set_tone(ping_sound[i].channel, ping_sound[i].tune);
        set_volume(ping_sound[i].channel, ping_sound[i].volume);
        enable_channel(ping_sound[i].channel, 1, 1);
    }
}
void play_collision_effect(){
    int i;
    for (i = 0; i < sizeof(hit_sound)/sizeof(hit_sound[0]); i++){
        set_tone(hit_sound[i].channel, hit_sound[i].tune);
        set_volume(hit_sound[i].channel, hit_sound[i].volume);
        enable_channel(hit_sound[i].channel, 1, 1);
    }
}