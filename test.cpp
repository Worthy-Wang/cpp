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
   A *operator&(A *lhs)
   {
      return lhs;
   }
};

void test1()
{
   A a;
   A b(a);
   A c;
   c = a;
   A *d = &a;
   const A *e = &a;
}

void test2()
{
   int **a = (int **)malloc(sizeof(int) * 3);
   for (int i = 0; i < 3; i++)
      a[i] = (int *)malloc(sizeof(int) * 4);

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
         cout << a[i][j] << endl;
}

void test3()
{
   int ***a = (int ***)malloc(sizeof(int) * 3);
   for (int i = 0; i < 3; i++)
   {
      a[i] = (int **)malloc(sizeof(int) * 4);
      for (int j = 0; j < 4; j++)
         a[i][j] = (int *)malloc(sizeof(int) * 5);
   }
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
         for (int k = 0; k < 5; k++)
            cout << a[i][j][k] << endl;
}

void test4()
{
   int **a = new int *[2];
   for (int i = 0; i < 2; i++)
      a[i] = new int[3];

   int cnt = 1;
   for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++)
         a[i][j] = cnt++;

   for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++)
         cout << a[i][j] << endl;
}

void test5()
{
   int ***a = new int **[3];
   for (int i = 0; i < 3; i++)
   {
      a[i] = new int *[4];
      for (int j = 0; j < 4; j++)
         a[i][j] = new int[5];
   }

   int cnt = 1;
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
         for (int k = 0; k < 5; k++)
            a[i][j][k] = cnt++;

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
         for (int k = 0; k < 5; k++)
            cout << a[i][j][k] << endl;
}

//vector
void test6()
{
   int m = 3, n = 4;
   vector<vector<int>> nums(m, vector<int>(n, 0));
}

int main()
{
   test6();
   return 0;
}
