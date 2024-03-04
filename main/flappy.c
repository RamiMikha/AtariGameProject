#include "..\renderer\renderer.h"
#include "..\events\events.h"
#include "..\raster\types.h"
#include "input.h"
#include <osbind.h>

#define BUFFER_SIZE 32000
#define ALIGNMENT 256

UINT32 get_time(){
    long *timer = (long *)0x462;
    long timeNow;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;

}

int main(){
    UINT32 *base = Physbase();
    UINT8 *base8 = Physbase();
    Model model;
    int quit = 0;
    UINT32 timeThen, timeNow, timeElapsed = 0;
    model.score.value = 1;
    model.score.x = 10;

    void* back_buffer = malloc(BUFFER_SIZE + ALIGNMENT);
    void* back_buffer_aligned = (void *)(((unsigned long)back_buffer + ALIGNMENT - 1) & ~(ALIGNMENT - 1));
    
    /*Setting up initial frame*/
    clear_screen(base);
    bird_spawn(&model.bird);
    pipe_spawn(&model.pipe);
    render(base, base8, model);
    Setscreen(-1,(long)back_buffer_aligned,-1);

    /*Main Game Loop*/
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){
            bird_gravity(&model.bird);
            pipe_move(&model.pipe);
            update_render(base, base8, model);
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

