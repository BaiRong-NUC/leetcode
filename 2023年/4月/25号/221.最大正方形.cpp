/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

#include <vector>

using namespace std;

/**
Accepted
78/78 cases passed (76 ms)
Your runtime beats 50.77 % of cpp submissions
Your memory usage beats 54.06 % of cpp submissions (20.4 MB)
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int ret = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    ret = max(ret, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ret * ret;
    }
};
// @lc code=end
