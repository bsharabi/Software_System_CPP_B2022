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
     
        Duke(Game& , const string& );   
        void block(Player &); 
        void tax(); 
    };

}
#endif