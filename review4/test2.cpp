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

void test1()
{
    vector<int> vec{1, 2, 3, 4, 5};
    vec.reserve(10);
    auto beg = vec.begin();
    auto end = --vec.end();

    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    cout << *end++ << endl;
    cout << *end++ << endl;
    cout << *end++ << endl;
    cout << *end++ << endl;
    cout << *end++ << endl;
}


void test2()
{
    list<int> lists{1,2,3,4,5};
    auto it = lists.begin();
    advance(it, 2);
    auto it2 = next(it);
    lists.erase(it);
    cout << *it2++ << endl;    
    cout << *it2++ << endl;    
    cout << *it2++ << endl;    
}

int main()
{
    
    return 0;
}
