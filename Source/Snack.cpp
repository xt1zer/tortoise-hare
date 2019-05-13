#include <Snack.h>

Snack::Snack(const float &x, const float &y, const sf::String &file) : mX(x), mY(y), mFile(file) {
    mTexture.loadFromFile(file);
    mSprite.setTexture(mTexture);

    mSprite.setPosition(mX, mY);
}

const sf::String Snack::get_type() const { return this->mType; }

const sf::Sprite Snack::get_sprite() const { return this->mSprite; }
