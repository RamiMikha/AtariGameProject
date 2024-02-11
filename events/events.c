#include <osbind.h>
#include "events.h"



/* Synchronized Events*/
void bird_gravity(Bird *bird){
    move_bird(bird, GRAVITY);
}

void pipe_move(Pipes *pipe){
    move_pipe(pipe, PIPE_SPEED);
}

void pipe_spawn(Pipes *pipe){
    pipe->x = 640;
    pipe->opening_gap = 96;

    /*pipe->opening_height = random? */
  
}



/* Unsynchronized Events*/
void bird_flap(Bird *bird){
    int ch;
    ch = c_necin();
    while(ch = ' '){
        move_bird(bird, FLAP);
        ch = c_necin();
    }
}



/* Condition-Based Events*/
void collision(Bird *bird, Pipes *pipe, Ground *ground){

    if (check_collision(bird, pipe, ground)){
        /*game ends*/
    }
}