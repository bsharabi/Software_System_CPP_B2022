#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include "Game.hpp"
#include "Team.hpp"
#include <string>
using namespace std;

namespace ariel
{

    class Schedule
    {

    private:

    public:
        //----------------------------- Constructor -----------------------------

        Schedule();
        //------------------------------ Functions ------------------------------
        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &out, const Game &p1);
        //--------------------------- Help Functions ----------------------------
    };

}
#endif