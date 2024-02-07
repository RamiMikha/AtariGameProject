#ifndef MODEL_H
#define MODEL_H

typedef struct {
  unsigned x,y;
  int delta_y;
} Bird;

typedef struct {
  unsigned x,y
  int delta_x;
} Pipes;

typedef struct {
  unsigned x,y;
} Ground;


#endif
