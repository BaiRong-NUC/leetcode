/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
private:
    int rfind(const string &s)
    {
        int i = 0;
        while (s[i] == '0')
            i++;
        return i;
    }

public:
    int reverse(int x)
    {
        if (x > -10 && x < 10)
            return x;

        string s_max = to_string(INT_MAX);
        string s_min = to_string(INT_MIN).substr(1);
        string s = to_string(x);

        if (x < 0)
            s = s.substr(1);

        std::reverse(s.begin(), s.end());
        s = s.substr(rfind(s));

        if (x < 0)
        {
            if (s.length() == s_min.length() && s > s_min)
                return 0;
            return stoi("-" + s);
        }
        else
        {
            if (s.length() == s_max.length() && s > s_max)
                return 0;
            return stoi(s);
        }
        return 0;
    }
};
// @lc code=end
