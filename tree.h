#pragma once
#include <iostream>

class Node
{
public:
    std::string data;
    int height;
    Node *left;
    Node *right;

    Node(std::string data)
    {
        this->data = data;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};



class Tree //general class with bst and avl
{
private:
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *m = x->right;
        x->right = y;
        y->left = m;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *m = y->left;
        y->left = x;
        x->right = m;
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;
        return y;
    }
    Node *insert(std::string data, Node *node, bool isAVL = false)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        else if (data < node->data)
        {
            node->left = insert(data, node->left, isAVL);
        }
        else if (data > node->data)
        {
            node->right = insert(data, node->right, isAVL);
        }
        else
        {
            return node;
        }
        if (isAVL)
        {
            node->height = 1 + std::max(height(node->left), height(node->right));
            int balance = getBalance(node);
            if (balance > 1 && data < node->left->data)
            {
                return rightRotate(node);
            }
            if (balance < -1 && data > node->right->data)
            {
                return leftRotate(node);
            }
            if (balance > 1 && data > node->left->data)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if (balance < -1 && data < node->right->data)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }
    Node *search(std::string data, Node *node)
    {
        if (node == nullptr || node->data == data)
        {
            return node;
        }
        else if (data < node->data)
        {
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }

public:
    Node *root;

    Tree()
    {
        this->root = nullptr;
    }

    
    // insert function for BST 
    void insertBST(std::string data)
    {
        this->root = this->insert(data, this->root);
    }
    // insert function for AVL
    void insertAVL(std::string data)
    {
        this->root = this->insert(data, this->root, true); //with bool isAVL=true we're switching to avl insertion
    }
    Node *search(std::string data)
    {
        return search(data, this->root);
    }
};
