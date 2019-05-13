#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Flag.h>
#include <Tortoise.h>
#include <Hare.h>
#include <Apple.h>
#include <Carrot.h>
#include <PackageOfSnacks.h>
#include <Ground.h>
#include <Message.h>

class Application : private sf::NonCopyable {
private:
    bool gameOver;
    bool isEnterPressed;
    float time;

    sf::RenderWindow mWindow;
    sf::Vector2u mWindowSize;

    Tortoise tortoise;
    Hare hare;

    Apple apple;
    Carrot carrot;
    PackageOfSnacks packageOfApples;
    PackageOfSnacks packageOfCarrots;

    Ground ground;
    Message startMsg;

public:
    Application();

    void update(const float &time);
    void render(const Flag &f1, const Flag &f2);
    void endGame();
};
