/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
using namespace std;

/**
Accepted
74/74 cases passed (24 ms)
Your runtime beats 40.24 % of cpp submissions
Your memory usage beats 5.53 % of cpp submissions (18.9 MB)
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0; // 指向0元素位置
        int right = 0;
        int right_prev = 0;
        while (right < nums.size())
        {
            right_prev = right;
            while (right < nums.size() && nums[right] != 0)
            {
                right += 1;
            }

            // right_prev-right没有0

            for (int i = right_prev; i < right; i++)
            {
                nums[left] = nums[i];
                left++;
            }
            right += 1;
        }
        while (left < nums.size())
        {
            nums[left] = 0;
            left += 1;
        }
    }
};
// @lc code=end
