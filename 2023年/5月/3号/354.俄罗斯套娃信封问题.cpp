/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
    static bool compare(vector<int> &left, vector<int> &right)
    {
        return left[0] < right[0] || (left[0] == right[0] && left[1] > right[1]);
    }

    // 贪心+动态规划
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp; // 表示长度为 i 的最长上升子序列的末尾元素的最小值
        for (int i = 0; i < envelopes.size(); i++)
        {
            if (dp.empty())
            {
                dp.emplace_back(envelopes[i][1]);
            }
            else
            {
                if (envelopes[i][1] > dp.back())
                {
                    dp.emplace_back(envelopes[i][1]);
                }
                else
                {
                    int pos = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
                    dp[pos] = envelopes[i][1];
                }
            }
        }
        return dp.size();
    }
};
// @lc code=end
