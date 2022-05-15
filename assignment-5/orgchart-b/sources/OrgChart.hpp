#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <map>
#include <list>

#include <stack>
#include <queue>

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

        private:
            void printSubtree(const std::string &prefix, std::ostream &out)
            {
                if (childs.empty())
                    return;
                out << prefix;
                size_t n_children = childs.size();
                out << "\033[1;31m" << (n_children > 1 ? "├── " : "") << "\033[0m";

                for (size_t i = 0; i < n_children; ++i)
                {
                    Node *c = childs[i];
                    if (i < n_children - 1)
                    {
                        if (i > 0)
                        {
                            out << prefix << "\033[1;31m"
                                << "├── "
                                << "\033[0m";
                        }
                        bool printStrand = n_children > 1 && !c->childs.empty();
                        string newPrefix = prefix + (printStrand ? "\033[1;31m│\033[0m\t" : "\t");
                        out << "\033[1;33m" << c->_name << "\033[0m"
                            << "\n";
                        c->printSubtree(newPrefix, out);
                    }
                    else
                    {
                        out << (n_children > 1 ? prefix : "") << "\033[1;31m"
                            << "└── "
                            << "\033[0m";
                        out << "\033[1;33m" << c->_name << "\033[0m"
                            << "\n";
                        c->printSubtree(prefix + "\t", out);
                    }
                }
            }

        public:
            void printTree(std::ostream &out)
            {
                out << "\033[0;32m" << _name << "\033[0m"
                    << "\n";
                printSubtree("", out);
                out << "\033[0m";
            }
        };
        /**
         * Private preorder_iterator class.
         * @return None.
         */
        class preorder_iterator
        {
        private:
            Node *_cur;
            std::list<Node *> nodeList;

        public:
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param ptr Pointer to any node of an employee in the organization of type Node
             * @return None.
             */
            preorder_iterator(Node *ptr = nullptr, map<int, vector<Node *>> *orgMap = nullptr)
            {
                if (ptr != nullptr)
                {

                    orgMap->clear();
                    stack<Node *> Stack;
                    Stack.push(ptr);
                    while (!Stack.empty())
                    {
                        _cur = Stack.top();
                        Stack.pop();
                        nodeList.push_back(_cur);
                        (*orgMap)[_cur->level_employee].push_back(_cur);
                        for (unsigned int i = _cur->childs.size(); i > 0; i--)
                        {
                            Stack.push(_cur->childs[i - 1]);
                        }
                    }
                    _cur = nodeList.front();
                    nodeList.pop_front();
                }
                else
                {
                    _cur = nullptr;
                }
            }
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
            preorder_iterator &operator++()
            {
                if (!nodeList.empty())
                {
                    _cur = nodeList.front();
                    nodeList.pop_front();
                }
                else
                {
                    _cur = nullptr;
                }
                return *this;
            }

            /**
             * Overloading ++operator
             * @return iterator.
             */
            preorder_iterator operator++(int)
            {
                preorder_iterator tmp = *this;
                return tmp;
            }
            /**
             * Overloading operator==
             * @return bool .
             */
            bool operator==(const preorder_iterator &rhs) const
            {
                return _cur == rhs._cur;
            }
            /**
             * Overloading operator!=
             * @return bool .
             */
            bool operator!=(const preorder_iterator &rhs) const
            {
                return _cur != rhs._cur;
            }
        };
        /**
         * Private levelorder_iterator class.
         * @return None.
         */
        class levelorder_iterator
        {
        private:
            Node *_cur;
            std::queue<Node *> nodeQueue;

        public:
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param ptr Pointer to any node of an employee in the organization of type Node
             * @return None.
             */
            levelorder_iterator(Node *ptr = nullptr, map<int, vector<Node *>> *orgMap = nullptr)
            {

                if (ptr != nullptr)
                {
                    orgMap->clear();
                    queue<Node *> q;
                    q.push(ptr);
                    while (!q.empty())
                    {
                        _cur = q.front();
                        q.pop();
                        nodeQueue.push(_cur);
                        (*orgMap)[_cur->level_employee].push_back(_cur);
                        for (Node *p : _cur->childs)
                        {
                            q.push(p);
                        }
                    }
                    _cur = nodeQueue.front();
                    nodeQueue.pop();
                }
                else
                {
                    _cur = nullptr;
                }
            }
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
                return &_cur->_name;
                ;
            }
            /**
             * Overloading operator++
             * @return iterator.
             */
            levelorder_iterator &operator++()
            {

                if (!nodeQueue.empty())
                {
                    _cur = nodeQueue.front();
                    nodeQueue.pop();
                }
                else
                {
                    _cur = nullptr;
                }
                return *this;
            }

            /**
             * Overloading ++operator
             * @return iterator.
             */
            levelorder_iterator operator++(int)
            {
                levelorder_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            /**
             * Overloading operator==
             * @return bool .
             */
            bool operator==(const levelorder_iterator &rhs) const
            {
                return _cur == rhs._cur;
            }
            /**
             * Overloading operator!=
             * @return bool .
             */
            bool operator!=(const levelorder_iterator &rhs) const
            {
                return _cur != rhs._cur;
            }
        };
        /**
         * Private Reverslevelorder_iterator class.
         * @return None.
         */
        class Reverslevelorder_iterator
        {
        private:
            Node *_cur;
            std::queue<Node *> nodeQueue;

        public:
            // ------------------------------ Constructor --------------------------------------
            /**
             * Constructor.
             * @param ptr Pointer to any node of an employee in the organization of type Node
             * @return None.
             */
            Reverslevelorder_iterator(Node *ptr = nullptr, map<int, vector<Node *>> *orgMap = nullptr)
            {
                if (ptr != nullptr)
                {
                    orgMap->clear();
                    queue<Node *> q;
                    q.push(ptr);
                    while (!q.empty())
                    {
                        _cur = q.front();
                        q.pop();
                        (*orgMap)[_cur->level_employee].push_back(_cur);
                        for (Node *p : _cur->childs)
                        {
                            q.push(p);
                        }
                    }

                    for (int index = orgMap->size() - 1; index >= 0; index--)
                    {
                        for (auto node : (*orgMap)[index])
                        {
                            nodeQueue.push(node);
                        }
                    }

                    _cur = nodeQueue.front();
                    nodeQueue.pop();
                }
                else
                {
                    _cur = nullptr;
                }
            }
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
                return &_cur->_name;
            }
            /**
             * Overloading operator++
             * @return iterator.
             */
            Reverslevelorder_iterator &operator++()
            {
                if (!nodeQueue.empty())
                {
                    _cur = nodeQueue.front();
                    nodeQueue.pop();
                }
                else
                {
                    _cur = nullptr;
                }
                return *this;
            }

            /**
             * Overloading ++operator
             * @return iterator.
             */
            Reverslevelorder_iterator operator++(int)
            {
                Reverslevelorder_iterator tmp = *this;
                return tmp;
            }
            /**
             * Overloading operator==
             * @return bool .
             */
            bool operator==(const Reverslevelorder_iterator &rhs) const
            {
                return _cur == rhs._cur;
            }
            /**
             * Overloading operator!=
             * @return bool .
             */
            bool operator!=(const Reverslevelorder_iterator &rhs) const
            {
                return _cur != rhs._cur;
            }
        };

        Node *root;
        int numberEmployee;
        map<int, vector<Node *>> orgMap;

    public:
        // ----------------------------------- Constuctors --------------------------------
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

        // ----------------------------------- functions ----------------------------------
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
        levelorder_iterator begin_level_order();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element level order..
         * @return Iterator.
         */
        levelorder_iterator end_level_order();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element revers order..
         * @return Iterator.
         */
        Reverslevelorder_iterator begin_reverse_order();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element revers order..
         * @return Iterator.
         */
        Reverslevelorder_iterator reverse_order();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element preorder..
         * @return Iterator.
         */
        preorder_iterator begin_preorder();
        /**
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element preorder..
         * @return Iterator.
         */
        preorder_iterator end_preorder();
        /**
         * Returns a read/write iterator that points to the first
         * element in the %vector. Iteration is done in ordinary
         * element order.
         * @return Iterator.
         */
        levelorder_iterator begin();
        /**
         * Constructor.
         * Returns a read/write iterator that points one past the last
         * element in the %vector. Iteration is done in ordinary
         * element order.
         * @return Iterator.
         */
        levelorder_iterator end();
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
        void add_child(Node *, string, string);
        /**
         * Function responsible for realizing memory allocation allocated during the program
         * @param Node  The root of the organization
         * @return None.
         */
        void freeOrgChart(Node *);
    };
}