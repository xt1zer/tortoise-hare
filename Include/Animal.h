#pragma once
#include <PackageOfSnacks.h>

class Animal {
protected:
    float mX;
    float mY;
    float mWidth;
    float mHeight;

    enum Directions { RIGHT, LEFT } mDir;

    float mDx;
    float mSpeed;

    sf::String mFile;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    float mCurrentFrame;

    bool mIsBonusActive;
    float mTotalBonusTime;
    float mCurrentBonusTime;

public:
    explicit Animal(const float &x, const float &y, const float &width, const float &height, const sf::String &file);

    const sf::Sprite get_sprite() const;
    void set_sprite_position(const float &x, const float &y);

    virtual void animate(const float &time) = 0;
    virtual void get_random_movement() = 0;
    void set_speed(const float &speed);
    void update(const float &time);

    const bool is_winner() const;
    const bool eat_snack(PackageOfSnacks *PackageOfFood);
    void activate_bonus(const bool &flag);
    const bool is_bonus_active() const;
    void set_total_bonus_time(const float &value);
    void set_current_bonus_time(const float &value);
    const float get_total_bonus_time() const;
    const float get_current_bonus_time() const;
};

