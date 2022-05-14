#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <map>

#include <algorithm>
using namespace std;

namespace ariel
{
    /**
     * OrgChart Public class
     *
     * This class represents an organization and allows you to transfer over the organization in all kinds of configurations
     */
    class OrgChart
    {
    private:
        /**
         * Node Private subclass
         *
         * This class is used to store employee data, as well as it keeps the employee's name, level and employees if they exist
         */
        class Node
        {
        public:
            string _name;
            int level_employee;
            vector<Node *> childs;
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param name Employee's name
             * @param level The level of the employee in the organization
             * @return None.
             */
            Node(const string &name, int level)
            {
                _name = name;
                level_employee = level;
            };
        };

        /**
         * Private Iterator class.
         * @return None.
         */
        class Iterator
        {
        private:
            Node *_cur;

        public:
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param ptr Pointer to any node of an employee in the organization of type Node
             * @return None.
             */
            Iterator(Node *ptr = nullptr) : _cur(ptr) {}
            /**
             * Overloading operator*
             * @return string name.
             */
            string &operator*() const { return _cur->_name; }
            /**
             * Overloading operator->
             * @return string name.
             */
            string *operator->() const
            {
                return &(_cur->_name);
            }
            /**
             * Overloading operator++
             * @return iterator.
             */
            Iterator &operator++()
            {
                return *this;
            }

            /**
             * Overloading ++operator
             * @return iterator.
             */
            Iterator operator++(int)
            {
                Iterator tmp = *this;
                return tmp;
            }
            /**
             * Overloading operator==
             * @return bool .
             */
            bool operator==(const Iterator &rhs) const
            {
                return _cur == rhs._cur;
            }
            /**
             * Overloading operator!=
             * @return bool .
             */
            bool operator!=(const Iterator &rhs) const
            {
                return _cur != rhs._cur;
            }
        };
        /**
         * Private Iterator class.
         * @return None.
         */
        class Iterator_Int
        {
        private:
            Node *_cur;

        public:
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param ptr Pointer to any node of an employee in the organization of type Node
             * @return None.
             */
            Iterator_Int(Node *ptr = nullptr) : _cur(ptr) {}
            /**
             * Overloading operator*
             * @return string name.
             */
            int &operator*() const { return _cur->level_employee; }
            /**
             * Overloading operator->
             * @return string name.
             */
            int *operator->() const
            {
                return 0;
            }
            /**
             * Overloading operator++
             * @return iterator.
             */
            Iterator_Int &operator++()
            {
                return *this;
            }

            /**
             * Overloading ++operator
             * @return iterator.
             */
            Iterator_Int operator++(int)
            {
                Iterator_Int tmp = *this;
                return tmp;
            }
            /**
             * Overloading operator==
             * @return bool .
             */
            bool operator==(const Iterator_Int &rhs) const
            {
                return _cur == rhs._cur;
            }
            /**
             * Overloading operator!=
             * @return bool .
             */
            bool operator!=(const Iterator_Int &rhs) const
            {
                return _cur != rhs._cur;
            }
        };
        Node *root;
        int numberEmployee;

    public:
        // ---------------------------- Constuctors --------------------------
        /**
         * Constructor.
         * @return None.
         */
        OrgChart();
        /**
         * Constructor.
         * This constructor is called when the created class object is no longer in use and allows the realization of a memory release allocated during the program
         * @return None.
         */
        // ~OrgChart() {}

        // ----------------------------- functions ---------------------------
        /**
         * A function that allows adding owners to the organization,
         * @param Owners_name Name of the owner of the organization
         * @return OrgChart.
         */
        OrgChart add_root(string const &);
        /**
         * A function that allows adding employees to the organization,
         * @param Manager_name The name of the actor
         * @param Employee_name Type of player
         * @return OrgChart.
         */
        OrgChart add_sub(const string &, const string &);
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element level order..
         * @return Iterator.
         */
        Iterator begin_level_order();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element level order..
         * @return Iterator.
         */
        Iterator end_level_order();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element revers order..
         * @return Iterator.
         */
        Iterator begin_reverse_order();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element revers order..
         * @return Iterator.
         */
        Iterator reverse_order();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element preorder..
         * @return Iterator.
         */
        Iterator end_preorder();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element preorder..
         * @return Iterator.
         */
        Iterator begin_preorder();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element order.
         * @return Iterator.
         */
        Iterator_Int begin();
        /**
         * Constructor.
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element order.
         * @return Iterator.
         */
        Iterator_Int end();
        // ---------------------------------- Overloading ----------------------------------
        /**
         * operator * overloading.
         *
         * @param out
         * @param mat The Vector expressing the matrix
         * @return new Matrix.
         */
        friend std::ostream &operator<<(std::ostream &, const OrgChart &);
        // ------------------------------- Getter && Setter --------------------------------
        /**
         * root getter
         *
         * @return root ref.
         */
        Node &getRoot();
        /**
         * getNumberEmployee
         * @return Number Employee.
         */
        int getNumberEmployee();
        // --------------------------------- Help functions --------------------------------
    private:
        /**
         * A function that allows new employees to be brought into the organization
         * @param Node  The root of the organization
         * @param parent name of Manager
         * @param Node  The new Employee of the organization
         * @return None.
         */
        void add_child(Node *, string, Node *);
        /**
         * Function responsible for realizing memory allocation allocated during the program
         * @param Node  The root of the organization
         * @return None.
         */
        void freeOrgChart(Node *);
    };
}