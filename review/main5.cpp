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

struct A
{
    int a;
    template <typename T>
    void func(T val)
    {
        cout << val << endl;
    }
};

class B : A
{
    int b;
};

int main()
{
    A a;
    a.func(3);
    return 0;
}
