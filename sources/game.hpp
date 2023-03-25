#pragma once
#include "player.hpp"

class Game
{
private:
    std::string *turns;

public:
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    Game(Player, Player);
};

namespace ariel
{

};