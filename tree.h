#pragma once
#include <iostream>

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
    Node *root;
    BST()
    {
        root = nullptr;
        // root->height=1;
        // root->left=nullptr;
        // root->right=nullptr;
    }

    void BInsert(std::string data)
    {
        Node *nn = new Node;
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        nn->height = 1;

        if (root == nullptr)
        {
            root = nn;
            return;
        }

        Node *now = root;
        Node *parent = nullptr;
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
                std::cout << data << " exists" << std::endl;
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
    }

    Node *BSearch(std::string data)
    {
        Node *now = root;
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
    void AInsert(std::string data)
    {
        Node *nn = new Node;
        nn->data = data;
        nn->left = nullptr;
        nn->right = nullptr;
        nn->height = 1;
    }
};
