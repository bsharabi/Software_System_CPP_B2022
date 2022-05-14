#include <string>
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Good input")
{
    Notebook notebook;

    // test for writing from the begining of the row/column horizontal&vertical
    for (int i = 0; i < 10; i++)
        notebook.write(i, 0, 0, Direction::Horizontal, to_string(i) + " row!");

    for (int i = 10; i < 20; i++)
        notebook.write(i, 0, 0, Direction::Vertical, to_string(i) + " column!");

    // here we read what we wrote above
    for (int i = 0; i < 10; i++)
        CHECK(notebook.read(i, 0, 0, Direction::Horizontal, 6) == to_string(i) + " row!");
    for (int i = 10; i < 20; i++)
        CHECK(notebook.read(i, 0, 0, Direction::Vertical, 10) == to_string(i) + " column!");

    // trying to read from somewhere we didnt write anything
    for (int i = 110; i < 116; i++)
        CHECK(notebook.read(i, 0, 0, Direction::Horizontal, 10) == "__________");

    // test to erase what we wrote above horizontal&vertical
    for (int i = 0; i < 10; i++)
        notebook.erase(i, 0, 0, Direction::Horizontal, 2);
    for (int i = 10; i < 20; i++)
        notebook.erase(i, 0, 0, Direction::Vertical, 1);

    // chacking if its actually removed
    for (int i = 0; i < 10; i++)
        CHECK(notebook.read(i, 0, 0, Direction::Horizontal, 2) == "~~");
    for (int i = 10; i < 20; i++)
        CHECK(notebook.read(i, 0, 0, Direction::Vertical, 1) == "~");
}

TEST_CASE("Bad input ")
{
    Notebook notebook;

    // invalid page&rows&colunms&length numbers inputs, negetive numbers
    for (int i = -10; i < 0; i++)
    {
        CHECK_THROWS(notebook.read(i, 0, 0, Direction::Horizontal, i * -1));
        CHECK_THROWS(notebook.read(i, 0, 0, Direction::Horizontal, i ));
        CHECK_THROWS(notebook.read(i, i, 0, Direction::Horizontal, i ));
        CHECK_THROWS(notebook.read(i, i, i, Direction::Horizontal, i ));
        CHECK_THROWS(notebook.read(i, 0, i, Direction::Horizontal, i ));
        CHECK_THROWS(notebook.read(i, i, 0, Direction::Horizontal, i ));
        CHECK_THROWS(notebook.read(i, 0, 0, Direction::Vertical, i * -1));
        CHECK_THROWS(notebook.read(i, 0, 0, Direction::Vertical, i ));
        CHECK_THROWS(notebook.read(i, i, 0, Direction::Vertical, i ));
        CHECK_THROWS(notebook.read(i, i, i, Direction::Vertical, i ));
        CHECK_THROWS(notebook.read(i, 0, i, Direction::Vertical, i ));
        CHECK_THROWS(notebook.read(i, i, 0, Direction::Vertical, i ));
    }

    // write more then 100 char to a row from 0 and 99 column
    CHECK_THROWS(notebook.write(1, 0, 0, Direction::Horizontal, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
    CHECK_THROWS(notebook.write(1, 0, 99, Direction::Horizontal, "#$$%^^^^%^%^$%$^%&%"));

    // check if possible to write more then 100 chars to column
    CHECK_NOTHROW(notebook.write(2, 0, 0, Direction::Vertical, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2"));

    notebook.write(0, 0, 0, Direction::Horizontal, "Check the erase function");
    notebook.erase(0, 0, 0, Direction::Horizontal, 20);
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, "Check the erase function"));

    // check for invalid input for column over 100 and length of row over 100
    CHECK_THROWS(notebook.read(0, 0, 120, Direction::Horizontal, 10));
    CHECK_THROWS(notebook.erase(0, 0, 120, Direction::Horizontal, 10));
    CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Horizontal, 150));
    CHECK_THROWS(notebook.read(0, 0, 0, Direction::Horizontal, 150));
}

