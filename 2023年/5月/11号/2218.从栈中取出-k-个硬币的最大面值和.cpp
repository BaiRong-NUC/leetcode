/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
 */

#include <vector>

using namespace std;

// @lc code=start
/**
Accepted
123/123 cases passed (540 ms)
Your runtime beats 8.82 % of cpp submissions
Your memory usage beats 7.56 % of cpp submissions (29.1 MB)
 */
class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i)
        {
            int z = piles[i - 1].size();
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                int cur = 0;
                for (int t = 1; t <= min(j, z); ++t)
                {
                    cur += piles[i - 1][t - 1];
                    dp[i][j] = max(dp[i - 1][j - t] + cur, dp[i][j]);
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end
