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
    virtual void func(){}
};

class B : public A
{
};

int main()
{
    A a;
    B b;
    try
    {
        B& b = dynamic_cast<B&>(a);
    }catch(bad_cast)
    {
        cout << "bad_cast" << endl;
    }
    return 0;
}
