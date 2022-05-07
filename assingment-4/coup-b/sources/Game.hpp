#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"
#include "Player.hpp"


using coup::CardType;
using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
        string _Ngame;
        vector<Player *> _players;
        bool active;
        unsigned int _numberOfPlayer;
        int _numberOfPlayerActive;
        unsigned int _turn;

    public:
        // --------------------------------Constructor -------------------------------
        /**
         * @brief Constructor
         * The class builder, creates a new object and initializes the class fields
         *
         * @return None.
         */
        Game();
        // -------------------------------- Functions --------------------------------
        /**
         * @brief A function that returns the name of the player who now has his turn in the gameץ
         *
         * @return Returns the name of the player whose turn it is now.
         */
        string turn();
        /**
         * @brief A function responsible for creating a vector that contains the names of the players in the game.
         *
         * @return Returns a vector that contains the names of all the active players in the game.
         */
        vector<string> players();
        /**
         * @brief Function responsible for returning the name of the player who won the game (last in the game)
         * If the game is still active returns an error.
         *
         * @return The name of the winner.
         */
        string winner();
        // ------------------------------- Help function ------------------------------
        /**
         * @brief A function responsible for creating a vector that contains the object of the players in the game.
         *
         * @return Returns a vector that contains the object of all the  players in the game.
         */
        vector<Player *> players_obj();
        /**
         *@brief A function responsible for adding players in a game into the players vector.
         * The insertion is by the address of the object.
         *
         * @param Player The obj of player
         * @return None.
         */
        void addPlayer(Player *);
        /**
         *@brief A function that increases the number of players in one.
         *
         * @return None.
         */
        void incPlayerNumber();
        /**
         *@brief A function that returns the number of players who started the game.
         *
         * @return Number of players in the game.
         */
        unsigned int get_numberOfPlayer() const;
        /**
         * The function responsible for promoting the turn to the next player.
         *
         * @return None.
         */
        void incTurn();
        /**
         * isActive - Checks if the game is running.
         *
         * @return True if not otherwise
         */
        bool isActive() const;
        /**
         * Description method.
         *
         * @return Player description.
         */
        string description();
        //------------------------------- Getter && Setter -----------------------------
        /**
         * Setter.
         *
         * @return None.
         */
        void setName();
        /**
         * getter.
         *
         * @return game's name.
         */
        string getName();
        /**
         *  Setter
         * @return None.
         */
        void setTurn();
        /**
         *@brief Function responsible for returning the current queue number.
         *
         * @return Current queue number.
         */
        unsigned int getTurn() const;
        /**
         *Setter
         * @return None.
         */
        void setActive();
        /**
         * getter.
         *
         * @return return  active.
         */
        bool getActive();
        /**
         * getter.
         *
         * @return return  active.
         */
        void setActivePlayer(int);
        /**
         * getter.
         *
         * @return return  active.
         */
        int getActivePlayer() const;
    };

}
#endif