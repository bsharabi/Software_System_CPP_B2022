#ifndef CAPTAIN_H
#define CAPTAIN_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

using coup::CardType;

using namespace std;

namespace coup
{
    class Captain : public Player
    {
    private:
        Player *stolen_from;
    public:
        Captain(Game &,const  string&);
        void block(Player &);
        void steal(Player &);
        Player *getStolen();
    };

}
#endif