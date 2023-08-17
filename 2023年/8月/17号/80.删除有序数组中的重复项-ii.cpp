/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int merge = 0;
        while (right < nums.size())
        {
            while (right < nums.size() && nums[left] == nums[right])
            {
                right += 1;
            }
            if (right - left + 1 > 2)
            {
                nums[merge++] = nums[left];
                nums[merge++] = nums[left];
                left = right;
            }
            else
            {
                nums[merge++] = nums[left];
                left = right;
            }
        }
        return merge;
    }
};
// @lc code=end
