/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // s中 i-j范围最长回文串的长度
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int i = s.length() - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.length(); j++)
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
        return dp[0][s.length() - 1];
    }
};
// @lc code=end
