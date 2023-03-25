#include "doctest.h"
#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"

TEST_CASE("Player test")
{
    CHECK_THROWS(Player(NULL));
    Player one("one");
    Player two("two");
    CHECK(one.stacksize() == 26);
    CHECK(two.stacksize() == 26);
    CHECK(one.cardesTaken() == 0);
    CHECK(two.cardesTaken() == 0);
    Game g(one, two);
    g.playTurn();
    bool isStackSizeChanged = (2 <= one.stacksize() - two.stacksize()) || (2 <= two.stacksize() - one.stacksize());
    CHECK(isStackSizeChanged);
    bool isCardsTaken = (2 <= one.cardesTaken()) || (2 <= two.cardesTaken());
    CHECK(isCardsTaken);
    CHECK(one.stacksize() == two.stacksize());
    CHECK(one.cardesTaken() != two.cardesTaken());
}

TEST_CASE("Game test")
{
    Player one("one");
    Player two("two");
    Game g(one, two);
    CHECK_THROWS(g.printLastTurn());
    CHECK_THROWS(g.printLog());
    g.playAll();
    bool isStacksEmpty = (one.stacksize() == 0) && (two.stacksize() == 0);
    CHECK(isStacksEmpty);
    bool allCardsTaken = one.cardesTaken() + two.cardesTaken() == 52;
    CHECK(allCardsTaken);
    CHECK_THROWS(g.playTurn());
    CHECK_THROWS(g.playAll());
}
