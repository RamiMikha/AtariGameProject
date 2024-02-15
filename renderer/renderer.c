#include "renderer.h"
#include "model.h"
#include "raster.h"


void render();

void render_bird(Bird *bird, UINT32 *base)  
{
    plot_bitmap_32(base, bird->x, bird->y, flappy_bitmap, BIRD_HEIGHT);
}

void render_pipe(Pipes *pipe, UINT32 *base)
{
    /*possible logic: if we have the pipe bitmap be smaller squares of the pipe
    we can have a while loop to print the parts until reaching pipe->opening_height
    then it prints the opening(lines of zeros) then prints more pipe square parts until it reacher ground */

    while(pipe->y < pipe->opening_height)
    {
        plot_bitmap_32(base, pipe->x, pipe->y, pipe_section_bitmap, PIPE_SECTION_HEIGHT); /*To do: decide ons section height and create bitmap*/
        pipe->y += PIPE_SECTION_HEIGHT;
    }

    render_pipe_opening(base, PIPE_OPENING_SIZE, pipe->x, pipe->y);

    while(pipe->y < GROUND_Y) /*To do: decide on ground y value*/
    {
        plot_bitmap_32(base, pipe->x, pipe->y, pipe_section_bitmap, PIPE_SECTION_HEIGHT); 
        pipe->y += PIPE_SECTION_HEIGHT;
    }
}

void render_pipe_opening(UINT32 *base, int opening_size, int x, int y)
{
    fill_region(base, x, x + PIPE_WIDTH, y, y + opening_size); /*changing fill region to be able to set with values with 1 or 0 */
}

void render_ground(UINT32 *base, const Ground *ground) 
{
    fill_region(base, ground->x1, ground->x2, ground->y1, ground->y2);
}
{

}

void render_score();
