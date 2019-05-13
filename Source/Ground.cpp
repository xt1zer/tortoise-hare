#include <Ground.h>

Ground::Ground() : Environment(0, 0, "Media/land.png") {}

void Ground::generate_ground(sf::Vector2u &windowSize) {
    for (int i = 0; i < windowSize.x / 75 + 1; ++i) {
        for (int j = 0; j < windowSize.y / 75 + 1; ++j) {
            if (j == 2 || j == 4) {
                mSprite.setTextureRect(sf::IntRect(75, 0, 75, 75));
                mSprite.setPosition(i * 75, j * 75);
            }
            else {
                mSprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
                mSprite.setPosition(i * 75, j * 75);
            }
            ground.push_back(mSprite);
        }
    }
}

void Ground::draw(sf::RenderWindow *window) {
    for (auto plate : ground) {
        window->draw(plate);
    }
}
