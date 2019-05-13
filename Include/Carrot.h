#pragma once
#include <Snack.h>

class Carrot : public Snack {
public:
    explicit Carrot(const float &x, const float &y, const sf::String &file);
    Carrot();
};
