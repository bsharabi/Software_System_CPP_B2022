#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace zich;
using namespace std;

TEST_CASE("Good inputs")
{
    SUBCASE("Operator check not throw")
    {
        vector<double> a = {2, 2, 2, 1, 1, 1, 3, 3, 3};
        Matrix mat1(a, 3, 3);
        vector<double> b = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        Matrix mat2(b, 3, 3);
        bool ans;
        CHECK_NOTHROW(mat1 + mat2);
        CHECK_NOTHROW(mat1 - mat2);
        CHECK_NOTHROW(mat1 * mat2);
        CHECK_NOTHROW(mat1 += mat2);
        CHECK_NOTHROW(mat1 -= mat2);
        CHECK_NOTHROW(mat1 *= mat2);
        CHECK_NOTHROW(ans = mat1 == mat2);
        CHECK_NOTHROW(ans = mat1 != mat2);
        CHECK_NOTHROW(ans = mat1 > mat2);
        CHECK_NOTHROW(ans = mat1 < mat2);
        CHECK_NOTHROW(ans = mat1 <= mat2);
        CHECK_NOTHROW(ans = mat1 >= mat2);
    }

    SUBCASE("Operators correc")
    {
        vector<double> a = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        Matrix mat1(a, 3, 3);
        vector<double> b = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        Matrix mat2(b, 3, 3);

        CHECK(mat1 >= mat2);
        CHECK(mat2 <= mat1);
        CHECK(mat1 != mat2);
        CHECK(mat1 == ++mat2);
        CHECK(mat1++ != mat2);
        mat1 *= 3;
        mat2 *= 3;
        CHECK(mat1 == mat2);
        CHECK(mat1 * 3 == 3 * mat2);
        CHECK(mat1 + mat2 == mat2 + mat1);
        CHECK(mat1 - mat2 == mat2 - mat1);
    }
}

TEST_CASE("Bad inputs")
{
    SUBCASE("invalid Matrix size")
    {
        vector<double> a = {2, 2, 2, 1, 1, 1, 3, 3, 3};
        Matrix mat1(a, 3, 3);
        vector<double> b = {2, 2, 2, 1, 1, 1, 3, 3, 3, 4, 4, 4};
        Matrix mat2(b, 4, 3);
        bool ans;
        CHECK_THROWS(mat1 + mat2);
        CHECK_THROWS(mat1 += mat2);
        CHECK_THROWS(mat1 -= mat2);
        CHECK_THROWS(mat1 * mat2);
        CHECK_THROWS(ans = mat1 <= mat2);
        CHECK_THROWS(ans = mat1 < mat2);
        CHECK_THROWS(ans = mat1 == mat2);
        CHECK_THROWS(mat1 - mat2);
        CHECK_THROWS(ans = mat1 != mat2);
        CHECK_THROWS(ans = mat1 > mat2);
        CHECK_THROWS(ans = mat1 >= mat2);
        CHECK_THROWS(mat1 *= mat2);
    }
}
