#include "OrgChart.hpp"

using namespace ariel;
namespace ariel
{

    OrgChart::OrgChart() : root(nullptr), numberEmployee(0)
    {
        cout << "Hello constructor" << endl;
    }
    OrgChart OrgChart::add_root(const string &name)
    {
        if (root == nullptr)
        {
            root = new Node(name, 0);
        }
        else
        {
            root->_name = name;
        }
        numberEmployee++;

        return *this;
    }
    OrgChart OrgChart::add_sub(const string &parent, const string &child)
    {
        if (root == nullptr)
        {
            throw invalid_argument("Error: No root exists, new employee can not be inserted");
        }
        else
        {
            Node *temp = new Node(child, 0);
            add_child(root, parent, temp);
        }
        numberEmployee++;
        return *this;
    }
    OrgChart::levelorder_iterator OrgChart::begin_level_order()
    {
        return levelorder_iterator{root, &orgMap};
    }
    OrgChart::levelorder_iterator OrgChart::end_level_order()
    {
        return levelorder_iterator{nullptr, &orgMap};
    }
    OrgChart::Reverslevelorder_iterator OrgChart::begin_reverse_order()
    {
        return Reverslevelorder_iterator{root, &orgMap};
    }
    OrgChart::Reverslevelorder_iterator OrgChart::reverse_order()
    {
        return Reverslevelorder_iterator{nullptr, &orgMap};
    }
    OrgChart::preorder_iterator OrgChart::begin_preorder()
    {
        return preorder_iterator{root, &orgMap};
    }
    OrgChart::preorder_iterator OrgChart::end_preorder()
    {
        return preorder_iterator{nullptr, &orgMap};
    }
    OrgChart::levelorder_iterator OrgChart::begin()
    {
        return levelorder_iterator{root, &orgMap};
    }
    OrgChart::levelorder_iterator OrgChart::end()
    {
        return levelorder_iterator{nullptr, &orgMap};
    }
    OrgChart::Node &OrgChart::getRoot()
    {
        return *root;
    }
    int OrgChart::getNumberEmployee()
    {
        return numberEmployee;
    }
    void OrgChart::add_child(Node *root, string parent, Node *node)
    {

        if (root->_name == parent)
        {
            node->level_employee = root->level_employee + 1;
            for (Node *n : root->childs)
            {
                if (n->_name == node->_name)
                {
                    throw invalid_argument("Employee exist");
                }
            }
            root->childs.push_back(node);
        }
        else
        {
            int l = root->childs.size();
            for (unsigned int i = 0; i < l; i++)
            {
                if (root->childs[i]->_name == parent)
                    add_child(root->childs[i], parent, node);
                else
                    add_child(root->childs[i], parent, node);
            }
        }
    }
    void OrgChart::freeOrgChart(Node *root)
    {
        if (root == nullptr)
            return;
        else if (root->childs.size() != 0)
        {
            unsigned int childsNumber = root->childs.size();
            for (unsigned int child = 0; child < childsNumber; child++)
                freeOrgChart(root->childs[child]);
        }
        cout << "delete " << root->_name << endl;
        delete root;
    }
    std::ostream &operator<<(ostream &out, const OrgChart &p1)
    {
        cout << endl;
        out << p1.root->_name << endl;
        out << "|--------|--------|" << endl;
        out << p1.root->childs[0]->_name << "      " << p1.root->childs[1]->_name << "      " << p1.root->childs[2]->_name << "      " << endl;
        out << "|                 |" << endl;
        out << p1.root->childs[0]->childs[0]->_name << "            " << p1.root->childs[2]->childs[0]->_name << endl;
        return out;
    }
}
