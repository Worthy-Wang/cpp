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
    void func()
    {
        cout << "A::func()" << endl;
    }
    virtual void func(int a, int b)
    {
        cout << "A::func(int,int) " << endl;
    }
};

class B : public A
{
public:
    void func(int a)
    {
        cout << "B::func()" << endl;
    
    }
    void func(int a, int b)
    {
        cout << "B::func(int,int)" << endl;
    }
};

int main()
{
    A *a = new B;
    a->A::func(3,2);
    return 0;
}
