/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

/**
Accepted
49/49 cases passed (8 ms)
Your runtime beats 97.84 % of cpp submissions
Your memory usage beats 10.08 % of cpp submissions (10.1 MB)
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 1)
        {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }
        int size = matrix.size();
        vector<vector<int>> dp(size, vector<int>(size, 0)); // dp[i][j]代表到达matrix[i][j]的最短路径
        for (int i = 0; i < size; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j - 1 < 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                    continue;
                }
                if (j + 1 >= size)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];
            }
        }
        return *min_element(dp[size - 1].begin(), dp[size - 1].end());
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> ret = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    solution.minFallingPathSum(ret);
    return 0;
}
