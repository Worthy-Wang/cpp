#include <iostream>
using namespace std;

//菱形继承案例
class A {
public:
	int _a;
};


class B :virtual public A {
public:
	int _b;
};


class C :virtual public A {
public:
	int _c;
};


class D :public B, public C{
public:
	int _d;
public:
	void display() {
		//cout << "_a = " << _a << endl;//ERROR! 这里出现了菱形继承时不被允许的
		cout << "B::_a = " << _a << endl; //可以！这里明确了是哪一个_a
		cout << "C::_a = " << _a << endl; //可以！这里明确了是哪一个_a
		cout << "_b = " << _b << endl;
		cout << "_c = " << _c << endl;
		cout << "_d = " << _d << endl;

	}
};


int main() {
    D d;
    d.display();
	return 0;
}
