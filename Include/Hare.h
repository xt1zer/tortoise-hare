#pragma once
#include <Animal.h>

class Hare : public Animal {
public:
    Hare();

    void animate(const float &time);
    void get_random_movement();
};

