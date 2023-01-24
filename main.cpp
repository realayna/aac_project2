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

    BST t;
    auto begin_i = steady_clock::now();
    t.BInsert("dog");
    t.BInsert("cat");
    t.BInsert("bird");
    t.BInsert("aardvark");
    t.BInsert("zebra");
    t.BInsert("human");
    t.BInsert("crocodile");
    t.BInsert("ayna");
    t.BInsert("meow");
    auto end_i = steady_clock::now();
    std::cout << "BST created successfully" << std::endl;
    i = end_i - begin_i;

    std::string value = "nnn";
    BNode *result = t.BSearch(value);

    if (result != nullptr)
    {
        std::cout << value << " was found in the tree." << std::endl;
    }
    else
    {
        std::cout << value << " was not found in the tree." << std::endl;
    }

    AVL ss;
    auto begin_m = steady_clock::now();

    ss.AVLInsert("hippo");
    ss.AVLInsert("kokko");
    ss.AVLInsert("shoko");
    ss.AVLInsert("podoso");
    ss.AVLInsert("mokoko");
    ss.AVLInsert("lion");
    ss.AVLInsert("popopo");
    auto end_m = steady_clock::now();
    m = end_m - begin_m;
    std::string calue = "hippo";

    Node *mesult = ss.ASearch(calue);
    if (mesult != nullptr)
    {
        std::cout << calue << " was found in the tree." << std::endl;
    }
    else
    {
        std::cout << calue << " was not found in the tree." << std::endl;
    }

    std::cout << "insert_bst insert_avl\n";
    std::cout << i.count() << " " << m.count() << std::endl;

    return 0;
}