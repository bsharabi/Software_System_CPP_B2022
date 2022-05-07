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
         /**
         * Constructor.
         *
         * @param game The instance expressing the game
         * @param name The name of player
         * @return None.
         */
        Contessa(Game &, const string &);
         /**
         * A function that blocks the assassin's coup ..
         *
         * @param Player The obj of player
         * @return None.
         */
        void block(Player &);
    };

}
#endif
