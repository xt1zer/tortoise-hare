#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Snack {
protected:
    sf::String mType;

    float mX;
    float mY;
    float mWidth;
    float mHeight;
    sf::String mFile;

    sf::Texture mTexture;
    sf::Sprite mSprite;

public:
    Snack() {}
    explicit Snack(const float &x, const float &y, const sf::String &file);

    const sf::String get_type() const;
    const sf::Sprite get_sprite() const;
};

