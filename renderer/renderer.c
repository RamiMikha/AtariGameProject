#include "renderer.h"

const UINT32 flappy_bitmap[BIRD_HEIGHT] = {
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x000fff00, 
  0x000fff00, 
  0x00f060c0, 
  0x00f060c0, 
  0x03018030, 
  0x03018030, 
  0x7fc180cc, 
  0x7fc180cc, 
  0x806180cc, 
  0x806180cc, 
  0x8018600c, 
  0x8018600c, 
  0x80181ffe, 
  0x80181ffe, 
  0x60606001, 
  0x60606001, 
  0x1f819ffe, 
  0x1f819ffe, 
  0x18006006, 
  0x18006006, 
  0x07801ff8, 
  0x07801ff8, 
  0x007fe000, 
  0x007fe000, 
  0x00000000, 
  0x00000000, 
  0x00000000,
  0x00000000, 
  0x00000000
};

const UINT32 pipe_section_bitmap[PIPE_SECTION_HEIGHT] = {
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF

};

void render(UINT32 *base, Model model) {
    clear_screen(base);
    render_bird(base, &model.bird);
    render_pipe(base, &model.pipe);
    render_ground(base);
}


void render_bird(UINT32 *base, Bird *bird) {
    plot_bitmap_32(base, bird->x, bird->y, flappy_bitmap, BIRD_HEIGHT);
}

void render_pipe(UINT32 *base, Pipes *pipe) {
    while(pipe->y < GROUND_Y1) { 
        plot_bitmap_32(base, pipe->x, pipe->y, pipe_section_bitmap, PIPE_SECTION_HEIGHT);
        pipe->y += PIPE_SECTION_HEIGHT;
    }

    pipe->opening_height = rand() % 200 + 50; 

    render_pipe_opening(base, PIPE_OPENING_SIZE, pipe->x, pipe->opening_height);

}

void render_pipe_opening(UINT32 *base, int opening_size, int x, int y) {
    fill_region(base, x, x + PIPE_WIDTH, y, y + opening_size, 0); 
}

void render_ground(UINT32 *base) {
    fill_region(base, GROUND_X1, GROUND_X2, GROUND_Y1, GROUND_Y2, 1);
}


void render_score();
