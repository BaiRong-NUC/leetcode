/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        if (nums.size() == 0)
        {
            return ret;
        }
        if (nums.size() == 1)
        {
            ret.push_back(to_string(nums[0]));
            return ret;
        }
        int left = 0;
        int right = 1;
        while (right < nums.size() || left < nums.size())
        {
            string str = "";
            if (right >= nums.size())
            {
                if (right - left == 1)
                {
                    str = to_string(nums[left]);
                }
                else
                {
                    str = to_string(nums[left]) + "->" + to_string(nums[nums.size() - 1]);
                }
                ret.push_back(str);
                left = right;
            }
            else
            {
                if (nums[right] == 1 + nums[right - 1])
                {
                    right += 1;
                }
                else
                {
                    if (right - left == 1)
                    {
                        str = to_string(nums[left]);
                    }
                    else
                    {
                        str = to_string(nums[left]) + "->" + to_string(nums[right - 1]);
                    }
                    left = right;
                    right += 1;
                    cout << str << endl;
                    ret.push_back(str);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
