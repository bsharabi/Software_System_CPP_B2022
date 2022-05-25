/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#define RESET "\033[0m"
#define BLACK "\033[30m"            /* Black */
#define RED "\033[31m"              /* Red */
#define GREEN "\033[32m"            /* Green */
#define YELLOW "\033[1;33m"         /* Yellow */
#define BLUE "\033[34m"             /* Blue */
#define MAGENTA "\033[35m"          /* Magenta */
#define CYAN "\033[36m"             /* Cyan */
#define WHITE "\033[37m"            /* White */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main()
{
  OrgChart organization;
  organization.add_root("CEO")
      .add_sub("CEO", "CTO")
      .add_sub("CEO", "CFO")
      .add_sub("CEO", "COO")
      .add_sub("CTO", "VP_SW")
      .add_sub("COO", "VP_BI");

  char ch = 'S';
  string name1, name2;
  do
  {
    switch (ch)
    {
    case 'A':
      cout << YELLOW << "Enter Name" << RESET << endl;
      cin >> name1;
      try
      {
        organization.add_root(name1);
        cout << "The employee was successfully added";
      }
      catch (...)
      {
        cout << "Invalid name";
      }
      break;
    case 'B':
      cout << YELLOW << "Enter Parent Name" << RESET << endl;
      cin >> name1;
      cout << YELLOW << "Enter Employee Name" << RESET << endl;
      cin >> name2;
      try
      {
        organization.add_sub(name1, name2);
        cout << "The employee was successfully added";
      }
      catch (...)
      {
        cout << "Invalid name";
      }
      break;
    case 'C':
      system("clear");
      break;
    case 'S':
      cout << organization << endl;
      break;
    case 'L':
      cout << "------------------ Level Order -----------------------" << endl;
      cout << GREEN;
      for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
      {
        cout << (*it) << " ";
      }
      cout << RESET;
      break;
    case 'R':
      cout << "------------------- Reverse Level Order -----------------" << endl;
      cout << BLUE;
      for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
      {
        cout << (*it) << " ";
      }
      cout << RESET;
      break;
    case 'P':
      cout << "---------------------- Pre Order --------------------" << endl;
      cout << RED;
      for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
      {
        cout << (*it) << " ";
      }
      cout << RESET;
      break;
    case 'N':
      cout << "Numbers Employees " << organization.getNumberEmployee();
      break;
    default:
      cout << "Wrong choice";
      break;
    }
    cout << endl;
    cout << CYAN << "---------------------- Menu --------------------------" << RESET << endl;
    cout << YELLOW;
    cout << "A - add/change root Employee" << endl;
    cout << "B - add sub Employee" << endl;
    cout << "C - Clean screen" << endl;
    cout << "S - Show organization" << endl;
    cout << "L - Show level-order" << endl;
    cout << "R - Show reverse-level-order" << endl;
    cout << "P - Show Pre-order" << endl;
    cout << "N - Show Number's Employee" << endl;
    cout << "E - Exit" << RESET << endl;
    cin >> ch;
  } while (ch != 'E');
  cout << "Good bay";
}