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

    /*'%200 + 50' limits the height to be between 50 to 250 pixels down on screen */
    pipe->opening_height = random() % 200 + 50;
  
}



/* Unsynchronized Events*/
void bird_flap(Bird *bird){
        move_bird(bird, FLAP);   
}



/* Condition-Based Events*/
void collision(Bird *bird, Pipes *pipe, Ground *ground){

    if (check_collision(bird, pipe, ground)){
        clear_screen();
        /*this is where the game normally ends but since we do not have score screen yet this will be added later*/

    }
}