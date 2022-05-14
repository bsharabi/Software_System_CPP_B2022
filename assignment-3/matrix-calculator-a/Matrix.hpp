#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        int _row;
        int _col;
        int _size;
        vector<double> _mat;

    public:
        /**
         * Constructor.
         *
         * @param mat The Vector expressing the matrix
         * @param row The Number of row
         * @param column The Number of columns
         * @return None.
         */
        Matrix(const vector<double> &mat, int row, int col);

        /**
         * operator + overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix operator+(const Matrix &mat) const;

        /**
         * operator - overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix operator-(const Matrix &mat) const;
        /**
         * operator * overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix operator*(const Matrix &mat) const;

        /**
         * operator * overloading.
         *
         * @param num The number we want to double the matrix
         * @return new Matrix.
         */
        Matrix operator*(double num) const;

        /**
         * operator - overloading.
         * - unary
         * @return new Matrix.
         */
        Matrix operator-();

        /**
         * operator + overloading.
         * + unary
         * @return new Matrix.
         */
        Matrix operator+();

        /**
         * operator ++ overloading.
         * ++increment
         * @return new Matrix.
         */
        Matrix &operator++();
        /**
         * operator ++ overloading.
         * increment++
         * @return new Matrix.
         */
        Matrix operator++(int);
        /**
         * operator ++ overloading.
         * --Decrement
         * @return new Matrix.
         */
        Matrix &operator--();
        /**
         * operator ++ overloading.
         * Decrement--
         * @return new Matrix.
         */
        Matrix operator--(int);
        /**
         * operator += overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix &operator+=(const Matrix &mat);
        /**
         * operator -= overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix &operator-=(const Matrix &mat);
        /**
         * operator *= overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        Matrix &operator*=(const Matrix &mat);
        /**
         * operator *= overloading.
         *
         * @param num The number we want to double the matrix
         * @return new Matrix.
         */
        Matrix &operator*=(double num);
        /**
         * operator == overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator==(const Matrix &mat) const;
        /**
         * operator != overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator!=(const Matrix &mat) const;
        /**
         * operator >= overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator>=(const Matrix &mat) const;
        /**
         * operator <= overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator<=(const Matrix &mat) const;
        /**
         * operator < overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator<(const Matrix &mat) const;
        /**
         * operator > overloading.
         *
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        bool operator>(const Matrix &mat) const;
        /**
         * operator * overloading.
         *
         * example:
         * let a a matrix
         * 3*a
         * @param mat The Vector expressing the matrix
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        friend Matrix operator*(int num, Matrix mat);
        /**
         * operator * overloading.
         *
         * @param in
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        friend std::istream &operator>>(std::istream &in, Matrix &mat);
        /**
         * operator * overloading.
         *
         * @param out
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);

        /**
         * A function that checks the integrity of the input
         *
         * @param mat The Vector expressing the matrix
         * @param row The Number of row
         * @param col The Number of columns
         * @return True If all the integrity tests are correct else throw error .
         */
        bool valid_argument(int row, int col, vector<double> mat)
        {

            _size = row * col;
            if (col < 1 || row < 1 || mat.size() != _size)
            {
                throw invalid_argument("matrix size must be grater then 0");
            }
            return true;
        }

        /**
         * A function is responsible for checking the integrity of the matrix dimension
         *
         * @param mat The Vector expressing the matrix
         * @param mode Number representing the operations Account 1 for (+,-,==,!=, <=...) 2 to (*)
        
         * @return True If all the integrity tests are correct else throw error .
         */
        bool valid_size_matrix(Matrix mat, int mode) const
        {
            switch (mode)
            {
            case 1:

                if (mat._col != _col || mat._row != _row)
                {
                    throw invalid_argument("invalid matrix size for operator +");
                }
                break;
            case 2:
                if (_col != mat._row)
                {
                    throw invalid_argument("invalid matrix size for operator *");
                }
                break;
            }
            return true;
        }
    };

}