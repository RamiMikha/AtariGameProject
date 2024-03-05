#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include <osbind.h>

UINT8 unaligned_back_buffer[32256];

UINT32 get_time() {
    long *timer = (long *)0x462;
    long timeNow;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

UINT8 align_back_buffer(back_buffer) {
    while (back_buffer % 256 != 0) {
        back_buffer += 1;
    }

    return back_buffer;
}

int main() {
    UINT32 *base = Physbase();
    UINT8 *base8 = Physbase();
    Model model;
    int quit = 0;
    UINT32 timeThen, timeNow, timeElapsed = 0;
    model.score.value = 1;
    model.score.x = 10;
    
    /*Setting up initial frame*/
    clear_screen(base);
    bird_spawn(&model.bird);
    pipe_spawn(&model.pipe);
    render(base, base8, model);

    /*Main Game Loop*/
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){
            bird_gravity(&model.bird);
            Vsync();
            pipe_move(&model.pipe);
            Vsync();
            update_render(base, base8, model);
            Setscreen(-1,align_back_buffer(unaligned_back_buffer),-1);
            Vsync();
            if (collision(&model.bird, &model.pipe)){
                quit = 1;
            }
            
            if (pass_pipe(&model.bird, &model.pipe, &model.score)){
                pipe_spawn(&model.pipe);
                clear_pipe(base, &model.pipe);
            }
        }    
        if (get_input() == ' '){
            bird_flap(&model.bird);
            clear_bird(base, &model.bird);
        }

        timeThen = timeNow;
    }

    return 0;
}
