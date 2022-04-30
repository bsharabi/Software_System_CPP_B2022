#ifndef ASSASSIN_H
#define ASSASSIN_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;
namespace coup
{
    class Assassin : public Player

    {private:
        Player *attacked;
    public:
        Assassin(Game &, const string&);
        void coup(Player&);
        Player *getAttacked();
    };

}
#endif