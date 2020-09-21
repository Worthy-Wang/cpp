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
    int m = 1;
    void func()
    {
        cout << "A::func()" << endl;
    }
};

class B
{
public:
    int m = 2;
    void func() 
    {
        cout << "B::func()" << endl;
    }
};

class C : public A, public B
{
public:
    int m = 3;
    void func() 
    {
        cout << "C::func()" << endl;
    }
};

void display(A *a)
{
    a->func();
}

void test1()
{
    C c;
    cout << c.A::m << endl;
    cout << c.B::m << endl;
    cout << c.C::m << endl;
    cout << c.m << endl;
}

class People
{
public:
    int _age;
};

class Student: People
{
public:
    void display()
    {
        cout << _age << endl;
    }
};

class A1
{
    int _a;
public:
    A1(int a)
    :_a(a)
    {
        cout << "A1()" << endl;
    }
    ~A1()
    {
        cout << "~A1()" << endl;
    }
};

class A2
{
    int _a2;
public:
    A2(int a)
    :_a2(a)
    {
        cout << "A2()" << endl;
    }
    ~A2()
    {
        cout << "~A2()" << endl;
    }
};

class A3: A1,  A2
{
    int _a3;
public:
    A3(int a1, int a2, int a3)
    :A1(a1), A2(a2), _a3(a3)
    {
        cout << "A3()" << endl;
    }
    ~A3()
    {
        cout << "~A3()" << endl;
    }
};

void test2()
{
    A3 *a3 = new A3(1,2,3);
    delete a3;
}

int main()
{
    test1();
    return 0;
}
