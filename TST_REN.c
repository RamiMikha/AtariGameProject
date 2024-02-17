#include "renderer\renderer.h"

int main() {
    UINT32 *base = Physbase();
    Model model;

    model.bird.x = 100;
    model.bird.y = 100;

    render(base, model);
    return 0;

}