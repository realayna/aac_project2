#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include "tree.h"

using std::chrono::nanoseconds;
using std::chrono::steady_clock;

std::string randomString(std::string characters, int length)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.length() - 1);
    std::string randomString = "";
    for (int i = 0; i < length; i++)
    {
        randomString += characters[distribution(generator)];
    }
    return randomString;
}

int main()
{
    constexpr int max_size = 1000;
    constexpr int step = 1;
    constexpr int times = 1;
    nanoseconds i(0);
    nanoseconds m(0);
    nanoseconds k(0);
    nanoseconds b(0);
    nanoseconds s(0);
    nanoseconds q(0);
    BST as;
    AVL ks;
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::cout<<"binsert ainsert bsearch asearch"<<std::endl;
    for (auto i = step; i < max_size; i += step)
    {

        std::string kalue = randomString(str, i);
        auto k_b = steady_clock::now();
        as.BInsert(kalue);
        auto k_e = steady_clock::now();
        k += k_e - k_b;

        std::string jalue = randomString(str, i);
        auto b_b = steady_clock::now();
        ks.AVLInsert(jalue);
        auto b_e = steady_clock::now();
        b += b_e - b_b;

        auto q_b = steady_clock::now();
        as.BSearch(kalue);
        auto q_e = steady_clock::now();
        q += q_e - q_b;
        
       // std::string jalue = randomString(str, i);
        auto s_b = steady_clock::now();
        ks.ASearch(jalue);
        auto s_e = steady_clock::now();
        s += s_e - s_b;



    


        std::cout << i << " " << k.count() / times << " " << 
        b.count() / times << " "<< q.count()/times <<" "<< s.count()/times<< std::endl;
    }

    // BST t;
    // auto begin_i = steady_clock::now();
    // t.BInsert("dog");
    // t.BInsert("cat");
    // t.BInsert("bird");
    // t.BInsert("aardvark");
    // t.BInsert("zebra");
    // t.BInsert("human");
    // t.BInsert("crocodile");
    // t.BInsert("ayna");
    // t.BInsert("meow");
    // t.BInsert("sss");
    // t.BInsert("meqqqow");
    // t.BInsert("aa");
    // auto end_i = steady_clock::now();
    // std::cout << "BST created successfully" << std::endl;
    // i = end_i - begin_i;

    // std::string value = "sss";
    // BNode *result = t.BSearch(value);

    // if (result != nullptr)
    // {
    //     std::cout << value << " was found in the tree." << std::endl;
    // }
    // else
    // {
    //     std::cout << value << " was not found in the tree." << std::endl;
    // }

    // AVL ss;
    // auto begin_m = steady_clock::now();

    // ss.AVLInsert("hippo");
    // ss.AVLInsert("kokko");
    // ss.AVLInsert("shoko");
    // ss.AVLInsert("podoso");
    // ss.AVLInsert("mokoko");
    // ss.AVLInsert("lion");
    // ss.AVLInsert("popopo");
    // ss.AVLInsert("ppo");
    // ss.AVLInsert("a");
    // ss.AVLInsert("b");
    // ss.AVLInsert("c");
    // auto end_m = steady_clock::now();
    // m = end_m - begin_m;
    // std::string calue = "hippo";

    // Node *mesult = ss.ASearch(calue);
    // if (mesult != nullptr)
    // {
    //     std::cout << calue << " was found in the tree." << std::endl;
    // }
    // else
    // {
    //     std::cout << calue << " was not found in the tree." << std::endl;
    // }

    // std::cout << "insert_bst insert_avl\n";
    //   std::cout << i.count() << " " << m.count() << " " << k.count() / 1000 << std::endl;

    return 0;
}