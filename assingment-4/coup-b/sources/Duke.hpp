#ifndef DUKE_H
#define DUKE_H

#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;
using coup::CardType;

namespace coup
{
    class Duke : public Player
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
        Duke(Game &, const string &);
        /**
         * A function that blocks the Block the double pay operation..
         *
         * @param Player The obj of player
         * @return None.
         */
        void block(Player &);
        /**
         * A function that allows the duke to take a tax of 3 coins from the .
         *
         * @return None.
         */
        void tax();
    };

}
#endif