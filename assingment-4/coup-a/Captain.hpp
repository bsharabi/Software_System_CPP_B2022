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
      /**
         * Constructor.
         *
         * @param game The instance expressing the game
         * @param name The name of player
         * @return None.
         */
        Captain(Game &,const  string&);
          /**
         * A function that blocks the captain's steal..
         *
         * @param Player The obj of player
         * @return None.
         */
        void block(Player &);
          /**
         * A function that allows the theft of 2 coins from another player ..
         *
         * @param Player The obj of player
         * @return None.
         */
        void steal(Player &);
          /**
         * A function that returns the player from whom the coins were stolen while activating the steal function.
         * 
         * @return Player.
         */
        Player *getStolen();
    };

}
#endif