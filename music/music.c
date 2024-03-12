#include "music.h"

extern Note song[]= {
    {0, 248, 11}
}

/*No function is tested yet*/

void start_music(Model *model){
    model.music.current_note = 0;
    model.music.channel = &song[model.music.current_note][0];
    model.music.tune = &song[model.music.current_note][1];
    model.music.volume = &song[model.music.current_note][2];

    set_tone(model.music.channel, model.music.tune);
    set_volume(model.music.channel, model.music.volume);
    enable_channel(model.music.channel, 1, 0);
}


void update_music(UINT32 time_elapsed, Model *model){
    int time_since_last_note += time_elapsed;
    
    if (time_since_last_note > NOTE_DURATION){
        model.music.current_note++;
        model.music.channel = &song[model.music.current_note][0];
        model.music.tune = &song[model.music.current_note][1];
        model.music.volume = &song[model.music.current_note][2];

        set_tone(model.music.channel, model.music.tune);
        set_volume(model.music.channel, model.music.volume);
        enable_channel(model.music.channel, 1, 0);

        time_since_last_note = 0;
    }
}
