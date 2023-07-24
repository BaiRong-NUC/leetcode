/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>
using namespace std;
/**
Accepted
170/170 cases passed (32 ms)
Your runtime beats 79.32 % of cpp submissions
Your memory usage beats 89.57 % of cpp submissions (18.4 MB)
 */
// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }
        // 首先对数组进行排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (ret.empty() || ret.back()[1] < left)
            {
                ret.push_back({left, right});
            }
            else
            {
                ret.back()[1] = max(ret.back()[1], right);
            }
        }
        return ret;
    }
};
// @lc code=end
