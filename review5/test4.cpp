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
    int _i;
    A(int i)
    :_i(i)
    {}
};

class B:public A
{
public:
    B(int i)
    :A(i)
    {}
};

class C
{
    int& _i;
public:
    C(int i)
    :_i(i)
    {}
};

int main()
{
    C c(3);
    return 0;
}



