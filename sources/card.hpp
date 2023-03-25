#pragma once

class Card
{
private:
    int number;
    int shape; // 1 - Hearts, 2 - Diamonds, 3 - Spades, 4 - Clubs
public:
    void setNumber(int);
    void setShape(int);
    int compareTo(Card);
    Card();
    Card(int, int);
};