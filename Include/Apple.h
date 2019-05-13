#pragma once
#include <Snack.h>

class Apple :public Snack {
public:
    explicit Apple(const float &x, const float &y, const sf::String &file);

    Apple();
};
