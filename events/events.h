#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/* Synchronized Events*/
void bird_gravity(Bird *bird);

void pipe_move(Pipes *pipe);

void pipe_spawn(Pipes *pipe);




/* Unsynchronized Events*/
void bird_flap(Bird *bird);



/* Condition-Based Events*/
void collision(Bird *bird, Pipes *pipe, Ground *ground);



#endif





