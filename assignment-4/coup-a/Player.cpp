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
        last_action = ActionType::start;
        alive = true;
        _role = role;
        this->name = name;
        _money = money;
        turn_number = (*(_game)).get_numberOfPlayer();
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
        string line;
        ifstream myfile("logo_card/" + _card_name);
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                actor_draw += "\033[0;34m" + line + "\n";
            }
            myfile.close();
            actor_draw += "\033[0m";
        }
        else
        {
            cout << "Unable to open file";
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
    ActionType Player::getLastAction()
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
    ostream &
    operator<<(std::ostream &out, const Player &p1)
    {

        out << "\033[1;31mName: \033[1;33m" << p1.name + " \033[0;34m" + p1._card_name + "\033[0m";
        return out;
    }
    string Player::description()
    {

        string action;
        switch (last_action)
        {
        case ActionType::income:
            action = "income";
            break;
        case ActionType::foreign_aid:
            action = "foreign_aid";
            break;
        case ActionType::tax:
            action = "tax";
            break;
        case ActionType::steal:
            action = "steal";
            break;
        case ActionType::block:
            action = "block";
            break;
        case ActionType::transfer:
            action = "transfer";
            break;
        case ActionType::err:
            action = "err";
            break;
        case ActionType::coup:
            action = "coup";
            break;
        case ActionType::start:
            action = "start";
            break;
        }
        string doc;
        string tempAlive = alive?"true":"false";
        doc += actor_draw;
        doc += "\033[1;31m| Name: \033[1;33m" + *getName() + "\n";
        doc += "\033[1;31m| Role: \033[1;33m" + _card_name + "\n";
        doc += "\033[1;31m| Coins: \033[1;33m" + to_string(_money) + "\n";
        doc += "\033[1;31m| Alive: \033[1;33m" + tempAlive + "\n";
        doc += "\033[1;31m| Last-Action: \033[1;33m" + action + "\n";
        doc += "\033[1;31m| Turn-Number: \033[1;33m" + to_string(turn_number) + "\n\033[0m";
        return doc;
    }

}