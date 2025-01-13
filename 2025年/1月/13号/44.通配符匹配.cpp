/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // dp[i][j]表示s[0-i]和p[0-j]是否匹配
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // 初始化dp
        dp[0][0] = true;
        for (int j = 1; j <= p.size(); j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = true;
            }
            else
            {
                // dp数组默认为false
                //  dp[0][j]=false;
                break;
            }
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                {
                    // 匹配一个
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // dp[i][j-1]代表使用*匹配src[i-1],dp[i-1][j]代表不使用*直接跳过
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
