#include <PackageOfSnacks.h>

void PackageOfSnacks::generate_food(Snack *food) {
    for (int i = 0; i < 3; ++i) {
        int pos = rand() % 1000 + 100;
        if (food->get_type() == "Apple")
            package[i] = new Snack(pos, 170, "Media/apple.png");
        else
            package[i] = new Snack(pos, 320, "Media/carrot.png");
    }
}

void PackageOfSnacks::draw(sf::RenderWindow *window) {
    for (auto food : package) {
        window->draw(food.second->get_sprite());
    }
}
