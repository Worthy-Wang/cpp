#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

/*
虚函数与虚函数表：
*/

class A {
public:
	void print() {
		cout << "this is A" << endl;
	}
};


class A1 :public A {
public:
	A1() {
		cout << "A1()" << endl;
	}
	~A1() {
		cout << "~A1()" << endl;
	}
	void print() {
		cout << "this is A1()" << endl;
	}
};

class A2 :public A {
public:

	A2() {
		cout << "A2()" << endl;
	}
	~A2() {
		cout << "~A2()" << endl;
	}

	void print() {
		cout << "this is A2()" << endl;
	}
};


class B :public A1, public A2 {
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}

	void print() {
		cout << "this is B" << endl;
	}
};

struct MyStruct 
{ 
char dda; 
double dda1; 
int type ;
};

#pragma pack(push) 
#pragma pack(4) 
struct test 
{ 
char m1; 
double m4; 
int m3; 
}; 
#pragma pack(pop)


int main() {
    // cout << sizeof(A1) << endl;
    // cout << sizeof(B) << endl;
	// cout << sizeof(MyStruct) << endl;
	cout << sizeof(test) << endl;
	return 0;
}
