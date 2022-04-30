#include "Player.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using namespace coup;
namespace coup
{
    Player::Player(const string &name, int money, CardType role, Game &g)
    {
        _game = &g;
        last_action = ActionType::err;
        alive = true;
        _role = role;
        this->name = name;
        _money = money;
        turn_number = (*(_game)).get_numberOfPlayer();
        (*(_game)).incPlayerNumber();
        switch (_role)
        {
        case CardType::Duke:
            this->_card_name = "Duke";
            break;
        case CardType::Assassin:
            this->_card_name = "Assassin";
            break;
        case CardType::Ambassador:
            this->_card_name = "Ambassador";
            break;
        case CardType::Captain:
            this->_card_name = "Captain";
            break;
        case CardType::Contessa:
            this->_card_name = "Contessa";
            break;
        }
        (*(_game)).addPlayer(this);
    };
    void Player::income()
    {
        if (is_turn())
        {
            last_action = ActionType::income;
            this->_money++;
        }
    }
    void Player::foreign_aid()
    {
        if (is_turn())
        {
            last_action = ActionType::foreign_aid;
            this->_money += 2;
        }
    }
    void Player::coup(Player &p)
    {
        if (*this == p)
        {
            throw invalid_argument("A player can not dismiss himself from the game...");
        }
        if (!p.is_alive())
        {
            throw invalid_argument("The player was eliminated from the game");
        }
        if (_money < m_)
        {
            throw invalid_argument("The cost of the method is about 7 coins, you do not have enough ...");
        }
        is_turn();
        cout << "Hello coup from Player" << endl;
        last_action = ActionType::coup;
        p.setAlive(false);
    }
    string Player::role()
    {
        return _card_name;
    }
    int Player::coins() const
    {
        return _money;
    }
    string *Player::getName()
    {
        return &name;
    }
    string Player::getCardName()
    {
        return _card_name;
    }
    bool Player::is_turn()
    {

        if (turn_number != (*(_game)).getTurn())
        {
            cout << "print: Is not your turn " << *this << endl;
            throw invalid_argument("Is not your turn");
        }
        if (!is_alive())
        {
            cout << "You're out of the game " << *this << endl;
            (*(_game)).incTurn();
            throw invalid_argument("You're out of the game");
        }
        (*(_game)).incTurn();
        return true;
    }
    bool Player::is_alive() const
    {
        return alive;
    }
    ActionType Player::lastAction()
    {
        return last_action;
    }
    Game *Player::getGame()
    {
        return _game;
    }

    unsigned int Player::turn_Number() const
    {
        return turn_number;
    }

    void Player::block(Player &p)
    {
        throw invalid_argument("This player can not perform this action");
    }
    void Player::steal(Player &p)
    {
        throw invalid_argument("This player can not perform this action");
    }
    void Player::tax()
    {
        throw invalid_argument("This player can not perform this action");
    }
    void Player::transfer(Player &p1, Player &p2)
    {
        throw invalid_argument("This player can not perform this action");
    }
    void Player::setName(const string &name)
    {
        this->name = name;
    }
    ostream &
    operator<<(std::ostream &out, const Player &p1)
    {
        out << "\033[1;31mName: \033[1;33m" << p1.name + " \033[0;34m" + p1._card_name + "\033[0m";
        return out;
    }
    string Player::description()
    {
        return "\033[1;31mName: \033[1;33m" + *this->getName() + " \033[0;34m" + this->_card_name + "\033[0m";
    }
    bool Player::operator==(const Player &p) const
    {
        return this == &p;
    }
    void Player::setMoney(int m)
    {
        _money += m;
    }
    Player *Player::getStolen()
    {
        throw invalid_argument("This player can not perform this action");
    }
    void Player::setAlive(bool Alive)
    {
        alive = Alive;
    }
    Player *Player::getAttacked()
    {
        throw invalid_argument("This player can not perform this action");
    }

}