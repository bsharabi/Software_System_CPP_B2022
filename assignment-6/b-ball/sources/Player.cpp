#include "Player.hpp"

namespace ariel
{

    Player::Player(string const &f_name, string const &l_name, string birthday, size_t age, int health, Team *team=nullptr)
    {

        validPlayerDetails(f_name, l_name, birthday, age, health);
        first_name = f_name;
        last_name = l_name;
        _age = age;
        _birthday = birthday;
        _health = health;
        _date = time(0);
        current_team = team;
    }

    std::ostream &operator<<(ostream &out, const Player &p)
    {
        out << "Full name " << p.last_name << " " << p.first_name << endl;
        out << ((p.current_team != nullptr) ? (p.current_team->get_team_name()) : " ") << endl;
        out << "Age " << p._age << endl;
        out << "Birthday " << p._birthday << endl;
        out << "Health " << p._health << endl;

        return out;
    }

}