#include "events.h"
#include "..\music\effects.h"

/* Synchronized Events*/

void bird_gravity(Bird *bird) {
    move_bird(bird, GRAVITY);
}

void pipe_move(Pipes *pipe) {
    move_pipe(pipe, PIPE_SPEED);
}

void pipe_spawn(Pipes *pipe) {
    pipe->prev_x = pipe->x;
    pipe->x = PIPE_SPAWN_X_COORDINATE;
    pipe->y = PIPE_SPAWN_Y_COORDINATE;

    /*'%200 + 50' limits the height to be between 50 to 250 pixels down on screen */
    pipe->opening_height = rand() % MAX_PIPE_OPENING_HEIGHT + MIN_PIPE_OPENING_HEIGHT;
}

void bird_spawn(Bird *bird) {
    bird->x = BIRD_SPAWN_X_COORDINATE;
    bird->y = BIRD_SPAWN_Y_COORDINATE;
}

/* Unsynchronized Events*/

void bird_flap(Bird *bird) {
        move_bird(bird, FLAP);   
        play_bird_effect();
}

/* Condition-Based Events*/

int collision(Bird *bird, Pipes *pipe) {
    int status = 0;
    if(check_collision(bird, pipe)){
        play_collision_effect();
        status = 1;
    }
    
    return status;
    
}

int pass_pipe(Bird *bird, Pipes *pipe, Score *score) {
    int status = 0;
    if (bird->x > pipe->x + PIPE_WIDTH) {
        play_pipe_effect();
        increment_score(bird, pipe, score);
        status = 1;
    }
    return status;
}
