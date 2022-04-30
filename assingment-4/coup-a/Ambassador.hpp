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
        Ambassador(Game &, const string&);
        void block(Player &);
        void transfer(Player &, Player &);
        Player* getTransferPlayer(int );
    };

}
#endif