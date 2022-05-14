#include "Duke.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Duke::Duke(Game &game, const string &name) : Player(name, 0, CardType::Duke, game)
{
    // cout << "Constructor: " << this << endl;
}
void Duke::block(Player &p)
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
    if (p.getLastAction() == ActionType::foreign_aid)
    {
        p.setMoney(-2);
        last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.getName() + " " + p.getCardName() + " performed is income, which cannot be blocked by any role");
    }
}
void Duke::tax()
{
    last_action = ActionType::err;
    is_turn("tax");
    setMoney(3);
    last_action = ActionType::tax;
    cout << "Hello tax from " << *this << endl;
    this->_game->incTurn();
}
