#include <vector>
#include <algorithm>

using namespace std;

/**
执行用时：16 ms, 在所有 C++ 提交中击败了67.75%的用户
内存消耗：11.4 MB, 在所有 C++ 提交中击败了27.54%的用户
通过测试用例：103 / 103
 */

class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        int house = costs.size();
        int color = costs[0].size();
        vector<vector<int>> dp(house, vector<int>(color));
        for (int i = 0; i < color; i++)
        {
            dp[0][i] = costs[0][i];
        }
        for (int i = 1; i < house; i++)
        {
            for (int j = 0; j < color; j++)
            {
                int minBefore = INT_MAX;
                for (int p = 0; p < color; p++)
                {
                    if (p != j)
                    {
                        minBefore = min(minBefore, dp[i - 1][p]);
                    }
                }
                dp[i][j] = minBefore + costs[i][j];
            }
        }
        return *min_element(dp[house - 1].begin(), dp[house - 1].end());
    }
};