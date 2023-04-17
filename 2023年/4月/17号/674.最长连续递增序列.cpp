/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int ret = 0;
        while (right + 1 < nums.size())
        {
            while (right + 1 < nums.size() && nums[right + 1] > nums[right])
            {
                right += 1;
            }
            ret = max(ret, right - left);
            right += 1;
            left = right;
        }
        return ret + 1;
    }
};
// @lc code=end
