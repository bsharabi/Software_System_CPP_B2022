#ifndef LEAUGE_H
#define LEAUGE_H
#include <iostream>
#include "Game.hpp"
#include "Team.hpp"
#include <string>
using namespace std;

namespace ariel
{

    class Leauge
    {

    private:

    public:
        //----------------------------- Constructor -----------------------------

        Leauge();
        //------------------------------ Functions ------------------------------
        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &out, const Game &p1);
        //--------------------------- Help Functions ----------------------------
    };

}
#endif