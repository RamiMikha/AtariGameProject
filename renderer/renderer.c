#include "renderer.h"



void render(UINT32 *base, Model model) {
    
    clear_screen(base);
    render_bird(base, &model.bird);
    model.bird.prev_y = model.bird.y;
    
    render_pipe(base, &model.pipe);
    model.pipe.prev_x = model.pipe.x;

    render_ground(base);
    render_score(base, SCORE_X, SCORE_Y, &model.score);
    render_word(base, SCORE_TITLE_X, SCORE_TITLE_Y, "SCORE");
}

void update_render(UINT32 *base, Model model) {

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
    if (model.score.value != model.score.prev_value) {
        clear_score(base);
        render_score(base, SCORE_X, SCORE_Y , &model.score);
    }
}

void render_bird(UINT32 *base, Bird *bird) {
    plot_bitmap_32(base, bird->x, bird->y, flappy_birds[bird->frame], BIRD_HEIGHT);
}


void clear_bird(UINT32 *base, Bird *bird) {
    fill_region(base, bird->x, bird->x + BIRD_WIDTH, bird->prev_y, bird->prev_y + BIRD_HEIGHT + 5 , WHITE);
}

void render_pipe(UINT32 *base, Pipes *pipe) {
    pipe->y = 0;
    fill_region(base, pipe->x, pipe->x + PIPE_WIDTH, 0, pipe->opening_height, BLACK);
    pipe->y = pipe->opening_height + PIPE_OPENING_SIZE;
    fill_region(base, pipe->x, pipe->x + PIPE_WIDTH, pipe->y, GROUND_Y1, BLACK);

}


void clear_pipe(UINT32 *base, Pipes *pipe) {
    pipe->y = 0;
    fill_region(base, pipe->prev_x, pipe->prev_x + PIPE_WIDTH, pipe->y, GROUND_Y1, WHITE);
    
}

void render_ground(UINT32 *base) {
    fill_region(base, GROUND_X1, GROUND_X2, GROUND_Y1, GROUND_Y2, BLACK);
}

void clear_score(UINT32 *base) {
    fill_region(base, SCORE_X, SCORE_X + SCORE_WIDTH, SCORE_Y , SCORE_Y + FONT_LENGTH, WHITE);
}


