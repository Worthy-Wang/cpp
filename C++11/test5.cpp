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

class A: public enable_shared_from_this<A>
{
public:
    shared_ptr<A> returnS()
    {
        return shared_from_this();
    }
};

int main()
{
    shared_ptr<int> p1 = std::make_shared<int>(3);
    return 0;
}
