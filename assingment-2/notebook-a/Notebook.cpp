#include <iostream>
#include "Notebook.hpp"
#include <map>
#include <string>
using ariel::Notebook;
using namespace std;
typedef unsigned int uint;

void Notebook::write(int page, int row_number, int column, ariel::Direction direction, string const &str)
{
    if (!Notebook::validation(page, row_number, column, direction, 0, str))
    {
        return;
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
        line = notebook[page_number][row];
        for (uint i = (uint)col, cnt = 0; i < len + (uint)col; i++, cnt++)
        {
            if (line[i] != '_')
            {
                throw invalid_argument("Can not write in this column");
            }

            line[i] = str[cnt];
        }
        notebook[page_number][row] = line;
    }
    else
    {
        Notebook::createMultiLine(page_number, row, len + 1);

        for (uint i = (uint)row; direction == Direction::Vertical && i < (uint)row + len; i++)
        {
            line = Notebook::notebook[page_number][(uint)i];
            if (line[col] != '_')
            {
                return;
            }
            // throw invalid_argument("Can not write in this column ver");
        }
        for (uint i = (uint)row, cnt = 0; direction == Direction::Vertical && i < row + len; i++, cnt++)
        {
            Notebook::notebook[page_number][i][col] = str[cnt];
        }
    }
}

string Notebook::read(int page, int row_number, int column, ariel::Direction direction, int len)
{
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
    uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;
    Notebook::createMultiLine(page_number, row, count_row);
    for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
    {
        line = Notebook::notebook[page_number][i];
        word += line[col];
    }

    line = Notebook::notebook[page_number][row];
    for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
    {
        word += line[i];
    }
    return word;
}

void Notebook::erase(int page, int row_number, int column, ariel::Direction direction, int len)
{
    if (!Notebook::validation(page, row_number, column, direction, 0, "ok", len))
    {
        return;
    }

    uint row = (uint)row_number;
    uint col = (uint)column;
    uint page_number = (uint)page;
    uint length = (uint)len;
    string line;
    string word;
    uint count_row = (direction == Direction::Vertical) ? length + 1 : 3;
    Notebook::createMultiLine(page_number, row, count_row);
    for (uint i = row; direction == Direction::Vertical && i < row + length; i++)
    {
        Notebook::notebook[page_number][i][col] = '~';
    }

    for (uint i = col; direction == Direction::Horizontal && i < col + length; i++)
    {
        Notebook::notebook[page_number][row][i] = '~';
    }
}

void Notebook::show(int page_n)
{
    uint page_number = (uint)page_n;
    if (Notebook::pageExist(page_number))
    {
        cout << "Page " + to_string(page_number) + " Does not exist" << endl;
        return;
    }

    map<uint, string> page = Notebook::getPage(page_number);

    cout << "                                        -Page number(" << to_string(page_number) << ")-" << endl;
    for (auto const &kv : page)
    {
        cout << kv.second << endl;
    }
}

Notebook::Notebook(){};
