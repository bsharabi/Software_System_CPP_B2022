
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"
#include "Game.hpp"
#define m_ 7
using namespace std;

namespace coup
{
    class Game;
    class Player
    {
    protected:
        string name;
        string _card_name;
        CardType _role;
        Game *_game;
        ActionType last_action;
        int _money;
        unsigned int turn_number;
        bool alive;

    public:
        /**
         * Constructor.
         * @param name The name of the actor
         * @param role Type of player
         * @param game The object of the game
         * @return None.
         */
        Player(const string &, int, CardType, Game &);
        /**
         *@brief  Take a coin.
         *This action has no cost, no counter-actions and the player earns a single coin..
         * @return None.
         */
        void income();
        /**
         *@brief  Double pay - foreign_aid - take two coins from the pile.
         *This action has no cost and it entitles the player to two coins.
         *But, there is a role in the game that can block this action.
         *  If the player is blocked while trying to take a double pay, his turn ends.
         * @return None.
         */
        void foreign_aid();
        /**
         *@brief  Coup - to oust an opposing player
         *from his position and thus remove him from the game.
         *The cost of this action is 7 coins,
         *it has no counter-actions and it ends with the player on whom the
         *action was activated being fired and ending the game
         *
         * @param player Object player
         * @return None.
         */
        virtual void coup(Player &);
        /**
         *@brief  The role of the actor
         * A function that returns the role of the player
         *
         * @return None.
         */
        string role();
        /**
         *@brief  The coins of the actor
         * A function that returns The amount of coins of the player
         *
         * @return None.
         */
        int coins()const;
        /**
         *@brief  The coins of the actor
         * A function that returns The amount of coins of the player
         *
         * @param player Object player
         * @return None.
         */
        virtual void block(Player &);
        virtual void steal(Player &);
        virtual void tax();
        virtual void transfer(Player &, Player &);
        ActionType lastAction();
        /**
         *@brief  The method returns
         *
         * @return name's ref.
         */
        string *getName();
        /**
         *@brief  The method returns the role of the actor
         *
         * @return Card Name.
         */
        string getCardName();
        /**
         *@brief  The method returns the object of the game
         *
         * @return object of the game.
         */
        Game *getGame();
        /**
         *@brief  name's setter
         *
         * @param name The new name of the actor
         * @return None.
         */
        void setName(const string &);
        /**
         *@brief  The method returns whether it is the player's turn
         *
         * @return True if not otherwise..
         */
        bool is_turn();
        /**
         *@brief  TThe method returns whether the player is still in the game
         *
         * @return True if not otherwise.
         */
        bool is_alive() const;
        /**
         * @brief The method returns the player's turn number
         *
         * @param player The object expressing the player
         * @return turn number.
         */
        unsigned int turn_Number() const;
        /**
         * operator = overloading.
         *
         * @param player The object expressing the player
         * @return Player description.
         */
        string description();
        /**
         * operator * overloading.
         *
         * @param out
         * @param player The object expressing the player
         * @return st.
         */
        friend std::ostream &operator<<(std::ostream &out, const Player &p1);
        /**
         * operator == overloading.
         *
         * @param player The object expressing the player
         * @return True if not otherwise.
         */
        bool operator==(const Player &p) const;

        void setMoney(int m);
        virtual Player *getStolen();
        void setAlive(bool);
        virtual Player *getAttacked();
    };

}
#endif