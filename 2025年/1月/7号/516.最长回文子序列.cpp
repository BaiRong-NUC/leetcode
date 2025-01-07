/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // 状态压缩
        vector<int> dp(s.size(), 1);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int pre = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                int tmp = dp[j];
                if (s[i] == s[j])
                {
                    // 这次遍历第一次遇到j，这个值是上次外层遍历赋值的，所以pre保存的是dp[i+1][j-1]的值
                    // dp[i][j] = dp[i+1][j-1] + 2;
                    dp[j] = pre + 2;
                }
                else
                {
                    // dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = tmp;
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end
