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
#include <unistd.h>
using namespace std;

void test1()
{
    srand(time(NULL));
    int l = 3, r = 6;
    while(1)
    cout << 3 + random()%(r-l+1) << endl;
}

int main()
{
    test1();
    return 0;
}
