/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

/**
Accepted
210/210 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 23.51 % of cpp submissions (11.5 MB)
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));
        // dp[i][0];第i天持有股票，且到最大值
        // dp[i][1];第i天不持有股票，下一天位冷冻期
        // dp[i][2];不持有股票，下一天非冷冻期
        dp[0][0] = -prices[0];
        dp[0][1] = INT_MIN; // 当天买入，当天卖出，造成冷冻期，亏损最大化
        dp[0][2] = 0;
        for (int i = 1; i < size; i++)
        {
            // 今天的股票=昨天的股票，昨天没买今天买股票的最大值
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 今天卖出的价钱
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 不做任何操作，冷冻期或不处理
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        // 最后一天dp[size-1][0]代表还持有股票，收益肯定比不持有的情况低
        return max(dp[size - 1][1], dp[size - 1][2]);
    }
};
// @lc code=end
