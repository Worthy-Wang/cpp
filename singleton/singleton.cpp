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

class Singleton
{
    static Singleton *_pInstance;

public:
    static Singleton *getInstance()
    {
        return _pInstance;
    }
    static void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    Singleton() {}
    ~Singleton() {}
};

Singleton *Singleton::_pInstance = new Singleton();

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    Singleton *s3 = Singleton::getInstance();
    printf("%p\n", s1);
    printf("%p\n", s2);
    printf("%p\n", s3);
    return 0;
}
