#pragma once
#include <iostream>
#include <stack>
struct BNode
{
    std::string data;
    BNode *left;
    BNode *right;
};
struct Node
{
    std::string data;
    int height;
    Node *left;
    Node *right;
};
class BST
{
public:
    BNode *root;
    BST()
    {
        root = nullptr;
    }

    void BInsert(std::string data)
    {
        BNode *nn = new BNode;
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        // nn->height = 1;

        if (root == nullptr)
        {
            root = nn;
            return;
        }

        BNode *now = root;
        BNode *parent = nullptr;

        while (now != nullptr)
        {
            parent = now;

            if (data < now->data)
            {
                now = now->left;
            }

            else if (data > now->data)
            {
                now = now->right;
            }
            else
            {

                return;
            }
        }
        if (data < parent->data)
        {
            parent->left = nn;
        }
        else
        {
            parent->right = nn;
        }
        // parent->height = max(height(parent->left), height(parent->right)) + 1;
    }
    // int height(BNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return 0;
    //     }
    //     return root->height;
    // }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    BNode *BSearch(std::string data)
    {
        BNode *now = root;
        while (now != nullptr)
        {
            if (now->data == data)
            {
                return now;
            }
            else if (data < now->data)
            {
                now = now->left;
            }
            else
            {
                now = now->right;
            }
        }
        return nullptr;
    }
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = nullptr;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int height(Node *m)
    {
        if (m == nullptr)
            return 0;
        return m->height;
    }
    int chBalance(Node *n)
    {
        if (n == nullptr)
            return 0;
        return height(n->left) - height(n->right);
    }
    Node *AVLInsert(std::string data)
    {
        Node *nn = new Node;
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        nn->height = 1;

        if (root == nullptr)
        {
            root = nn;
            return root;
        }

        Node *now = root;
        Node *parent = nullptr;

        std::stack<Node *> st;
        while (now != nullptr)
        {

            st.push(now);

            parent = now;
            if (data < now->data)
            {
                now = now->left;
            }
            else if (data > now->data)
            {
                now = now->right;
            }
            else
            {

                return root;
            }
        }

        if (data < parent->data)
        {
            parent->left = nn;
        }
        else
        {
            parent->right = nn;
        }

        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            temp->height = max(height(temp->left), height(temp->right)) + 1;
            int balance = chBalance(temp);

            if (balance > 1 && data < temp->left->data)
            {
                Node *new_root = RRotate(temp);
                if (st.empty())
                {
                    root = new_root;
                }
                else
                {
                    Node *parent = st.top();
                    if (parent->left == temp)
                        parent->left = new_root;
                    else
                        parent->right = new_root;
                }
                temp = new_root;
            }
            if (balance < -1 && data > temp->right->data)
            {
                Node *new_root = LRotate(temp);
                if (st.empty())
                {
                    root = new_root;
                }
                else
                {
                    Node *parent = st.top();
                    if (parent->left == temp)
                        parent->left = new_root;
                    else
                        parent->right = new_root;
                }
                temp = new_root;
            }

            if (balance > 1 && data > temp->left->data)
            {
                Node *new_root = LRotate(temp->left);
                temp->left = new_root;
                new_root = RRotate(temp);
                if (st.empty())
                {
                    root = new_root;
                }
                else
                {
                    Node *parent = st.top();
                    if (parent->left == temp)
                        parent->left = new_root;
                    else
                        parent->right = new_root;
                }
                temp = new_root;
            }
            if (balance < -1 && data < temp->right->data)
            {
                Node *new_root = RRotate(temp->right);
                temp->right = new_root;
                new_root = LRotate(temp);
                if (st.empty())
                {
                    root = new_root;
                }
                else
                {
                    Node *parent = st.top();
                    if (parent->left == temp)
                        parent->left = new_root;
                    else
                        parent->right = new_root;
                }
                temp = new_root;
            }
        }

      //  parent->height = max(height(parent->left), height(parent->right)) + 1;
        int balance = chBalance(parent);
        if (balance > 1 && data < st.top()->left->data)
        {
            Node *new_root = RRotate(st.top());
            if (st.empty())
            {
                root = new_root;
            }
            else
            {
                Node *parent = st.top();
                if (parent->left == st.top())
                    parent->left = new_root;
                else
                    parent->right = new_root;
            }
            return new_root;
        }
        if (balance < -1 && data > st.top()->right->data)
        {
            Node *new_root = LRotate(st.top());
            if (st.empty())
            {
                root = new_root;
            }
            else
            {
                Node *parent = st.top();
                if (parent->left == st.top())
                    parent->left = new_root;
                else
                    parent->right = new_root;
            }
            return new_root;
        }
        if (balance > 1 && data > st.top()->left->data)
        {
            Node *new_root = LRotate(st.top()->left);
            st.top()->left = new_root;
            new_root = RRotate(st.top());
            if (st.empty())
            {
                root = new_root;
            }
            else
            {
                Node *parent = st.top();
                if (parent->left == st.top())
                    parent->left = new_root;
                else
                    parent->right = new_root;
            }
            return new_root;
        }
        if (balance < -1 && data < st.top()->right->data)
        {
            Node *new_root = RRotate(st.top()->right);
            st.top()->right = new_root;
            new_root = LRotate(st.top());
            if (st.empty())
            {
                root = new_root;
            }
            else
            {
                Node *parent = st.top();
                if (parent->left == st.top())
                    parent->left = new_root;
                else
                    parent->right = new_root;
            }
            return new_root;
        }
        return root;
    }

    Node *RRotate(Node *m)
    {
        Node *l = m->left;
        Node *t = l->right;
        l->right = m;
        m->left = t;

        m->height = max(height(m->left), height(m->right)) + 1;
        l->height = max(height(l->left), height(l->right)) + 1;
        return l;
    }
    Node *LRotate(Node *m)
    {
        Node *l = m->right;
        Node *t = l->left;
        l->left = m;
        m->right = t;
        m->height = max(height(m->left), height(m->right)) + 1;
        l->height = max(height(l->left), height(l->right)) + 1;
        return l;
    }
};
