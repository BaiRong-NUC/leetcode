/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
//查找数组中第一个大于等于target的位置
class Solution
{
    int Search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right + 1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int small = Search(nums, target);
        int big = Search(nums, target + 1) - 1;
        if (small <= big)
        {
            return {small, big};
        }
        return {-1, -1};
    }
};
// @lc code=end
