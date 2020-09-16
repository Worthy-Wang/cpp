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

int main()
{
    test3();
    return 0;
}
