
#include "mat.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

void create_rug(int a, int b, int c, int d, char symbol1, vector<vector<char>> &matrix)
{
    int length_row = matrix.size();
    int length_col = matrix[a].size();

    if (length_row < a || c > length_col)
    {
        return;
    }
    for (int j = c; j < d; j++)
    {
        matrix[b][j] = symbol1;
        matrix[a][j] = symbol1;
    }
    for (int j = a; j < b; j++)
    {
        matrix[j][c] = symbol1;
        matrix[j][d - 1] = symbol1;
    }
    create_rug(a + 2, b - 2, c + 2, d - 2, symbol1, matrix);
}

string ariel::mat(int width, int hight, char symbol1, char symbol2)
{
    if (symbol1 < '!' || symbol1 > '~' || symbol2 < '!' || symbol2 > '~' )
    {
        throw invalid_argument("bad letters");
    }
    if (width % 2 == 0 || hight % 2 == 0)
    {
        throw invalid_argument("Argument error");
    }
    if (width <= 0 || hight <= 0)
    {
        throw invalid_argument("Argument error");
    }

    vector<vector<char>> vec;

    for (int i = 0; i < hight; i++)
    {
        vector<char> row;
        row.reserve(width);
        for (int j = 0; j < width; j++)
        {
            row.push_back(symbol2);
        }
        vec.push_back(row);
    }

    create_rug(0, hight - 1, 0, width, symbol1, vec);
    string s(vec[0].begin(), vec[0].end());
    string mat;
    for (int i = 0; i < hight; i++)
    {
        string s(vec[i].begin(), vec[i].end());
        mat += s + '\n';
    }
    return mat;
}
