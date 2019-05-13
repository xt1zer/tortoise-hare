#pragma once
#include <Snack.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>

class PackageOfSnacks {
public:
    std::map <unsigned int, Snack *> package;

    void generate_food(Snack *food);
    void draw(sf::RenderWindow *window);
};
