#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
实现memcpy, strcpy, strcat, strncat, strcmp, strncmp, strlen

*/
void* myMemcpy(void* des, const void* src, size_t n)
{
    assert(des && src);
    char* p1 = (char*)des;
    const char* p2 = (const char*)src;
    size_t i = 0;
    for (; i < n; i++)
        p1[i] = p2[i];
    return p1;
}

void test1()
{
    char des[3], src[100] = "HelloWorld";
    memcpy(des, src, 104);
    // myMemcpy(des, src, 5);
    cout << des << endl;
}

char* myStrcpy(char* des, const char* src)
{
    assert(des && src);
    int i = 0;
    for (; src[i]; i++)
        des[i] = src[i];
    des[i] = 0;
    return des;
}

void test2()
{
    char des[2], src[100] = "HelloWorld";
    // strcpy(des, src);
    myStrcpy(des, src);
    cout << des << endl;
}


char* myStrcat(char* s1, const char* s2)
{
    int i = 0;
    while (s1[i])
        i++;
    int j = 0;
    while (s2[j])
        s1[i++] = s2[j++];
    s1[i] = 0;
    return s1;
}

void test3()
{
    char s1[100] = "Hello", s2[100] = "World";
    // strcat(s1, s2);
    myStrcat(s1, s2);
    cout << s1 << endl;
}

char* myStrncat(char* s1, const char* s2, size_t n)
{
    assert(s1 && s2);
    int i = 0;
    while (s1[i])
        i++;
    for (int j = 0; j < n; j++)
        s1[i++] = s2[j];
    s1[i] = 0;
    return s1;
}

void test4()
{
    char s1[100] = "Hello", s2[100] = "Worlddddd";
    strncat(s1, s2, 6);
    // myStrncat(s1, s2, 6);
    cout << s1 << endl;
}

int myStrcmp(const char* s1, const char* s2)
{
    assert(s1 && s2);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; s1[i]; i++)
        sum1 += s1[i];
    for (int i = 0; s2[i]; i++)
        sum2 += s2[i];
    return sum1 - sum2;
}

void test5()
{
    char s1[100] = "aa", s2[100] = "aa";
    // cout << strcmp(s1, s2) << endl;
    cout << myStrcmp(s1, s2) << endl;   
}

int myStrncmp(const char* s1, const char* s2, size_t n)
{
    assert(s1 && s2);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; s1[i] && i < n; i++)
        sum1 += s1[i];
    for (int i = 0; s2[i] && i < n; i++)
        sum2 += s2[i];
    return sum1 - sum2;
}

void test6()
{
    char s1[100] = "aa", s2[100] = "a";
    // cout << strncmp(s1, s2, 3) << endl;
    cout << myStrncmp(s1, s2, 3) << endl;   
}

int myStrlen(const char* s)
{
    assert(s);
    int cnt = 0;
    for (int i = 0; s[i] ; i++)
        cnt++;
    return cnt;
}

void test7()
{
    char s[100] = "a";
    cout << strlen(s) << endl;    
    cout << myStrlen(s) << endl;
}


int main()
{
    int a = 5, b = 7, c;
    c = a+++b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}
