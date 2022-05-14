#include "doctest.h"
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "Card.hpp"

using namespace std;
using namespace coup;

TEST_CASE("initialization the player")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Checking the game reference")
    {
        // Checking the game address of the players
        CHECK(duke.getGame() == &game_1);
        CHECK(assassin.getGame() == &game_1);
        CHECK(ambassador.getGame() == &game_1);
        CHECK(captain.getGame() == &game_1);
        CHECK(contessa.getGame() == &game_1);
        // Checking the game address of the players (ref)
        CHECK(players[0]->getGame() == &game_1);
        CHECK(players[1]->getGame() == &game_1);
        CHECK(players[2]->getGame() == &game_1);
        CHECK(players[3]->getGame() == &game_1);
        CHECK(players[4]->getGame() == &game_1);
    }
    SUBCASE("Checking the actor reference")
    {
        CHECK(&duke == players[0]);
        CHECK(&assassin == players[1]);
        CHECK(&ambassador == players[2]);
        CHECK(&captain == players[3]);
        CHECK(&contessa == players[4]);
    }
    SUBCASE("Checking the name reference")
    {
        // Checking the player name
        CHECK(*duke.getName() == "Moshe");
        CHECK(*assassin.getName() == "Yossi");
        CHECK(*ambassador.getName() == "Meirav");
        CHECK(*captain.getName() == "Reut");
        CHECK(*contessa.getName() == "Gilad");
        // Checking the player name (ref)
        CHECK(*players[0]->getName() == "Moshe");
        CHECK(*players[1]->getName() == "Yossi");
        CHECK(*players[2]->getName() == "Meirav");
        CHECK(*players[3]->getName() == "Reut");
        CHECK(*players[4]->getName() == "Gilad");

        // Attempt to change player name
        duke.setName("Barak");
        CHECK(*duke.getName() == "Barak");
        CHECK(*players[0]->getName() == "Barak");

        // Attempt to change player name (ref)
        players[2]->setName("Maria");
        CHECK(*players[2]->getName() == "Maria");
        CHECK(*ambassador.getName() == "Maria");
    }
    SUBCASE("Checking the player's role reference")
    {
        CHECK(duke.role() == "Duke");
        CHECK(assassin.role() == "Assassin");
        CHECK(ambassador.role() == "Ambassador");
        CHECK(captain.role() == "Captain");
        CHECK(contessa.role() == "Contessa");

        CHECK(players[0]->role() == "Duke");
        CHECK(players[1]->role() == "Assassin");
        CHECK(players[2]->role() == "Ambassador");
        CHECK(players[3]->role() == "Captain");
        CHECK(players[4]->role() == "Contessa");
    }
    SUBCASE("Checking the player's coins reference")
    {
        // Checking the player money
        CHECK(duke.coins() == 0);
        CHECK(assassin.coins() == 0);
        CHECK(ambassador.coins() == 0);
        CHECK(captain.coins() == 0);
        CHECK(contessa.coins() == 0);
        // Checking the player money (ref)
        CHECK(players[0]->coins() == 0);
        CHECK(players[1]->coins() == 0);
        CHECK(players[2]->coins() == 0);
        CHECK(players[3]->coins() == 0);
        CHECK(players[4]->coins() == 0);
    }
    SUBCASE("Checking the amount of players")
    {
        Game game{};
        CHECK(game.get_numberOfPlayer() == 0);

        Duke duke1{game, "Moshe"};
        CHECK(game.get_numberOfPlayer() == 1);

        Assassin assassin1{game, "Yossi"};
        CHECK(game.get_numberOfPlayer() == 2);

        Ambassador ambassador1{game, "Meirav"};
        CHECK(game.get_numberOfPlayer() == 3);

        Captain captain1{game, "Reut"};
        CHECK(game.get_numberOfPlayer() == 4);

        Contessa contessa1{game, "Gilad"};
        CHECK(game.get_numberOfPlayer() == 5);

        Contessa contessa2{game, "Gilad"};
        CHECK(game.get_numberOfPlayer() == 6);
    }
    SUBCASE("Active player testing")
    {
        // Checking the game address of the players
        CHECK(duke.is_alive() == true);
        CHECK(assassin.is_alive() == true);
        CHECK(ambassador.is_alive() == true);
        CHECK(captain.is_alive() == true);
        CHECK(contessa.is_alive() == true);
        // Checking the game address of the players (ref)
        CHECK(players[0]->is_alive() == true);
        CHECK(players[1]->is_alive() == true);
        CHECK(players[2]->is_alive() == true);
        CHECK(players[3]->is_alive() == true);
        CHECK(players[4]->is_alive() == true);
    }
    SUBCASE("Turn number player testing")
    {
        // Checking the game address of the players
        CHECK(duke.turn_Number() == 0);
        CHECK(assassin.turn_Number() == 1);
        CHECK(ambassador.turn_Number() == 2);
        CHECK(captain.turn_Number() == 3);
        CHECK(contessa.turn_Number() == 4);
        // Checking the game address of the players (ref)
        CHECK(players[0]->turn_Number() == 0);
        CHECK(players[1]->turn_Number() == 1);
        CHECK(players[2]->turn_Number() == 2);
        CHECK(players[3]->turn_Number() == 3);
        CHECK(players[4]->turn_Number() == 4);
    }
}
TEST_CASE("Functionality test")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Income action")
    {
        vector<Player *> players = game_1.players_obj();
        /*Add a coin to each of the players and then check
        if there is an equality between the player object
         and the object which is created in the vector*/
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
        for (Player *p : players)
        {
            CHECK(p->coins() == 1);
            p->income();
        }
        CHECK(duke.coins() == 2);
        CHECK(assassin.coins() == 2);
        CHECK(ambassador.coins() == 2);
        CHECK(captain.coins() == 2);
        CHECK(contessa.coins() == 2);
    }
    SUBCASE("Foreign_aid action")
    {
        /*Add a coin to each of the players and then check
        if there is an equality between the player object
         and the object which is created in the vector*/
        duke.foreign_aid();
        assassin.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();
        for (Player *p : players)
        {
            CHECK(p->coins() == 2);
            p->foreign_aid();
        }
        CHECK(duke.coins() == 4);
        CHECK(assassin.coins() == 4);
        CHECK(ambassador.coins() == 4);
        CHECK(captain.coins() == 4);
        CHECK(contessa.coins() == 4);
    }
    SUBCASE("Is turn player testing")
    {

        for (Player *p : players)
        {
            CHECK(p->turn_Number() == game_1.getTurn());
            p->income();
        }
        // Checking the game address of the players
        CHECK(duke.turn_Number() == game_1.getTurn());
        CHECK_FALSE(assassin.turn_Number() == game_1.getTurn());
        CHECK_FALSE(ambassador.turn_Number() == game_1.getTurn());
        CHECK_FALSE(captain.turn_Number() == game_1.getTurn());
        CHECK_FALSE(contessa.turn_Number() == game_1.getTurn());

        // Checking the game address of the players (ref)
        CHECK(players[0]->turn_Number() == game_1.getTurn());
        CHECK_FALSE(players[1]->turn_Number() == game_1.getTurn());
        CHECK_FALSE(players[2]->turn_Number() == game_1.getTurn());
        CHECK_FALSE(players[3]->turn_Number() == game_1.getTurn());
        CHECK_FALSE(players[4]->turn_Number() == game_1.getTurn());

        // Checking the game address of the players
        duke.income();
        CHECK_FALSE(duke.turn_Number() == game_1.getTurn());
        CHECK_THROWS(duke.is_turn());

        CHECK(assassin.turn_Number() == game_1.getTurn());
        CHECK_FALSE(ambassador.turn_Number() == game_1.getTurn());
        CHECK_FALSE(captain.turn_Number() == game_1.getTurn());
        CHECK_FALSE(contessa.turn_Number() == game_1.getTurn());
        CHECK_THROWS(ambassador.is_turn());
        CHECK_THROWS(captain.is_turn());
        CHECK_THROWS(contessa.is_turn());
        
    }
}
TEST_CASE("operator overloading")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();
    

    SUBCASE("to string function player testing")
    {
        for (Player *p : players)
            cout << *p << endl;
        for (Player *p : players)
        {
            string Player1 = p->description();
            string Player2 = p->description();
            CHECK(Player1 == Player2);
        }
    }
    SUBCASE("Equality between objects")
    {

        CHECK(duke == duke);
        CHECK_FALSE(duke == assassin);
        CHECK_FALSE(duke == ambassador);
        CHECK_FALSE(duke == captain);
        CHECK_FALSE(duke == contessa);

        CHECK(assassin == assassin);
        CHECK_FALSE(assassin == duke);
        CHECK_FALSE(assassin == ambassador);
        CHECK_FALSE(assassin == captain);
        CHECK_FALSE(assassin == contessa);

        CHECK(ambassador == ambassador);
        CHECK_FALSE(ambassador == assassin);
        CHECK_FALSE(ambassador == duke);
        CHECK_FALSE(ambassador == captain);
        CHECK_FALSE(ambassador == contessa);

        CHECK(captain == captain);
        CHECK_FALSE(captain == ambassador);
        CHECK_FALSE(captain == assassin);
        CHECK_FALSE(captain == contessa);
        CHECK_FALSE(captain == duke);

        CHECK(contessa == contessa);
        CHECK_FALSE(contessa == ambassador);
        CHECK_FALSE(contessa == assassin);
        CHECK_FALSE(contessa == duke);
        CHECK_FALSE(contessa == captain);
    }
}
TEST_CASE("Action test")
{
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    vector<Player *> players = game_1.players_obj();

    SUBCASE("Block action")
    {
        //-------------------- duke -------------------------
        CHECK_THROWS(duke.block(assassin));
        CHECK_THROWS(duke.block(captain));
        CHECK_THROWS(duke.block(ambassador));
        CHECK_THROWS(duke.block(contessa));
        CHECK_THROWS(duke.block(duke));
        duke.income();
        CHECK(duke.coins() == 1);
        assassin.foreign_aid();
        CHECK(assassin.coins() == 2);
        duke.block(assassin);
        CHECK(assassin.coins() == 0);
        CHECK(game_1.getTurn() == 2);

        // //-------------------- assassin ----------------------
        // CHECK_THROWS(assassin.block(duke));
        // CHECK_THROWS(assassin.block(captain));
        // CHECK_THROWS(assassin.block(ambassador));
        // CHECK_THROWS(assassin.block(contessa));

        // CHECK_THROWS(assassin.block(assassin));

        // //-------------------- ambassador ---------------------
        // CHECK_NOTHROW(ambassador.block(duke));
        // CHECK_NOTHROW(ambassador.block(assassin));
        // CHECK_NOTHROW(ambassador.block(contessa));
        // CHECK_NOTHROW(ambassador.block(captain));

        // CHECK_THROWS(ambassador.block(ambassador));

        // //-------------------- captain ------------------------
        // CHECK_NOTHROW(captain.block(duke));
        // CHECK_NOTHROW(captain.block(assassin));
        // CHECK_NOTHROW(captain.block(ambassador));
        // CHECK_NOTHROW(captain.block(contessa));

        // CHECK_THROWS(captain.block(captain));

        // //-------------------- contessa ------------------------
        // CHECK_NOTHROW(contessa.block(duke));
        // CHECK_NOTHROW(contessa.block(assassin));
        // CHECK_NOTHROW(contessa.block(ambassador));
        // CHECK_NOTHROW(contessa.block(captain));

        // CHECK_THROWS(contessa.block(contessa));
    }
    SUBCASE("Tax action")
    {
        CHECK(duke.coins() == 0);
        CHECK_NOTHROW(duke.tax());
        CHECK(duke.coins() == 3);
        CHECK_THROWS(assassin.tax());
        CHECK_THROWS(ambassador.tax());
        CHECK_THROWS(captain.tax());
        CHECK_THROWS(contessa.tax());
        CHECK(assassin.coins() == 0);
        CHECK(ambassador.coins() == 0);
        CHECK(captain.coins() == 0);
        CHECK(contessa.coins() == 0);
    }
    SUBCASE("Transfer action")
    {
        //------------------duke-----------------
        CHECK_THROWS(duke.transfer(duke, duke));
        CHECK_THROWS(duke.transfer(duke, assassin));
        CHECK_THROWS(duke.transfer(duke, ambassador));
        CHECK_THROWS(duke.transfer(duke, captain));
        CHECK_THROWS(duke.transfer(duke, contessa));

        CHECK_THROWS(duke.transfer(assassin, assassin));
        CHECK_THROWS(duke.transfer(assassin, duke));
        CHECK_THROWS(duke.transfer(assassin, ambassador));
        CHECK_THROWS(duke.transfer(assassin, captain));
        CHECK_THROWS(duke.transfer(assassin, contessa));

        CHECK_THROWS(duke.transfer(ambassador, ambassador));
        CHECK_THROWS(duke.transfer(ambassador, duke));
        CHECK_THROWS(duke.transfer(ambassador, assassin));
        CHECK_THROWS(duke.transfer(ambassador, captain));
        CHECK_THROWS(duke.transfer(ambassador, contessa));

        CHECK_THROWS(duke.transfer(captain, captain));
        CHECK_THROWS(duke.transfer(captain, duke));
        CHECK_THROWS(duke.transfer(captain, assassin));
        CHECK_THROWS(duke.transfer(captain, ambassador));
        CHECK_THROWS(duke.transfer(captain, contessa));

        CHECK_THROWS(duke.transfer(contessa, contessa));
        CHECK_THROWS(duke.transfer(contessa, duke));
        CHECK_THROWS(duke.transfer(contessa, assassin));
        CHECK_THROWS(duke.transfer(contessa, ambassador));
        CHECK_THROWS(duke.transfer(contessa, captain));

        //------------------assassin-----------------

        CHECK_THROWS(assassin.transfer(duke, duke));
        CHECK_THROWS(assassin.transfer(duke, assassin));
        CHECK_THROWS(assassin.transfer(duke, ambassador));
        CHECK_THROWS(assassin.transfer(duke, captain));
        CHECK_THROWS(assassin.transfer(duke, contessa));

        CHECK_THROWS(assassin.transfer(assassin, assassin));
        CHECK_THROWS(assassin.transfer(assassin, duke));
        CHECK_THROWS(assassin.transfer(assassin, ambassador));
        CHECK_THROWS(assassin.transfer(assassin, captain));
        CHECK_THROWS(assassin.transfer(assassin, contessa));

        CHECK_THROWS(assassin.transfer(ambassador, ambassador));
        CHECK_THROWS(assassin.transfer(ambassador, duke));
        CHECK_THROWS(assassin.transfer(ambassador, assassin));
        CHECK_THROWS(assassin.transfer(ambassador, captain));
        CHECK_THROWS(assassin.transfer(ambassador, contessa));

        CHECK_THROWS(assassin.transfer(captain, captain));
        CHECK_THROWS(assassin.transfer(captain, duke));
        CHECK_THROWS(assassin.transfer(captain, assassin));
        CHECK_THROWS(assassin.transfer(captain, ambassador));
        CHECK_THROWS(assassin.transfer(captain, contessa));

        CHECK_THROWS(assassin.transfer(contessa, contessa));
        CHECK_THROWS(assassin.transfer(contessa, duke));
        CHECK_THROWS(assassin.transfer(contessa, assassin));
        CHECK_THROWS(assassin.transfer(contessa, ambassador));
        CHECK_THROWS(assassin.transfer(contessa, captain));

        //------------------ambassador-----------------

        CHECK_THROWS(ambassador.transfer(duke, duke));
        CHECK_THROWS(ambassador.transfer(duke, assassin));
        CHECK_THROWS(ambassador.transfer(duke, ambassador));
        CHECK_THROWS(ambassador.transfer(duke, captain));
        CHECK_THROWS(ambassador.transfer(duke, contessa));

        CHECK_THROWS(ambassador.transfer(assassin, assassin));
        CHECK_THROWS(ambassador.transfer(assassin, duke));
        CHECK_THROWS(ambassador.transfer(assassin, ambassador));
        CHECK_THROWS(ambassador.transfer(assassin, captain));
        CHECK_THROWS(ambassador.transfer(assassin, contessa));

        CHECK_THROWS(ambassador.transfer(ambassador, ambassador));
        CHECK_THROWS(ambassador.transfer(ambassador, duke));
        CHECK_THROWS(ambassador.transfer(ambassador, assassin));
        CHECK_THROWS(ambassador.transfer(ambassador, captain));
        CHECK_THROWS(ambassador.transfer(ambassador, contessa));

        CHECK_THROWS(ambassador.transfer(captain, captain));
        CHECK_THROWS(ambassador.transfer(captain, duke));
        CHECK_THROWS(ambassador.transfer(captain, assassin));
        CHECK_THROWS(ambassador.transfer(captain, ambassador));
        CHECK_THROWS(ambassador.transfer(captain, contessa));

        CHECK_THROWS(ambassador.transfer(contessa, contessa));
        CHECK_THROWS(ambassador.transfer(contessa, duke));
        CHECK_THROWS(ambassador.transfer(contessa, assassin));
        CHECK_THROWS(ambassador.transfer(contessa, ambassador));
        CHECK_THROWS(ambassador.transfer(contessa, captain));

        //------------------captain-----------------

        CHECK_THROWS(captain.transfer(duke, duke));
        CHECK_THROWS(captain.transfer(duke, assassin));
        CHECK_THROWS(captain.transfer(duke, ambassador));
        CHECK_THROWS(captain.transfer(duke, captain));
        CHECK_THROWS(captain.transfer(duke, contessa));

        CHECK_THROWS(captain.transfer(assassin, assassin));
        CHECK_THROWS(captain.transfer(assassin, duke));
        CHECK_THROWS(captain.transfer(assassin, ambassador));
        CHECK_THROWS(captain.transfer(assassin, captain));
        CHECK_THROWS(captain.transfer(assassin, contessa));

        CHECK_THROWS(captain.transfer(ambassador, ambassador));
        CHECK_THROWS(captain.transfer(ambassador, duke));
        CHECK_THROWS(captain.transfer(ambassador, assassin));
        CHECK_THROWS(captain.transfer(ambassador, captain));
        CHECK_THROWS(captain.transfer(ambassador, contessa));

        CHECK_THROWS(captain.transfer(captain, captain));
        CHECK_THROWS(captain.transfer(captain, duke));
        CHECK_THROWS(captain.transfer(captain, assassin));
        CHECK_THROWS(captain.transfer(captain, ambassador));
        CHECK_THROWS(captain.transfer(captain, contessa));

        CHECK_THROWS(captain.transfer(contessa, contessa));
        CHECK_THROWS(captain.transfer(contessa, duke));
        CHECK_THROWS(captain.transfer(contessa, assassin));
        CHECK_THROWS(captain.transfer(contessa, ambassador));
        CHECK_THROWS(captain.transfer(contessa, captain));

        //------------------contessa-----------------

        CHECK_THROWS(contessa.transfer(duke, duke));
        CHECK_THROWS(contessa.transfer(duke, assassin));
        CHECK_THROWS(contessa.transfer(duke, ambassador));
        CHECK_THROWS(contessa.transfer(duke, captain));
        CHECK_THROWS(contessa.transfer(duke, contessa));

        CHECK_THROWS(contessa.transfer(assassin, assassin));
        CHECK_THROWS(contessa.transfer(assassin, duke));
        CHECK_THROWS(contessa.transfer(assassin, ambassador));
        CHECK_THROWS(contessa.transfer(assassin, captain));
        CHECK_THROWS(contessa.transfer(assassin, contessa));

        CHECK_THROWS(contessa.transfer(ambassador, ambassador));
        CHECK_THROWS(contessa.transfer(ambassador, duke));
        CHECK_THROWS(contessa.transfer(ambassador, assassin));
        CHECK_THROWS(contessa.transfer(ambassador, captain));
        CHECK_THROWS(contessa.transfer(ambassador, contessa));

        CHECK_THROWS(contessa.transfer(captain, captain));
        CHECK_THROWS(contessa.transfer(captain, duke));
        CHECK_THROWS(contessa.transfer(captain, assassin));
        CHECK_THROWS(contessa.transfer(captain, ambassador));
        CHECK_THROWS(contessa.transfer(captain, contessa));

        CHECK_THROWS(contessa.transfer(contessa, contessa));
        CHECK_THROWS(contessa.transfer(contessa, duke));
        CHECK_THROWS(contessa.transfer(contessa, assassin));
        CHECK_THROWS(contessa.transfer(contessa, ambassador));
        CHECK_THROWS(contessa.transfer(contessa, captain));

        //לבדוק עכשיו באמת העבברה
    }
    SUBCASE("Ref transfer action")
    {
        for (unsigned int k = 0; k < 5; k++)
        {
            for (unsigned int i = 0; i < 5; i++)
            {
                for (unsigned int j = 0; j < 5; j++)
                {

                    CHECK_THROWS(players[k]->transfer(*players[i], *players[j]));
                }
            }
        }
    }
    SUBCASE("Steal action")
    {
        CHECK_THROWS(duke.steal(duke));
        CHECK_THROWS(duke.steal(assassin));
        CHECK_THROWS(duke.steal(ambassador));
        CHECK_THROWS(duke.steal(captain));
        CHECK_THROWS(duke.steal(contessa));

        CHECK_THROWS(assassin.steal(duke));
        CHECK_THROWS(assassin.steal(assassin));
        CHECK_THROWS(assassin.steal(ambassador));
        CHECK_THROWS(assassin.steal(captain));
        CHECK_THROWS(assassin.steal(contessa));

        CHECK_THROWS(ambassador.steal(duke));
        CHECK_THROWS(ambassador.steal(assassin));
        CHECK_THROWS(ambassador.steal(ambassador));
        CHECK_THROWS(ambassador.steal(captain));
        CHECK_THROWS(ambassador.steal(contessa));

        CHECK_THROWS(captain.steal(duke));
        CHECK_THROWS(captain.steal(assassin));
        CHECK_THROWS(captain.steal(ambassador));
        CHECK_THROWS(captain.steal(captain));
        CHECK_THROWS(captain.steal(contessa));

        CHECK_THROWS(contessa.steal(duke));
        CHECK_THROWS(contessa.steal(assassin));
        CHECK_THROWS(contessa.steal(ambassador));
        CHECK_THROWS(contessa.steal(captain));
        CHECK_THROWS(contessa.steal(contessa));

        //לבדוק גם גניבה אמיתית
    }
    SUBCASE("Ref steal action")
    {
        for (unsigned int k = 0; k < 5; k++)
        {
            for (unsigned int i = 0; i < 5; i++)
            {

                CHECK_THROWS(players[k]->steal(*players[i]));
            }
        }
    }
}