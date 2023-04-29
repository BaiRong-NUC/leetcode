/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

#include <vector>
#include <algorithm>

using namespace std;

/**
Accepted
205/205 cases passed (44 ms)
Your runtime beats 98.22 % of cpp submissions
Your memory usage beats 74.63 % of cpp submissions (21.9 MB)
 */

// @lc code=start
class Solution
{
    static bool compare(vector<int> &left, vector<int> &right)
    {
        return left[1] < right[1];
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        // 贪心解法
        int cur = INT_MIN;
        sort(pairs.begin(), pairs.end(), compare);
        int ret = 0;
        for (auto &p : pairs)
        {
            if (cur < p[0])
            {
                cur = p[1];
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end
