/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0)); // dp[i][j]代表到ij的最小距离
        dp[0][0] = grid[0][0];
        for (int i = 1; i < dp[0].size(); i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        // for (int i = 0; i < dp.size(); i++)
        // {
        //     for (int j = 0; j < dp[0].size(); j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[row - 1][col - 1];
    }
};
// @lc code=end
