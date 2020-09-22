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
    virtual void func()
    {
        cout << "A::func()" << endl;
    }
};

class B : public A
{
public:
    virtual void func()
    {
        cout << "B::func()" << endl;
    }
};

void display(A a)
{
    a.func();
}

void show()
{
    cout << "show()" << endl;
}

class C
{
public:
    static void show()
    {
    }
};

static int a = 5;
const int b = 3;



int main()
{

    return 0;
}
