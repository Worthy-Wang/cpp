#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class C
{

};

class A1
{
    int _val;
public:
    int operator=(int a)
    {
        return 8;
    }

    int operator+(int a)
    {
        return 9;
    }
};

class B1 : public A1
{
public:
    int operator-(int a)
    {
        return 7;
    }
};


int main()
{
    B1 b;
    cout << (b+3) << endl;
    cout << (b-2) << endl;
    // cout << (b=3) << endl;
    return 0;
}
