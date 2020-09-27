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
using namespace std;

class A
{
public:
    int _val;
    A(int val)
        : _val(val)
    {
    }
};

struct myComp
{
    bool operator()(const A &lhs, const A &rhs)
    {
        return lhs._val < rhs._val;
    }
};

void test1()
{
    set<A, myComp> sets;
    A a1(1), a2(2), a3(3);
    sets.insert(a1);
    sets.insert(a2);
    sets.insert(a3);
    for (auto &e : sets)
        cout << e._val << endl;
}

void test2()
{
    vector<A> vec;
    A a1(1), a2(2), a3(3);
    vec.push_back(a1);
    vec.push_back(a2);
    vec.push_back(a3);
    for (auto &e : vec)
        cout << e._val << endl;
    sort(vec.begin(), vec.end(), myComp());
}

void test3()
{
    vector<int> vec{42, 1, 3, 5, 6};
    sort(vec.begin(), vec.end(), greater<int>());
    for (auto &e : vec)
        cout << e << endl;
}

void test4()
{
    vector<int> vec{1,2,3};
    vector<int> vec2;
    std::copy(vec.begin(), vec.end(), back_inserter(vec2));
    for(auto& e: vec2)
        cout << e << endl;
}

int main()
{
    test4();
    return 0;
}
