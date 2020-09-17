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
#include <stdio.h>
using namespace std;

/*
函数指针与using function的区别

*/

// using Func = function<int(int a, int b)>;
int (*Func)(int, int);

int sum(int a, int b)
{
    return a + b;
}

/*
指针数组与数组指针

*/

void test2()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p1[2];
    for (int i = 0; i < 2; i++)
        p1[i] = a[i];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << p1[i][j] << " ";
        cout << endl;
    }
}

void test3()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*p2)[3];
    p2 = a;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << p2[i][j] << " ";
        cout << endl;
    }
}

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (size > num.size())
        return {};
    vector<int> ans;
    std::deque<int> deque;
    for (int i = 0; i < size; i++)
    {
        while (!deque.empty() && num[deque.back()] <= num[i])
            deque.pop_back();
        deque.push_back(i);
    }
    ans.push_back(num[deque.front()]);
    for (int i = size; i < num.size(); i++)
    {
        while (!deque.empty() && num[deque.back()] <= num[i])
            deque.pop_back();
        deque.push_back(i);
        if (i - deque.front() >= size)
            deque.pop_front();
        ans.push_back(num[deque.front()]);
    }
    return ans;
}

class A
{
    int _a = 0;
    mutable int _b = 0;

public:
    A() {}
    void change() const
    {
        // _a++;
        _b++;
    }
};

const A getA()
{
    A a;
    return a;
}

//const 修饰普通变量
void test4()
{
    const int a = 7;
    int *p = (int *)&a;
    *p = 8;
    cout << a << endl;
}

const char* getstr()
{
    char *str = "hello";
    return str;
}

void funcF(const int& a)
{
    cout << a << endl;
}

int main()
{
    funcF(3);
    return 0;
}
