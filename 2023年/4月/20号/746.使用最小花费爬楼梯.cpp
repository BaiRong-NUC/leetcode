/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

#include <vector>

using namespace std;

/**
Accepted
283/283 cases passed (4 ms)
Your runtime beats 86.39 % of cpp submissions
Your memory usage beats 19.86 % of cpp submissions (13.4 MB)
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 0)
        {
            return 0;
        }
        if (cost.size() <= 2)
        {
            return min(cost[cost.size() - 1], cost[cost.size() - 2]);
        }
        vector<int> dp(cost.size()); // 到i台阶需要的最小值
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};
// @lc code=end
