#include <Hare.h>

Hare::Hare() : Animal(0, 300, 33, 28, "Media/hare.png") {
    mSprite.setScale(2, 2);
}

void Hare::animate(const float &time) {
    mCurrentFrame += 0.009 * time;
    if (mCurrentFrame > 2)
        mCurrentFrame -= 2;
    mSprite.setTextureRect(sf::IntRect(33 * int(mCurrentFrame), 0, 33, 29));
}

void Hare::get_random_movement() {
    int rnd = rand() % 10 + 1;
    if (rnd <= 5) {
        mDir = LEFT;
        mSpeed = 0.03;
    }
    else {
        mDir = RIGHT;
        mSpeed = 0.08;
    }
}