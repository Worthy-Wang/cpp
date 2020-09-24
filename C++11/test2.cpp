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

union A
{
    char chs[13];
    int i;
};

union B
{
    char chs[13];
    int i;
};

union s1
{
char a;
double b;
int c;
char d;
};

union s2
{
char a;
char b;
int c;
double d;
};

union s3
{
    double i;
    char s;
};

int main()
{
    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s3) << endl;
    return 0;
}
