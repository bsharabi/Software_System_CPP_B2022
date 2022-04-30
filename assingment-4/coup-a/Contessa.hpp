#ifndef CONTESSA_H
#define CONTESSA_H
#include <iostream>
#include <vector>
#include <string>

#include "Player.hpp"

#include "Game.hpp"

using coup::CardType;

using namespace std;

namespace coup
{
    class Contessa : public Player
    {
    private:
    public:
        Contessa(Game &, const string &);
        void block(Player &);
    };

}
#endif
