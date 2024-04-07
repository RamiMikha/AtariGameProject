#include "flappy.h"
UINT8 back_buffer[BACK_BUFFER];

int quit = 0;

UINT32 get_time() {
    long *timer = (long *)TIMER_MEMORY_ADDRESS;
    long timeNow;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

int align_back_buffer(UINT8 back_buffer[]) {
    UINT32 address = (UINT32)back_buffer;
    /*Adds 256-1 to make sure the address is slightly above a 256 byte aligned location
    then rounds down to the nearest 256 aligned byte using bitwise AND, then subtracts original address to get index*/
    return ((address + BACK_BUFFER_ALIGNER - 1) & ~(BACK_BUFFER_ALIGNER - 1)) - address;
}

void run_game(UINT32 *base, UINT32 *back_base, UINT32 timeThen, UINT32 timeNow, UINT32 timeElapsed, Model model){
    int buffer_switch_bool = 0;
    int input = 0;
    while(!quit){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if(key_buffer_head != key_buffer_tail){
            input = dequeue_key();
        }

        if (input == SPACEASCII){
            bird_flap(&model.bird);
        }

        if (render_request){
            bird_gravity(&model.bird);
            pipe_move(&model.pipe);  
            if (pass_pipe(&model.bird, &model.pipe, &model.score)){
                pipe_spawn(&model.pipe);
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
        render_request = 0;
    }
}

void load_splash_screen(UINT32 *base) {
    int input = 0;
    int start = 0;
    render_splash_screen(base);
    while(!start){
        if(key_buffer_head != key_buffer_tail){
            input = dequeue_key();
            if (input == SPACEASCII){
                start = 1;
            }
        }
        if (mouse_x_value != mouse_x_prev || mouse_y_value != mouse_y_prev){
            render_mouse(base);
        }

            /*Does not check for mouse button click
            when check was added it did not work*/
            if(mouse_x_value >= SPLASH_PLAY_BUTTON_X && mouse_x_value <= SPLASH_PLAY_BUTTON_X + SPLASH_BUTTONS_WIDTH 
                && mouse_y_value >= SPLASH_PLAY_BUTTON_Y && mouse_y_value <= SPLASH_PLAY_BUTTON_Y + FONT_LENGTH){
                    start = 1;

            } 
            else if(mouse_x_value >= SPLASH_QUIT_BUTTON_X && mouse_x_value <= SPLASH_QUIT_BUTTON_X + SPLASH_BUTTONS_WIDTH 
                && mouse_y_value >= SPLASH_QUIT_BUTTON_Y && mouse_y_value <= SPLASH_QUIT_BUTTON_Y + FONT_LENGTH){
                    if(mouse_button_state == LEFT_BUTTON_PRESS){
                        quit = 1;
                    }
            }
        
    }
}

int main() {
    UINT32 *base = (UINT32 *)get_video_base();
    UINT32 *back_base = (UINT32 *)&back_buffer[align_back_buffer(back_buffer)];
    UINT32 timeThen, timeNow, timeElapsed = 0;
    Model model;
    Vector IKBD_orig_vector = install_vector(IKBD, IKBD_isr);
    Vector VBL_orig_vector = install_vector(VBL, VBL_isr);
    model.score.value = 0;
    model.bird.frame = 0;
    
    disable_midi_interrupt();
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
    enable_midi_interrupt();
    install_vector(IKBD, IKBD_orig_vector);
    install_vector(VBL, VBL_orig_vector);
    return 0;
}
