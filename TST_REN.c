#include "renderer\renderer.h"

int main() {
    UINT32 *base = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;
    model.pipe.x = 300;

    /*Calling main render function to test the rendering of the full screen*/
    render(base, model);
    return 0;

}