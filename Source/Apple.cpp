#include <Apple.h>

Apple::Apple(const float &x, const float &y, const sf::String &file) : Snack(x, y, file) { mType = "Apple"; }

Apple::Apple() { mType = "Apple"; }
