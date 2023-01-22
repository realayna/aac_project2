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

    std::string value = "ayna";
    Node *result = t.BSearch(value);

    if (result != nullptr)
    {
        std::cout << value << " was found in the tree." << std::endl;
    }
    else
    {
        std::cout << value << " was not found in the tree." << std::endl;
    }
    AVL ss;



    // AVL mm;
    // auto b = steady_clock::now();
    // // t.insertAVL("elephant");
    // // t.insertAVL("giraffe");
    // // t.insertAVL("hippopotamus");
    // // t.insertAVL("iguana");
    // // t.insertAVL("aligator");
    // // t.insertAVL("eminem");
    // //     avl.print(avl.root);
    // auto g = steady_clock::now();
    // m = g - b;'
    //  t.print(t.root);
    //
    // std::cout << "AVL tree created successfully" << std::endl;
    // std::string searchValue = "giraffe";
    // Node *result = t.search(searchValue);

    // if (result != nullptr)
    // {
    //     std::cout << "Node found: " << result->data << std::endl;
    // }
    // else
    // {
    //     std::cout << "Node " << searchValue << " not found" << std::endl;
    // }

    std::cout << "insert_bst insert_avl\n";
    std::cout << i.count() << " " << std::endl;

    return 0;
}