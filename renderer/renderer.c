#include "renderer.h"


int main() {
    UINT32 *base = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;
    render(base, model);
    return 0;

}
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

    render_pipe_opening(base, PIPE_OPENING_SIZE, pipe->x, pipe->y);

}

void render_pipe_opening(UINT32 *base, int opening_size, int x, int y) {
    fill_region(base, x, x + PIPE_WIDTH, y, y + opening_size, 0); 
}

void render_ground(UINT32 *base) {
    fill_region(base, GROUND_X1, GROUND_X2, GROUND_Y1, GROUND_Y2, 1);
}


void render_score();
