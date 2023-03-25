#pragma once
#include <string>
#include "card.hpp"

class Player
{
    std::string name;
    Card stack[26];

public:
    int stacksize();
    int cardesTaken();
    Player(std::string);
};
