/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */
#include <vector>
#include <set>
using namespace std;
/**
Accepted
103/103 cases passed (236 ms)
Your runtime beats 5.51 % of cpp submissions
Your memory usage beats 5.19 % of cpp submissions (72.6 MB)
 */
// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int size = nums.size();
        if (size < 3)
        {
            return false;
        }

        // 左侧最小值
        int left_min = nums[0];
        // 右侧元素(次小值)的所有值
        multiset<int> right_val;
        for (int j = 2; j < size; j++)
        {
            right_val.insert(nums[j]);
        }

        // 枚举最大值
        for (int k = 1; k < size - 1; k++)
        {
            if (left_min < nums[k])
            {
                // 找右侧次小值
                auto ptr = right_val.upper_bound(left_min);
                if (ptr != right_val.end() && *ptr < nums[k])
                {
                    return true;
                }
            }
            left_min = min(left_min, nums[k]);
            right_val.erase(right_val.find(nums[k + 1]));
        }
        return false;
    }
};
// @lc code=end
