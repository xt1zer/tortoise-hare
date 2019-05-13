#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Environment {
protected:
    float mX;
    float mY;

    sf::String mFile;
    sf::Texture mTexture;
    sf::Sprite mSprite;

public:
    explicit Environment(const float &x, const float &y, const sf::String &file);

    const sf::Sprite get_sprite() const;
};

