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

class Foo
{
public:
    static int cnt;
    Foo()
    {
        // cnt++;
    }
};


static int i = 3;
void func()
{
    i++;
    cout << i << endl;
}



int main()
{
    func();
    func();
    func();
    return 0;
}
