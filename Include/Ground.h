#pragma once
#include <Environment.h>
#include <vector>

class Ground : public Environment {
private:
    std::vector <sf::Sprite> ground;

public:
    Ground();

    void generate_ground(sf::Vector2u &windowSize);
    void draw(sf::RenderWindow *window);
};
