/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
Accepted
269/269 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 5.24 % of cpp submissions (6.4 MB)
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        // 定义二维数组f[n][2]
        // f[i][0]存储前i个字符不与前一个字符合并的解码情况数
        // f[i][1]存储第i个字符与前一个字符合并的解码情况数。
        vector<vector<int>> dp(s.length(), vector<int>(2));
        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0)
            {
                // 第一个字符，不予前面的字符和并
                if (s[i] >= '1' && s[i] <= '9')
                {
                    dp[i][0] = 1;
                }
            }
            else
            {
                if (s[i] >= '1' && s[i] <= '9')
                {
                    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                }
                // 前一个字符为1或2，当前字符在0-6之间可以合并
                char bef = s[i - 1];
                if (bef == '1' || (bef == '2' && s[i] >= '0' && s[i] <= '6'))
                {
                    dp[i][1] = dp[i - 1][0];
                }
            }
        }
        return dp[s.length() - 1][0] + dp[s.length() - 1][1];
    }
};
// @lc code=end
