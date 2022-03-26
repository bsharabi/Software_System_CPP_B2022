#pragma once
#include "Direction.hpp"
#include <iostream>
#include <map>
#include <vector>

#include <string>
// typedef unsigned int int;
using namespace std;

namespace ariel
{
    class Notebook
    {

    public:
        // constuctor
        Notebook();

        /**
         * write string to the page.
         *
         * Function responsible for writing on the page
         *
         * @param page The page number we would like to write on.
         * @param row The row number we would like to write on.
         * @param column The column number we would like to write on.
         * @param dir Writing direction (vertical or horizontal).
         * @param str A string of characters that we want to write on the page.
         * @return None.
         */
        void write(int page, int row, int column, ariel::Direction dir, string const &str);

        /**
         * read string from the page.
         *
         * Function responsible for reading from the page.
         *
         * @param page The page number we would like to read on.
         * @param row The row number we would like to read on.
         * @param column The column number we would like to read on.
         * @param dir reading direction (vertical or horizontal).
         * @param length The length of the string we want to read.
         * @return string (The requested string.
         */
        string read(int page, int row, int column, ariel::Direction dir, int length);

        /**
         * erase string from the page.
         *
         * Function responsible for deleting from the page.
         *
         * @param page The page number we would like to delete on.
         * @param row The row number we would like to delete on.
         * @param column The column number we would like to delete on.
         * @param dir deleting direction (vertical or horizontal).
         * @param length The length of the string we want to delete.
         * @return None.
         */
        void erase(int page, int row, int column, ariel::Direction dir, int length);

        /**
         * show page.
         *
         * Function responsible for conveniently displaying the page.
         *
         * @param page The page number we would like to delete on.
         * @return None.
         */
        void show(int page_number);

        // Data structure for storing the notebook
        map<uint, map<uint, string>> notebook;

    private:
        /**
         * checking the integrity of the input.
         *
         * Function responsible for checking the integrity of the input.
         *
         * @param page_number The page number we would like to write on.
         * @param row The row number we would like to write on.
         * @param column The column number we would like to write on.
         * @param dir Writing direction (vertical or horizontal).
         * @param mode Mode Selection (Writing - 0 Reading 1).
         * @param str A string of characters that we want to write on the page by defualt ok.
         * @param length length The length of the string we want to read by default 1.
         * @return True If all the integrity tests are correct else throw error .
         */
        bool validation(int page, int row_number, int col, ariel::Direction dir, int mode, string const &str = "OK", int len = 1)
        {

            /*
            Checking the parameters before use
            The row number, column, and page number should be positive values
            */
            if (row_number < 0 || col < 0 || col > 100 || page < 0 || len < 0)
                throw invalid_argument("Incorrect parameters, can not write in negative locations");

            uint page_number = (uint)page;
            uint row = (uint)row_number;
            uint column = (uint)col;
            uint length = (uint)len;

            // validity read
            if (mode)
            {
                // Check reading input length, not more than 100 columns per line or negative output length
                if ((length > 100 && dir == Direction::Horizontal) || length < 0)
                    throw invalid_argument("String length is invalid");

                // Output deviation from the received column (not more than 100 columns)
                if ((length + column > 100 && dir == Direction::Horizontal))
                    throw invalid_argument("String length is invalid");
            }
            // validity write
            else
            {
                uint length_str = str.length();
                // String length integrity check
                if (length_str == 0)
                    throw invalid_argument("An empty string");
                // Input deviation from the received column (no more than 100 columns)
                if (length_str + (uint)column > 100 && dir == Direction::Horizontal)
                    throw invalid_argument("String length is invalid");
                // Check the input length for deletion
                if (length > 100)
                    throw invalid_argument("String length is invalid");
            }
            // Once all the tests are correct we will want to check if the requested page exists and create if necessary
            if (Notebook::pageExist(page_number))
                Notebook::setPage(page_number);

            return 1;
        }

        /**
         * Create a new line.
         *
         * Function responsible for Create a new line.
         *
         * @param page_number The page number we would like to Create a new line.
         * @param row_number The row number we would like to Create a new line.
         * @return None .
         */
        void setRow(uint page_number, uint row_number)
        {
            string init_row;
            for (uint i = 0; i < 5; i++)
            {
                init_row += "____________________";
            }
            notebook[page_number][row_number] = init_row;
        }

        /**
         * Checking the existence of a line.
         *
         * Function responsible for Checking the existence of a line.
         *
         * @param page_number The page number we would like to check.
         * @param row_number The row number we would like to check.
         * @return True if row does not exist else false .
         */
        bool rowExit(uint page_number, uint row_number)
        {
            return notebook[page_number][row_number].empty();
        }

        /**
         * Returns the requested page from the data structure.
         *
         * Function responsible for Returns the requested page from the data structure.
         *
         * @param page_number The page number we would like to get.
         * @return  map<uint string> if page exist else None .
         */
        map<uint, string> getPage(uint page_number)
        {
            return Notebook::notebook[page_number];
        }

        /**
         * Create a new page.
         *
         * Function responsible for Create a new page.
         *
         * @param page_number The page number we would like to set.
         * @return  None .
         */
        void setPage(uint page_number)
        {
            map<uint, string> new_page;
            Notebook::notebook[page_number] = new_page;
        }

        /**
         * Checking the existence of a page.
         *
         * Function responsible for Checking the existence of a page.
         *
         * @param page_number The page number we would like to check.
         * @return True if page does not exist else false .
         */
        bool pageExist(uint page_number)
        {
            return Notebook::notebook[page_number].empty();
        }
        /**
         * Checking the existence of a page.
         *
         * Function responsible for Checking the existence of a page.
         *
         * @param page_number The page number we would like to create a new line.
         * @param row_number The row number we would like to create a new line.
         * @param count_row The number of rows we want to create.
         * @return None.
         */
        void createMultiLine(uint page_number, uint row_number, uint count_row = 3)
        {
            if (row_number <= 0)
            {
                row_number = 1;
                count_row--;
            }
            for (uint i = row_number - 1; i < row_number + count_row; i++)
            {
                if (Notebook::rowExit(page_number, i))
                    Notebook::setRow(page_number, i);
            }
        }
    };

}