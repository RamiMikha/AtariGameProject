#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include "..\music\music.h"
#include <osbind.h>


UINT8 back_buffer[32256];

UINT32 get_time() {
    long *timer = (long *)0x462;
    long timeNow;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

int align_back_buffer(UINT8 back_buffer[]) {
    int index = 0;
    while ((UINT8)&back_buffer[index] % 256 != 0) {
        index++;
    }
    return index;
}

int main() {
    UINT32 *base = Physbase();
    UINT8 *base8 = Physbase();
    UINT32 *back_base = (UINT32 *)&back_buffer[align_back_buffer(back_buffer)];
    Model model;
    int quit = 0;
    int switch_bool = 0;
    UINT32 timeThen, timeNow, timeElapsed = 0;
    model.score.value = 0;
    
    
    /*Setting up initial frame*/
    clear_screen(base);
    bird_spawn(&model.bird);
    pipe_spawn(&model.pipe);
    render(base, base8, model);
    start_music(&model.music);

    /*Main Game Loop*/
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){
            bird_gravity(&model.bird);
            pipe_move(&model.pipe);
            update_render(base, base8, model);

            /* back buffer */
            if (switch_bool == 0) {
            Setscreen(-1,back_base,-1);
            switch_bool = 1;                
            }

            /* front buffer */
            if (switch_bool == 1) {
            Setscreen(-1,base,-1);
            switch_bool = 0;                
            }

            if (collision(&model.bird, &model.pipe)){
                quit = 1;
            }
            
            if (pass_pipe(&model.bird, &model.pipe, &model.score)){
                pipe_spawn(&model.pipe);
                clear_pipe(base, &model.pipe);
            }
            
            update_music(timeElapsed, &model.music);
        }    
        if (get_input() == ' '){
            bird_flap(&model.bird);
            clear_bird(base, &model.bird);
        }

        timeThen = timeNow;
    }

    return 0;
}
