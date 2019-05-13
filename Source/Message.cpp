#include <Message.h>

Message::Message() : mX(350), mY(50) {
    mFont.loadFromFile("C:/Windows/Fonts/impact.TTF");
    mText.setFont(mFont);
    mText.setString("Press Enter to start");
    mText.setPosition(mX, mY);
}

Message::Message(const float &x, const float &y, const sf::String &msg) : mX(x), mY(y) {
    mFont.loadFromFile("C:/Windows/Fonts/impact.TTF");
    mText.setFont(mFont);
    mText.setString(msg);
    mText.setPosition(mX, mY);
}

void Message::printMsg(sf::RenderWindow *window) {
    window->draw(mText);
}
