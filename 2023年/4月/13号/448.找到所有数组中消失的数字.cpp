/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ret;
        vector<bool> found(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); i++)
        {
            found[nums[i]] = true;
        }

        for (int i = 1; i < found.size(); i++)
        {
            if (found[i] == false)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end
