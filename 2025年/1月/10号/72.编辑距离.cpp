/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // dp[i][j]表示word1[0...i]和word2[0...j]的最短编辑距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
