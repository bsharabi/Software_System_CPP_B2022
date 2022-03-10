

#include "mat.hpp"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void create_rug(int a, int b, int c, int d, char symbol1, char **matrix, int length_row, int length_col)
{
    if (length_row < a || c > length_col)
    {
        return;
    }
    for (int j = c; j < d; j++)
    {
        *(*(matrix + b) + j) = symbol1;
        *(*(matrix + a) + j) = symbol1;
    }
    for (int j = a; j < b; j++)
    {
        *(*(matrix + j) + c) = symbol1;
        *(*(matrix + j) + d - 1) = symbol1;
    }

    create_rug(a + 2, b - 2, c + 2, d - 2, symbol1, matrix, length_row, length_col);
}

string ariel::mat(int width, int hight, char symbol1, char symbol2)
{

    if (width % 2 == 0 || hight % 2 == 0)
        throw invalid_argument("Argument error");
    else if (width < 0 || hight < 0)
        throw invalid_argument("Argument error");

    char **matrix = new char *[hight];
    for (int i = 0; i < hight; ++i)
        *(matrix + i) = new char[width];

    for (int i = 0; i < hight; i++)
        for (int j = 0; j < width; j++)
            *(*(matrix + i) + j) = '-';

    create_rug(0, hight - 1, 0, width, symbol1, matrix, hight / 2, width / 2);
    string mat = "";
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
            mat += *(*(matrix + i) + j);
        mat += "\n";
    }
    for (int i = 0; i < hight; i++)
        delete[] matrix[i];

    delete[] matrix;

    return mat;
}
