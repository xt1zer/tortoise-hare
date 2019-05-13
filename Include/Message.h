#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Message {
private:
    float mX;
    float mY;

    sf::Font mFont;
    sf::Text mText;

public:
    Message();
    explicit Message(const float &x, const float &y, const sf::String &msg);

    void printMsg(sf::RenderWindow *window);
};
