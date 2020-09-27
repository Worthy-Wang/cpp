#include <iostream>
#include <memory>
using namespace std;
class B;
class A
{
public:
    A()
    {
        cout << "构造函数" << endl;
    }
    ~A()
    {
        cout << "析构函数" << endl;
    }
    weak_ptr<B> _pb;//若为shared_ptr，那么析构时只会析构pA和pB，但A 和 B 的引用计数仍为1，所以不能析构并释放内存
};

class B
{
public:
    B()
    {
        cout << "构造函数" << endl;
    }
    ~B()
    {
        cout << "析构函数" << endl;
    }
    weak_ptr<A> _pa;
};

int main()
{
    shared_ptr<A> pA(new A());
    shared_ptr<B> pB(new B());
    pA->_pb = pB;
    pB->_pa = pA;
    cout << "A的引用计数：" << pA.use_count() << endl;
    cout << "B的引用计数：" << pB.use_count() << endl;
    return 0;
}

