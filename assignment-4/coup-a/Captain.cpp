#include "Captain.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Captain::Captain(Game &game,const string &name) : Player(name, 0, CardType::Captain, game)
{
    // cout <<  "Constructor: "<<this << endl;
    stolen_from=NULL;
}
void Captain::block(Player &p)
{
    this->last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not block himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (p.getLastAction() == ActionType::steal)
    {
        p.setMoney(-2);
        p.getStolen()->setMoney(2);
        this->last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.getName() + " " + p.getCardName() + " performed is income, which cannot be blocked by any role");
    }
}
void Captain::steal(Player &p)
{
    this->last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not steal himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (is_turn())
    {
        if (_money < 2)
        {
            throw invalid_argument("Can not steal from ...");
        }
        this->last_action = ActionType::steal;
        this->stolen_from = &p;
        _money += 2;
        p.setMoney(-2);
        cout << "Hello steal from " << *this << " to " << p << endl;
    }
}
Player *Captain::getStolen()
{
    return stolen_from;
}
