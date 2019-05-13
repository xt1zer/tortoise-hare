#include <Carrot.h>

Carrot::Carrot(const float &x, const float &y, const sf::String &file) : Snack(x, y, file) { mType = "Carrot"; }

Carrot::Carrot() { mType = "Carrot"; }
