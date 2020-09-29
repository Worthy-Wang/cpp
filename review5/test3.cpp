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
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }

    void*  operator new(size_t n)
    {
        cout << "operator new(size_t)" << endl;
        A *ret = (A*)malloc(n);
        return ret;
    }

    void* operator new[](size_t n)
    {
        cout << "operator new[](size_t)" << endl;
        A* ret = (A*)malloc(n);
        return ret;    
    }

    void operator delete(void* p)
    {
        if (p)
        {
            cout << "operator delete(void*)" << endl;
            free(p);
            p = nullptr;
        }
    }

    void operator delete[](void* p)
    {
        if (p)
        {
            cout << "operator delete[](void*)" << endl;
            free(p);
            p = nullptr;
        }
    }
};

int main()
{
    A *a = new A();
    delete a;
    return 0;
}
