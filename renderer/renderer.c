#include "renderer.h"
#include "model.h"
#include "raster.h"


void render();

void render_bird(const Bird *bird, UINT32 *base)  
{
    plot_bitmap_32(base, bird->x, bird->y, flappy_bitmap, BIRD_HEIGHT);
}

void render_pipe(const Pipes *pipe, UINT32 *base)
{
    /*possible logic: if we have the pipe bitmap be smaller squares of the pipe
    we can have a while loop to print the parts until reaching pipe->opening_height
    then it prints the opening(lines of zeros) then prints more pipe square parts until it reacher ground */
}

void render_pipe_opening();

void render_ground(UINT32 *base, const Ground *ground) 
{
    fill_region(base, ground->x1, ground->x2, ground->y1, ground->y2);
}
{

}

void render_score();
