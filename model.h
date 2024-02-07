#ifndef MODEL_H
#define MODEL_H

#define BIRD_WIDTH 32
#define BIRD_HEIGHT 32
#define PIPE_WIDTH 32
#define PIPE_HEIGHT 640

typedef struct {
  unsigned int x,y;
  int delta_y;
} Bird;

typedef struct {
  unsigned int x,y;
  unsigned int opening_height, opening_gap;
  int delta_x;
} Pipes;

typedef struct {
  unsigned x1,y1,x2,y2;
} Ground;


#endif
