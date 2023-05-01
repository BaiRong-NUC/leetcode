/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
