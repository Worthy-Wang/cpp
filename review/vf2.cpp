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
    int a = 1;
};

class B:protected A
{
protected:
    int b = 2;
};

class C:protected A
{
protected:
    int c = 3;
};

class D:B, C
{
    int d = 4;
public:
    void display ()
    {
        cout << B::a << endl;
        cout << C::a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
    }
};

int main()
{
    D d;
    d.display();
   return 0;
}
