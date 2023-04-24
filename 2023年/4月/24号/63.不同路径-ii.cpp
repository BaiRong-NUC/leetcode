/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        vector<vector<int>> dp(row); // dp[i][j]到大ij位置时需要几步

        for (int i = 0; i < row; i++)
        {
            dp[i] = vector<int>(obstacleGrid[i].size(), 0);
            for (int j = 0; j < obstacleGrid[i].size(); j++)
            {
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                int sum = 0;
                if (j - 1 >= 0)
                {
                    sum += dp[i][j - 1];
                }
                if (i - 1 >= 0)
                {
                    sum += dp[i - 1][j];
                }
                dp[i][j] = sum;
            }
        }

        return dp[row - 1][obstacleGrid[row - 1].size() - 1];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> vet = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    solution.uniquePathsWithObstacles(vet);
    return 0;
}
