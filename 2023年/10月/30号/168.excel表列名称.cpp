/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ret;
        while (columnNumber > 0)
        {
            columnNumber -= 1;
            ret += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
