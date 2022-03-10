/**
 * AUTHORS: <Barak Sharabi>
 *
 * Date: 2021-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{
	CHECK(nospaces(mat(25, 7, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@\n"
													 "@-----------------------@\n"
													 "@-@@@@@@@@@@@@@@@@@@@@@-@\n"
													 "@-@-------------------@-@\n"
													 "@-@@@@@@@@@@@@@@@@@@@@@-@\n"
													 "@-----------------------@\n"
													 "@@@@@@@@@@@@@@@@@@@@@@@@@"));

	CHECK(nospaces(mat(31, 9, '#', '-')) == nospaces("###############################\n"
													 "#-----------------------------#\n"
													 "#-###########################-#\n"
													 "#-#-------------------------#-#\n"
													 "#-#-#######################-#-#\n"
													 "#-#-------------------------#-#\n"
													 "#-###########################-#\n"
													 "#-----------------------------#\n"
													 "###############################"));

	CHECK(nospaces(mat(25, 7, '$', '-')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$\n"
													 "$-----------------------$\n"
													 "$-$$$$$$$$$$$$$$$$$$$$$-$\n"
													 "$-$-------------------$-$\n"
													 "$-$$$$$$$$$$$$$$$$$$$$$-$\n"
													 "$-----------------------$\n"
													 "$$$$$$$$$$$$$$$$$$$$$$$$$"));

	CHECK(nospaces(mat(9, 5, 'b', '-')) == nospaces("bbbbbbbbb\n"
													"b-------b\n"
													"b-bbbbb-b\n"
													"b-------b\n"
													"bbbbbbbbb"));

	CHECK(nospaces(mat(1, 31, '*', '-')) == nospaces("*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*\n"
													 "*"));

	CHECK(nospaces(mat(3, 21, '*', '-')) == nospaces("***\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "*-*\n"
													 "***"));

	CHECK(nospaces(mat(23, 29, 'a', '-')) == nospaces("aaaaaaaaaaaaaaaaaaaaaaa\n"
													  "a---------------------a\n"
													  "a-aaaaaaaaaaaaaaaaaaa-a\n"
													  "a-a-----------------a-a\n"
													  "a-a-aaaaaaaaaaaaaaa-a-a\n"
													  "a-a-a-------------a-a-a\n"
													  "a-a-a-aaaaaaaaaaa-a-a-a\n"
													  "a-a-a-a---------a-a-a-a\n"
													  "a-a-a-a-aaaaaaa-a-a-a-a\n"
													  "a-a-a-a-a-----a-a-a-a-a\n"
													  "a-a-a-a-a-aaa-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-a-a-a-a-a-a-a\n"
													  "a-a-a-a-a-aaa-a-a-a-a-a\n"
													  "a-a-a-a-a-----a-a-a-a-a\n"
													  "a-a-a-a-aaaaaaa-a-a-a-a\n"
													  "a-a-a-a---------a-a-a-a\n"
													  "a-a-a-aaaaaaaaaaa-a-a-a\n"
													  "a-a-a-------------a-a-a\n"
													  "a-a-aaaaaaaaaaaaaaa-a-a\n"
													  "a-a-----------------a-a\n"
													  "a-aaaaaaaaaaaaaaaaaaa-a\n"
													  "a---------------------a\n"
													  "aaaaaaaaaaaaaaaaaaaaaaa"));

	CHECK(nospaces(mat(7, 9, '!', '-')) == nospaces("!!!!!!!\n"
													"!-----!\n"
													"!-!!!-!\n"
													"!-!-!-!\n"
													"!-!-!-!\n"
													"!-!-!-!\n"
													"!-!!!-!\n"
													"!-----!\n"
													"!!!!!!!"));

	CHECK(nospaces(mat(3, 41, '^', '-')) == nospaces("^^^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^-^\n"
													 "^^^"));

	CHECK(nospaces(mat(1, 5, '&', '-')) == nospaces("&\n"
													"&\n"
													"&\n"
													"&\n"
													"&"));

	CHECK(nospaces(mat(1, 1, 'm', '-')) == nospaces("m"));

	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));

	CHECK(nospaces(mat(7, 5, '@', '-')) == nospaces("@@@@@@@\n"
													"@-----@\n"
													"@-@@@-@\n"
													"@-----@\n"
													"@@@@@@@"));

	CHECK(nospaces(mat(7, 7, '@', '-')) == nospaces("@@@@@@@\n"
													"@-----@\n"
													"@-@@@-@\n"
													"@-@-@-@\n"
													"@-@@@-@\n"
													"@-----@\n"
													"@@@@@@@"));

	CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@@@"));

	CHECK(nospaces(mat(5, 7, '@', '-')) == nospaces("@@@@@\n"
													"@---@\n"
													"@-@-@\n"
													"@-@-@\n"
													"@-@-@\n"
													"@---@\n"
													"@@@@@"));

	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));

	CHECK(nospaces(mat(5, 13, '@', '-')) == nospaces("@@@@@\n"
													 "@---@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@-@-@\n"
													 "@---@\n"
													 "@@@@@"));

	CHECK(nospaces(mat(11, 15, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													  "@---------@\n"
													  "@-@@@@@@@-@\n"
													  "@-@-----@-@\n"
													  "@-@-@@@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@-@-@-@\n"
													  "@-@-@@@-@-@\n"
													  "@-@-----@-@\n"
													  "@-@@@@@@@-@\n"
													  "@---------@\n"
													  "@@@@@@@@@@@\n"));
}

TEST_CASE("Bad input")
{

	for (int i = 0; i < 20; i += 2)
	{
		CHECK_THROWS(mat(i, 5, '$', '%'));
		CHECK_THROWS(mat(9, i, '$', '%'));
		CHECK_THROWS(mat(i, i + 8, '$', '%'));
		CHECK_THROWS(mat(i + 1, i, '$', '%'));
		CHECK_THROWS(mat(10, i, '$', '%'));
	}

	for (int i = 0; i > -20; i--)
		for (int j = 0; j < 20; j++)
			CHECK_THROWS(mat(i, j, '$', '%'));

	for (int i = 0; i > 20; i--)
		for (int j = 0; j < -20; j++)
			CHECK_THROWS(mat(i, j, '$', '%'));
}
