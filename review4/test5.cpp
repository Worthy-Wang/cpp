#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <memory>
#include <limits>
#include <list>
#include <regex>
#include <functional>
#include <math.h>
#include <unordered_set>
#include <hash_map>
#include <hash_set>
using namespace std;

void test0()
{
    vector<int> vec{1, 2, 3, 4};
    vec.insert(vec.begin(), 0);
    for (auto &e : vec)
        cout << e << endl;
}

void test1()
{
    std::list<int> list{1, 4, 5, 6};
    std::list<int> list2{2, 3, 4};
    list.splice(next(list.begin()), list2, list2.begin(), prev(list2.end()));
    for (auto &e : list)
        cout << e << endl;
}

void test2()
{
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i); // mylist1: 1 2 3 4

    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10); // mylist2: 10 20 30

    it = mylist1.begin();
    ++it; // points to 2

    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2 (empty)
                                 // "it" still points to 2 (the 5th element)


    mylist2.splice(mylist2.begin(), mylist1, it);
    // // mylist1: 1 10 20 30 3 4
    // // mylist2: 2
    // // "it" is now invalid.
    it = mylist1.begin();
    std::advance(it, 3); // "it" points now to 30

    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
    for(auto& e: mylist1)
        cout << e << endl;
    // // mylist1: 30 3 4 1 10 20

    // std::cout << "mylist1 contains:";
    // for (it = mylist1.begin(); it != mylist1.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // std::cout << "mylist2 contains:";
    // for (it = mylist2.begin(); it != mylist2.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
}



int main()
{
     
    return 0;
}
