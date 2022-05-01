#include "Contessa.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Contessa::Contessa(Game &game,const string &name) : Player(name, 0, CardType::Contessa, game)
{
    // cout <<  "Constructor: "<<this << endl;
}

void Contessa::block(Player &p)
{
    last_action = ActionType::err;
    if (*this == p)
    {
        throw invalid_argument("Can not block himself");
    }
    if (!p.is_alive())
    {
        throw invalid_argument("The player was eliminated from the game");
    }
    if (p.getLastAction() == ActionType::coup)
    {
        p.getAttacked()->setAlive(true);
        last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.getName() + " " + p.getCardName() + " performed is foreign aid, which cannot be blocked by " + *this->getName() + " " + this->getCardName());
    }
}
