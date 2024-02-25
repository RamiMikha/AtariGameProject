#include "renderer\renderer.h"

int main() {
    UINT32 *base = Physbase();
    UINT8 *base8 = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;
    model.pipe.x = 300;
    model.pipe.y = 0;
    model.score.value = 10;

    clear_screen(base);
    render(base, base8, model);
    model.bird.prev_y = model.bird.y;
    model.pipe.prev_x = model.pipe.x;
    model.bird.y = 200;
    model.pipe.x = 400;
    render(base, base8, model);
    return 0;

}