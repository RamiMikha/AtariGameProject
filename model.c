#include "model.h"

void move_bird (Bird *bird) {
    bird->y += bird->delta_y;
}

void move_pipe (Pipes *pipe) {
    pipe->x += pipe->delta_x;
}

int check_collision(Bird *bird, Pipes *pipe, Ground *ground) {
    if (bird->x < pipe->x + PIPE_WIDTH && bird->x + BIRD_WIDTH > pipe->x) {
        if (bird->y < pipe->opening_height || bird->y + BIRD_HEIGHT > pipe->opening_height + pipe->opening_gap) {
            return 1; 
        }
    }
    return 0; 
}


