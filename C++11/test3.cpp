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
#include <array>
using namespace std;

class String
{
public:
    String();
    String(const char *);
    String(const String &);
    String(String &&lhs); //移动构造函数
    ~String();
    String &operator=(const String &);
    String &operator=(const char *);
    String &operator=(String &&lhs); //移动赋值运算符
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

private:
    char *_pstr;
};

String::String()
    : _pstr(new char('\0'))
{
    cout << "String()" << endl;
}

String::String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1])
{
    cout << "String(const char*)" << endl;
    memcpy(_pstr, pstr, strlen(pstr) + 1);
}

String::String(const String &lhs)
    : _pstr(new char[strlen(lhs._pstr) + 1])
{
    cout << "String(const String&)" << endl;
    strcpy(_pstr, lhs._pstr);
}

/*
*/
String::String(String &&lhs)
{
    cout << "String(String&&)" << endl;
    _pstr = lhs._pstr;
    lhs._pstr = NULL;
}

String::~String()
{
    if (_pstr)
    {
        cout << "~String()" << endl;
        delete[] _pstr;
        _pstr = NULL;
    }
}

String &String::operator=(const String &lhs)
{
    if (this != &lhs)
    {
        delete[] _pstr;
        _pstr = new char[strlen(lhs._pstr) + 1];
        memcpy(_pstr, lhs._pstr, strlen(lhs._pstr) + 1);
    }
    return *this;
}

String &String::operator=(const char *s)
{
    if (_pstr != s)
    {
        delete[] _pstr;
        _pstr = new char[strlen(s) + 1];
        memcpy(_pstr, s, strlen(s) + 1);
    }
    return *this;
}

//移动赋值运算符
String &String::operator=(String &&lhs)
{
    if (this != &lhs)
    {
        cout << "String& operator=(String&&)" << endl;
        _pstr = lhs._pstr;
        lhs._pstr = NULL;
    }
    return *this;
}

ostream &operator<<(ostream &os, const String &s)
{
    if (s._pstr)
    {
        os << s._pstr;
    }
    return os;
}

//测试移动构造函数
void test2()
{
    vector<String> vec;
    String s1("s1");
    vec.push_back(s1);
}

//测试移动赋值运算符
void test3()
{
    String s1("s1");
    String s2("s2");
    s1 = std::move(s2);
    cout << s1 << endl;
}

String returnS()
{
    return String("s");
}


class A
{
public:
    A()
    {
        cout << "A()" <<endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
    A(const A& lhs)
    {
        cout << "const A&" << endl;
    }    
    A(A&& lhs)
    {
        cout << "A&& lhs" << endl;
    }
};

A returnA()
{
    A a;
    return a;
}

int main()
{
    A a = returnA();
    return 0;
}
