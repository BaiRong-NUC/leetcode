/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
using namespace std;
/**
Accepted
195/195 cases passed (4 ms)
Your runtime beats 68.84 % of cpp submissions
Your memory usage beats 75 % of cpp submissions (10.7 MB)
 */
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        if (size <= 0)
        {
            return -1;
        }
        if (size == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        int left = 0;
        int right = size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            {
                // 0-mid有序
                if (nums[0] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                // mid-right有序
                if (nums[mid] < target && target <= nums[size - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
