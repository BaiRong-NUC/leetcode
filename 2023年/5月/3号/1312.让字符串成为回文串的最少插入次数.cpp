/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

#include <string>
#include <vector>

using namespace std;

/**
Accepted
58/58 cases passed (40 ms)
Your runtime beats 66.78 % of cpp submissions
Your memory usage beats 48.69 % of cpp submissions (27.7 MB)
 */

// @lc code=start

// s.length()-最长回文字符串长度即可,套路题

class Solution
{
public:
    int minInsertions(string s)
    {
        int len = s.length();
        // dp[i][j]= s[i-j]最长回文字符串
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = len - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return len - dp[0][len - 1];
    }
};
// @lc code=end
