/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

#include <vector>

/**
Accepted
28/28 cases passed (4 ms)
Your runtime beats 99.49 % of cpp submissions
Your memory usage beats 51.7 % of cpp submissions (7 MB)
 */

using namespace std;

// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end
