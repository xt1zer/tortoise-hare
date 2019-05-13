#include <Environment.h>

Environment::Environment(const float &x, const float &y, const sf::String &file) : mX(x), mY(y), mFile(file) {
    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(mX, mY);
}

const sf::Sprite Environment::get_sprite() const { return this->mSprite; }
