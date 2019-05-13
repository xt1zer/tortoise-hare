#pragma once
#include <Animal.h>

class Tortoise : public Animal {
public:
    Tortoise();
    //explicit Tortoise(const float &x, const float &y, const float &width, const float &height, const sf::String &file);

    void animate(const float &time);
    void get_random_movement();
};
