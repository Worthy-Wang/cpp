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
#define N 5
// #define UINT unsigned int
// typedef unsigned int UINT;
// using UINT = unsigned int;
#define USA "The\ 
United  \
Status "

#define MIN(a,b) (((a)<(b))?(a):(b))
#define multi(a,b) (a*b)
#define PRINT cout << "hello world" << endl
#define ERROR_CHECK(argc) if(-1 == argc){cout << "ERROR" <<endl;}\
else {cout << "OK" <<endl;}
#define SECONDS_PER_YEAR (60*60*24*365)


void set3bit(int& num)
{
    int x = 0x4;
    if (!(num & x))
        num ^= x;
}

void clear3bit(int& num)
{
    int x = 0x4;
    if (num & x)
        num ^= x;
}

#ifndef _cplusplus
#error 亲，您使用的不是C++的编译器哦，所以这里会给您报错
#endif


int main()
{

    return 0;
}
