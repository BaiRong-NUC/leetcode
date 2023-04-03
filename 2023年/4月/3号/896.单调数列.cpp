/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    void InitFlag(bool &flag, vector<int> &nums, int prev, int pos)
    {

        // 初始化flag
        if (nums[prev] > nums[pos])
        {
            // 降序
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

public:
    bool isMonotonic(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return true;
        }
        bool flag = false; // false means 升序 true means 降序
        int prev = 0;
        int pos = 1;
        bool ret = true;
        while (pos < nums.size() && nums[prev] == nums[pos])
        {
            prev++;
            pos++;
        }
        if (pos == nums.size())
        {
            // 所有元素相同
            return ret;
        }
        else
        {
            InitFlag(flag, nums, prev, pos);
            while (pos < nums.size())
            {
                if (flag == true)
                {
                    // 降序
                    if (nums[prev] < nums[pos])
                    {
                        ret = false;
                        break;
                    }
                }
                else if (flag == false)
                {
                    // 升序
                    if (nums[prev] > nums[pos])
                    {
                        ret = false;
                        break;
                    }
                }
                pos++;
                prev++;
            }
            return ret;
        }
    }
};
// @lc code=end
