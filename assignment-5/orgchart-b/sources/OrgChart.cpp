#include "OrgChart.hpp"

using namespace ariel;
namespace ariel
{

    OrgChart::OrgChart() : root(nullptr), numberEmployee(0) {}

    OrgChart OrgChart::add_root(const string &name)
    {
        if (name.empty())
        {
            throw invalid_argument("empty string");
        }
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
        if (parent.empty() || child.empty())
        {
            throw invalid_argument("empty string");
        }

        if (root == nullptr)
        {
            throw invalid_argument("Error: No root exists, new employee can not be inserted");
        }

        int checkAdd = numberEmployee;
        add_child(root, parent, child);
        if (checkAdd == numberEmployee)
        {
            throw invalid_argument("employer doesn't exist");
        }

        return *this;
    }
    OrgChart::Iterator OrgChart::begin_level_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::levelOrder, root};
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::levelOrder, nullptr};
    }
    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::ReverseLevelOrder, root};
    }
    OrgChart::Iterator OrgChart::reverse_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::ReverseLevelOrder, nullptr};
    }
    OrgChart::Iterator OrgChart::begin_preorder()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::preOrder, root};
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::preOrder, nullptr};
    }
    OrgChart::Iterator OrgChart::begin()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::levelOrder, root};
    }
    OrgChart::Iterator OrgChart::end()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{Mode::levelOrder, nullptr};
    }
    OrgChart::Node &OrgChart::getRoot()
    {
        return *root;
    }
    int OrgChart::getNumberEmployee() const
    {
        return numberEmployee;
    }
    void OrgChart::add_child(Node *root, const string &parent, const string &child)
    {

        if (root->_name == parent)
        {

            Node *node = new Node(child, root->level_employee + 1);
            root->childs.push_back(node);
            numberEmployee++;
        }
        else
        {
            int l = root->childs.size();
            for (unsigned int i = 0; i < l; i++)
            {
                add_child(root->childs[i], parent, child);
            }
        }
    }
    void OrgChart::freeOrgChart(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (!root->childs.empty())
        {
            unsigned int childsNumber = root->childs.size();
            for (unsigned int child = 0; child < childsNumber; child++)
            {
                freeOrgChart(root->childs[child]);
            }
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
