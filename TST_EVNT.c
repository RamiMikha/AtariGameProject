#include "events\events.h"
#include <stdio.h>

int main()
{   
    Model model;
    
    int i = 0;
    int y;
    /*Testing object spawn functions*/
    bird_spawn(&model.bird);
    pipe_spawn(&model.pipe);

    printf("Bird X value: %d\n", model.bird.x);
    printf("Bird Y value: %d\n", model.bird.y);

    printf("Pipe X value: %d\n", model.pipe.x);
    printf("Pipe opening_height value: %d\n", model.pipe.opening_height);


    /*Testing gravity event*/
    while(i < 5){
        bird_gravity(&model.bird);
        printf("Bird Y value due to gravity: %d\n", model.bird.y);
        i++;
    }
    i=0;
    
    /*Testing flap event*/
    while(i < 5){
        bird_flap(&model.bird);
        printf("Bird Y value due to flap: %d\n", model.bird.y);
        i++;
    }
    i=0;

    /*Testing pipe_move event*/
    while(i < 5){
        pipe_move(&model.pipe);
        printf("Pipe X value due to move: %d\n", model.pipe.x);
        i++;
    }
    i=0;
    return 0;
}