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

int main()
{
    int a = 0x1234;
    char b = static_cast<char>(a);
    if (b == 0x12)
        cout << "大端模式" << endl;
    else if (b == 0x34)
        cout << "小端模式" << endl;
    
    return 0;
}
