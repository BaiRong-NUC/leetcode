/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

#include <vector>
#include <iostream>

using namespace std;

/**
Accepted
15/15 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 39.06 % of cpp submissions (6.5 MB)
 */
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0 && dp[i - num] < INT_MAX - dp[i])
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
