/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
    int findLeft(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                // nums[mid] == target
                right = mid - 1;
            }
        }
        if (left == nums.size() || nums[left] != target)
        {
            return -1;
        }
        else
        {
            return left;
        }
    }

    int findRight(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
        {
            return -1;
        }
        else
        {
            return right;
        }
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = findLeft(nums, target);
        // cout << left << endl;
        int right = findRight(nums, target);
        // cout << right << endl;
        return {left, right};
    }
};
// @lc code=end
