/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
public:
    int minInsertions(string s)
    {
        // dp[i][j]表示s[i-j]变成回文串的最少插入次数
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    // 已经是回文串
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end
