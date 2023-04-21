/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> dp(nums.size() + 1); // dp[i]偷到i号房最多的价格
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};
// @lc code=end
