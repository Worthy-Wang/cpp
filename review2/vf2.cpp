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
	virtual void func1() {}
	virtual void func2() {}
	virtual void func3() {}
};


class B:public A
{
public:
	virtual void func3(){}
	virtual void func4(){}
};


int main()
{
	char* s[3] = {"123", "456", "789"};
	char** p = s;
	// cout << p[1] << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	return 0;
}
