#include "sources/Player.hpp"
#include "sources/Duke.hpp"
#include "sources/Assassin.hpp"
#include "sources/Ambassador.hpp"
#include "sources/Captain.hpp"
#include "sources/Contessa.hpp"
#include "sources/Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

	Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	duke.description();
	Assassin assassin{game_1, "Yossi"};
	assassin.description();
	Ambassador ambassador{game_1, "Meirav"};
	ambassador.description();
	Captain captain{game_1, "Reut"};
	captain.description();
	Contessa contessa{game_1, "Gilad"};
	contessa.description();
	vector<string> players = game_1.players();

	/*
		prints:
		Moshe
		Yossi
		Meirav
		Reut
		Gilad
	*/

	// throws no exceptions
	cout << "duke income" << endl;
	duke.income();
	duke.description();

	cout << "assassin income" << endl;
	assassin.income();
	assassin.description();

	cout << "ambassador income" << endl;
	ambassador.income();
	ambassador.description();

	cout << "captain income" << endl;
	captain.income();
	captain.description();

	cout << "contessa income" << endl;
	contessa.income();
	contessa.description();

	// throws exception, it is duke's turn now
	cout << "-------------------------- Throw ----------------------------\n";
	try
	{
		assassin.income();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "-------------------------------------------------------------\n";
	cout << "duke income" << endl;
	duke.income();
	duke.description();

	cout << "duke foreign_aid" << endl;
	assassin.foreign_aid();
	assassin.description();

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	cout << "-------------------------- Throw ----------------------------\n";
	try
	{
		captain.block(duke);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "-------------------------------------------------------------\n";

	// throws exception, the last operation assassin performed
	// is foreign aid, which cannot be blocked by contessa
	cout << "-------------------------- Throw ----------------------------\n";

	try
	{
		contessa.block(assassin);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "-------------------------------------------------------------\n";
	cout << "-------------------------- duke.block(assassin) ----------------------------\n";
	duke.block(assassin);
	assassin.description();
	cout << "-------------------------------------------------------------\n";

	cout << "-------------------------- ambassador.transfer(duke, assassin) ----------------------------\n";
	ambassador.transfer(duke, assassin); // transfers 1 coin from duke to assassin
	duke.description();
	assassin.description();
	cout << "captain foreign_aid" << endl;
	captain.foreign_aid();
	captain.description();

	cout << "contessa foreign_aid" << endl;
	contessa.foreign_aid();
	contessa.description();

	cout << "duke tax" << endl;
	duke.tax();
	duke.description();

	cout << "assassin income" << endl;
	assassin.income();
	assassin.description();

	cout << "ambassador foreign_aid" << endl;
	ambassador.foreign_aid();
	ambassador.description();

	cout << "captain steal from contessa" << endl;
	captain.steal(contessa);
	captain.description();

	cout << "contessa foreign_aid" << endl;
	contessa.foreign_aid();
	contessa.description();

	cout << "duke tax" << endl;
	duke.tax();
	duke.description();

	cout << "-------------------------- assassin.coup(duke) ----------------------------\n";
	// no exception, assassin can coup with only 3 coins
	assassin.coup(duke);
	duke.description();

	players = game_1.players();
	/*
		prints:
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string const &name : players)
	{
		cout << name << endl;
	}
	cout << "-------------------------- contessa.block(assassin) ----------------------------\n";
	contessa.block(assassin);
	duke.description();

	players = game_1.players();
	/*
		prints:
		Moshe
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string const &name : players)
	{
		cout << name << endl;
	}
}
