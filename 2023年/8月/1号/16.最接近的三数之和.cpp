/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/**
Accepted
99/99 cases passed (60 ms)
Your runtime beats 40.04 % of cpp submissions
Your memory usage beats 31.53 % of cpp submissions (10 MB)
 */
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ret = INT_MAX;
        // 枚举a
        for (int i = 0; i < nums.size(); i++)
        {
            // 保证和之前枚举的结果不一致
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 双指针模拟b，c
            int b = i + 1;
            int c = size - 1;
            while (b < c)
            {
                int sum = nums[i] + nums[b] + nums[c];
                // 如果和为 target 直接返回答案
                if (sum == target)
                {
                    return target;
                }
                // 更新答案
                ret = (ret == INT_MAX) || abs(sum - target) < abs(ret - target) ? sum : ret;
                if (sum >= target)
                {
                    c -= 1;
                    // 移动到下一个不相等的位置
                    while (b < c && nums[c] == nums[c + 1])
                    {
                        c -= 1;
                    }
                }
                else
                {
                    b += 1;
                    while (b < c && nums[b] == nums[b - 1])
                    {
                        b += 1;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
