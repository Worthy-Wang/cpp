#include <iostream>
using namespace std;

class A {
public:
	A() {};
	~A() {};
	int a;

	void set() {
		a = 0;
		a1 = 1;
		a2 = 2;
		a3 = 3;
	}

	void show() {
		cout << "a = " << a << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		cout << "a3 = " << a3 << endl;
	}

public:
	int a1;
protected:
	int a2;
private:
	int a3;
};


//注意，像这样没有直接标明继承类型的都是private继承
class B:A {
public:
	B() {};
	~B() {};
	void show() {
		cout << "a = " << a << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		// cout << "a3 = " << a3 << endl;//ERROR! private修饰的成员只能在本类中访问
	}
	
};

class C :B {
public:
	C() {};
	~C() {};
	void show() {
		//ERROR! 由于B类从A类是private继承，所以 a, a1, a2 都已经全部变为private修饰了，所以在C类中不能进行访问
		cout << "a = " << a << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		cout << "a3 = " << a3 << endl;
	}

};



int main() {
	B b;
	cout << b.a << endl;//ERROR! private修饰的成员只能再本类中访问
	cout << b.a1 << endl;//ERROR! private修饰的成员只能再本类中访问
	cout << b.a2 << endl;//ERROR! private修饰的成员只能再本类中访问
	cout << b.a3 << endl;//ERROR! private修饰的成员只能再本类中访问

	return 0;
}
