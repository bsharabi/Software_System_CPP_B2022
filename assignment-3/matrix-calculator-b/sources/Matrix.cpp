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
        _row = (row);
        _col = (col);
        _size = (row * col);
        _mat = (mat);
    }

    Matrix Matrix::operator+(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        vector<double> temp((size_t)(_size));

        for (size_t i = 0; i < _size; i++)
        {
            temp[i] = _mat[i] + mat._mat[i];
        }
        return Matrix(temp, _row, _col);
    }

    Matrix Matrix::operator-(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        vector<double> temp((size_t)(_size));
        for (size_t i = 0; i < _size; ++i)
        {
            temp[i] = _mat[i] - mat._mat[i];
        }
        return Matrix(temp, _row, _col);
    }

    Matrix Matrix::operator*(const Matrix &mat) const
    {

        valid_size_matrix(mat, 2);
        vector<double> temp((size_t)(_row * mat._col));

        for (size_t i = 0; i < _row; ++i)
        {
            for (size_t j = 0; j < mat._col; ++j)
            {
                uint index = i * (size_t)mat._col + j;
                temp[index] = 0;
                for (size_t k = 0; k < mat._row; ++k)
                {
                    uint row = i * (size_t)_col + k;
                    uint col = k * (size_t)mat._col + j;
                    temp[index] += _mat[row] * mat._mat[col];
                }
            }
        }
        return Matrix(temp, _row, mat._col);
    }

    Matrix Matrix::operator*(double num) const
    {
        vector<double> temp((size_t)(_size));
        for (size_t i = 0; i < _size; ++i)
        {
            temp[i] = _mat[i] * num;
        }
        return Matrix(temp, _row, _col);
    }

    Matrix Matrix::operator-()
    {
        vector<double> temp((size_t)(_size));
        for (size_t i = 0; i < _size; ++i)
        {
            if (_mat[i] == 0)
            {
                continue;
            }
            temp[i] = _mat[i] * -1;
        }
        return Matrix(temp, _row, _col);
    }

    Matrix Matrix::operator+() { return *this; }

    Matrix &Matrix::operator++()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            this->_mat[i]++;
        }
        return *this;
    }

    Matrix Matrix::operator++(int)
    {
        Matrix temp = *this;
        for (size_t i = 0; i < _size; ++i)
        {
            ++this->_mat[i];
        }
        return temp;
    }

    Matrix &Matrix::operator--()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            this->_mat[i]--;
        }
        return *this;
    }

    Matrix Matrix::operator--(int)
    {
        Matrix temp = *this;
        for (size_t i = 0; i < _size; ++i)
        {
            --this->_mat[i];
        }
        return temp;
    }

    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        valid_size_matrix(mat, 1);

        for (size_t i = 0; i < _size; ++i)
        {
            _mat[i] += mat._mat[i];
        }
        return *this;
    }

    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        valid_size_matrix(mat, 1);
        for (size_t i = 0; i < _size; ++i)
        {
            _mat[i] -= mat._mat[i];
        }
        return *this;
    }

    Matrix &Matrix::operator*=(const Matrix &mat)
    {

        valid_size_matrix(mat, 2);
        *this = *this * mat;
        return *this;
    }

    Matrix &Matrix::operator*=(double num)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_mat[i] == 0)
            {
                continue;
            }
            _mat[i] *= num;
        }
        return *this;
    }

    bool Matrix::operator==(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);

        for (size_t i = 0; i < _size; ++i)
        {
            if (_mat[i] != mat._mat[i])
            {
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator!=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        for (size_t i = 0; i < _size; ++i)
        {
            if (_mat[i] != mat._mat[i])
            {
                return true;
            }
        }
        return false;
    }

    bool Matrix::operator>=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        return mat.Matrix_sum() <= this->Matrix_sum();
    }

    bool Matrix::operator<=(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        return mat.Matrix_sum() >= this->Matrix_sum();
    }

    bool Matrix::operator<(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        return mat.Matrix_sum() > this->Matrix_sum();
    }

    bool Matrix::operator>(const Matrix &mat) const
    {
        valid_size_matrix(mat, 1);
        return mat.Matrix_sum() < this->Matrix_sum();
    }

    Matrix operator*(int num, Matrix mat)
    {
        vector<double> temp((size_t)(mat._size));
        for (size_t i = 0; i < mat._size; ++i)
        {
            temp[i] = mat._mat[i] * num;
        }
        return Matrix(temp, mat._row, mat._col);
    }

    int count_row(string str, char to_count)
    {
        int count = 0;

        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == to_count)
            {
                ++count;
            }
        }

        return count;
    }
    void valid_input(string str)
    {
        bool flag = false;
        for (size_t i = 0; i < str.length(); ++i)
        {
            if ((str[i] == ']' && !flag) || (str[i] == '[' && flag))
            {
                throw invalid_argument("invalid input ");
            }
            if (str[i] == ']' && flag)
            {
                flag = false;
            }
            if (str[i] == '[')
            {
                flag = true;
            }
            if ((str[i] == ',' && str[i - 1] != ']') ||
                (str[i] == ',' && str[i + 1] != ' '))
            {
                throw invalid_argument("invalid input ");
            }
        }
    }
    istream &operator>>(std::istream &in, Matrix &mat)
    {
        string str;
        getline(in, str);
        valid_input(str);
        int row = count_row(str, ',') + 1;
        std::vector<double> mat_v;
        for (size_t i = 0, j = 0; i < str.length(); j = ++i)
        {
            while (isdigit(str[i]) != 0)
            {
                ++i;
            }
            if (i != j)
            {
                mat_v.push_back(std::stod(str.substr(j, i - j)));
            }
        }
        mat = Matrix(mat_v, row, int(mat_v.size()) / row);
        return in;
    }

    ostream &operator<<(std::ostream &out, const Matrix &mat)
    {
        int count = 0;
        for (size_t i = 0; i < mat._size; ++i)
        {
            if (count == 0)
            {
                out << "[";
            }
            out << mat._mat[i];
            out << ((count != mat._col - 1) ? " " : (i != mat._size - 1) ? "]\n"
                                                                         : "]");
            count = count == mat._col - 1 ? 0 : ++count;
        }
        return out;
    }

}