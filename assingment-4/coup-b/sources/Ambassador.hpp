#ifndef AMBASSADOR_H
#define AMBASSADOR_H
#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using coup::CardType;

using namespace std;

namespace coup
{
    class Ambassador : public Player

    {
    private:
        Player *transfer_from;
        Player *transfer_to;

    public:
        /**
         * Constructor.
         *
         * @param game The instance expressing the game
         * @param name The name of player
         * @return None.
         */
        Ambassador(Game &, const string &);
        /**
         * block - A function responsible for preventing the theft of a Captain-type player.
         *
         * @param Player The name of player
         * @return None.
         */
        void block(Player &);
        /**
         * A function that allows the transfer of coins from one player to another..
         *
         * @param Player The name of player
         * @param Player The name of player
         * @return None.
         */
        void transfer(Player &, Player &);
        /**
         * A function that returns the player from whom coins were taken or a player who received the coins when activating a transfer function.
         *
         * @param mode 1,0
         * @return Player.
         */
        Player *getTransferPlayer(int);
    };

}
#endif