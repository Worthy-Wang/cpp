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

#include <iostream>
using namespace std;
//全局变量
int all_num = 0;
int main()
{
    //局部变量
    int num_1 = 1;
    int num_2 = 2;
    int num_3 = 3;
    cout << "lambda1:\n";
    auto lambda1 = [=]() mutable {
        //全局变量可以访问甚至修改
        all_num = 10;
        //函数体内只能使用外部变量，而无法对它们进行修改
        num_1 = 10, num_2= 20, num_3 = 30;
    };
    lambda1();
    cout << all_num << endl;
    cout << num_1 << " "
         << num_2 << " "
         << num_3 << endl;

    auto lambda2 = [&] {
        all_num = 100;
        num_1 = 10, num_2 = 20, num_3 = 30;
    };
    lambda2();
    cout << all_num << endl;
    cout << num_1 << " "
         << num_2 << " "
         << num_3 << endl;
}
