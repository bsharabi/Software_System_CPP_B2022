#include "OrgChart.hpp"

using namespace ariel;
namespace ariel
{

    OrgChart::OrgChart() : root(nullptr), numberEmployee(0), _cur(nullptr) {}
    OrgChart::~OrgChart()
    {
        freeOrgChart();
    }
    OrgChart &OrgChart::add_root(const string &name)
    {
        if (validName(name))
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
    OrgChart &OrgChart::add_sub(const string &parent, const string &child)
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
        _cur = root;
        order.clear();
        levelOrder();
        return Iterator{&order};
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{nullptr};
    }
    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        _cur = root;
        order.clear();
        ReverseLevelOrder();
        return Iterator{&order};
    }
    OrgChart::Iterator OrgChart::reverse_order()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{nullptr};
    }
    OrgChart::Iterator OrgChart::begin_preorder()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        _cur = root;
        order.clear();
        preOrder();
        return Iterator{&order};
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{nullptr};
    }
    OrgChart::Iterator OrgChart::begin()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        _cur = root;
        order.clear();
        levelOrder();
        return Iterator{&order};
    }
    OrgChart::Iterator OrgChart::end()
    {
        if (root == nullptr)
        {
            throw invalid_argument("chart is empty!");
        }
        return Iterator{nullptr};
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
            return;
        }

        int l = root->childs.size();
        for (unsigned int i = 0; i < l; i++)
        {
            add_child(root->childs[i], parent, child);
        }
    }
    void OrgChart::freeOrgChart()
    {

        if (root != nullptr)
        {
            queue<Node *> q;
            q.push(root);
            while (!q.empty())
            {
                _cur = q.front();
                q.pop();
                order.push_back(_cur);
                for (Node *p : _cur->childs)
                {
                    q.push(p);
                }
            }
            for (Node *node : order)
            {
                // cout << "\ndelete " << node->_name << endl;
                delete node;
            }
        }
    }
    std::ostream &operator<<(ostream &out, const OrgChart &p1)
    {
        p1.root->printTree(out);
        return out;
    }
    void OrgChart::levelOrder()
    {

        queue<Node *> q;
        q.push(_cur);
        while (!q.empty())
        {
            _cur = q.front();
            q.pop();
            order.push_back(_cur);
            for (Node *p : _cur->childs)
            {
                q.push(p);
            }
        }
    }
    void OrgChart::preOrder()
    {
        stack<Node *> Stack;
        Stack.push(_cur);
        while (!Stack.empty())
        {
            _cur = Stack.top();
            Stack.pop();
            order.push_back(_cur);

            for (unsigned int i = _cur->childs.size(); i > 0; i--)
            {
                Stack.push(_cur->childs[i - 1]);
            }
        }
    }
    void OrgChart::ReverseLevelOrder()
    {
        map<int, vector<Node *>> orgMap;
        queue<Node *> q;
        q.push(_cur);
        while (!q.empty())
        {
            _cur = q.front();
            q.pop();
            orgMap[_cur->level_employee].push_back(_cur);
            for (auto *p : _cur->childs)
            {
                q.push(p);
            }
        }

        for (size_t index = orgMap.size(); index > 0; index--)
        {
            for (auto *node : orgMap[index - 1])
            {
                order.push_back(node);
            }
        }
    }
    
}
