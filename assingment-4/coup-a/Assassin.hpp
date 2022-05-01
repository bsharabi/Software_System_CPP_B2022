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
      /**
         * Constructor.
         *
         * @param game The instance expressing the game
         * @param name The name of player
         * @return None.
         */
        Assassin(Game &, const string&);
         /**
         * A function that allows a coup in the game, for this player a coup costs about 3 coins.
         *
         * @param Player The obj of player
         * @return None.
         */
        void coup(Player&);
         /**
         * A function that returns the last player we coup
         *
         * @return Player.
         */
        Player *getAttacked();
    };

}
#endif