/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int left = 0; // 指向1
        int right = 0;
        int ret = 0;

        while (right < nums.size())
        {
            while (right < nums.size() && nums[right] == 1)
            {
                right++;
            }
            ret = max(ret, right - left);

            // right找left要去的位置
            while (right < nums.size() && nums[right] != 1)
            {
                right++;
            }
            left = right;
        }
        return ret;
    }
};
// @lc code=end
