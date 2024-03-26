#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include "..\music\music.h"
#include "..\music\effects.h"
#include <osbind.h>
#include "..\raster\raster.h"


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
    while ((UINT32)&back_buffer[index] % 256 != 0) {
        index++;
    }
    return index;
}

int main() {
    UINT32 *base = (UINT32 *)get_video_base();
    UINT8 *base8 = (UINT8 *)get_video_base();
    UINT32 *back_base = (UINT32 *)&back_buffer[align_back_buffer(back_buffer)];
    UINT8 *back_base8 = (UINT8 *)back_base;
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
    render(back_base, back_base8, model);
    start_music();

    /*Main Game Loop*/
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (get_input() == ' '){
            bird_flap(&model.bird);
            if (switch_bool == 1) {
                clear_bird(base, &model.bird);
            }
            if (switch_bool == 0) {
                clear_bird(back_base, &model.bird);
            }
        }

        if (timeElapsed > 0){
            bird_gravity(&model.bird);
            pipe_move(&model.pipe);  
            
            if (pass_pipe(&model.bird, &model.pipe, &model.score)){
                pipe_spawn(&model.pipe);
                clear_pipe(base, &model.pipe);
                clear_pipe(back_base, &model.pipe);
            }

            /* back buffer */
            if (switch_bool == 0) {
            update_render(back_base, back_base8, model);
            Setscreen(-1,back_base,-1);
            switch_bool = 1;                
            }
            if (switch_bool == 1) {
            update_render(base, base8, model);
            Setscreen(-1,base,-1);
            switch_bool = 0;                
            }

            if (collision(&model.bird, &model.pipe)){
                quit = 1;
            }
            

            
            update_music(timeElapsed);
        }    


        timeThen = timeNow;
    }
    stop_sound();
    return 0;
}
