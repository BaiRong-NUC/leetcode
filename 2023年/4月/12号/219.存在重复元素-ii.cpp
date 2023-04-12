/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <vector>
#include <set>

using namespace std;

// 遍历所有长度为k的滑动窗口，看这个窗口内有没有新插入的值，如果有的话则可以找到

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        set<int> _hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
            {
                _hash.erase(nums[i - k - 1]);
            }
            if (_hash.count(nums[i]))
            {
                return true;
            }
            _hash.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
