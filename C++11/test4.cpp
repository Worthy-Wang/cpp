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
    weak_ptr<B> _pb;
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

/*
如果在类A与类B中都设置 shared_ptr型指针的话，会造成死锁的原因：
test4()函数结束，pA 与 pB销毁，但是A , B 的引用计数仍然为1, 所以A ，B并不会调用析构函数
*/

//测试weak_ptr
void test4()
{
    shared_ptr<A> pA(new A());
    shared_ptr<B> pB(new B());
    pA->_pb = pB;
    pB->_pa = pA;
    cout << "A的引用计数：" << pA.use_count() << endl;
    cout << "B的引用计数：" << pB.use_count() << endl;
}

int main()
{
    shared_ptr<int> p1(new int(3));
    shared_ptr<int> p2 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    return 0;
}
