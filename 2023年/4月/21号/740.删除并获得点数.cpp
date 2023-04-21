/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start

// 非常巧妙，转化为leetcode 198题

class Solution
{
    int rob(vector<int> &num)
    {
        if (num.size() == 1)
        {
            return num[0];
        }
        vector<int> dp(num.size() + 1, 0);
        dp[0] = 0;
        dp[1] = num[0];
        dp[2] = max(num[1], num[0]);
        for (size_t i = 3; i <= num.size(); i++)
        {
            dp[i] = max(dp[i - 2] + num[i - 1], dp[i - 1]);
        }
        return dp[num.size()];
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        int max = *max_element(nums.begin(), nums.end());
        vector<int> num(max + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            num[nums[i]] += nums[i];
        }

        // 选则了i,则i+1,i-1不能选
        return rob(num);
    }
};
// @lc code=end
