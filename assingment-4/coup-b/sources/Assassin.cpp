
#include "Assassin.hpp"
#include <vector>
#include <string>


using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, const string &name) : Player(name, 0, CardType::Assassin, game), attacked(NULL)
{
        // cout <<  "Constructor: "<<this << endl;
}
void Assassin::coup(Player &p)
{
        this->last_action = ActionType::err;
        is_turn("coup");
        if (*this == p)
        {
                throw invalid_argument("Can not coup himself");
        }
        if (!p.is_alive())
        {
                throw invalid_argument("The player was eliminated from the game");
        }
        if (_money >= 3)
        {
                _money -= cost_coup = (_money >= MAX_TO_COUP) ? MAX_TO_COUP : MIN_TO_COUP;
                p.setAlive(false);
                last_action = ActionType::coup;
                attacked = &p;
                cout << "Hello coup from " << *this << " to " << p << endl;
                this->_game->incTurn();
                this->_game->setActivePlayer(-1);
                return;
        }
        throw invalid_argument("This action can not be performed, the player does not have enough money");
}
Player *Assassin::getAttacked()
{
        return attacked;
}

