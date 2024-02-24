#include "renderer\renderer.h"

int main() {
    UINT32 *base = Physbase();
    UINT8 *base8 = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;
    model.pipe.x = 300;
    model.score.value = 10;

    /*Calling main render function to test the rendering of the full screen*/
    render(base, base8, model);
    return 0;

}