#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"
#include "Player.hpp"

using coup::CardType;

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
        string _Ngame;
        unsigned int _numberOfPlayer;
        vector<Player *> _players;
        unsigned int _turn;
        bool active;

    public:
        /**
         * Constructor.
         * @param
         * @param
         * @return None.
         */
        Game();
        string turn();
        vector<string> players();
        vector<Player *> players_obj();
        string winner();
        void addPlayer(Player *);
        unsigned int getTurn() const;
        void incPlayerNumber();
        unsigned int get_numberOfPlayer() const;
        void incTurn();
    };

}
#endif