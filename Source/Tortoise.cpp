#include <Tortoise.h>

Tortoise::Tortoise() : Animal(20, 150, 21, 31, "Media/tortoise.png") {
    mSprite.setScale(2, 2);
}

//Tortoise::Tortoise(const float &x, const float &y, const float &width, const float &height, const sf::String &file) 
//    : Animal(x, y, width, height, file) {
//    mSprite.setScale(2, 2);
//};

void Tortoise::animate(const float &time) {
    mCurrentFrame += 0.005 * time;
    if (mCurrentFrame > 2)
        mCurrentFrame -= 2;
    mSprite.setTextureRect(sf::IntRect(21 * int(mCurrentFrame), 0, 21, 31));
}

void Tortoise::get_random_movement() {
    srand(time(NULL));
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
