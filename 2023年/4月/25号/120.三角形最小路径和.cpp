/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
        {
            return triangle[0][0];
        }
        vector<vector<int>> dp(triangle.size()); // dp[i][j]代表到triangle[i][j]的距离
        dp[0].push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++)
        {
            dp[i] = vector<int>(dp[i - 1].size() + 1, 0);
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    continue;
                }
                if (j == triangle[i].size() - 1)
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        return *min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> ret = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    solution.minimumTotal(ret);
    return 0;
}
