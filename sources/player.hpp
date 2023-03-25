#pragma once
#include <string>
#include "card.hpp"

class Player
{
    std::string name;

public:
    int stacksize();
    int cardesTaken();
    Player(std::string);
};
