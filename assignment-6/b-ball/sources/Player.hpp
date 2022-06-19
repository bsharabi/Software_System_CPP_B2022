#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Team.hpp"
#include "Game.hpp"
#include <ctime>
#include <list>
#include <regex>
#include <string>
using namespace std;

namespace ariel
{
    class Team;
    class Player
    {
    private:
        class PLayer_Data
        {
        private:
        public:
        };
        class PLayer_Card
        {
        private:
        public:
        };
        // class Iterator
        // {
        // private:
        //     Game *_cur;
        //     list<Game *> *game;

        // public:
        //     //----------------------------- Constructor -----------------------------
        //     Iterator();
        //     // ------------------------------ Destructor  --------------------------------------
        //     /**
        //      * Overloading operator*
        //      * @return string name.
        //      */
        //     string &operator*() const { return _cur->getDetails(); }
        //     /**
        //      * Overloading operator->
        //      * @return string name.
        //      */
        //     string *operator->() const
        //     {
        //         return &_cur->getDetails();
        //     }
        //     /**
        //      * Overloading operator++
        //      * @return iterator.
        //      */
        //     Iterator &operator++()
        //     {

        //         return *this;
        //     }
        //     /**
        //      * Overloading ++operator
        //      * @return iterator.
        //      */
        //     Iterator operator++(int)
        //     {
        //         Iterator tmp = ++(*this);
        //         return tmp;
        //     }
        //     /**
        //      * Overloading operator==
        //      * @return bool .
        //      */
        //     bool operator==(const Iterator &rhs) const
        //     {
        //         return _cur == rhs._cur;
        //     }
        //     /**
        //      * Overloading operator!=
        //      * @return bool .
        //      */
        //     bool operator!=(const Iterator &rhs) const
        //     {
        //         return _cur != rhs._cur;
        //     }
        // };

    private:
        Team *current_team;
        int number;

        string first_name;
        string last_name;

        time_t _date;
        string _birthday;

        unsigned int _age;
        int _health;

    public:
        //----------------------------- Constructor -----------------------------
        Player(string const &, string const &, string, size_t, int,Team *);

        //------------------------------ Functions ------------------------------
        //----------------------------- overloading -----------------------------
        friend std::ostream &operator<<(ostream &, const Player &);
        //--------------------------- Help Functions ----------------------------
        static void validPlayerDetails(string const &f_name, string const &l_name, string b_day, size_t age, int health)
        {
            if (!regex_match(f_name, regex("^(?=.{1,40}$)[a-zA-Z1-9]+(?:[_'\\s][a-zA-Z]+)*$")))
            {
                throw invalid_argument("Invalid name");
            }

            if (!regex_match(l_name, regex("^(?=.{1,40}$)[a-zA-Z1-9]+(?:[_'\\s][a-zA-Z]+)*$")))
            {
                throw invalid_argument("Invalid last name");
            }

            if (!regex_match(b_day, regex("^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$")))
            {
                throw invalid_argument("Incorrect date of birth");
            }

            if (!(age >= 0 && age <= 120))
            {
                throw invalid_argument("Incorrect age");
            }

            if (!(health >= 0 && health <= 100))
            {
                throw invalid_argument("Improper health condition");
            }
        }
    };

}

#endif