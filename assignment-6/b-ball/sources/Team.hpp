
#ifndef TEAM_H
#define TEAM_H
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace ariel
{
    class Game;
    class Player;
    class Team
    {
    private:
        string _team_name;
        float _talent_level;
        int _id;
        string team_color;
        vector<Game *> games;
        map<int, Player *> _players;

    public:
        //----------------------------- Constructor -----------------------------
        Team():_team_name("barak"){};
        //------------------------------ Functions ------------------------------

        //--------------------------- Getter && Setter --------------------------
        string get_team_name(){
            return _team_name;
        }

        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &out, const Team &t);
    private:
        //--------------------------- Help Functions ----------------------------
    };

}
#endif