/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j]到大ij位置时需要几步
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int num = 0;
                if (i - 1 >= 0)
                {
                    num += dp[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    num += dp[i][j - 1];
                }
                dp[i][j] = num;
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.uniquePaths(3, 7);
    return 0;
}
