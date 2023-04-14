/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

#include <vector>

using namespace std;

/**
Accepted
40/40 cases passed (28 ms)
Your runtime beats 92.44 % of cpp submissions
Your memory usage beats 64.66 % of cpp submissions (25.2 MB)
*/

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int ret = 0;
        int endtime = timeSeries[0];
        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (endtime <= timeSeries[i])
            {
                ret += duration;
            }
            else if (timeSeries[i] < endtime)
            {
                // 持续期间又被攻击
                ret -= endtime - timeSeries[i]; // 先减去多加的部分
                ret += duration;                // 在加上重置后的持续时间
            }
            endtime = timeSeries[i] + duration;
        }
        return ret;
    }
};
// @lc code=end
