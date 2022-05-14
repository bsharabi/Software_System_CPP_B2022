#include <iostream>
#include "Notebook.hpp"
#include <map>
#include <string>
using ariel::Notebook;
using namespace std;
typedef unsigned int uint;

void Notebook::write(int page, int row_number, int column, ariel::Direction direction, string const &str)
{
    // Input integrity check
    if (!Notebook::validation(page, row_number, column, direction, 0, str))
    {
        throw invalid_argument("did not pass validation");
    }

    uint row = (uint)row_number;
    uint col = (uint)column;
    uint page_number = (uint)page;
    uint len = (uint)str.length();
    string line;

    // Checking the writing direction
    if (direction == Direction::Horizontal)
    {
        Notebook::createMultiLine(page_number, row);
        // Gets the line
        line = notebook[page_number][row];
        // A loop responsible for writing horizontally
        for (uint i = col, cnt = 0; i < len + col; i++, cnt++)
        {
            // Input integrity check
            if (line[i] != '_' || str[cnt] == '\n' || str[cnt] < ' ' || str[cnt] >= '~')
            {
                throw invalid_argument("Can not write in this column Hor");
            }

            line[i] = str[cnt];
        }
        // insert line to notebook
        notebook[page_number][row] = line;
    }

    else
    {
        Notebook::createMultiLine(page_number, row, len + 1);
        bool flag = true;
        // A loop responsible for writing horizontally
        for (uint i = row, cnt = 0; i < row + len; i++, cnt++)
        {
            // Gets the line
            line = Notebook::notebook[page_number][i];
            // Input integrity check
            if (line[col] != '_' || str[cnt] == '\n' || str[cnt] < ' ' || str[cnt] >= '~')
            {

                throw invalid_argument("Can not write in this column ver");
                flag = false;
                return;
            }
        }
        // insert lines to notebook
        for (uint i = row, cnt = 0; flag && i < row + len; i++, cnt++)
        {
            Notebook::notebook[page_number][i][col] = str[cnt];
        }
    }
}

string Notebook::read(int page, int row_number, int column, ariel::Direction direction, int len)
{
    // Input integrity check
    if (!Notebook::validation(page, row_number, column, direction, 1, "f", len))
    {
        throw invalid_argument("did not pass validation");
    }

    uint row = (uint)row_number;
    uint col = (uint)column;
    uint page_number = (uint)page;
    uint length = (uint)len;
    string line;
    string word;
    // Number of rows to create if not available
    uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;

    Notebook::createMultiLine(page_number, row, count_row);
    // A loop responsible for reading vertically
    for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
    {
        line = Notebook::notebook[page_number][i];
        word += line[col];
    }
    // Gets the line
    line = Notebook::notebook[page_number][row];
    // A loop responsible for reading horizontally
    for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
    {
        word += line[i];
    }
    return word;
}

void Notebook::erase(int page, int row_number, int column, ariel::Direction direction, int len)
{
    // Input integrity check
    if (!Notebook::validation(page, row_number, column, direction, 2, "ok", len))
    {
        return;
    }

    uint row = (uint)row_number;
    uint col = (uint)column;
    uint page_number = (uint)page;
    uint length = (uint)len;
    string line;
    string word;
    // Number of rows to create if not available
    uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;
    Notebook::createMultiLine(page_number, row, count_row);
    // A loop responsible for deleting vertically
    for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
    {
        Notebook::notebook[page_number][i][col] = '~';
    }
    // A loop responsible for deleting horizontally
    for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
    {
        Notebook::notebook[page_number][row][i] = '~';
    }
}

void Notebook::show(int page_n)
{
    // Check the page number that is not negative
    if (page_n < 0)
    {
        throw invalid_argument("Incorrect parameters");
    }

    uint page_number = (uint)page_n;

    // Create a page that has not yet been written and that we would like to show
    if (Notebook::pageExist(page_number))
    {
        Notebook::setPage(page_number);
    }

    map<uint, string> page = Notebook::getPage(page_number);
    // Print the page conveniently
    cout << "                                        -Page number(" << to_string(page_number) << ")-" << endl;
    for (auto const &kv : page)
    {
        cout << kv.second << endl;
    }
}

Notebook::Notebook(){};
