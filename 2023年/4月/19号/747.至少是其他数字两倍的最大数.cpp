/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        // 找最小值和次大值
        int max = INT_MIN;
        int prev_max = INT_MIN;
        int maxPos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                prev_max = max;
                max = nums[i];
                maxPos = i;
            }
            else if (nums[i] > prev_max)
            {
                prev_max = nums[i];
            }
        }
        return max >= prev_max * 2 ? maxPos : -1;
    }
};
// @lc code=end
