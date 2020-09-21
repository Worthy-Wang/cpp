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
    virtual void a() //虚函数
    {
        cout << "a() in A" << endl;
    }
    virtual void b() //虚函数
    {
        cout << "b() in A" << endl;
    }
    virtual void c() //虚函数
    {
        cout << "c() in A" << endl;
    }
};

class B
{
public:
    virtual void a() //虚函数
    {
        cout << "a() in B" << endl;
    }
    virtual void b() //虚函数
    {
        cout << "b() in B" << endl;
    }
    void c() //非虚函数
    {
        cout << "c() in B" << endl;
    }
    void d() //非虚函数
    {
        cout << "d() in B" << endl;
    }
};

class C : public A, public B
{
public:
    virtual void a() //虚函数，覆盖
    {
        cout << "a() in C" << endl;
    }
    void c() 
    {
        cout << "c() in C" << endl;
    }
    void d() //非虚函数，隐藏
    {
        cout << "d() in C" << endl;
    }
};

void test1()
{
    A* pa = new C();
    pa->a();
    pa->b();
    pa->c();
    //pa->d();//ERROR! 从A继承下来的虚函数表中没有覆盖d
}

void test2(){
    C c;
    B *pb = &c;
    pb->a();
    pb->b();
    pb->c();//这里实现的是静态联编，也就是直接在类B中寻找，与多态无关
    pb->d();//同上
}

void test3(){
    C c;
    C* pc = &c;
    pc->a();

    //pc->b();//ERROR!编译器并不知道是哪一张虚函数表中的b()
    pc->A::b();
    pc->B::b();

    pc->c();
    pc->A::c();
    pc->B::c();
    
    pc->d();
    pc->B::d();
}


void test4()
{
    C *c = new C();
    c->a();
    c->A::b();
    c->B::b();
    c->c();
    c->d();
}

int main()
{
    test4();
    return 0;
}

