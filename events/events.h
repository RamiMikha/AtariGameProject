#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/* Synchronized Events*/
void move_bird(Bird *bird);

void move_pipe(Pipes *pipe);

void spawn_pipe();




/* Unsynchronized Events*/
void flap_bird(Bird *bird);



/* Condition-Based Events*/
void collision(Bird *bird, Pipes *pipe, Ground *ground);



#endif





