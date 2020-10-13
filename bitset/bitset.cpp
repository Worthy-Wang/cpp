#include <bitset>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    bitset<4> bits1("0010");
    bitset<4> bits2("1011");
    
    cout << bits2.to_ulong() << endl;
    return 0;
}