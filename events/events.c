#include "events.h"

/* Synchronized Events*/

void bird_gravity(Bird *bird) {
    move_bird(bird, GRAVITY);
}

void pipe_move(Pipes *pipe) {
    move_pipe(pipe, PIPE_SPEED);
}

void pipe_spawn(Pipes *pipe) {
    pipe->x = 600;
    pipe->y = 0;

    /*'%200 + 50' limits the height to be between 50 to 250 pixels down on screen */
    pipe->opening_height = rand() % 200 + 50;
}

void bird_spawn(Bird *bird) {
    bird->x = 100;
    bird->y = 100;
}

/* Unsynchronized Events*/

void bird_flap(Bird *bird) {
        move_bird(bird, FLAP);   
}

/* Condition-Based Events*/

int collision(Bird *bird, Pipes *pipe) {
    return check_collision(bird, pipe);
}
