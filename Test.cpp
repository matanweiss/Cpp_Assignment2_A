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
    bool isStackSizeChanged = (one.stacksize() < 26) && (two.stacksize() < 26);
    CHECK(isStackSizeChanged);
    bool isCardsTaken = (2 <= one.cardesTaken()) || (2 <= two.cardesTaken());
    CHECK(isCardsTaken);
    CHECK(one.stacksize() == two.stacksize());
    CHECK(one.cardesTaken() != two.cardesTaken());
}

TEST_CASE("Game test")
{
    Player s("samePlayer");
    CHECK_THROWS(Game(s, s));
    Player one("one");
    Player two("two");
    Game g(one, two);
    CHECK_THROWS(Game(one, one));
    CHECK_THROWS(g.printLastTurn());
    CHECK_THROWS(g.printLog());
    CHECK_NOTHROW(g.playAll());
    bool isStacksEmpty = (one.stacksize() == 0) && (two.stacksize() == 0);
    CHECK(isStacksEmpty);
    bool allCardsTaken = one.cardesTaken() + two.cardesTaken() == 52;
    CHECK(allCardsTaken);
    CHECK_THROWS(g.playTurn());
    CHECK_THROWS(g.playAll());

    // players one and two already finished the game
    CHECK_NOTHROW(Game(one, Player("three")));
    CHECK_NOTHROW(Game(Player("four"), two));
}
