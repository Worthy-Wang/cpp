#include <iostream>
using namespace std;

class Base {
public:
    Base()
    {
        cout << "Base()" << endl;
    }
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived:public Base
{
public:
    Derived()
    {
        cout << "Derived()" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

inline void func()
{
    cout << "func()" << endl;
}


int main() {
    func();
	return 0;
}

