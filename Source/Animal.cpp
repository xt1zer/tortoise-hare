#include <Animal.h>

Animal::Animal(const float &x, const float &y, const float &width, const float &height, const sf::String &file)
    : mX(x), mY(y), mWidth(width), mHeight(height),
    mFile(file), mDir(RIGHT), mDx(0), mSpeed(0),
    mCurrentFrame(0), mIsBonusActive(false), mTotalBonusTime(0), mCurrentBonusTime(0) {

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, mWidth, mHeight));
    mSprite.setPosition(mX, mY);
}

const sf::Sprite Animal::get_sprite() const { return this->mSprite; }

void Animal::set_sprite_position(const float &x, const float &y) {
    mX = x;
    mY = y;
    mSprite.setPosition(mX, mY);
}

void Animal::set_speed(const float &speed) { this->mSpeed = speed; }

void Animal::update(const float &time) {
    switch (mDir) {
        case RIGHT:
            mDx = mSpeed;
            break;

        case LEFT:
            mDx = -mSpeed;
            break;
    }

    mX += mDx * time;

    if (mX < 0)
        mX = 0;

    mSprite.setPosition(mX, mY);
}

const bool Animal::is_winner() const {
    if (mX >= 1173)
        return true;
    return false;
}

const bool Animal::eat_snack(PackageOfSnacks *PackageOfFood) {
    for (auto food : PackageOfFood->package) {
        if (this->mSprite.getGlobalBounds().intersects(food.second->get_sprite().getGlobalBounds())) {
            delete food.second;
            PackageOfFood->package.erase(food.first);
            return true;
        }
    }
    return false;
}

void Animal::activate_bonus(const bool &flag) {
    this->mIsBonusActive = flag;

    if (mIsBonusActive) {
        mTotalBonusTime += 500 - mCurrentBonusTime;
        mCurrentBonusTime = 0;
        mDir = RIGHT;
        set_speed(0.20f);
    }
    else {
        mCurrentBonusTime = 0;
        mTotalBonusTime = 0;
    }
}

const bool Animal::is_bonus_active() const { return this->mIsBonusActive; }

void Animal::set_total_bonus_time(const float &value) { mTotalBonusTime += value; }

void Animal::set_current_bonus_time(const float &value) { mCurrentBonusTime += value; }

const float Animal::get_total_bonus_time() const { return this->mTotalBonusTime; }

const float Animal::get_current_bonus_time() const { return this->mCurrentBonusTime; }
