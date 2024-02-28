#include "renderer.h"
#include "../bitmaps.h"
#include <stdio.h>


void render(UINT32 *base, UINT8 *base8, Model model) {
    
    render_bird(base, &model.bird);
    model.bird.prev_y = model.bird.y;
    
    render_pipe(base, &model.pipe);
    model.pipe.prev_x = model.pipe.x;

    render_ground(base);
    render_score(base8, 10, SCORE_Y, &model.score);
}

void update_render(UINT32 *base, UINT8 *base8, Model model) {
    
    if(model.bird.y != model.bird.prev_y) {
        clear_bird(base, &model.bird);
        render_bird(base, &model.bird);
        model.bird.prev_y = model.bird.y;
    }
    if(model.pipe.x != model.pipe.prev_x) {
        clear_pipe(base, &model.pipe);
        render_pipe(base, &model.pipe);
        model.pipe.prev_x = model.pipe.x;
    }
    
    /*render_score(base8, 10, SCORE_Y, &model.score);*/
}

void render_bird(UINT32 *base, Bird *bird) {
    plot_bitmap_32(base, bird->x, bird->y, flappy_bitmap, BIRD_HEIGHT);
}

void clear_bird(UINT32 *base, Bird *bird) {
    fill_region(base, bird->x, bird->x + BIRD_WIDTH, bird->prev_y, bird->prev_y + BIRD_HEIGHT, 0);
}

void render_pipe(UINT32 *base, Pipes *pipe) {
    pipe->y = 0;
    while(pipe->y < GROUND_Y1) { 
        plot_bitmap_32(base, pipe->x, pipe->y, pipe_section_bitmap, PIPE_SECTION_HEIGHT);
        pipe->y += PIPE_SECTION_HEIGHT;
    }
 

    render_pipe_opening(base, PIPE_OPENING_SIZE, pipe->x, pipe->opening_height);

}

void render_pipe_opening(UINT32 *base, int opening_size, int x, int y) {
    fill_region(base, x, x + PIPE_WIDTH, y, y + opening_size, 0); 
}

void clear_pipe(UINT32 *base, Pipes *pipe) {
    pipe->y = 0;
    while (pipe->y < GROUND_Y1) {
        fill_region(base, pipe->prev_x, pipe->prev_x + PIPE_WIDTH, pipe->y, pipe->y + PIPE_SECTION_HEIGHT, 0);
        pipe->y += PIPE_SECTION_HEIGHT;
    }
}

void render_ground(UINT32 *base) {
    fill_region(base, GROUND_X1, GROUND_X2, GROUND_Y1, GROUND_Y2, 1);
}

/*Printing horizontal lines when printing scores*/
void render_score(UINT8 *base, int x, int y, Score *score) {
    int digit, i;
    int score_copy = score->value;
    int num_width = 8;

    /* Convert score to array of digits*/
    int digits[3];
    int num_digits = 0;
    while (score_copy > 0) {
        digit = score_copy % 10;
        digits[num_digits++] = digit;
        score_copy /= 10;
    }

    /*Render each digit*/
    for (i= num_digits - 1; i>=0; i--) {
        digit = digits[i];

        switch (digit) {
            case 0:
                plot_bitmap_8(base, x, y, zero_bitmap, FONT_LENGTH);
                break;
            case 1:
                plot_bitmap_8(base, x, y, one_bitmap, FONT_LENGTH);
                break;
            case 2:
                plot_bitmap_8(base, x, y, two_bitmap, FONT_LENGTH);
                break;
            case 3:
                plot_bitmap_8(base, x, y, three_bitmap, FONT_LENGTH);
                break;
            case 4:
                plot_bitmap_8(base, x, y, four_bitmap, FONT_LENGTH);
                break;
            case 5:
                plot_bitmap_8(base, x, y, five_bitmap, FONT_LENGTH);
                break;
            case 6:
                plot_bitmap_8(base, x, y, six_bitmap, FONT_LENGTH);
                break;
            case 7:
                plot_bitmap_8(base, x, y, seven_bitmap, FONT_LENGTH);
                break;
            case 8:
                plot_bitmap_8(base, x, y, eight_bitmap, FONT_LENGTH);
                break;
            case 9:
                plot_bitmap_8(base, x, y, nine_bitmap, FONT_LENGTH);
                break;
        }
        x += num_width;
    }
}