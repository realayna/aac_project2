#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include "tree.h"

using std::chrono::nanoseconds;
using std::chrono::steady_clock;

int main()
{
    nanoseconds i(0);
    nanoseconds m(0);

    Tree t;
    auto begin_i = steady_clock::now();
    t.insertBST("dog");
    t.insertBST("cat");
    t.insertBST("bird");
    t.insertBST("aardvark");
    t.insertBST("zebra");
    t.insertBST("human");
    t.insertBST("crocodile");
    auto end_i = steady_clock::now();
    std::cout << "BST created successfully" << std::endl;
    i = end_i - begin_i;

    Tree avl;
    auto b = steady_clock::now();
    t.insertAVL("elephant");
    t.insertAVL("giraffe");
    t.insertAVL("hippopotamus");
    t.insertAVL("iguana");
    t.insertAVL("aligator");
    t.insertAVL("eminem");
    auto g = steady_clock::now();
    m = g - b;

    std::cout << "AVL tree created successfully" << std::endl;
    std::string searchValue = "giraffe";
    Node *result = t.search(searchValue);

    if (result != nullptr)
    {
        std::cout << "Node found: " << result->data << std::endl;
    }
    else
    {
        std::cout << "Node " << result << " not found" << std::endl;
    }
    std::cout << "insert_bst insert_avl\n";
    std::cout << i.count() << " " << m.count() << std::endl;
    return 0;
}