
#ifndef PLAYER_H
#define PLAYER_H
#include "../doctest.h"
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"
#include "Game.hpp"
#include <fstream>
#define MAX_PLAYER 6
#define MAX_TO_COUP 7
#define MAX_COINS_TO_COUP 9
#define MIN_TO_COUP 3
#define MAX_PLAYERS 6
#define  MIN_ACTIVE 1  
using namespace std;

namespace coup
{
    class Game;
    class Player
    {
    protected:
        string name;
        string _card_name;
        string actor_draw;
        CardType _role;
        Game *_game;
        ActionType last_action;
        int _money;
        unsigned int turn_number;
        bool alive;
        int cost_coup;

    public:
        //-------------------------------------- Constructor -----------------------------------
        /**
         * Constructor.
         * @param name The name of the actor
         * @param role Type of player
         * @param game The object of the game
         * @return None.
         */
        Player(const string &, int, CardType, Game &);
        // ------------------------------------- Function --------------------------------------
        /**
         * @brief  Take a coin.
         * This action has no cost, no counter-actions and the player earns a single coin..
         * @return None.
         */
        void income();
        /**
         * @brief  Double pay - foreign_aid - take two coins from the pile.
         * This action has no cost and it entitles the player to two coins.
         * But, there is a role in the game that can block this action.
         * If the player is blocked while trying to take a double pay, his turn ends.
         * @return None.
         */
        void foreign_aid();
        /**
         *@brief  The role of the actor
         * A function that returns the role of the player
         *
         * @return returns the role of the player.
         */
        string role();
        /**
         *@brief  The coins of the actor
         * A function that returns The amount of coins of the player
         *
         * @return returns The amount of coins of the player.
         */
        int coins() const;
        // ----------------------------------- Help function -----------------------------------
        /**
         *@brief  The method returns whether it is the player's turn
         *
         * @return True if not otherwise..
         */
        bool is_turn(string const &);
        /**
         *@brief  TThe method returns whether the player is still in the game
         *
         * @return True if not otherwise.
         */
        bool is_alive() const;
        /**
         * @brief The method returns the player's turn number
         *
         * @return turn number.
         */
        unsigned int turn_Number() const;
        /**
         * Description method.
         *
         * @return Player description.
         */
        string description();
        /**
         * the cost of the last coup.
         *
         * @return Return the cost of the last coup.
         */
        int getCost_coup() const;
        // -------------------------------------- Overloading function --------------------------
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
        // ---------------------------------------- Getter && Setter ----------------------------
        /**
         *@brief  Function responsible for returning the last action performed by the player
         *
         * @return last action performed by the player.
         */
        ActionType getLastAction();
        /**
         *@brief setter coins
         *
         * @param m Number of coins to add
         * @return None.
         */
        void setMoney(int m);
        /**
         *@brief  setter alive
         *
         * @return None.
         */
        void setAlive(bool);
        /**
         *@brief  name's setter
         *
         * @param name The new name of the actor
         * @return None.
         */
        void setName(const string &);
        /**
         *@brief  name getter
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
        // ----------------------------------- Virtual Function -------------------------------
        /**
         *@brief  A function that returns the player from whom coins were stolen in the last round
         *
         * @return Player obj.
         */
        virtual Player *getStolen();
        /**
         *@brief  Virtual function, if the player does not have such a method then an error is thrown
         *
         * @param player Object player
         * @return None.
         */
        virtual void block(Player &);
        /**
         *@brief  Virtual function, if the player does not have such a method then an error is thrown
         *
         * @param player Object player
         * @return None.
         */
        virtual void steal(Player &);
        /**
         *@brief  TVirtual function, if the player does not have such a method then an error is thrown
         *
         * @return None.
         */
        virtual void tax();
        /**
         *@brief  Virtual function, if the player does not have such a method then an error is thrown
         * @param player from p
         * @param player to p
         * @return None.
         */
        virtual void transfer(Player &, Player &);
        /**
         *@brief  Virtual function, if the player does not have such a method then an error is thrown

         *
         * @return player Object player.
         */
        virtual Player *getAttacked();
        /**
         * @brief  Coup - to oust an opposing player
         * from his position and thus remove him from the game.
         * The cost of this action is 7 coins,
         * it has no counter-actions and it ends with the player on whom the
         * action was activated being fired and ending the game
         *
         * @param player Object player
         * @return None.
         */
        virtual void coup(Player &);

        
    };

}
#endif