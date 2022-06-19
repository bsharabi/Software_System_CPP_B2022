#include <iostream>

#include "./sources/Game.hpp"
#include "./sources/Player.hpp"
#include "./sources/Team.hpp"
#include "./sources/Goal.hpp"
#include "./sources/Leauge.hpp"
#include "./sources/Schedule.hpp"

using namespace ariel;
using namespace std;

int main()
{
    try
    {
        Player p("barak", "Sharabi", "22/11/1995", 26, 90,nullptr);
        cout << p << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }

    return 1;
}
