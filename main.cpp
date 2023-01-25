#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
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
    constexpr int num_words = 1000;
    constexpr int experiments = 100;
    std::vector<std::string> words;
    nanoseconds im(0);
    nanoseconds mm(0);
    nanoseconds k(0);
    nanoseconds b(0);
    nanoseconds s(0);
    nanoseconds q(0);
    nanoseconds qq(0);
    nanoseconds p(0);
    nanoseconds dd(0);
    nanoseconds kk(0);
    nanoseconds ss(0);
    nanoseconds bb(0);
    std::vector<nanoseconds> r_a_i(1000);
    std::vector<nanoseconds> r_b_i(1000);
    std::vector<nanoseconds> r_a_s(1000);
    std::vector<nanoseconds> r_b_s(1000);
    std::vector<nanoseconds> o_a_i(1000);
    std::vector<nanoseconds> o_b_i(1000);
    std::vector<nanoseconds> o_a_s(1000);
    std::vector<nanoseconds> o_b_s(1000);

    std::vector<nanoseconds> rr_a_i(1000);
    std::vector<nanoseconds> rr_b_i(1000);
    std::vector<nanoseconds> rr_a_s(1000);
    std::vector<nanoseconds> rr_b_s(1000);

    std::vector<nanoseconds> oo_a_i(1000);
    std::vector<nanoseconds> oo_b_i(1000);
    std::vector<nanoseconds> oo_a_s(1000);
    std::vector<nanoseconds> oo_b_s(1000);

    BST as;
    BST as2;
    AVL ks2;
    AVL ks;
    BST ms;
    AVL qs;
    BST ms2;
    AVL qs2;

    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::cout << "elements binsert ainsert bsearch asearch" << std::endl;
    for (auto i = step; i < max_size; i += step)
    {

        std::string kalue = randomString(str, i);
        auto k_b = steady_clock::now();
        as.BInsert(kalue);
        auto k_e = steady_clock::now();
        k += k_e - k_b;
        r_b_i[i] += k;

        std::string jalue = randomString(str, i);
        auto b_b = steady_clock::now();
        ks.AVLInsert(jalue);
        auto b_e = steady_clock::now();
        b += b_e - b_b;
        r_a_i[i] += b;

        auto q_b = steady_clock::now();
        as.BSearch(kalue);
        auto q_e = steady_clock::now();
        q += q_e - q_b;
        r_b_s[i] += q;

        // std::string jalue = randomString(str, i);
        auto s_b = steady_clock::now();
        ks.ASearch(jalue);
        auto s_e = steady_clock::now();
        s += s_e - s_b;
        r_a_s[i] += s;
    }

    // for (int i = 0; i < 1000; i++)
    // {
    //     printf("%i %i %i %i %i\n", i, r_b_i[i], r_a_i[i], r_b_s[i], r_a_s[i]);
    // }

    for (auto t = 0; t < experiments; t++)
    {
        for (auto i = step; i < max_size; i += step)

        {
            std::string kalue = randomString(str, i);
            auto kk_b = steady_clock::now();
            as2.BInsert(kalue);
            auto kk_e = steady_clock::now();
            kk += kk_e - kk_b;
            rr_b_i[i] += kk;

            std::string jalue = randomString(str, i);
            auto bb_b = steady_clock::now();
            ks2.AVLInsert(jalue);
            auto bb_e = steady_clock::now();
            bb += bb_e - bb_b;
            rr_a_i[i] += bb;

            auto qq_b = steady_clock::now();
            as2.BSearch(kalue);
            auto qq_e = steady_clock::now();
            qq += qq_e - qq_b;
            rr_b_s[i] += qq;

            // std::string jalue = randomString(str, i);
            auto ss_b = steady_clock::now();
            ks2.ASearch(jalue);
            auto ss_e = steady_clock::now();
            ss += ss_e - ss_b;
            rr_a_s[i] += ss;
        }
    }

    // for (int i = 0; i < max_size; i++)
    // {
    //     printf("%li %li %li %li %li\n", i, rr_b_i[i].count() / experiments, rr_a_i[i].count() / experiments, rr_b_s[i].count() / experiments, rr_a_s[i].count() / experiments);
    // }

    for (int i = 0; i < num_words; i++)
    {
        std::string word = randomString(str, 5);
        words.push_back(word);
    }

    std::sort(words.begin(), words.end());

//    std::cout << "elements ob_insert oa_insert ob_search oa_search" << std::endl;
    for (auto i = 0; i < words.size(); i++)
    {

        auto v_b = steady_clock::now();
        ms.BInsert(words[i]);
        auto v_e = steady_clock::now();
        im += v_e - v_b;
        o_b_i[i] += im;

        auto l_b = steady_clock::now();
        qs.AVLInsert(words[i]);
        auto l_e = steady_clock::now();
        mm += l_e - l_b;
        o_a_i[i] += mm;

        auto p_b = steady_clock::now();
        ms.BSearch(words[i]);
        auto p_e = steady_clock::now();
        p += p_e - p_b;
        o_b_s[i] += p;

        auto d_b = steady_clock::now();
        qs.ASearch(words[i]);
        auto d_e = steady_clock::now();
        dd += d_e - d_b;
        o_a_s[i] += dd;
    }
    nanoseconds ds(0);
    nanoseconds dm(0);
    nanoseconds dp(0);
    nanoseconds de(0);
    for (auto t = 0; t < experiments; t++)
    {
        for (auto i = 0; i < words.size(); i++)
        {

            auto vv_b = steady_clock::now();
            ms2.BInsert(words[i]);
            auto vv_e = steady_clock::now();
            ds += vv_e - vv_b;
            oo_b_i[i] += ds;

            auto ll_b = steady_clock::now();
            qs2.AVLInsert(words[i]);
            auto ll_e = steady_clock::now();
            dm += ll_e - ll_b;
            oo_a_i[i] += dm;

            auto pp_b = steady_clock::now();
            ms2.BSearch(words[i]);
            auto pp_e = steady_clock::now();
            dp += pp_e - pp_b;
            oo_b_s[i] += dp;

            auto dd_b = steady_clock::now();
            qs2.ASearch(words[i]);
            auto dd_e = steady_clock::now();
            de += dd_e - dd_b;
            oo_a_s[i] += de;
        }
    }
    //  for (int i = 0; i < 1000; i++)
    // {
    //     printf("%i %i %i %i %i\n", i, o_b_i[i], o_a_i[i], o_b_s[i], o_a_s[i]);
    // }
    for (int i = 0; i < max_size; i++)
    {
        printf("%li %li %li %li %li\n", i, oo_b_i[i].count() / experiments, oo_a_i[i].count() / experiments, oo_b_s[i].count() / experiments, oo_a_s[i].count() / experiments);
    }

    return 0;
}