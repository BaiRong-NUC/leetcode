/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int row = text1.length();
        int col = text2.length();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0)); // dp[i][j]指text1[0-i]和text2[0-j]最长公共子序列
        // dp[0][j]为0,dp[i][0]为0
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[row][col];
    }
};
// @lc code=end
