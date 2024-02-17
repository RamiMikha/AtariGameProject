#include "renderer\renderer.h"

int main() {
    UINT32 *base = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;
    model.pipe.x = 300;

    render(base, model);
    return 0;

}