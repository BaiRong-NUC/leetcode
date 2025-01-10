/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <D:/CppCode/leetcode/global/global.h>
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // dp[i]表示以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
