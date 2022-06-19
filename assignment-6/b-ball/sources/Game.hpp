
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Team.hpp"
#include <time.h>
#include <string>
using namespace std;

namespace ariel
{
class Team;
    class Game
    {

    private:
        Team *home;
        Team *out;
        time_t date;
        string _details;

    public:
        //----------------------------- Constructor -----------------------------

        Game(Team *, Team *);
        //------------------------------ Functions ------------------------------
        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &out, const Game &p1);
        //--------------------------- Help Functions ----------------------------
        //------------------------- Getter && Setter  ---------------------------
        string &getDetails() 
        {
            return _details;
        }
    };


}
#endif