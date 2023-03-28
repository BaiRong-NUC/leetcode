/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1; //[]
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] < target)
            {
                begin = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid;
                break;
            }
        }
        return begin;
    }
};
// @lc code=end
