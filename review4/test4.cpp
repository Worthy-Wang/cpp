#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FuncObject01
{
public:
    void operator()()
    {
        cout << "Hello WOrld!" << endl;
    }
};

void FuncObject02()
{
    cout << "Hello WOrld!" << endl;
}

void test01()
{
    FuncObject01 fobj;
    fobj();
    FuncObject02();
    cout << "------------" << endl;
}

class FuncObject03
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int FuncObject04(int a, int b)
{
    return a + b;
}

// 函数对象也可以像普通函数一样 具有返回值和参数
void test02()
{
    FuncObject03 fobj;
    int ret = fobj(10, 20);
    cout << "ret = " << ret << endl;
    ret = FuncObject04(10, 30);
    cout << "ret = " << ret << endl;
    cout << "------------------------" << endl;
}

// 函数对象超出了普通函数的功能，可以具有保存函数调用状态
// 例如 我们要统计函数的调用次数

class FuncObject05
{
public:
    FuncObject05() : count(0) {}
    void operator()()
    {
        cout << "Hello World!" << endl;
        count++;
    }
    int count;
};

// 普通函数统计调用次数，需要一个全局变量
int g_count = 0;
void FuncObject06()
{
    cout << "Hello World!" << endl;
    g_count++;
}

void test03()
{
    FuncObject06();
    FuncObject06();
    cout << "函数调用次数：" << g_count << endl;
    // 使用函数对象不需要使用全局变量
    FuncObject05 fobj;
    fobj();
    fobj();
    fobj();
    cout << "函数调用次数：" << fobj.count << endl;
    cout << "---------------------------" << endl;
}

// 函数对象做参数和返回值
class print
{
public:
    print() : count(0) {}
    void operator()(const int &val)
    {
        cout << val << " ";
        count++;
    }
    int count;
};

int num = 0;
void print2(int val)
{
    cout << val << " ";
    num++;
}

void test04()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    // 通过for_each算法 遍历容器元素
    print myprint;
    // 函数对象做返回值和参数
    myprint = for_each(v.begin(), v.end(), myprint);
    cout << endl;
    cout << "函数调用次数：" << myprint.count << endl;
    for_each(v.begin(), v.end(), print2);
    cout << endl;
    cout << "函数调用次数：" << num << endl;
}

int main()
{
    test04();
    return 0;
}