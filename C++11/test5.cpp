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
    shared_ptr<A> returnS()
    {
        return shared_ptr<A>(this);
    }
};

int main()
{
    A a;
    shared_ptr<A> p = a.returnS();
    cout << p.use_count() << endl;
    return 0;
}