void render_score(UINT32 *base, int x, int y, Score *score) {
    int digit, i;
    int score_copy = score->value;
    int num_width = 8;
    int digits[3];
    int num_digits = 0;

    if(score_copy == 0) {
        plot_bitmap_8(base, x, y, zero_bitmap, FONT_LENGTH);

    }else{
            /* Convert score to array of digits*/
        while (score_copy > 0) {
            digit = score_copy % 10;
            digits[num_digits++] = digit;
            score_copy /= 10;
        }

        /*Render each digit*/
        for (i= num_digits - 1; i>=0; i--) {
            digit = digits[i];

            switch (digit) {
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
}

void render_word(UINT32 *base, int x, int y, char *word) {
    int i;
    int char_width = 8;

    /* Render each character */
    for (i = 0; word[i] != '\0'; i++) {
        char c = word[i];

        switch (c) {
            case 'A':
                plot_bitmap_8(base, x, y, A_bitmap, FONT_LENGTH);
                break;
            case 'B':
                plot_bitmap_8(base, x, y, B_bitmap, FONT_LENGTH);
                break;
            case 'C':
                plot_bitmap_8(base, x, y, C_bitmap, FONT_LENGTH);
                break;
            case 'D':
                plot_bitmap_8(base, x, y, D_bitmap, FONT_LENGTH);
                break;
            case 'E':
                plot_bitmap_8(base, x, y, E_bitmap, FONT_LENGTH);
                break;
            case 'F':
                plot_bitmap_8(base, x, y, F_bitmap, FONT_LENGTH);
                break;
            case 'G':
                plot_bitmap_8(base, x, y, G_bitmap, FONT_LENGTH);
                break;
            case 'H':
                plot_bitmap_8(base, x, y, H_bitmap, FONT_LENGTH);
                break;
            case 'I':
                plot_bitmap_8(base, x, y, I_bitmap, FONT_LENGTH);
                break;
            case 'J':
                plot_bitmap_8(base, x, y, J_bitmap, FONT_LENGTH);
                break;
            case 'K':
                plot_bitmap_8(base, x, y, K_bitmap, FONT_LENGTH);
                break;
            case 'L':
                plot_bitmap_8(base, x, y, L_bitmap, FONT_LENGTH);
                break;
            case 'M':
                plot_bitmap_8(base, x, y, M_bitmap, FONT_LENGTH);
                break;
            case 'N':
                plot_bitmap_8(base, x, y, N_bitmap, FONT_LENGTH);
                break;
            case 'O':
                plot_bitmap_8(base, x, y, O_bitmap, FONT_LENGTH);
                break;
            case 'P':
                plot_bitmap_8(base, x, y, P_bitmap, FONT_LENGTH);
                break;
            case 'Q':
                plot_bitmap_8(base, x, y, Q_bitmap, FONT_LENGTH);
                break;
            case 'R':
                plot_bitmap_8(base, x, y, R_bitmap, FONT_LENGTH);
                break;
            case 'S':
                plot_bitmap_8(base, x, y, S_bitmap, FONT_LENGTH);
                break;
            case 'T':
                plot_bitmap_8(base, x, y, T_bitmap, FONT_LENGTH);
                break;
            case 'U':
                plot_bitmap_8(base, x, y, U_bitmap, FONT_LENGTH);
                break;
            case 'V':
                plot_bitmap_8(base, x, y, V_bitmap, FONT_LENGTH);
                break;
            case 'W':
                plot_bitmap_8(base, x, y, W_bitmap, FONT_LENGTH);
                break;
            case 'X':
                plot_bitmap_8(base, x, y, X_bitmap, FONT_LENGTH);
                break;
            case 'Y':
                plot_bitmap_8(base, x, y, Y_bitmap, FONT_LENGTH);
                break;
            case 'Z':
                plot_bitmap_8(base, x, y, Z_bitmap, FONT_LENGTH);
                break;
        }
        x += char_width;
    }
}

void render_splash_screen(UINT32 *base) {
    clear_screen(base);
    plot_full_screen(base, splash_screen);
    render_word(base, SPLASH_PLAY_BUTTON_X, SPLASH_PLAY_BUTTON_Y, "PLAY GAME");
    render_word(base, SPLASH_QUIT_BUTTON_X, SPLASH_QUIT_BUTTON_Y, "QUIT GAME");
}

void render_end_screen(UINT32 *base, Score *score) {
    clear_screen(base);
    plot_full_screen(base, splash_screen);
    render_word(base, GAME_OVER_X, GAME_OVER_Y, "GAME OVER");
    render_word(base, END_SCORE_X, END_SCORE_Y, "SCORE");
    render_score(base, END_SCORE_VALUE_X, END_SCORE_VALUE_Y, score);
    render_word(base, SPLASH_PLAY_BUTTON_X, SPLASH_PLAY_BUTTON_Y, "PLAY GAME");
    render_word(base, SPLASH_QUIT_BUTTON_X, SPLASH_QUIT_BUTTON_Y, "QUIT GAME");
}

void render_mouse(UINT32 *base) {
	UINT8 *base8 = (UINT8 *)base;
    int offset,i;
    /*Clearing old mouse*/
	offset = (mouse_y_prev * SCREEN_WIDTH_8) + (mouse_x_prev >> 3);
	for (i = 0; i < MOUSE_LENGTH; i++){
		if (offset < BYTES_PER_SCREEN){
			*(base8 + offset) ^= mouse_bitmap[i];
		}
		offset += SCREEN_WIDTH_8;
	}

    /*Plotting new mouse*/
	offset = (mouse_y_value * SCREEN_WIDTH_8) + (mouse_x_value >> 3);

	for (i = 0; i < MOUSE_LENGTH; i++){
		if (offset < BYTES_PER_SCREEN){
			*(base8 + offset) ^= mouse_bitmap[i];
		}
		offset += SCREEN_WIDTH_8;
	}

}
