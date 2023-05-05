/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
/**
Accepted
210/210 cases passed (20 ms)
Your runtime beats 19.25 % of cpp submissions
Your memory usage beats 15.91 % of cpp submissions (13.7 MB)
 */
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // 定义状态转移数组dp[天数][卖出的次数][是否持股]
        int size = prices.size();
        if (size == 0)
        {
            return 0;
        }
        int times = min(k, size / 2);                          // 交易次数
        vector<vector<int>> buy(size, vector<int>(times + 1)); // buy[i][j]代表第i天进行了j次交易，手上有股票的最大利润
        vector<vector<int>> sel(size, vector<int>(times + 1)); // sel[i][j]代表第i天进行了j次交易，手上没有股票的最大利润
        buy[0][0] = -prices[0];
        sel[0][0] = 0;
        for (int i = 1; i <= times; i++)
        {
            buy[0][i] = sel[0][i] = INT_MIN / 2; // 防止溢出
        }
        for (int i = 1; i < size; i++)
        {
            // 没有进行过交易，第i天有股票，可能是前一天买的或前一天卖出后又买入的
            buy[i][0] = max(buy[i - 1][0], sel[i - 1][0] - prices[i]);
            sel[i][0] = 0; // 第i天没有股票，进行了0次交易，只可能是0（sel[i-1][0]）
            for (int j = 1; j <= times; j++)
            {
                buy[i][j] = max(buy[i - 1][j], sel[i - 1][j] - prices[i]);
                // 第i天没有股票，进行了j次交易
                // 可能是i天什么都没做，或和昨天买入的股票做交易
                sel[i][j] = max(sel[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *max_element(sel[size - 1].begin(), sel[size - 1].end());
    }
};
// @lc code=end
