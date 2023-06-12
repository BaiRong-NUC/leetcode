/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

/**
Accepted
1157/1157 cases passed (16 ms)
Your runtime beats 37.88 % of cpp submissions
Your memory usage beats 40.19 % of cpp submissions (10.5 MB)
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
        {
            return s;
        }
        vector<string> ret(numRows);
        int flag = -1; // 向上走，向下走的标志
        int cur = 0;
        for (char &ch : s)
        {
            ret[cur] += ch;
            if (cur == 0 || cur == numRows - 1)
            {
                flag = -flag;
            }
            cur += flag;
        }
        for (int i = 1; i < numRows; i++)
        {
            ret[0] += ret[i];
        }
        return ret[0];
    }
};
// @lc code=end
