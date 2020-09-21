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
protected:
    int a = 3;
};

class B : public A
{
public:
    using A::a;
};

class Base
{
public:
    virtual void func() = 0;
    int a;
    char* p;
};


int main()
{
    cout << sizeof(Base) << endl;
    return 0;
}
