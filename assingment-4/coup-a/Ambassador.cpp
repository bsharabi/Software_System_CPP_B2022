#include "Ambassador.hpp"
#include <vector>
#include <string>
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, const string &name) : Player(name, 0, CardType::Ambassador, game)
{
    transfer_from = NULL;
    transfer_to = NULL;
    // cout << "Constructor: " << this << endl;
}
void Ambassador::block(Player &p)
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
        last_action = ActionType::block;
        cout << "Hello block from " << *this << " to " << p << endl;
    }
    else
    {
        throw invalid_argument("the last operation " + *p.getName() + " " + p.getCardName() + " performed is income, which cannot be blocked by any role");
    }
}
void Ambassador::transfer(Player &p1, Player &p2)
{
    last_action = ActionType::err;
    is_turn();
    if (p1 == p2)
    {
        throw invalid_argument("It is not possible to transfer money from a player to himself");
    }
    if (!p1.is_alive() || !p2.is_alive())
    {
        throw invalid_argument("One of the players was eliminated from the game");
    }
    if (p1.coins() < 1 || p2.coins() < 1)
    {
        throw invalid_argument("This action can not be performed, one of the players does not have enough money");
    }
    last_action = ActionType::transfer;
    transfer_from = &p1;
    transfer_from = &p2;
    p1.setMoney(-1);
    p2.setMoney(1);
    cout << "Hello transfer from " << p1 << " to " << p2 << endl;
}
Player *Ambassador::getTransferPlayer(int mode)
{
    if (mode < 0 || mode > 1)
    {
        throw invalid_argument("Err");
    }
    if (mode == 0)
    {
        return transfer_from;
    }

    return transfer_to;
}