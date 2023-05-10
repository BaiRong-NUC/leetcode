#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int houses = costs.size();
        vector<vector<int>> dp(houses, vector<int>(3));
        for (int i = 0; i < 3; i++)
        {
            dp[0][i] = costs[0][i];
        }
        for (int i = 1; i < houses; i++)
        {
            for (int j = 0; j < 3; j++)
            { // 三种不同颜色
                int minCost = INT_MAX;

                // 用前一个房子的颜色计算j颜色的最小值
                for (int k = 0; k < 3; k++)
                {
                    if (k != j)
                    {
                        minCost = min(minCost, dp[i - 1][k]);
                    }
                }

                dp[i][j] = minCost + costs[i][j];
            }
        }
        return *min_element(dp[houses - 1].begin(), dp[houses - 1].end());
    }
};