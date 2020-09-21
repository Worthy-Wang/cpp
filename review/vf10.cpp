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

class Base
{
public:
    Base(const char *str)
        : _pstr(new char[strlen(str) + 1])
    {
        strcpy(_pstr, str);
        cout << "Base(const char* str)" << endl;
    }

    Base(const Base &lhs)
        : _pstr(new char[strlen(lhs._pstr) + 1])
    {
        strcpy(_pstr, lhs._pstr);
        cout << "Base(const Base& lhs)" << endl;
    }

    Base &operator=(const Base &lhs)
    {
        if (this != &lhs)
        {
            delete[] _pstr;
            _pstr = new char[strlen(lhs._pstr) + 1];
            strcpy(_pstr, lhs._pstr);
            cout << "Base& operator=(const Base&)" << endl;
        }
        return *this;
    }

    ~Base()
    {
        if (_pstr)
        {
            cout << "~Base()" << endl;
            delete[] _pstr;
            _pstr = NULL;
        }
    }

    friend ostream &operator<<(ostream &, const Base &);

private:
    char *_pstr;
};

ostream &operator<<(ostream &os, const Base &lhs)
{
    os << lhs._pstr;
    return os;
}

class Derived : public Base
{
public:
    Derived(const char *str1, const char *str2)
        : Base(str1), _pstr(new char[strlen(str2) + 1])
    {
        strcpy(_pstr, str2);
        cout << "Derived(const char*, const char*)" << endl;
    }

    Derived(const char *str)
        : _pstr(new char[strlen(str) + 1]), Base(str)
    {
        strcpy(_pstr, str);
        cout << "Derived(const char* str)" << endl;
    }

    Derived(const Derived &lhs)
        : _pstr(new char[strlen(lhs._pstr) + 1]), Base(lhs) //这里的Derived类型会自动转换为Base类型，再调用Base的拷贝构造函数
    {
        strcpy(_pstr, lhs._pstr);
        cout << "Derived(const Derived& lhs)" << endl;
    }

    Derived &operator=(const Derived &lhs)
    {
        if (this != &lhs)
        {
            delete[] _pstr;
            _pstr = new char[strlen(lhs._pstr) + 1];
            strcpy(_pstr, lhs._pstr);

            #if 0
            Base& b = static_cast<Base&>(*this);
            b = static_cast<Base>(lhs);
            #endif 
            Base::operator=(lhs);

            cout << "Derived& operator=(const Derived&)" << endl;
        }
        return *this;
    }

    ~Derived()
    {
        if (_pstr)
        {
            cout << "~Derived()" << endl;
            delete[] _pstr;
        }
    }

    friend ostream &operator<<(ostream &, const Derived &);

private:
    char *_pstr;
};

ostream &operator<<(ostream &os, const Derived &lhs)
{
    const Base &b = static_cast<const Base &>(lhs);
    os << b << "," << lhs._pstr;
    return os;
}


void test0(){
    Derived d("Base", "Derived");
    Base b(d);
    cout << b << endl;
    cout << d << endl;

}


int main()
{
    test0();
    return 0;
}