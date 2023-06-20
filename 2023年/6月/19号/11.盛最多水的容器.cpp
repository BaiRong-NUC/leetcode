/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
#include <iostream>
using namespace std;

/**
Accepted
61/61 cases passed (64 ms)
Your runtime beats 91.52 % of cpp submissions
Your memory usage beats 38.09 % of cpp submissions (57.6 MB)
 */
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;
        while (left < right)
        {
            ret = max(min(height[left], height[right]) * (right - left), ret);
            height[left] < height[right] ? left += 1 : right -= 1;
        }
        return ret;
    }
};
// @lc code=end
