#include "OrgChart.hpp"

using namespace ariel;
namespace ariel
{

    OrgChart::OrgChart() : root(nullptr), numberEmployee(0)
    {
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
            add_child(root, parent, child);
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
    void OrgChart::add_child(Node *root, string parent, string child)
    {

        if (root->_name == parent)
        {

            Node *node = new Node(child, root->level_employee + 1);
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
                    add_child(root->childs[i], parent, child);
                else
                    add_child(root->childs[i], parent, child);
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
        p1.root->printTree(out);
        return out;
    }
}
