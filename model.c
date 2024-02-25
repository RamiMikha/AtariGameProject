#include "model.h"

void move_bird (Bird *bird, int move_value) {
    bird->delta_y = move_value;
    bird->prev_y = bird->y;
    bird->y += bird->delta_y;
}

void move_pipe (Pipes *pipe, int move_value) {
    pipe->delta_x = move_value;
    pipe->prev_x = pipe->x;
    pipe->x += pipe->delta_x;
}

int check_collision(Bird *bird, Pipes *pipe) {
    int collision_bool = 0;

    /* ground collision*/
    if (bird->y >= GROUND_Y1) {
        collision_bool = 1;
    }

    /* pipe collision*/    
    if (bird->x < pipe->x + PIPE_WIDTH && bird->x + BIRD_WIDTH > pipe->x) {
        if (bird->y < pipe->opening_height || bird->y + BIRD_HEIGHT > pipe->opening_height + PIPE_OPENING_SIZE) {
            collision_bool = 1; 
        }
    }
    
    return collision_bool; 
}


