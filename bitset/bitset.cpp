#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);
    string res, temp;
    while (ss >> temp)
        res = " " + temp + res;
    if (res.empty())
        return string();
    return string(res.begin() + 1, res.end());
}

int main()
{
    string s("Helloworld");
    cout << s.substr(0,2) << endl;
    return 0;
}