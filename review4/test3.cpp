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

using FUNC = function<void()>;

class Figure
{
    FUNC _cb;

public:
    void setCb(const FUNC &cb)
    {
        _cb = cb;
    }
    void display()
    {
        _cb();
    }
};

class Circle
{
    double _r;

public:
    Circle(double r)
        : _r(r)
    {
    }
    void display()
    {
        cout << "Circle:" << 3.1415 * _r * _r << endl;
    }
};

void test1()
{
    Figure *f = new Figure();
    f->setCb(std::bind(&Circle::display, Circle(1)));
    f->display();
}

struct Pred
{
    bool operator()(int i)
    {
        if (i & 0x1)
            return true;
        else
            return false;
    }
};

bool IsOdd(int i)
{
    if (i & 0x1)
        return true;
    else
        return false;
}

void test2()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec.erase(remove_if(vec.begin(), vec.end(), std::bind2nd(greater<int>(), 5)), vec.end());
    for (auto &e : vec)
        cout << e << endl;
}

void test3()
{
    vector<int> vec{1, 3, 5, 6, 7, 8};
    vec.erase(remove_if(vec.begin(), vec.end(), bind2nd(std::greater_equal<int>(), 5)), vec.end());
    for (auto &e : vec)
        cout << e << endl;
}


int main()
{
    test2();
    return 0;
}

