/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
/**
Accepted
214/214 cases passed (548 ms)
Your runtime beats 7.39 % of cpp submissions
Your memory usage beats 6.95 % of cpp submissions (202.1 MB)
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 一天结束时，可能有持股、可能未持股、可能卖出过1次、可能卖出过2次、也可能未卖出过
        // 所以定义状态转移数组dp[天数][当前是否持股][卖出的次数]
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(3, 0)));
        // 第一天休息
        dp[0][0][0] = 0;
        // 第一天买入
        dp[0][1][0] = -prices[0];
        // 第一天不可能已经有卖出，如果未持股买入+卖出，初始化为0，其他情况为不可能
        dp[0][0][1] = 0;
        dp[0][0][2] = INT_MIN;
        // 第一天不可能已经卖出
        dp[0][1][1] = INT_MIN;
        dp[0][1][2] = INT_MIN;
        for (int i = 1; i < len; i++)
        {
            // 未持股，未卖出过，说明从未进行过买卖
            dp[i][0][0] = 0;
            // 未持股，卖出过1次，可能是今天卖的，可能是之前卖的
            dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1]);
            // 未持股，卖出过2次，可能是今天卖的，可能是之前卖的
            dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2]);
            // 持股，未卖出过，可能是今天买的，可能是之前买的
            dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
            // 持股，卖出过1次，可能是今天买的，可能是之前买的
            dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
            // 持股，卖出过2次，不可能
            dp[i][1][2] = INT_MIN;
        }
        return max(max(dp[len - 1][0][1], dp[len - 1][0][2]), 0);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vet = {1, 2, 3, 4, 5};
    solution.maxProfit(vet);
    return 0;
}
