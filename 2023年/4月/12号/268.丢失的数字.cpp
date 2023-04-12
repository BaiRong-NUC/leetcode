/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            ret ^= i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};
// @lc code=end
