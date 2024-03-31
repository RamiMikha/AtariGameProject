#include "flappy.h"
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

void run_game(UINT32 *base, UINT32 *back_base, UINT32 timeThen, UINT32 timeNow, UINT32 timeElapsed, Model model){
    int quit = 0;
    int buffer_switch_bool = 0;
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (get_input() == ' '){
            bird_flap(&model.bird);
            if (buffer_switch_bool == 1) {
                clear_bird(base, &model.bird);
            }
            if (buffer_switch_bool == 0) {
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

            if (buffer_switch_bool == 0) {
                model.bird.frame++;
                if(model.bird.frame > 2){
                    model.bird.frame = 0;
                }
            update_render(back_base, model);
            set_video_base((UINT16 *)back_base);
            buffer_switch_bool = 1;                
            }

            if (buffer_switch_bool == 1) {
                model.bird.frame++;
                if(model.bird.frame > 2){
                    model.bird.frame = 0;
                }
            update_render(base, model);
            set_video_base((UINT16 *)base);
            buffer_switch_bool = 0;                
            }

            if (collision(&model.bird, &model.pipe)){
                quit = 1;
            }
            update_music(timeElapsed);
        }
        timeThen = timeNow;
    }
}

void load_splash_screen(UINT32 *base) {
    render_splash_screen(base);
    while(get_input() != ' '){
        ;
    }
}

int main() {
    UINT32 *base = (UINT32 *)get_video_base();
    UINT32 *back_base = (UINT32 *)&back_buffer[align_back_buffer(back_buffer)];
    UINT32 timeThen, timeNow, timeElapsed = 0;
    Model model;
    model.score.value = 0;
    model.bird.frame = 0;
    
    
    load_splash_screen(base);
    
    /*Setting up initial frame*/
    clear_screen(base);
    bird_spawn(&model.bird);
    pipe_spawn(&model.pipe);
    render(base, model);
    render(back_base, model);

    start_music();
    run_game(base, back_base, timeThen, timeNow, timeElapsed, model);
    stop_sound();
    return 0;
}
