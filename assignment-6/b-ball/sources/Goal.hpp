#ifndef GOAL_H
#define GOAL_H
#include <iostream>
#include "Game.hpp"
#include "Team.hpp"
#include <string>
using namespace std;

namespace ariel
{

    class Goal
    {

    private:

    public:
        //----------------------------- Constructor -----------------------------

        Goal();
        //------------------------------ Functions ------------------------------
        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &out, const Game &p1);
        //--------------------------- Help Functions ----------------------------
    };

}
#endif