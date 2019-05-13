#pragma once
#include <Environment.h>

class Flag : public Environment {
public:
    explicit Flag(const float &x, const float &y, const sf::String &file);
};
