/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

#include <vector>
#include <iostream>

/**
Accepted
44/44 cases passed (192 ms)
Your runtime beats 20.93 % of cpp submissions
Your memory usage beats 18.4 % of cpp submissions (88.7 MB)
 */

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));
        // dp[i][0]不做处理,不持有股票的收益最大值
        // dp[i][1]买入股票，收益最大值
        // dp[i][2]卖出股票,付手续费，收益最大值
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = -fee; // 买入再卖出，还得付手续费
        for (int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], max(dp[i - 1][2] - prices[i], dp[i - 1][1]));
            dp[i][2] = prices[i] + dp[i - 1][1] - fee;
        }
        return max(dp[size - 1][0], max(dp[size - 1][1], dp[size - 1][2]));
    }
};
// @lc code=end
