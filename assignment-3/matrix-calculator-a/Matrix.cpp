#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <string>
using namespace std;

namespace zich
{
    
    Matrix::Matrix(const vector<double> &mat, int row, int col)
    {
        valid_argument(row, col, mat);
        _col = col;
        _row = row;
        _mat = mat;
        _size = row * col;
    }

    

    Matrix Matrix::operator+(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return *this;
    }

    Matrix Matrix::operator*(const Matrix &mat) const
    {
        valid_size_matrix(mat, 2);

        return *this;
    }

    Matrix Matrix::operator*(double num) const
    {

        return *this;
    }

    Matrix Matrix::operator-()
    {
        return *this;
    }

    Matrix Matrix::operator+()
    {
        return *this;
    }

    Matrix &Matrix::operator++()
    {
        return *this;
    }

    Matrix Matrix::operator++(int)
    {
        return *this;
    }

    Matrix &Matrix::operator--()
    {
        return *this;
    }

    Matrix Matrix::operator--(int)
    {
        return *this;
    }

    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        valid_size_matrix(mat, 1);

        return *this;
    }

    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        valid_size_matrix(mat, 1);

        return *this;
    }

    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        valid_size_matrix(mat, 2);

        return *this;
    }

    Matrix &Matrix::operator*=(double num)
    {

        return *this;
    }

    bool Matrix::operator==(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    bool Matrix::operator!=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    bool Matrix::operator>=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    bool Matrix::operator<=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    bool Matrix::operator<(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    bool Matrix::operator>(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        return true;
    }

    Matrix operator*(int num, Matrix mat)
    {

        return mat;
    }

    std::istream &operator>>(std::istream &in, Matrix &mat)
    {
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Matrix &mat)
    {
        return out;
    }
}