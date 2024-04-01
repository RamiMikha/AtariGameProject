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
    int pipe_spawn_x_coordinate = 600;
    int pipe_spawn_y_coordinate = 0;
    
    pipe->prev_x = pipe->x;
    pipe->x = pipe_spawn_x_coordinate;
    pipe->y = pipe_spawn_y_coordinate;

    /*'%200 + 50' limits the height to be between 50 to 250 pixels down on screen */
    pipe->opening_height = rand() % 200 + 50;
}

void bird_spawn(Bird *bird) {
    int bird_spawn_x_coordinate = 120;
    int bird_spawn_y_coordinate = 100;
    
    bird->x = bird_spawn_x_coordinate;
    bird->y = bird_spawn_y_coordinate;
}

/* Unsynchronized Events*/

void bird_flap(Bird *bird) {
        move_bird(bird, FLAP);   
        play_bird_effect();
}

/* Condition-Based Events*/

int collision(Bird *bird, Pipes *pipe) {
    return check_collision(bird, pipe);
    play_collision_effect();
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
