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
    int _val;

public:
    explicit A(int val)
        : _val(val)
    {
        cout << "A(int)" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }

    A(const A &lhs)
    {
        _val = lhs._val;
        cout << "const A&" << endl;
    }

    A &operator=(const A &lhs)
    {
        if (this != &lhs)
        {
            _val = lhs._val;
            cout << "operator=" << endl;
        }
        return *this;
    }

    int operator++()
    {
        _val++;
        return _val;
    }

    int operator++(int)
    {
        int ret = _val;
        _val++;
        return ret;
    }

    friend bool operator<(const A &lhs, const A &rhs);

    friend ostream &operator<<(ostream &os, const A &lhs);
};

ostream &operator<<(ostream &os, const A &lhs)
{
    os << lhs._val;
    return os;
}
bool operator<(const A &lhs, const A &rhs)
{
    return lhs._val < rhs._val;
}

struct Func
{
    void operator()(int a, int b)
    {
        cout << "funciton()" << endl;
    }
};

class Nums
{
    class Proxy;
    vector<int> nums;
public:
    Nums(int n)
    {
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
    }

    Proxy operator[](int index)
    {
        return Proxy(*this, index);
    }

private:
    class Proxy
    {
        Nums &_nums;
        int _index;

    public:
        Proxy(Nums &nums, int index)
            : _nums(nums), _index(index)
        {
        }

        operator int()
        {
            cout << "Read Only" << endl;
            return _nums.nums[_index];
        }

        int operator=(int index)
        {
            cout << "Write" << endl;
        }
    };
};

int main()
{
    Nums nums(3);
    cout << nums[2] << endl;
    nums[2] = 1;
    return 0;
}
