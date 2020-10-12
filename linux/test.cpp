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

/*
begin:
end:
Time Complexity:
Space Complexity:
Method:
*/

int lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;
    stack<char> stk;
    unordered_set<char> sets;
    size_t Max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (sets.find(s[i]) != sets.end())
        {
            while (stk.top() != s[i])
            {
                sets.erase(stk.top());
                stk.pop();
            }
            sets.erase(stk.top());
            stk.pop();
        }
        stk.push(s[i]);
        sets.insert(s[i]);
        Max = std::max(Max, stk.size());
    }
    return Max;
}

int main()
{
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
